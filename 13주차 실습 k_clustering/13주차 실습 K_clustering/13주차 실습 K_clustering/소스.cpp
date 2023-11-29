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
	int N, M; // 사람 N, 경찰 M
	std::cin >> N >> M;
	std::vector<std::pair<int, int>> v; // pair형식으로 좌표들을 x,y로 받음.
	int x, y;

	for (int i = 0; i < N; i++) // 사람들 위치 입력받기.
	{
		std::cin >> x >> y;
		v.emplace_back(std::pair<int, int>(x, y));
	}

	// 첫번째 경찰 : v[0].first, v[0].second의 위치에 있음.

	// 경찰로 결정된 사람들은 vector에서 제거해버리고, 남은 사람들 사이의 거리를 통해서 다음 경찰을 결정한다?
	// 경찰들을 넣어놓는 리스트를 따로 만들자.
	std::vector<std::pair<int, int>> police;
	police.emplace_back(v[0]);
	v.erase(v.begin()); // 첫번째 경찰 없애기.

	// 다음 경찰을 찾기. 
	std::vector<std::pair<int, int>>::iterator itr = v.begin(); // 다음 경찰의 위치를 받아올 변수.
	double min = 2147483647;

	std::vector<std::pair<double, std::vector<std::pair<int, int>>::iterator>> position; // 거리의 최소와 그떄의 위치를 가져올 벡터.	
	for (int k = 1; k < M; k++) // 매 반복당 경찰이 하나씩 늘어남.
	{
		for (int i = 0; i < v.size(); i++) // 사람들 vector를 돌면서 가장 먼 거리의 사람들을 찾음.
		{
			for (int p = 0; p < police.size(); p++ ) // 지금까지 들어있는 경찰들에 대해서 반복.
			{
				// 한 점에 대해서 모든 경찰들에 대한 거리의 최솟값과, 그 점의 iterator를 저장함.
				double dist = get_distance(police[p], v[i]); // 특점 점과 경찰 사이의 거리
				if (dist < min) 
				{
					min = dist;
					itr = v.begin() + i;
				}
			} // for문이 끝나면 특점 점에 각 경찰들 까지의 거리 중 최소인 점의 위치가 itr에 저장됨.
			position.emplace_back(min, itr);
			min = 2147483647;
			itr = v.begin();
		}
		std::sort(position.rbegin(), position.rend()); // 큰순으로 정렬
		police.emplace_back(v[position[0].second - v.begin()]); // 제일 큰 점을 police에 넣고
		v.erase(position[0].second); // 그걸 사람들에서 지움.
		position.clear(); // position벡터를 초기화함.
	}

	for (auto i : police)
	{
		std::cout << i.first << ' ' << i.second << '\n';
	}
}