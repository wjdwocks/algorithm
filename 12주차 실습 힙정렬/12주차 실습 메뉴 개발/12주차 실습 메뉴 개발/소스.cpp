#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

int arr[200] = { 0, };
int sortedarr[200] = { 0, };

bool compare(int a, int b)
{
	return a > b;
}

void downheap(int* arr)
{
	int cursor = 1; // ó������ root�� ����Ŵ.
	while (arr[2 * cursor] != 0 || arr[2 * cursor + 1] != 0) // �� �ڽ��� 0�̶�� (���������) ����.
	{
		if (arr[2 * cursor] > arr[2 * cursor + 1] && arr[2 * cursor] > arr[cursor]) // �����ڽ��� ū ���.
		{
			std::swap(arr[2 * cursor], arr[cursor]); // �θ�� �����ڽ� ��ü.
			cursor = 2 * cursor; // Ŀ���� �����ڽ����� ����.
		}
		else if (arr[2 * cursor + 1] > arr[2 * cursor] && arr[2 * cursor + 1] > arr[cursor]) // �������ڽ��� ū ���.
		{
			std::swap(arr[2 * cursor + 1], arr[cursor]);
			cursor = 2 * cursor + 1;
		}
		else
			break;
	}
}

void heapsort(int* arr, int limit)
{
	int last = limit; // ������ �ε���
	for (int i = 1; i <= limit; i++) // 15�� �ݺ�
	{
		sortedarr[i] = arr[1]; // root�� ���ο� �迭�� �ְ�.
		std::swap(arr[1], arr[last]); // root�� ������ ���Ҹ� �ٲ�.
		arr[last--] = 0; // ������ ���Ҹ� ����.
		downheap(arr); // downheap�� �����Ͽ� �ٽ� ���� ���·� �ٲ�.
	}
}

int main()
{
	int M, datanum = 0; // M�� �ּ� ����, datanum�� ��� ����

	std::string str; // ù��° �Է¹��� ���ڿ�
	std::getline(std::cin, str);
	
	std::stringstream ss(str); // ���ڿ��� ���ڷ� �ٲٱ�.

	int i = 1;
	while (ss >> arr[i++])
	{
		datanum++;
	}


	std::cin >> M; 

	heapsort(arr, datanum); // ������ ����.

	std::reverse(sortedarr+1, sortedarr + datanum+1); // ū�����ͷ� ���ĵǼ� ��������.
	int limit = datanum; // ���ĵ� �迭�� �ִ� ������ ������ �����ϴ� ����
	int cnt = 0; // ��� ���⸦ �߳� 
	while (sortedarr[1] < M) // ���� ���� ����� 8000���� ������ ����.
	{
		limit--; // ���� ���̰�,
		int temp1 = sortedarr[1], temp2 = sortedarr[2], merge = temp1 + temp2*2; // ���� �޴���
		sortedarr[1] = 0, sortedarr[2] = merge; // �޴��� �߰�.
		std::sort(sortedarr, std::end(sortedarr), compare); // �������������� �ϰ�(���� �޴��� 0���� �߱� ������)
		std::reverse(sortedarr, sortedarr + limit + 1); // ������.
		cnt++;
	}


	std::cout << cnt;
}