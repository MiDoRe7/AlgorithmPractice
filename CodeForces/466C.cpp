#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
 
int main() {
    long long n;
    long long sum = 0, ans = 0, sum3;
    long long A[500005], P[500005];
    
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++) {
        scanf("%lld", &A[i]);
        sum += A[i];
    }
    
    if (sum % 3 != 0) printf("0");
    else {
        long long s = 0, j = 0;
        sum3 = (long long)(sum/3);
        for (long long i = 1; i < n; i++) {
            s += A[i];
            if (s == sum3) j++;
            P[i] = j;
            if (s == sum3 * 2 && i >= 2) ans += P[i - 1];
        }
        printf("%lld", ans);
    }
    return 0;
}
