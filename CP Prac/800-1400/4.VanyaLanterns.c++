#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(v) v.begin(), v.end()


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    cin >> n >> l;
    vector<ll> v(n);
    for(auto &i : v) cin >> i;
    sort(all(v));
    double ans = 0.0;
    if(v[0] != 0){
        ans = max(ans, (double)v[0]);
    }
    if(v[n-1] != l){
        ans = max(ans, (double)(l - v[n-1]));
    }
    for(int i = 1; i < n; i++){
        ans = max(ans, (v[i] - v[i-1])/2.0);
    }

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}