#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
 
int dp[5000][3];
int L[3];
 
int main() {
	int n;
	scanf("%d %d %d %d", &n, &L[0], &L[1], &L[2]);
 
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (i - L[j] < 0) dp[i][j] = -1;
			else {
				if (max(max(dp[i - L[j]][0], dp[i - L[j]][1]), dp[i - L[j]][2]) == -1) dp[i][j] = -1;
				else dp[i][j] = max(max(dp[i - L[j]][0], dp[i - L[j]][1]), dp[i - L[j]][2]) + 1;
			}
		}
	}
 
	printf("%d", max(max(dp[n][0], dp[n][1]), dp[n][2]));
 
	return 0;
}
