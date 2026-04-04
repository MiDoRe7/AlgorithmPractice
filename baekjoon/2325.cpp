#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<pair<int, int>> graph[1001];
int d[1001];
int parent[1001];
vector<int> path;

void dijkstra(int bu, int bv) {
	fill(d, d + 1001, 1e9);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });
	d[1] = 0;

	while (!pq.empty()) {
		auto [dist, node] = pq.top();
		pq.pop();

		if (d[node] < dist) continue;

		for (auto [next_node, weight] : graph[node]) {
			if ((node == bu && next_node == bv) || (node == bv && next_node == bu)) { continue; }
			
			if (d[next_node] > dist + weight) {
				d[next_node] = dist + weight;
				if (bu == -1 && bv == -1) { //차단된 도로가 없는 시점에만 부모 기록
					parent[next_node] = node;
				}
				pq.push({ d[next_node], next_node });
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	int maxd = 0;

	for (int i = 0;i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}

	dijkstra(-1, -1);

	int cur = n;
	while (cur != 0) {
		path.push_back(cur);
		cur = parent[cur];
	}

	for (int i = 0; i < path.size() - 1; i++) {
		dijkstra(path[i], path[i + 1]);
		if (maxd < d[n]) maxd = d[n];
	}

	printf("%d\n", maxd);
}