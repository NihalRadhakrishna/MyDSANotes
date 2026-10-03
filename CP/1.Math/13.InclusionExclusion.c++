// Inclusion-exclusion counts a union without counting shared elements twice.
// Two sets: |A ∪ B| = |A| + |B| - |A ∩ B|
// Elements in both sets were added twice, so the intersection is removed once.


// Numbers from 1 to 20 divisible by 2 or 3.
// Multiples of 2: 10, multiples of 3: 6, multiples of both (6): 3.
// 10 + 6 - 3 = 13
int countDivisibleBy2Or3(int n) {
    return n / 2 + n / 3 - n / 6;
}

// Time complexity: O(1)
// Space complexity: O(1)


// Three sets alternate the sign: add singles, subtract pairs, add the triple.
// |A ∪ B ∪ C| = |A| + |B| + |C| - |A ∩ B| - |A ∩ C| - |B ∩ C| + |A ∩ B ∩ C|
//
// Numbers from 1 to 100 divisible by 2, 3, or 5:
// 100/2 + 100/3 + 100/5 - 100/6 - 100/10 - 100/15 + 100/30
// = 50 + 33 + 20 - 16 - 10 - 6 + 3 = 74
int countDivisibleBy2Or3Or5(int n) {
    return n / 2 + n / 3 + n / 5
         - n / 6 - n / 10 - n / 15
         + n / 30;
}

// Time complexity: O(1)
// Space complexity: O(1)


// "Divisible by x and y" means divisible by lcm(x, y).
// Count of multiples of k from 1 to n is n / k.
// For more than three values, every non-empty subset is one term.
// A subset with an odd size is added. A subset with an even size is subtracted.
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

long long countUnion(long long n, vector<long long> values) {
    int k = values.size();
    long long answer = 0;

    for (int mask = 1; mask < (1 << k); mask++) {
        long long currentLcm = 1;
        int bits = 0;

        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                bits++;

                // The count is 0 once the lcm becomes larger than n.
                if (currentLcm > n / values[i]) {
                    currentLcm = n + 1;
                    break;
                }

                currentLcm = lcm(currentLcm, values[i]);
            }
        }

        if (currentLcm > n)
            continue;

        if (bits % 2 == 1)
            answer += n / currentLcm;
        else
            answer -= n / currentLcm;
    }

    return answer;
}

// Time complexity: O(2^k * k * log(max value))
// Space complexity: O(1), excluding the input vector
