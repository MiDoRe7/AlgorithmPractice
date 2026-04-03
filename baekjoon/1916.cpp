#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int n, m, a, b, c;
vector<pair<int, int>> graph[1001];
int d[1001];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, start });
    d[start] = 0;
    
    while (!pq.empty()) {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist) continue;
        
        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].second;
            int cost = graph[now][i].first;
            int ncost = dist + cost;

            if (ncost < d[next]) {
                d[next] = ncost;
                pq.push({ ncost, next });
            }
        }
        
    }
}

int main() {
    scanf("%d", &n);
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({c, b});
    }

    int start, end;
    scanf("%d %d", &start, &end);
    
    fill(d, d + 1001, INF);

    dijkstra(start);
    printf("%d", d[end]);
    
    return 0;
}
