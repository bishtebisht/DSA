#include<bits/stdc++.h>
using namespace std;

// void subsequences(int i,vector<int> &ans, int arr[], int n) {
//     //&ans is passed by reference because we want to modify the same vector in all the recursive calls
//     if(i == n) {
//         for(int x : ans) {
//             cout << x;
//         }
//         cout << endl;
//         return;
//     }
//     ans.push_back(arr[i]);
//     subsequences(i+1, ans, arr, n);
//     //backtracking step to remove the last element added to the vector before the next recursive call
//     ans.pop_back();
//     subsequences(i+1, ans, arr, n);
// }

// int main() {
//     cout<<"number of digits: ";
//     int n;
//     cin >> n;
//     cout<<"enter the digits: ";
//     int arr[n];
//     for(int i=0; i<n; i++) {
//         cin >> arr[i];
//     }
//     vector<int> ans;
//     subsequences(0,ans,arr,n);
//     return 0;
// }




//lonngest harmonious subsequence

int findLHS(vector<int>& nums) {
    unordered_map<int, int> freq;
    for(int num : nums) {
        freq[num]++;
    }
    int longest = 0;
    for(auto it : freq) {
        if(freq.find(it.first + 1) != freq.end()) {
            longest = max(longest, it.second + freq[it.first + 1]);
        }
    }
    return longest;
}
int main() {
    int n;
    cout<<"number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout<<"enter the elements: ";
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }
    cout << "length of longest harmonious subsequence: " << findLHS(nums);
    return 0;
}