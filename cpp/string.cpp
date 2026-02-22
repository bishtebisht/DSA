#include <bits/stdc++.h>
using namespace std;


bool isSubsequence(string s, string t) {
    int i=0, j=0;
    while(i<s.size() && j<t.size()) {
        if(s[i] == t[j]) {
            i++;
        }
        j++;
    }
    //if i ==s, found all the characters of s in t in the correct order.
    return i == s.size();
}
int main() {
    string s, t;
    cout<<"enter the subsequence string: ";
    cin >> s;
    cout<<"enter the main string: ";
    cin >> t;
    if(isSubsequence(s,t)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}