#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> graph[50001];
int d[50001];

void Dijkstra() {
	fill(d, d + 50001, 1e9);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });
	d[1] = 0;

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

	Dijkstra();

	printf("%d\n", d[n]);

	return 0;
}