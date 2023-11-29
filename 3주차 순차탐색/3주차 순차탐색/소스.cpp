#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>

int main()
{
	clock_t start, stop = 0; // 시간 계산 start, stop
	double result = 0;  // start와 stop의 차이를 넣을 result변수

	start = clock(); // 시작 시간 기록.

	FILE* fp = fopen("C:\\Users\\user\\Downloads\\1.in", "r"); // 파일을 읽어옴
	if (fp == NULL)
		return -1; // 파일을 못읽었을때 프로그램 종료

	for (int i = 0; i < 10000001; i++) // 파일의 데이터를 하나씩 fscanf로 읽으며 그 값이 내가 찾으려는 값인지 비교함.
	{
		int temp;
		fscanf(fp, "%d", &temp);
		if (temp == 6896383) // 찾으려는 값이 맞다면 반복문을 종료함.
			break;
	}
	stop = clock(); // 종료시간을 기록
	result = (double)(stop - start) / CLOCKS_PER_SEC; // 종료시간과 시작시간의 차를 계산함.
	printf("걸린 시간은 %f초 입니다.", result);

}