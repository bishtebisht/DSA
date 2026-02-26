#include<bits/stdc++.h>
using namespace std;

//Two pointers is a technique where two indices move through an array/string to solve problems efficiently (usually in O(n) time).

//Opposite Direction Pointers

//Palindrome
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        if (!isalnum(s[left])) left++;
        else if (!isalnum(s[right])) right--;
        else {
            if (tolower(s[left]) != tolower(s[right]))
                return false;
            left++;
            right--;
        }
    }
    return true;
}

//Two Sum
vector<int> twoSum(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target)
            return {left, right};
        else if (sum < target)
            left++;
        else
            right--;
    }
    return {};
}

//Fast and Slow Pointers
//Both start from same side, move at different speeds.

//Remove Duplicates from Sorted Array
int removeDuplicates(vector<int>& nums) {
    int slow = 0;

    for (int fast = 1; fast < nums.size(); fast++) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    return slow + 1;
}

//Move zeroes
int removeDuplicates(vector<int>& nums) {
    int slow = 0;

    for (int fast = 1; fast < nums.size(); fast++) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }
    return slow + 1;
}

//Sliding Window (Special Two Pointer Case)
//Both move forward, maintain a window.

//Longest Substring Without Repeating Characters

int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); right++) {
        while (set.count(s[right])) {
            set.erase(s[left]);
            left++;
        }
        set.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
