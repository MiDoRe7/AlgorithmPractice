#include <stdio.h>
 
void solve() {
    int n;
    long long a[100005];
    scanf("%d", &n);
    
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        total_sum += a[i];
    }
 
    // 조건 1: 앞에서부터 부분합을 구하며 total_sum과 비교 (마지막 원소 제외)
    long long current_sum = 0;
    for (int i = 0; i < n - 1; i++) {
        current_sum += a[i];
        if (current_sum >= total_sum) {
            printf("NO\n");
            return;
        }
        if (current_sum <= 0) current_sum = 0;
    }
 
    // 조건 2: 뒤에서부터 부분합을 구하며 total_sum과 비교 (첫 번째 원소 제외)
    current_sum = 0;
    for (int i = n - 1; i > 0; i--) {
        current_sum += a[i];
        if (current_sum >= total_sum) {
            printf("NO\n");
            return;
        }
        if (current_sum <= 0) current_sum = 0;
    }
 
    printf("YES\n");
}
 
int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
