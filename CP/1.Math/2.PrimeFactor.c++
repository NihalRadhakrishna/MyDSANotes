// Count distinct prime factors by trial division.
// Once a factor i is found, divide it out completely so it is counted once.
// Any value left above 1 is itself a prime factor larger than sqrt of the original n.
int countDistinctPrimeFactors(int n) {
    int cnt = 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;

            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 1)
        cnt++;

    return cnt;
}

// Time complexity: O(sqrt(n))
// Space complexity: O(1)