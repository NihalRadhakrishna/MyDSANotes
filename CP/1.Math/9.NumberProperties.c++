// 2  → last digit is even
// 3  → sum of digits divisible by 3
// 4  → last 2 digits divisible by 4
// 5  → last digit is 0 or 5
// 9  → sum of digits divisible by 9
// 10 → last digit is 0




// Finding all divisors of a number
void divisors(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";

            if (i != n / i)
                cout << n / i << " ";
        }
    }
}


// Checking if a number is a perfect square
long long x = sqrt(n);

if (x * x == n)
    cout << "Perfect square";


// Checking if a number is a power of 2
if (n > 0 && (n & (n - 1)) == 0)
    cout << "Power of 2";


    // n % 2 == 0              // even

    // n % k == 0              // divisible by k
    
    // i * i <= n              // iterate factors efficiently
    
    // n & 1                   // odd
    
    // (n & (n - 1)) == 0      // power of 2