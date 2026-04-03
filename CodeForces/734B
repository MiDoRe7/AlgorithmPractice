#include <cstdio>
#include <algorithm>
using namespace std;
 
int main(){
    int k2, k3, k5, k6, m, n, ans = 0;
    
    scanf("%d %d %d %d", &k2, &k3, &k5, &k6);
    
    m = min(k5, k6);
    n = min(k2, m);
    
    ans += n * 256;
    
    k2 -= n;
    n = min(k2, k3);
    
    ans += n * 32;
    
    printf("%d", ans);
    
    return 0;
}
