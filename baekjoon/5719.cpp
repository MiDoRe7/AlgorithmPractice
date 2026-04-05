#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int n, m, s, d;

vector<pair<int, int>> graph[505];
vector<pair<int, int>> back[505];

bool deleted[505][505];

int dists[505];

void Dijkstra(int start) {
	fill(dists, dists + 505, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dists[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dists[now] < dist) continue;
		for (auto[cost, next] : graph[now]) {
			if (deleted[now][next]) continue; //삭제된 간선은 무시
			int ndist = dist + cost;
			if (ndist < dists[next]) {
				dists[next] = ndist;
				pq.push({ ndist, next });
			}
		}
	}
}

void BFS(int start, int end) {
	queue<int> q;
	bool visited[505] = { false };
	q.push(end);
	visited[end] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == start) continue; //시작점에 도달하면 종료
		for (auto[cost, prev] : back[now]) {
			if (dists[now] == dists[prev] + cost) { //최단 경로에 포함된 간선
				deleted[prev][now] = true; //간선 삭제
				if (!visited[prev]) {
					q.push(prev);
					visited[prev] = true;
				}
			}
		}
	}
}

int main() {
	while (true) {
		scanf("%d %d", &n, &m);

		if (n == 0 && m == 0) break;

		scanf("%d %d", &s, &d);

		for (int i = 0; i < n; i++) {
			graph[i].clear();
			back[i].clear();
			for (int j = 0; j < n; j++) {
				deleted[i][j] = false;
			}
		}

		for (int i = 0; i < m; i++) {
			int u, v, p;
			scanf("%d %d %d", &u, &v, &p);
			graph[u].push_back({ p, v });
			back[v].push_back({ p, u });
		}

		Dijkstra(s); //최단 경로 계산
		BFS(s, d); //간선 삭제
		Dijkstra(s); //다시 최단 경로 계산

		if (dists[d] == INF) printf("-1\n");
		else printf("%d\n", dists[d]);
	}

	return 0;
}