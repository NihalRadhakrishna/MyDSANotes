#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'


ll solve(ll mn, ll mx, ll k, vector<vector<ll>>&v){
    ll count;
    ll ans = LONG_LONG_MIN;
    while(mn <= mx){
        count = 0;
        
        ll mid = (mx+mn)/2;
        for(int i = 0; i<v.size(); i++){
            ll cur_sum = v[i][0] + v[i][1] + v[i][2];
            if((v[i][0] == v[i][1]) && (v[i][0] == v[i][2])){
                if(cur_sum < mid){
                    count = k+1;
                    break;
                }
                else{
                    continue;
                }
            } 
            if(cur_sum < mid){
                ll a = v[i][1] - v[i][2];
                ll b = v[i][0] - v[i][2];
                ll c = v[i][0] - v[i][1];
                ll max_diff = max({a, b, c});
                if(max_diff > 0){
                    count += mid - cur_sum;
                }
                else{
                    cur_sum = cur_sum - abs(max_diff) - 1;
                    count += abs(max_diff) + 1 + (mid-cur_sum);
                }
            }
            if(count > k) break;
        }
        if(count <= k){
            mn = mid+1;
            ans = max(ans, mid);
        }
        else{
            mx = mid-1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll cur_sum = 0;
        ll mn = LONG_LONG_MAX;
        vector<vector<ll>> v(n, vector<ll>(3));
        for(int i = 0; i<n; i++){
            cin >> v[i][0] >> v[i][1] >> v[i][2];
            cur_sum = v[i][0] + v[i][1] + v[i][2];
            mn = min(cur_sum, mn);
        }
        ll mx = mn + k;
        ll ans = solve(mn, mx, k, v);
        cout << ans << endl;
        
    }

    return 0;
}