#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n;
    if (!(cin >> n)) return 0;
 
    vector<int> a(n);
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_sum += a[i];
    }
 
    sort(a.rbegin(), a.rend());
 
    int my_sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        my_sum += a[i];
        count++;
        if (my_sum > total_sum - my_sum) {
            break;
        }
    }
 
    cout << count << endl;
 
    return 0;
}
