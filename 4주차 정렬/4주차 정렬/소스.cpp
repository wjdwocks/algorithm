#include <iostream>

void swap(int* a, int* b) // 두 배열에 저장된 값을 서로 바꾸기위한 함수
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int left, int right)
{
	int pivot = arr[right]; // 나뉘어진 영역의 맨 오른쪽 값을 pivot으로 둔다.
	int i = left - 1; // i는 마지막에 pivot이 있어야 할 위치를 나타내기 위한 변수.

	for (int j = left; j <= right - 1; j++) // 맨 오른쪽이 pivot이기 때문에 right-1까지 반복
	{
		if (arr[j] <= pivot) // 피봇보다 작으면
		{
			i++;
			swap(&arr[i], &arr[j]); // 배열의 맨 앞에서부터 줄지어서 정렬
		}
	}
	swap(&arr[i + 1], &arr[right]); // 피봇보다 작은것들을 앞에서 세웠으니 그 다음에 pivot을 둠.
	return (i + 1); // pivot의 위치는 정해졌고, pivot 전과 후는 pivot보다 작고, 큰값만 남음.
}


void quickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int next_pibot = partition(arr, left, right); // 다음 pivot값을 알아내고

		quickSort(arr, left, next_pibot - 1); // pivot을 기준으로 이전
		quickSort(arr, next_pibot + 1, right); // pivot을 기준으로 이후를 다시 quickSort함.
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