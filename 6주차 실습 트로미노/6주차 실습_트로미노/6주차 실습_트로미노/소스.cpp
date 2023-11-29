#include <iostream>

int num = 1;
// ��и� ������ ���� : 1��и�, �»�� : 2��и�, ���ϴ� : 3��и�, ���ϴ� : 4��и����� �߽��ϴ�.

// l : ������ ������ ���� ����� x ��ǥ, r : ������ ������ ���ʻ�� y��ǥ. row : ���� ����. sqr : ������ ��и� ��ġ. x,y : ������ ��ġ.

void func(int* arr[16], int row, int l, int r, int x, int y) // �迭�� �� �迭�� ���μ��� ����, ������ �ִ� ��ġ.
{
	if (row == 2) // ���� ���̰� 2�� �Ǹ� ������ ������ ������ �κп� ������ �д�.
	{
		if (x % 2 == 0 && y % 2 == 0) // ���� ���� �����϶� 
		{
			arr[x + 1][y + 1] = num;
			arr[x + 1][y] = num;
			arr[x][y + 1] = num;
		}
		else if (x % 2 == 1 && y % 2 == 0) // ���� ���� �����϶�
		{
			arr[x - 1][y + 1] = num;
			arr[x - 1][y] = num;
			arr[x][y + 1] = num;
		}
		else if (x % 2 == 0 && y % 2 == 1) // ���� �Ʒ��� �����϶�
		{
			arr[x][y - 1] = num;
			arr[x + 1][y] = num;
			arr[x + 1][y - 1] = num;
		}
		else
		{
			arr[x - 1][y - 1] = num; // ���� �Ʒ��� �����϶�
			arr[x - 1][y] = num;
			arr[x][y - 1] = num;
		}
		num++;
		return;
	}
	// ���� ���̰� 4, 8, 16�� ��
	// ������ ������ ����(�簢�� ��) �� ��и����� Ȯ���ϰ�, �� ��и��� ������ �ٸ� �� ��и鿡 ��ġ���� ������ �� �� �׷��� ���� ���� 4���� ���� ���� �� �Լ��� ��� ȣ���Ѵ�.
	if (x < (l + l + row)/2) // ������ 2,3��и� �� �ϳ��� ��.
	{
		if (y < (r + r + row) / 2) // ������ 2��и� �̶�� ������ ��и鿡 ��� ��ġ���� ����� ��.
		{
			arr[l + row / 2][r + row / 2] = num;
			arr[l + row / 2][r + row / 2 - 1] = num;
			arr[l + row / 2 - 1][r + row / 2] = num; 
			num++;
			func(arr, row / 2, l, r, x, y); // ���� 2��и鿡 �ִ� Ÿ�� ���� ���� �ݺ�
			func(arr, row / 2, l + row/2, r + row/2, l + row / 2, r + row / 2); // ���� 4��и鿡 �ִ� Ÿ�� ���� ���� �ݺ�
			func(arr, row / 2, l + row/2, r, l + row / 2, r + row / 2 - 1); // ���� 1��и� ...
			func(arr, row / 2, l, r + row / 2, l + row / 2 - 1, r + row / 2); // ���� 3��и� ...
		}
		else // 3��и��̶��
		{
			arr[l + row / 2][r + row / 2] = num;
			arr[l + row / 2][r + row / 2 - 1] = num;
			arr[l + row / 2 - 1][r + row / 2 - 1] = num;
			num++;
			func(arr, row / 2, l, r + row / 2, x, y); // ���� 3��и�
			func(arr, row / 2, l + row/2, r + row / 2, l + row / 2, r + row / 2); // ���� 4��и�
			func(arr, row / 2, l + row/2, r, l + row / 2, r + row / 2 - 1); // ���� 1��и�
			func(arr, row / 2, l, r, l + row / 2 - 1, r + row / 2 - 1); // ���� 2��и�
		}
	}
	else // 1,4��и� �� �ϳ��� ������ �ִٸ�
	{
		if (y < (r + r + row) / 2 ) // 1��и�
		{
			arr[l + row / 2][r + row / 2] = num;
			arr[l + row / 2 - 1][r + row / 2 - 1] = num;
			arr[l + row / 2 - 1][r + row / 2] = num;
			num++;
			func(arr, row / 2, l + row / 2, r, x, y); // ���� 1��и�
			func(arr, row / 2, l + row / 2, r + row/2, l + row / 2, r + row / 2); // ���� 4��и�
			func(arr, row / 2, l, r, l + row / 2 -1, r + row / 2 - 1); // ���� 2��и�
			func(arr, row / 2, l, r + row/2, l + row / 2 - 1, r + row / 2); // ���� 3��и�
		}
		else // 4��и�
		{
			arr[l + row / 2 - 1][r + row / 2] = num;
			arr[l + row / 2][r + row / 2 - 1] = num;
			arr[l + row / 2 - 1][r + row / 2 - 1] = num;
			num++;
			func(arr, row / 2, l + row/2, r + row/2, x, y); // ���� 4��и�
			func(arr, row / 2, l, r + row/2, l + row / 2 - 1, r + row / 2); // ���� 3�úи�
			func(arr, row / 2, l + row / 2, r, l + row / 2, r + row / 2 - 1); // ���� 1��и�
			func(arr, row / 2, l, r, l + row / 2 - 1, r + row / 2 - 1); // ���� 2��и�
		}
	}
}


int main()
{
	int k, x, y; // 2^k�� ����, x,y�� ����
	std::cin >> k;
	std::cin >> x >> y;

	// �ϴ� 2���� ���¸� ������.
	int row = 1;
	while (k--) // k�� ���� ����, ���� ���̸� �����ְ�,
	{
		row *= 2;
	}
	
	int** arr = (int**)calloc(16, sizeof(int*)); // 2���� �迭�� �����. ���� ���� ���̸�ŭ ������� �ߴµ� �׳� 16 x 16���� ����� ����� row��ŭ�� �ϴ� �ɷ� �մϴ�.
	for (int i = 0; i < 16; i++)
	{
		arr[i] = (int*)calloc(16, sizeof(int));
	}
	
	arr[x - 1][y - 1] = -1; // ����ִ� ���� �����.

	func(arr, row, 0, 0, x - 1, y - 1); // �Լ� ����

	for (int i = 0; i < row; i++) // �迭 ���.
	{
		for (int j = 0; j < row; j++)
		{
			std::cout << arr[j][i] << ' ';
		}
		putchar('\n');
	}

}


