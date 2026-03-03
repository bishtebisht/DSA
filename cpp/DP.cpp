#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
    // Base cases
    if (n <= 1)
        return n;

    // Create dp array
    int dp[n + 1];

    dp[0] = 0;  // 0th Fibonacci
    dp[1] = 1;  // 1st Fibonacci

    // Build the solution bottom-up
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    cout << fibonacci(6);
}