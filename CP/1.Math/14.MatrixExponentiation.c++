using Matrix = vector<vector<long long>>;

Matrix multiply(Matrix A, Matrix B) {
    Matrix C(2, vector<long long>(2));

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                C[i][j] += A[i][k] * B[k][j];

    return C;
}

Matrix power(Matrix A, long long n) {
    Matrix ans = {{1, 0}, {0, 1}}; // identity matrix

    while (n) {
        if (n & 1)
            ans = multiply(ans, A);

        A = multiply(A, A);
        n >>= 1;
    }

    return ans;
}

// For Fibonacci sequence
Matrix A = {{1, 1},
            {1, 0}};

Matrix result = power(A, n);