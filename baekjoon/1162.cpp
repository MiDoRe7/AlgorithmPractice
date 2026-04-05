#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
int n, m, k;
vector<pair<int, int>> graph[10005];
long long d[10005][25]; //K개를 포장했을 경우의 상태 저장

void Dijkstra() {
	for (int i = 0; i < 10005; i++) {
		fill(d[i], d[i] + 25, INF);
	}

	priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
	d[1][0] = 0;
	pq.push({ 0, 1, 0 });

	while (!pq.empty()) {
		auto [dist, now, used] = pq.top();
		pq.pop();

		if (d[now][used] < dist) continue;

		for (auto edge : graph[now]) {
			long long cost = dist + edge.first;
			int next = edge.second;

			if (cost < d[next][used]) { //도로를 포장하지 않은 경우
				d[next][used] = cost;
				pq.push({ cost, next, used });
			}

			if (used < k && dist < d[next][used + 1]) { //도로를 포장한 경우
				d[next][used + 1] = dist;
				pq.push({ dist, next, used + 1 });
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0;i < m;i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
	}

	Dijkstra();

	printf("%lld", *min_element(d[n], d[n] + k + 1));
}