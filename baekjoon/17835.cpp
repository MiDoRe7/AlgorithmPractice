#include <bits/stdc++.h>
using namespace std;
#define INF 1e18

int n, m, k;
vector<pair<long long, int>> graph[100005];
long long d[100005];
vector<int> cities;

void Dijkstra(const vector<int>& starts) {
	fill(d, d + 100005, INF);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	for (int start : starts) {
        d[start] = 0;
		pq.push({ 0, start });
    }
    while (!pq.empty()) {
        long long dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (d[now] < dist) continue;

        for(auto[cost, next] : graph[now]) {
            long long ndist = dist + cost;
            if (ndist < d[next]) {
                d[next] = ndist;
                pq.push({ ndist, next });
            }
		}
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < m; i++) {
        int u, v;
        long long c;
        scanf("%d %d %lld", &u, &v, &c);
        graph[v].push_back({ c, u });
    }

    for (int i = 0; i < k; i++) {
        int city;
        scanf("%d", &city);
        cities.push_back(city);
    }

    Dijkstra(cities);

    int ans = 0;
    long long mdist = -1;

    for (int i = 1; i <= n; i++) {
        if (mdist < d[i]) {
            mdist = d[i];
            ans = i;
        }
    }

	printf("%d\n%lld", ans, mdist);

    return 0;
}