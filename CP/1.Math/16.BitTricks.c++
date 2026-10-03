// Bit positions are counted from the right, starting at 0.
// 10 is 1010 in binary, so bit 1 (value 2) and bit 3 (value 8) are set.
// Use 1LL << k. A plain 1 << k overflows once k is 31 or more.


// Check whether bit k is 1.
bool isBitSet(long long n, int k) {
    return n & (1LL << k);
}

// Turn bit k on. A bit that is already 1 stays 1.
long long setBit(long long n, int k) {
    return n | (1LL << k);
}

// Turn bit k off.
long long clearBit(long long n, int k) {
    return n & ~(1LL << k);
}

// Flip bit k: 0 becomes 1, and 1 becomes 0.
long long toggleBit(long long n, int k) {
    return n ^ (1LL << k);
}

// Time complexity: O(1)
// Space complexity: O(1)


// n & (n - 1) clears the lowest 1.
// 12 is 1100 and 11 is 1011, so 1100 & 1011 = 1000, which is 8.
long long removeLowestSetBit(long long n) {
    return n & (n - 1);
}

// Each step removes one set bit, so the loop runs once per set bit.
int countSetBits(long long n) {
    int count = 0;

    while (n > 0) {
        n &= n - 1;
        count++;
    }

    return count;
}

// Time complexity: O(number of set bits)
// Space complexity: O(1)


// n & -n keeps only the lowest 1. This uses two's complement.
// 12 is 1100, and 12 & -12 = 0100, which is 4.
long long lowestSetBit(long long n) {
    return n & -n;
}

// Time complexity: O(1)
// Space complexity: O(1)


// Every integer from 0 to 2^n - 1 is one subset.
// Bit i of the mask says whether arr[i] is included.
// For [1, 2, 3]:
// 000 -> {}
// 001 -> {1}
// 010 -> {2}
// 011 -> {1, 2}
// 100 -> {3}
vector<long long> allSubsetSums(vector<int>& arr) {
    int n = arr.size();
    vector<long long> sums;

    for (int mask = 0; mask < (1 << n); mask++) {
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))
                sum += arr[i];
        }

        sums.push_back(sum);
    }

    return sums;
}

// Time complexity: O(n * 2^n)
// Space complexity: O(2^n) for the returned sums
