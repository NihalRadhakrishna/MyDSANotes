// Sieve of Eratosthenes: mark every multiple of a prime as composite.
// Multiples below i * i were already marked by smaller primes, so marking starts at i * i.
vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}

// Time complexity: O(n log log n)
// Space complexity: O(n)