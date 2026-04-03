#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
 
int a[101];
int b[101];
int dp[101];
 
int main() {
	int n, s = 0, md = -1000000;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		s += a[i];
		b[i] = a[i] == 1 ? -1 : 1;
	}
 
	dp[0] = b[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + b[i], b[i]);
	}
	for (int i = 0; i < n; i++) {
		md = max(md, dp[i]);
	}
	printf("%d", s + md);
 
	return 0;
}
