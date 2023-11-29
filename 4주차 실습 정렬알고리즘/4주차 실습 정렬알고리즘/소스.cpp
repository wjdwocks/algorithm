#include <iostream>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = *a;
}

int partition(int arr[], int left, int right)
{
	int pivot = arr[right];
	int i = left - 1;

	for (int j = left; j <= right - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[right]);
	return (i + 1);
}


void quickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int next_pibot = partition(arr, left, right);

		quickSort(arr, left, next_pibot - 1);
		quickSort(arr, next_pibot + 1, right);
	}
}

int main()
{
	int N;
	std::cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		std::cin >> arr[i];

	quickSort(arr, 0, N - 1);
	std::cout << arr[0] << '\n';
}