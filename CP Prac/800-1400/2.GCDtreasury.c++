// Codeforces 2267C - Greedy Pirate
// https://codeforces.com/contest/2267/problem/C
//
// Each steal replaces x with gcd(a[i], x). That gcd keeps a prime factor of
// the original x, so every later value of x stays divisible by one fixed prime.
// Piles that do not share that prime can never be used in the same chain.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (auto &v : a) cin >> v;

        // Distinct prime factors of x. Powers are divided out so each prime
        // is stored once.
        vector<int> primes;
        int y = x;
        for (int p = 2; 1LL * p * p <= y; p++) {
            if (y % p == 0) {
                primes.push_back(p);
                while (y % p == 0) y /= p;
            }
        }
        if (y > 1) primes.push_back(y);

        // For a prime p, every pile divisible by p can be emptied completely:
        // both the pile and x stay divisible by p after each steal.
        // The answer is the best such group of piles.
        long long ans = 0;
        for (int p : primes) {
            long long sum = 0;
            for (int v : a)
                if (v % p == 0) sum += v;
            ans = max(ans, sum);
        }

        cout << ans << '\n';
    }
    return 0;
}

// Time complexity: O(sqrt(x) + n * d) per test, where d is the number of
// distinct prime factors of x
// Space complexity: O(n)