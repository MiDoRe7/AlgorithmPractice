#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
 
long long solve(long long n, long long l, long long r) {
	long long mid, leng, nn;
	if (n == 0) return 0;
	nn = n;
	leng = 1;
	while (nn > 1) {
		leng = leng * 2 + 1;
		nn /= 2;
	}
	mid = (leng + 1) / 2;
 
	if (l == 1 && r == leng) return n; //각 a의 자리수 비트가 a번 나옴
	if (r < mid) {
		return solve(n / 2, l, r);
	}
	if (l > mid) {
		return solve(n / 2, l - mid, r - mid);
	}
	if (l == mid && r == mid) return n % 2;
	if (l < mid && r == mid) return solve(n / 2, l, mid - 1) + n % 2;
	if (r > mid && l == mid) return solve(n / 2, 1, r - mid) + n % 2;
	return solve(n / 2, l, mid - 1) + solve(n / 2, 1, r - mid) + n % 2;
}
 
int main() {
	long long n, l, r;
	scanf("%lld %lld %lld", &n, &l, &r);
	printf("%lld\n", solve(n, l, r));
}
