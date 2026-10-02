// Addition and multiplication can be reduced before combining them.
// The extra % m is required because (a % m) + (b % m) can still be >= m.
// (a + b) % m = ((a % m) + (b % m)) % m
// (a * b) % m = ((a % m) * (b % m)) % m

long long a, b, m;
cin >> a >> b >> m;

long long ans = ((a % m) + (b % m)) % m;

cout << ans;

// Time complexity: O(1)
// Space complexity: O(1)