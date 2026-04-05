#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
int n, m;
vector<vector<pair<int, long long>>> graph;
vector<long long> d;
vector<long long> p;

void Dijkstra() {
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

	d[1] = 0;
	pq.push({ 0, 1 });

	while (!pq.empty()) {
		long long dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue;

		for (auto [cost, next] : graph[now]) {
			long long ndist = dist + cost;
			if (ndist < d[next]) {
				d[next] = ndist;
				pq.push({ ndist, next });
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	graph.resize(n + 1);
	d.assign(n + 1, INF);
	p.resize(n + 1);

	for (int i = 1;i <= n;i++) {
		scanf("%lld", &p[i]);
	}

	for (int i = 0;i < m;i++) {
		int a, b;
		long long c;
		scanf("%d %d %lld", &a, &b, &c);
		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
	}

	Dijkstra();

	unsigned long long ans = 0;
	for (int i = 1;i <= n;i++) {
		if (d[i] == INF) continue;
		ans += (unsigned long long)d[i] * p[i]; //최단 거리 * 도시의 중요도
	}

	printf("%llu", ans);

	return 0;
}