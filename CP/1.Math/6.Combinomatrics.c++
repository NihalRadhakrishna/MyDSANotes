// nCr = product of (n - i + 1) / i for i = 1 to r.
// Dividing at every step keeps the intermediate value equal to a binomial
// coefficient, so the division is exact for integer arithmetic.
long long combination(int n, int r) {
    long long ans = 1;

    for (int i = 1; i <= r; i++) {
        ans = ans * (n - i + 1) / i;
    }

    return ans;
}

// Time complexity: O(r)
// Space complexity: O(1)