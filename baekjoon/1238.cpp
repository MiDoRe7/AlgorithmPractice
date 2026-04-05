#include <bits/stdc++.h>
using namespace std;

int n, m, x;
int ans[1001];
vector<pair<int, int>> graph[1001];
vector<pair<int, int>> back[1001];
int d[1001];

void Dijkstra(int start, vector<pair<int, int>>(&g)[1001]) {
	fill(d, d + 1001, 2e7);
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue;

		for(auto[cost, next] : g[now]) {
			int ndist = dist + cost;
			if (ndist < d[next]) {
				d[next] = ndist;
				pq.push({ ndist, next });
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &x);
	for (int i = 0;i < m;i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ c, b });
		back[b].push_back({ c, a });
	}
	
	Dijkstra(x, graph);
	for (int i = 1;i <= n;i++) ans[i] += d[i];
	Dijkstra(x, back);
	for (int i = 1;i <= n;i++) ans[i] += d[i];
	
	int maxans = ans[1];
	for (int i = 1;i <= n;i++) maxans = max(maxans, ans[i]);

	printf("%d", maxans);
	return 0;
}