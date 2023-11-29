#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>

int main()
{
	clock_t start, stop = 0; // �ð� ��� start, stop
	double result = 0;  // start�� stop�� ���̸� ���� result����

	start = clock(); // ���� �ð� ���.

	FILE* fp = fopen("C:\\Users\\user\\Downloads\\1.in", "r"); // ������ �о��
	if (fp == NULL)
		return -1; // ������ ���о����� ���α׷� ����

	for (int i = 0; i < 10000001; i++) // ������ �����͸� �ϳ��� fscanf�� ������ �� ���� ���� ã������ ������ ����.
	{
		int temp;
		fscanf(fp, "%d", &temp);
		if (temp == 6896383) // ã������ ���� �´ٸ� �ݺ����� ������.
			break;
	}
	stop = clock(); // ����ð��� ���
	result = (double)(stop - start) / CLOCKS_PER_SEC; // ����ð��� ���۽ð��� ���� �����.
	printf("�ɸ� �ð��� %f�� �Դϴ�.", result);

}