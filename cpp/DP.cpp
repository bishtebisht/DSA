#include<bits/stdc++.h>
using namespace std;

// int fibonacci(int n) {
//     // Base cases
//     if (n <= 1)
//         return n;

//     // Create dp array
//     int dp[n + 1];

//     dp[0] = 0;  // 0th Fibonacci
//     dp[1] = 1;  // 1st Fibonacci

//     // Build the solution bottom-up
//     for (int i = 2; i <= n; i++) {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }

//     return dp[n];
// }

// int main() {
//     cout << fibonacci(6);
// }


// int numSpecial(vector<vector<int>>& mat) {
//     int m = mat.size();       // number of rows
//     int n = mat[0].size();    // number of columns

//     vector<int> rowCount(m, 0);
//     vector<int> colCount(n, 0);

//     // Step 1: Count 1s in each row and column
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if (mat[i][j] == 1) {
//                 rowCount[i]++;
//                 colCount[j]++;
//             }
//         }
//     }

//     int specialCount = 0;

//     // Step 2: Check special positions
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if (mat[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1) {
//                 specialCount++;
//             }
//         }
//     }

//     return specialCount;
// }

// int main() {
//     vector<vector<int>> mat = {
//         {1,0,0},
//         {0,0,1},
//         {1,0,0}
//     };

//     cout << numSpecial(mat);
// }


// int minOperations(string s) {
//     int n = s.size();

//     int startWith0 = 0; // mismatches if pattern starts with '0'
//     int startWith1 = 0; // mismatches if pattern starts with '1'

//     for (int i = 0; i < n; i++) {

//         // Expected characters for alternating patterns
//         char expected0 = (i % 2 == 0) ? '0' : '1'; // pattern: 010101...
//         char expected1 = (i % 2 == 0) ? '1' : '0'; // pattern: 101010...

//         // Count mismatches
//         if (s[i] != expected0)
//             startWith0++;

//         if (s[i] != expected1)
//             startWith1++;
//     }

//     // Return minimum operations required
//     return min(startWith0, startWith1);
// }

// int main() {
//     string s;

//     cout << "Enter binary string: ";
//     cin >> s;

//     int result = minOperations(s);

//     cout << "Minimum operations needed: " << result << endl;

//     return 0;
// }


bool checkOnesSegment(string s) {
    bool seenZero = false;

    for (char c : s) {
        if (c == '0') {
            seenZero = true;
        }
        // If we see '1' after a '0', it means a new segment started
        else if (seenZero && c == '1') {
            return false;
        }
    }

    return true;
}

int main() {
    string s;
    cin >> s;

    if (checkOnesSegment(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}