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


//printing subsequences with sum k
void subsequences(int i,vector<int> &ans, int arr[], int n, int sum, int k) {
    if(i == n) {
        if(sum == k) {
            for(int x : ans) {
                cout << x <<" ";
            }
            cout << endl;
        }
        return;
    }
    ans.push_back(arr[i]);
    sum += arr[i];
    subsequences(i+1, ans, arr, n, sum, k);
    //backtracking step to remove the last element added to the vector before the next recursive call
    ans.pop_back();
    sum -= arr[i];
    subsequences(i+1, ans, arr, n, sum, k);
}

int main() {
    cout<<"number of digits: ";
    int n;
    cin >> n;
    cout<<"enter the digits: ";
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int k;
    cout<<"enter the sum : ";
    cin >> k;
    vector<int> ans;
    subsequences(0,ans,arr,n,0,k);
    return 0;
}