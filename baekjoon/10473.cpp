#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

Point points[105];
vector<pair<double, int>> graph[105];
double d[105];

double get_distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void Dijkstra(int start) {
	fill(d, d + 105, 1e9);
    priority_queue < pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    d[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        double dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
		if (d[now] < dist) continue;

		for (auto edge : graph[now]) {
            double cost = dist + edge.first;
            if (cost < d[edge.second]) {
                d[edge.second] = cost;
                pq.push({ cost, edge.second });
            }
        }
    }
}

int main() {
    scanf("%lf %lf", &points[0].x, &points[0].y);

    //마지막 노드에 넣기 위해 임시 저장
    Point end_point;
    scanf("%lf %lf", &end_point.x, &end_point.y);

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    points[n + 1] = end_point;

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            if (i == j) continue;

            double dist = get_distance(points[i], points[j]);
            double time = dist / 5.0; //걷기

            // 대포가 있으면 대포 탑승을 고려
            if (i >= 1 && i <= n) {
                double cannon_time = 2.0 + abs(dist - 50.0) / 5.0;
                time = min(time, cannon_time); //시간이 더 적게 걸리는 쪽을 push
            }

            graph[i].push_back({ time, j });
        }
    }

    Dijkstra(0);

    printf("%f\n", d[n + 1]);
    return 0;
}