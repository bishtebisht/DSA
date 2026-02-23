#include<bits/stdc++.h>
using namespace std;
    
vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end());
    
    //prefix sum
    for(int i = 1; i < nums.size(); i++){
        nums[i] += nums[i - 1];
    }
    
    vector<int> answer;
    
    for(int q : queries){
        int len = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
        answer.push_back(len);
    }
    
    return answer;
}

int main() {
    int n, m;
    cout<<"number of elements in nums: ";
    cin >> n;
    vector<int> nums(n);
    cout<<"enter the elements in nums: ";
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }
    cout<<"number of queries: ";
    cin >> m;
    vector<int> queries(m);
    cout<<"enter the queries: ";
    for(int i=0; i<m; i++) {
        cin >> queries[i];
    }
    
    vector<int> answer = answerQueries(nums, queries);
    
    cout << "answers to the queries: ";
    for(int ans : answer) {
        cout << ans << " ";
    }
    
    return 0;
}