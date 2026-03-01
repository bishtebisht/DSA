#include<bits/stdc++.h>
using namespace std;

//longest harmonious subsequence

// int findLHS(vector<int>& nums) {
//     unordered_map<int, int> freq;
//     //count the frequency of each number
//     //store it in the unordered_map freq
//     //the key is the number and the value is its frequency
//     for(int num : nums) {
//         freq[num]++;
//     }

//     int longest = 0;
//     //iterate through the unordered_map freq 
//     //check if there is a number that is one greater than the current number
//     for(auto it : freq) {
//         if(freq.find(it.first + 1) != freq.end()) {
//             //if there is a number that is one greater than the current number
//             //update the longest variable
//             //maxi of the curr longest and the sum of the freq of the curr number and the freq of the number that is one greater
//             longest = max(longest, it.second + freq[it.first + 1]);
//             //it.second is the frequency of the current number 
//             //freq[it.first + 1] is the frequency of the number that is one greater than the current number
//         }
//     }
//     return longest;
// }
// int main() {
//     int n;
//     cout<<"number of elements: ";
//     cin >> n;
//     vector<int> nums(n);
//     cout<<"enter the elements: ";
//     for(int i=0; i<n; i++) {
//         cin >> nums[i];
//     }
//     cout << "length of longest harmonious subsequence: " << findLHS(nums);
//     return 0;
// }

//ISOMORPHIC STRING
bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) 
        return false;

    unordered_map<char, char> mapST;
    unordered_map<char, char> mapTS;

    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i];
        char c2 = t[i];

        //s -> t mapping
        if (mapST.count(c1)) {
            if (mapST[c1] != c2)
                return false;
        } else {
            mapST[c1] = c2;
        }

        //t -> s mapping
        if (mapTS.count(c2)) {
            if (mapTS[c2] != c1)
                return false;
        } else {
            mapTS[c2] = c1;
        }
    }

    return true;
}

//Word Pattern (same concept)
 bool wordPattern(string pattern, string s) {
    vector<string> words;
    string word;
    
    // Split string by spaces
    stringstream ss(s);
    // Extract words one by one from the stringstream
    // The >> operator reads characters until it finds a space
    while (ss >> word) {
        words.push_back(word);
    }
    
    if (pattern.length() != words.size())
        return false;
    
    unordered_map<char, string> charToWord;
    unordered_map<string, char> wordToChar;
    
    for (int i = 0; i < pattern.length(); i++) {
        char c = pattern[i];
        string w = words[i];
        
        if (charToWord.count(c)) {
            if (charToWord[c] != w)
                return false;
        } else {
            charToWord[c] = w;
        }
        
        if (wordToChar.count(w)) {
            if (wordToChar[w] != c)
                return false;
        } else {
            wordToChar[w] = c;
        }
    }
    
    return true;
}