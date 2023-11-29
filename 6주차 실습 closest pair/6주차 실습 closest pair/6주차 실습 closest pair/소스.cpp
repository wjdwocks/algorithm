#include <iostream>
#include <cmath> 

typedef struct pair // std::pair�� ���� �ȵɰ� ���Ƽ� ����ü�� �߽��ϴ�.
{
	int first;
	int second;
};

void swap(pair& a, pair& b) // pair �ڷ����� �´� swap�Լ�
{
	pair temp = a;
	a.first = b.first;
	a.second = b.second;
	b.first = temp.first;
	b.second = temp.second;
}

int partition(pair* arr, int l, int r, int order) // quickSort�� �� ������ ���� ������ �����ϴ� partition �Լ�.
{
	pair pivot = arr[l]; // ������ ���� �Ǻ����� �����Ѵ�.
	int small = l + 1; // small�� pivot���� ���� ���� �δ� ������ �Ѵ�.
	if (order == 0) // x��ǥ�� �������� ����
	{
		for (int i = l + 1; i <= r; i++)
		{
			if (arr[i].first < pivot.first)
			{
				swap(arr[i], arr[small]); // small�� ��ġ�� pivot.first ���� ���� arr[i]�� �ٲ�.
				small++;
			}
		}
		swap(arr[l], arr[small - 1]); // �̰� �ؾ� ���� pivot���� ���õ� �迭�� ũ����� ��ġ�� �������� ���̴�.
		return small - 1; // ���� �Ǻ��� return����.
	}
	else // y��ǥ�� �������� ����
	{
		for (int i = l + 1; i <= r; i++)
		{
			if (arr[i].second < pivot.second)
			{
				swap(arr[i], arr[small]); // small�� ��ġ�� pivot.second ���� ���� arr[i]�� �ٲ�.
				small++;
			}
		}
		swap(arr[l], arr[small - 1]); // �̰� �ؾ� ���� pivot���� ���õ� �迭������ pivot�� ��ġ�� �������� ���̴�.
		return small - 1; // ���� �Ǻ��� return����.
	}
}

void quickSort(pair* arr, int l, int r, int order)
{
	if (l < r) // l < r�̶�°� ���� ������ �� �ȵƴٴ°�.
	{
		if (order == 0) // x��ǥ�� �������� �����ϰڴ�.
		{
			int next_pivot = partition(arr, l, r, 0);
			quickSort(arr, l, next_pivot - 1, 0);
			quickSort(arr, next_pivot + 1, r, 0);
		}
		else // y��ǥ�� �������� ������ ���̴�.
		{
			int next_pivot = partition(arr, l, r, 1);
			quickSort(arr, l, next_pivot - 1, 1);
			quickSort(arr, next_pivot + 1, r, 1);
		}
	}
}


 // ex) arr[3] arr[4] arr[5] �϶� l == 3, r == 5;
double find_min(pair* arr, int l, int r) // �������� ������ ���� 2���� 3���� �� �� ���� ������ �Ÿ� �� �ּڰ��� ��ȯ�ϴ� �Լ�.
{
	if (r - l + 1 == 3) // ���Ե� ���� 3���� ��
	{
		double one = sqrt(pow(arr[l + 1].first - arr[l].first, 2) + pow(arr[l + 1].second - arr[l].second, 2)); // ù��°, �ι��� �� ������ �Ÿ�.
		double two = sqrt(pow(arr[l + 2].first - arr[l + 1].first, 2) + pow(arr[l + 2].second - arr[l + 1].second, 2)); // �ι���, ����° �� ������ �Ÿ�
		double three = sqrt(pow(arr[l + 2].first - arr[l].first, 2) + pow(arr[l + 2].second - arr[l].second, 2)); // ù����, ����° �� ������ �Ÿ�.
		if (one <= two && one <= three) // ������ �Ÿ��� �ּ��� ���� ��ȯ��.
			return one;
		else if (two <= one && two <= three)
			return two;
		else
			return three;
	}
	return sqrt(pow(arr[l + 1].first - arr[l].first, 2) + pow(arr[l + 1].second - arr[l].second, 2)); // ���� �ΰ��� �� �Ÿ��� �ּ���.
}

double find_middle(pair* arr, int l, int r, double mid_range) // ���� ������ ���� ����, ��� �������� �������� �� ��� ������ ���� �� �ּڰ��� ���ϴ� �Լ�.
{ // l�� ��� ������ ���� ���� x��ǥ�� ���� ���� �迭 ����, r �� ��� ������ ���� ������ x��ǥ�� ���� ���� �迭 ����
	double min = mid_range; // �ּڰ��� func�Լ����� �������� ���� ����, ���� ������ �ּڰ��� �� �ּڰ��� mid_range�� �ΰ� mid������ �ִ� ������ �Ÿ��� ���Ͽ� ������ �Ÿ��� �� ������ min�� �ֽ�ȭ��.

	quickSort(arr, l, r, 1); // y��ǥ�� �������� �����ϰ�,

	for (int i = l; i <= r - 1; i++)
	{
		for (int j = i + 1; j <= r; j++)
		{
			if (arr[i].second - arr[j].second >= mid_range)
				break;
			if (sqrt(pow(arr[i].first - arr[j].first, 2) + pow(arr[i].second - arr[j].second, 2)) < mid_range)
				min = sqrt(pow(arr[i].first - arr[j].first, 2) + pow(arr[i].second - arr[j].second, 2));
		}
	}
	return min;

}

double func(pair* arr, int l, int r) // l : ������ ���� �迭 ��ȣ, r : ������ ������ �迭 ��ȣ ex) arr[l]~arr[r]�� ������ ����.
{ // �� �Լ��� ������ ������ ������ 3����� ����������(����, ����, �߾�) ���� �ּڰ����� ��ȯ�� �߾��� ������ ����, ������ �ּڰ��� ���� �޶�����, ����, ������ �ּڰ��� �߾��� �ּڰ��� ���Ͽ� ��ȯ.
	int elements = r - l + 1; // �迭�� ���Ե� ���� ������ 3�� �����̸� �Ÿ��� �ּڰ��� ���Ϸ� ��.
	if (elements <= 3)
	{
		return find_min(arr, l, r);
	}

	// �迭�� ���Ե� ������ ������ 3���� ���� �ʴٸ� ����, ����, �߾����� ����� ����, ������ ������ ���ؼ� �� �Լ��� ��ø�Ͽ� ȣ����.
	int mid = (l + r) / 2;
	double left = func(arr, l, mid);
	double right = func(arr, mid + 1, r);

	double mid_range; // mid_range�� left�� �ּڰ��� right�� �ּڰ� �� �� ���� ���� �������� �߾ӿ��� ã�� x���� ������ ����.
	if (left < right)
		mid_range = left;
	else
		mid_range = right;

	// mid_range�� ���ؼ� ���� ������ ���� �������� arr[mid]���� arr[mid-1], arr[mid-2]�� �� �������鼭 x��ǥ�� ���̰� mid_range���� Ŀ���� �� �ٷ� �� ���� mid������ ���� ������,
	// arr[mid + 1]���� arr[mid + 2]... �� �� �ö󰡸鼭 x��ǥ ���̰� mid_range���� Ŀ���� �� �ٷ� �� ���� mid������ ���� ���� ������ �ؼ� �� ���� ������ �Ÿ� �� �ּڰ��� ���Ѵ�.
	int mid_left = mid - 1;
	int mid_right = mid + 2;
	while ((arr[mid].first - arr[mid_left].first) > mid_range && mid_left-- != l); // mid ������ left���� ã�� ���� loop
	while ((arr[mid_right].first - arr[mid + 1].first) > mid_range && mid_right-- != r); // mid ������ right���� ã�� ���� loop

	double middle = find_middle(arr, mid_left, mid_right, mid_range); // �߾��� ������ ���� �˰����� �ʿ���. --> find_middle��

	if (mid_range < middle) // ����, ���� ������ �ּڰ��� �߾��� �ּڰ��� ���Ͽ� �� �������� ��ȯ��.
		return mid_range;
	else
		return middle;
}

int main()
{
	int n; // ��ü ���� ����.
	std::cin >> n;

	pair* arr = new pair[n]; // x��ǥ�� y��ǥ�� ���� ������ ����ü pair�� �����, pair���� �迭�� n�� ����.

	int i = 0; // �Է¹޴� ������ ���� i = 0���� �����ν� ù�������� �ް� ��.
	char comma; // �Է¿� ,�� �ִ°� �޴� �뵵.

	int repeat = n; // while���� n�� �ݺ�
	while (repeat--)
	{
		std::cin >> arr[i].first >> comma >>  arr[i].second;
		i++;
	}

	quickSort(arr, 0, n-1, 0); // x��ǥ�� �������� �������� �����ϱ�.

	printf("%.6lf", func(arr, 0, n-1)); // �Ҽ��� 6��°���� �ޱ� ���ؼ� printf�� �����.
	// ������ arr[0]~arr[n-1/2]������ arr[n-1/2 + 1]~arr[n-1]������ ������. 
	// ������ �����ִ� ���� ������ 3�� ���ϰ� �� ������ ������ �װ͵��� �Ÿ����� ���ؼ� ���� �ּڰ��� ����.

	delete[] arr; // �����迭 ���� ���ְ�.
}