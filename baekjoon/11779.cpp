#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
vector<pair<int, int>> graph[1001];
int d[1001];
int parent[1001];
vector<int> path;

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, a});
	d[a] = 0;
	while (!pq.empty()) {
		auto [dist, node] = pq.top();
		pq.pop();
		if (d[node] < dist) continue;
		for (auto [next_node, weight] : graph[node]) {
			if (d[next_node] > dist + weight) {
				d[next_node] = dist + weight;
				parent[next_node] = node;
				pq.push({d[next_node], next_node});
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 0;i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back({v, w});
	}

	scanf("%d %d", &a, &b);

	fill(d, d + 1001, 1e9);

	dijkstra();

	printf("%d\n", d[b]);
	int cur = b;
	while (cur != 0) {
		path.push_back(cur);
		cur = parent[cur];
	}
	printf("%d\n", path.size());
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d ", path[i]);
	}
}