/*
    Problem Name : Group Anagrams
    Company Tags  : Amazon(multiple times), Google, Uber, Facebook, Bloomberg, Yahoo, Goldman Sachs, Microsoft, Apple, Walmart Labs, Twilio
    Leetcode : 49
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Approach - 01 : Time Complexity - O(N* Nlog(N)), Space Complexity - O(N)
        int n = strs.size();
        
        vector<vector<string>> result;
        map<string, vector<string>> mp;
        
        // Iterate through each string and store it in a map in sorted alphabhetical order
        for(int i = 0; i < n; i++){
            string temp = strs[i];
            sort(begin(temp), end(temp));
        
            // Make a vector of strings for unique strings after sorting
            mp[temp].push_back(strs[i]);
        }

        // Traverse through map and store result in strings
        for(auto it : mp){
            result.push_back(it.second);
        }

        return result;
    }
};

int main(){
    // Driver Code 
    return 0;
}