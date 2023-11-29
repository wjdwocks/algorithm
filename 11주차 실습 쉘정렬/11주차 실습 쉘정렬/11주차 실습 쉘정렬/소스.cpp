#include <iostream>

void shell_sort(int* arr, int n)
{
    // gap을 전체크기의 반으로 설정하고 이를 줄이며 1까지로 줄어들게 함.
    for (int gap = n / 2; gap > 0; gap /= 2) // 1 4 5 2 3에서는 gap = 2로 시작 -> 1
    {
        // 삽입 정렬
        for (int i = gap; i < n; ++i) // 2 3 4
        {
            int temp = arr[i]; 
            int j;
            for (j = i; j >= gap; j -= gap) //  2 -> 0의 부분배열 비교, 3 -> 1의 부분배열 비교, 4 -> 2 -> 0의 부분배열 비교.
            {
                if (arr[j - gap] > temp) // 크기가 앞에게 더 크다면 
                    arr[j] = arr[j - gap]; // 뒤의 요소에다가 앞에거를 넣고. --> for문이 종료된 후 작아진 j에다가 temp를 넣음.
                else
                    break; // 이미 다음 수가 정렬이 되어있는 경우. --> j = i인 상태에서 밑의 코드에서 i위치에다가 temp를 넣음.
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
