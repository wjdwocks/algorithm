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