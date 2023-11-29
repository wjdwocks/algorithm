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
	int cursor = 1; // 처음에는 root를 가리킴.
	while (arr[2 * cursor] != 0 || arr[2 * cursor + 1] != 0) // 두 자식이 0이라면 (리프노드라면) 종료.
	{
		if (arr[2 * cursor] > arr[2 * cursor + 1] && arr[2 * cursor] > arr[cursor]) // 왼쪽자식이 큰 경우.
		{
			std::swap(arr[2 * cursor], arr[cursor]); // 부모와 왼쪽자식 교체.
			cursor = 2 * cursor; // 커서를 왼쪽자식으로 보냄.
		}
		else if (arr[2 * cursor + 1] > arr[2 * cursor] && arr[2 * cursor + 1] > arr[cursor]) // 오른쪽자식이 큰 경우.
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
	int last = limit; // 마지막 인덱스
	for (int i = 1; i <= limit; i++) // 15번 반복
	{
		sortedarr[i] = arr[1]; // root를 새로운 배열에 넣고.
		std::swap(arr[1], arr[last]); // root와 마지막 원소를 바꿈.
		arr[last--] = 0; // 마지막 원소를 없앰.
		downheap(arr); // downheap을 수행하여 다시 힙의 형태로 바꿈.
	}
}

int main()
{
	int M, datanum = 0; // M은 최소 가격, datanum은 재료 개수

	std::string str; // 첫번째 입력받을 문자열
	std::getline(std::cin, str);
	
	std::stringstream ss(str); // 문자열을 숫자로 바꾸기.

	int i = 1;
	while (ss >> arr[i++])
	{
		datanum++;
	}


	std::cin >> M; 

	heapsort(arr, datanum); // 힙정렬 수행.

	std::reverse(sortedarr+1, sortedarr + datanum+1); // 큰수부터로 정렬되서 뒤집어줌.
	int limit = datanum; // 정렬된 배열에 있는 원소의 개수를 추적하는 변수
	int cnt = 0; // 몇번 섞기를 했나 
	while (sortedarr[1] < M) // 제일 작은 비용이 8000원이 넘으면 종료.
	{
		limit--; // 갯수 줄이고,
		int temp1 = sortedarr[1], temp2 = sortedarr[2], merge = temp1 + temp2*2; // 섞은 메뉴를
		sortedarr[1] = 0, sortedarr[2] = merge; // 메뉴를 추가.
		std::sort(sortedarr, std::end(sortedarr), compare); // 내림차순정렬을 하고(없는 메뉴를 0으로 했기 때문에)
		std::reverse(sortedarr, sortedarr + limit + 1); // 뒤집기.
		cnt++;
	}


	std::cout << cnt;
}