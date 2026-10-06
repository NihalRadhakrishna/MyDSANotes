#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

// void solve() {
//     // Your solution here
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    unordered_map<string, int> mp;
    while (t--) {
        string s;
        cin >> s;
        if(mp.find(s) == mp.end()){
            mp[s] = 1;
            cout << "OK" << endl;
        }
        else{
            string ans = s + to_string(mp[s]);
            mp[s]++;
            cout << ans << endl;
        }
    }

    return 0;
}