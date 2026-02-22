#include<bits/stdc++.h>
using namespace std;

//longest harmonious subsequence

int findLHS(vector<int>& nums) {
    unordered_map<int, int> freq;
    //count the frequency of each number
    //store it in the unordered_map freq
    //the key is the number and the value is its frequency
    for(int num : nums) {
        freq[num]++;
    }

    int longest = 0;
    //iterate through the unordered_map freq 
    //check if there is a number that is one greater than the current number
    for(auto it : freq) {
        if(freq.find(it.first + 1) != freq.end()) {
            //if there is a number that is one greater than the current number
            //update the longest variable
            //maxi of the curr longest and the sum of the freq of the curr number and the freq of the number that is one greater
            longest = max(longest, it.second + freq[it.first + 1]);
            //it.second is the frequency of the current number 
            //freq[it.first + 1] is the frequency of the number that is one greater than the current number
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