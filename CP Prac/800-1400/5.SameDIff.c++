#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'


ll nCr(int n, int r){
    r = min(r, n-r);
    ll res = 1;
    for(int i = 1; i<=r; i++){
        res = res * (n-i+1)/i;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(auto &i : v) cin >> i;
        unordered_map<int, int> mp;
        for(int i = 0; i<n; i++){
            mp[v[i] - i]++;
        }
        ll ans = 0;
        for(auto &i : mp){
            if(i.second > 1){
                ans += nCr(i.second, 2);
            }
        }
        cout << ans << endl;
    }

    return 0;
}