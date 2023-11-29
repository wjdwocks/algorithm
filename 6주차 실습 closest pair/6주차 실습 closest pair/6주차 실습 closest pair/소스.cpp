#include <iostream>
#include <cmath> 

typedef struct pair // std::pair를 쓰면 안될것 같아서 구조체로 했습니다.
{
	int first;
	int second;
};

void swap(pair& a, pair& b) // pair 자료형에 맞는 swap함수
{
	pair temp = a;
	a.first = b.first;
	a.second = b.second;
	b.first = temp.first;
	b.second = temp.second;
}

int partition(pair* arr, int l, int r, int order) // quickSort할 때 구역을 나눌 기준을 생성하는 partition 함수.
{
	pair pivot = arr[l]; // 왼쪽의 쌍을 피봇으로 선정한다.
	int small = l + 1; // small을 pivot보다 작은 쌍을 두는 곳으로 한다.
	if (order == 0) // x좌표를 기준으로 정렬
	{
		for (int i = l + 1; i <= r; i++)
		{
			if (arr[i].first < pivot.first)
			{
				swap(arr[i], arr[small]); // small의 위치에 pivot.first 보다 작은 arr[i]와 바꿈.
				small++;
			}
		}
		swap(arr[l], arr[small - 1]); // 이걸 해야 이제 pivot으로 선택된 배열의 크기상의 위치가 정해지는 것이다.
		return small - 1; // 다음 피봇을 return해줌.
	}
	else // y좌표를 기준으로 정렬
	{
		for (int i = l + 1; i <= r; i++)
		{
			if (arr[i].second < pivot.second)
			{
				swap(arr[i], arr[small]); // small의 위치에 pivot.second 보다 작은 arr[i]와 바꿈.
				small++;
			}
		}
		swap(arr[l], arr[small - 1]); // 이걸 해야 이제 pivot으로 선택된 배열에서의 pivot의 위치가 정해지는 것이다.
		return small - 1; // 다음 피봇을 return해줌.
	}
}

void quickSort(pair* arr, int l, int r, int order)
{
	if (l < r) // l < r이라는건 아직 정렬이 다 안됐다는것.
	{
		if (order == 0) // x좌표를 기준으로 정렬하겠다.
		{
			int next_pivot = partition(arr, l, r, 0);
			quickSort(arr, l, next_pivot - 1, 0);
			quickSort(arr, next_pivot + 1, r, 0);
		}
		else // y좌표를 기준으로 정렬할 것이다.
		{
			int next_pivot = partition(arr, l, r, 1);
			quickSort(arr, l, next_pivot - 1, 1);
			quickSort(arr, next_pivot + 1, r, 1);
		}
	}
}


 // ex) arr[3] arr[4] arr[5] 일때 l == 3, r == 5;
double find_min(pair* arr, int l, int r) // 나누어진 구역의 점이 2개나 3개일 때 그 점들 사이의 거리 중 최솟값을 반환하는 함수.
{
	if (r - l + 1 == 3) // 포함된 점이 3개일 떄
	{
		double one = sqrt(pow(arr[l + 1].first - arr[l].first, 2) + pow(arr[l + 1].second - arr[l].second, 2)); // 첫번째, 두번쨰 점 사이의 거리.
		double two = sqrt(pow(arr[l + 2].first - arr[l + 1].first, 2) + pow(arr[l + 2].second - arr[l + 1].second, 2)); // 두번쨰, 세번째 점 사이의 거리
		double three = sqrt(pow(arr[l + 2].first - arr[l].first, 2) + pow(arr[l + 2].second - arr[l].second, 2)); // 첫번쨰, 세번째 점 사이의 거리.
		if (one <= two && one <= three) // 각각의 거리중 최소인 점을 반환함.
			return one;
		else if (two <= one && two <= three)
			return two;
		else
			return three;
	}
	return sqrt(pow(arr[l + 1].first - arr[l].first, 2) + pow(arr[l + 1].second - arr[l].second, 2)); // 점이 두개라 그 거리가 최소임.
}

double find_middle(pair* arr, int l, int r, double mid_range) // 좌측 구역과 우측 구역, 가운데 구역으로 나눠졌을 때 가운데 구역의 점들 중 최솟값을 구하는 함수.
{ // l은 가운데 구역의 가장 왼쪽 x좌표를 가진 점의 배열 순서, r 은 가운데 구역의 가장 오른쪽 x좌표를 가진 점의 배열 순서
	double min = mid_range; // 최솟값에 func함수에서 나누어진 우측 구역, 좌측 구역의 최솟값들 중 최솟값인 mid_range를 두고 mid구역에 있는 점들의 거리와 비교하여 점들의 거리가 더 작으면 min을 최신화함.

	quickSort(arr, l, r, 1); // y좌표를 기준으로 정렬하고,

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

double func(pair* arr, int l, int r) // l : 범위의 왼쪽 배열 번호, r : 범위의 오른쪽 배열 번호 ex) arr[l]~arr[r]의 범위로 나뉨.
{ // 이 함수를 실행할 때마다 구역이 3군대로 나누어지고(좌측, 우측, 중앙) 각각 최솟값들을 반환함 중앙의 범위는 좌측, 우측의 최솟값에 따라 달라지고, 좌측, 우측의 최솟값과 중앙의 최솟값을 비교하여 반환.
	int elements = r - l + 1; // 배열에 포함된 점의 갯수가 3개 이하이면 거리의 최솟값을 구하러 감.
	if (elements <= 3)
	{
		return find_min(arr, l, r);
	}

	// 배열에 포함된 점들의 개수가 3보다 작지 않다면 좌측, 우측, 중앙으로 나누어서 좌측, 우측은 각각에 대해서 이 함수를 중첩하여 호출함.
	int mid = (l + r) / 2;
	double left = func(arr, l, mid);
	double right = func(arr, mid + 1, r);

	double mid_range; // mid_range는 left의 최솟값과 right의 최솟값 중 더 작은 수를 기준으로 중앙에서 찾을 x값의 범위를 정함.
	if (left < right)
		mid_range = left;
	else
		mid_range = right;

	// mid_range를 통해서 좌측 구역의 가장 오른쪽인 arr[mid]부터 arr[mid-1], arr[mid-2]로 쭉 내려가면서 x좌표의 차이가 mid_range보다 커지는 점 바로 전 점을 mid구역의 제일 좌측점,
	// arr[mid + 1]부터 arr[mid + 2]... 로 쭉 올라가면서 x좌표 차이가 mid_range보다 커지는 점 바로 전 점을 mid구역의 제일 우측 점으로 해서 그 점들 사이의 거리 중 최솟값을 구한다.
	int mid_left = mid - 1;
	int mid_right = mid + 2;
	while ((arr[mid].first - arr[mid_left].first) > mid_range && mid_left-- != l); // mid 구역의 left값을 찾기 위한 loop
	while ((arr[mid_right].first - arr[mid + 1].first) > mid_range && mid_right-- != r); // mid 구역의 right값을 찾기 위한 loop

	double middle = find_middle(arr, mid_left, mid_right, mid_range); // 중앙의 값들을 비교할 알고리즘이 필요함. --> find_middle로

	if (mid_range < middle) // 좌측, 우측 구역의 최솟값과 중앙의 최솟값을 비교하여 더 작은값을 반환함.
		return mid_range;
	else
		return middle;
}

int main()
{
	int n; // 전체 점의 개수.
	std::cin >> n;

	pair* arr = new pair[n]; // x좌표와 y좌표를 같이 보관할 구조체 pair를 만들고, pair동적 배열을 n개 만듦.

	int i = 0; // 입력받는 점들의 쌍을 i = 0으로 함으로써 첫번쨰부터 받게 함.
	char comma; // 입력에 ,가 있는걸 받는 용도.

	int repeat = n; // while문을 n번 반복
	while (repeat--)
	{
		std::cin >> arr[i].first >> comma >>  arr[i].second;
		i++;
	}

	quickSort(arr, 0, n-1, 0); // x좌표를 기준으로 오름차순 정렬하기.

	printf("%.6lf", func(arr, 0, n-1)); // 소수점 6번째까지 받기 위해서 printf로 출력함.
	// 구역을 arr[0]~arr[n-1/2]까지와 arr[n-1/2 + 1]~arr[n-1]까지로 나눈다. 
	// 구역에 남아있는 점의 개수가 3개 이하가 될 때까지 나누고 그것들의 거리들을 구해서 그중 최솟값을 얻어낸다.

	delete[] arr; // 동적배열 해제 해주고.
}