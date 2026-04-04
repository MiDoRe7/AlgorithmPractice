#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> graph[50001];
int d[50001];

void Dijkstra(int start) {
	fill(d, d + 50001, 2e7); //Overflow 방지
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue;

		for (pair<int, int> i : graph[now]) {
			int cost = dist + i.first;
			if (cost < d[i.second]) {
				d[i.second] = cost;
				pq.push({ cost, i.second });
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0;i < m;i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
	}
	int v1, v2;
	scanf("%d %d", &v1, &v2);

	int ans1 = 0, ans2 = 0;

	Dijkstra(1);
	int o_to_v1 = d[v1];
	int o_to_v2 = d[v2];

	// v1 노드에서 출발하는 경우의 최단 거리
	Dijkstra(v1);
	int v1_to_v2 = d[v2];
	int v1_to_n = d[n];

	// v2 노드에서 출발하는 경우의 최단 거리
	Dijkstra(v2);
	int v2_to_n = d[n];

	// 두 가지 경로의 총합
	ans1 = o_to_v1 + v1_to_v2 + v2_to_n;
	ans2 = o_to_v2 + v1_to_v2 + v1_to_n;

	int ans = min(ans1, ans2);

	if (ans >= 2e7) {
		printf("-1\n");
	}
	else {
		printf("%d\n",ans);
	}
	return 0;
}