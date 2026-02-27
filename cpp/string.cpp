#include <bits/stdc++.h>
using namespace std;


// bool isSubsequence(string s, string t) {
//     int i=0, j=0;
//     while(i<s.size() && j<t.size()) {
//         if(s[i] == t[j]) {
//             i++;
//         }
//         j++;
//     }
//     //if i ==s, found all the characters of s in t in the correct order.
//     return i == s.size();
// }
// int main() {
//     string s, t;
//     cout<<"enter the subsequence string: ";
//     cin >> s;
//     cout<<"enter the main string: ";
//     cin >> t;
//     if(isSubsequence(s,t)) {
//         cout << "true";
//     } else {
//         cout << "false";
//     }
//     return 0;
// }


//Palindrome Partitioning


class Solution {
public:
    vector<vector<string>> result;

    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

    void backtrack(string &s, int start, vector<string> &path) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, path);
                path.pop_back();  // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        backtrack(s, 0, path);
        return result;
    }
};

int main() {
    Solution sol;
    string s;

    cout << "Enter string: ";
    cin >> s;

    vector<vector<string>> partitions = sol.partition(s);

    cout << "\nPalindrome Partitions:\n";
    for (auto &vec : partitions) {
        cout << "[ ";
        for (auto &str : vec) {
            cout << "\"" << str << "\" ";
        }
        cout << "]\n";
    }

    return 0;
}