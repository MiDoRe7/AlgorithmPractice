#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
 
int solve(int s, int* x) {
	if (s == 0) return 0;
 
	int m = x[0];
	for (int i = 1; i < s; i++) {
		if (x[i] < m) m = x[i];
	}
	for (int i = 0; i < s; i++) {
		x[i] -= m;
	}
	int ans = m;
	int p = 0;
	for (int i = 0; i <= s; i++) {
		if (i == s || x[i] == 0) {
			if (i > p) {
				ans += solve(i - p, x + p);
			}
			p = i + 1;
		}
	}
 
	return min(ans, s);
}
 
int main() {
	int n;
	int a[5005];
 
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
 
	printf("%d", solve(n, a));
}
