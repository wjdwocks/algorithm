#include <iostream>

void shell_sort(int* arr, int n)
{
    // gap�� ��üũ���� ������ �����ϰ� �̸� ���̸� 1������ �پ��� ��.
    for (int gap = n / 2; gap > 0; gap /= 2) // 1 4 5 2 3������ gap = 2�� ���� -> 1
    {
        // ���� ����
        for (int i = gap; i < n; ++i) // 2 3 4
        {
            int temp = arr[i]; 
            int j;
            for (j = i; j >= gap; j -= gap) //  2 -> 0�� �κй迭 ��, 3 -> 1�� �κй迭 ��, 4 -> 2 -> 0�� �κй迭 ��.
            {
                if (arr[j - gap] > temp) // ũ�Ⱑ �տ��� �� ũ�ٸ� 
                    arr[j] = arr[j - gap]; // ���� ��ҿ��ٰ� �տ��Ÿ� �ְ�. --> for���� ����� �� �۾��� j���ٰ� temp�� ����.
                else
                    break; // �̹� ���� ���� ������ �Ǿ��ִ� ���. --> j = i�� ���¿��� ���� �ڵ忡�� i��ġ���ٰ� temp�� ����.
            }

            arr[j] = temp;
        }
    }
}

int main() 
{
    int n, temp;
    std::cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        arr[i] = temp;
    }

    shell_sort(arr, n);

    for (int i = 0; i < n; i++)
        std::cout << arr[i] << '\n';

    return 0;
}
