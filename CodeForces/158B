#include <cstdio>
#include <algorithm>
using namespace std;
 
int main() {
    int n, group_size;
    int S[5] = {0};
    int ans = 0;
 
    if (scanf("%d", &n) != 1) return 0;
 
    for (int i = 0; i < n; i++) {
        scanf("%d", &group_size);
        S[group_size]++;
    }
 
    ans += S[4];
 
    ans += S[3];
    S[1] = max(0, S[1] - S[3]);
 
    ans += S[2] / 2;
    if (S[2] % 2 != 0) {
        ans++;
        S[1] = max(0, S[1] - 2);
    }
 
    ans += (S[1] + 3) / 4;
 
    printf("%d\n", ans);
    return 0;
}
