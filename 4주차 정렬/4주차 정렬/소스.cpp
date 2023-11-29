#include <iostream>

void swap(int* a, int* b) // �� �迭�� ����� ���� ���� �ٲٱ����� �Լ�
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int left, int right)
{
	int pivot = arr[right]; // �������� ������ �� ������ ���� pivot���� �д�.
	int i = left - 1; // i�� �������� pivot�� �־�� �� ��ġ�� ��Ÿ���� ���� ����.

	for (int j = left; j <= right - 1; j++) // �� �������� pivot�̱� ������ right-1���� �ݺ�
	{
		if (arr[j] <= pivot) // �Ǻ����� ������
		{
			i++;
			swap(&arr[i], &arr[j]); // �迭�� �� �տ������� ����� ����
		}
	}
	swap(&arr[i + 1], &arr[right]); // �Ǻ����� �����͵��� �տ��� �������� �� ������ pivot�� ��.
	return (i + 1); // pivot�� ��ġ�� ��������, pivot ���� �Ĵ� pivot���� �۰�, ū���� ����.
}


void quickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int next_pibot = partition(arr, left, right); // ���� pivot���� �˾Ƴ���

		quickSort(arr, left, next_pibot - 1); // pivot�� �������� ����
		quickSort(arr, next_pibot + 1, right); // pivot�� �������� ���ĸ� �ٽ� quickSort��.
	}
}

int main()
{
	int N;
	std::cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		std::cin >> arr[i];

	quickSort(arr, 0, N-1);
	for(int i=0;i<N;i++)
		std::cout << arr[i] << '\n';
}