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

//     return specialCount; //3
// }

// int main() {
//     vector<vector<int>> mat = {
//         {1,0,0},
//         {0,0,1},
//         {0,1,0}
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


// bool checkOnesSegment(string s) {
//     bool seenZero = false;

//     for (char c : s) {
//         if (c == '0') {
//             seenZero = true;
//         }
//         // If we see '1' after a '0', it means a new segment started
//         else if (seenZero && c == '1') {
//             return false;
//         }
//     }

//     return true;
// }

// int main() {
//     string s;
//     cin >> s;

//     if (checkOnesSegment(s))
//         cout << "true";
//     else
//         cout << "false";

//     return 0;
// }


//without dp
// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     int pre1=points[0][0],  pre2=points[0][1],  pre3=points[0][2];
//     int cur1,  cur2,  cur3;
//     for(int i=1; i<n; i++){
//        cur1=points[i][0]+max(pre2,pre3);
//        cur2=points[i][1]+max(pre3,pre1);
//        cur3=points[i][2]+max(pre1,pre2);
//        cout<<cur1<<" "<<cur2<<" "<<cur3<<endl;
//        pre1=cur1;
//        pre2=cur2;
//         pre3=cur3;
//     }
//     return max(pre1,max(pre2,pre3));
// }
// int main() {
//     int n;
//     cin >> n;
//     vector<vector<int>> points(n, vector<int>(3));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < 3; j++) {
//             cin >> points[i][j];
//         }
//     }

//     cout << ninjaTraining(n, points) << endl;

//     return 0;
// }

//with dp
int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(day==0){
        int maxi=0;
        for(int task=0; task<3; task++){
            if(task!=last){
                maxi=max(maxi, points[0][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1) return dp[day][last];
    int maxi=0;
    for(int task=0; task<3; task++){
        if(task!=last){
            int point=points[day][task]+f(day-1, task, points, dp);
            maxi=max(maxi, point);
        }
    }

    return dp[day][last]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(n-1, 3, points, dp);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> points[i][j];
        }
    }


    cout << ninjaTraining(n, points) << endl;

    return 0;
}
