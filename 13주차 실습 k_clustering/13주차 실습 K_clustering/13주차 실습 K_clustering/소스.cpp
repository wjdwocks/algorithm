#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>


double get_distance(const std::pair<int, int>& p1, const std::pair<int, int>& p2)
{
	return sqrt(pow((p1.first - p2.first), 2) + pow((p1.second - p2.second), 2));
}


int main()
{
	int N, M; // ��� N, ���� M
	std::cin >> N >> M;
	std::vector<std::pair<int, int>> v; // pair�������� ��ǥ���� x,y�� ����.
	int x, y;

	for (int i = 0; i < N; i++) // ����� ��ġ �Է¹ޱ�.
	{
		std::cin >> x >> y;
		v.emplace_back(std::pair<int, int>(x, y));
	}

	// ù��° ���� : v[0].first, v[0].second�� ��ġ�� ����.

	// ������ ������ ������� vector���� �����ع�����, ���� ����� ������ �Ÿ��� ���ؼ� ���� ������ �����Ѵ�?
	// �������� �־���� ����Ʈ�� ���� ������.
	std::vector<std::pair<int, int>> police;
	police.emplace_back(v[0]);
	v.erase(v.begin()); // ù��° ���� ���ֱ�.

	// ���� ������ ã��. 
	std::vector<std::pair<int, int>>::iterator itr = v.begin(); // ���� ������ ��ġ�� �޾ƿ� ����.
	double min = 2147483647;

	std::vector<std::pair<double, std::vector<std::pair<int, int>>::iterator>> position; // �Ÿ��� �ּҿ� �׋��� ��ġ�� ������ ����.	
	for (int k = 1; k < M; k++) // �� �ݺ��� ������ �ϳ��� �þ.
	{
		for (int i = 0; i < v.size(); i++) // ����� vector�� ���鼭 ���� �� �Ÿ��� ������� ã��.
		{
			for (int p = 0; p < police.size(); p++ ) // ���ݱ��� ����ִ� �����鿡 ���ؼ� �ݺ�.
			{
				// �� ���� ���ؼ� ��� �����鿡 ���� �Ÿ��� �ּڰ���, �� ���� iterator�� ������.
				double dist = get_distance(police[p], v[i]); // Ư�� ���� ���� ������ �Ÿ�
				if (dist < min) 
				{
					min = dist;
					itr = v.begin() + i;
				}
			} // for���� ������ Ư�� ���� �� ������ ������ �Ÿ� �� �ּ��� ���� ��ġ�� itr�� �����.
			position.emplace_back(min, itr);
			min = 2147483647;
			itr = v.begin();
		}
		std::sort(position.rbegin(), position.rend()); // ū������ ����
		police.emplace_back(v[position[0].second - v.begin()]); // ���� ū ���� police�� �ְ�
		v.erase(position[0].second); // �װ� ����鿡�� ����.
		position.clear(); // position���͸� �ʱ�ȭ��.
	}

	for (auto i : police)
	{
		std::cout << i.first << ' ' << i.second << '\n';
	}
}