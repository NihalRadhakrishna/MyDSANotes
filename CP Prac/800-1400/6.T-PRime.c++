#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(1e6+1, 1);
    v[0] = v[1] = 0;
    for(int i = 2; i*i<=1e6; i++){
        if(v[i] == 1){
            for(int j = i*i; j<=1e6; j+=i){
                v[j] = 0;
            }
        }
    }
    for(int i = 0; i<n; i++){
        ll x;
        cin >> x;
        ll sq = sqrt(x);
        if(sq*sq == x && v[sq] == 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}