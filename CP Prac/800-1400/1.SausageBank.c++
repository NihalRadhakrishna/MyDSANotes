#include <bits/stdc++.h>
using namespace std;


long long power(long long base, long long exp) {
    long long ans = 1;
    while(exp > 0) {
        if(exp & 1) {
            ans *= base;
        }
        base *= base;
        exp >>= 1;
    }
    
    return ans;
}

long long solve(int n, int k) {
    long long ans = 0;
    ans += 2*(k-1);
    ans += power(2, n-k+1);
    return ans;
}

int main() {
    int c;
    cin >> c;
    for(int i = 0; i < n; i++) {
        int n, k;
        cin >> n >> k;
        long long output = solve(n, k);
        cout << output << endl;
    }
}