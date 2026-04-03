#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
 
int main() {
    int n, k;
    int A[5001];
 
    if (scanf("%d %d", &n, &k) != 2) return 0;
 
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
 
    double mavg = 0.0;
 
    for (int i = 0; i <= n - k; i++) {
        int sum = 0;
 
        for (int j = i; j < i + k; j++) {
            sum += A[j];
        }
 
        double avg = (double)sum / k;
        if (avg > mavg) {
            mavg = avg;
        }
 
        for (int len = k + 1; i + len <= n; len++) {
            sum += A[i + len - 1];
            avg = (double)sum / len;
            if (avg > mavg) {
                mavg = avg;
            }
        }
    }
 
    printf("%f\n", mavg);
 
    return 0;
}
