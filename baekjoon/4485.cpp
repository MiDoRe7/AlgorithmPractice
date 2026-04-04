#include <bits/stdc++.h>
using namespace std;

int n;
int board[125][125];
int d[125][125];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void Dijkstra() {
	fill(&d[0][0], &d[0][0] + 125 * 125, 1e9);
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

	pq.push({ board[0][0], 0, 0 });
	d[0][0] = board[0][0];

	while (!pq.empty()) {
		auto [dist, x, y] = pq.top();
		pq.pop();

		if (d[x][y] < dist) continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

			int cost = dist + board[nx][ny];

			if (cost < d[nx][ny]) {
				d[nx][ny] = cost;
				pq.push({ cost, nx, ny });
			}
		}
	}
}

int main() {
	int tc = 1;

	while (true) {
		scanf("%d", &n);

		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &board[i][j]);
			}
		}

		Dijkstra();

		printf("Problem %d: %d\n", tc++, d[n - 1][n - 1]);
	}

	return 0;
}