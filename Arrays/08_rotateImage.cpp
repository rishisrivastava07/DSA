/*
    Company Tags 😱🤯 : Amazon, FactSet, Hike, Amazon, MakeMyTrip, Qualcomm, Infosys, Microsoft, Google, Salesforce, Flipkart
    LeetCode - 48
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Approach 1 - Time Complexity - O(N^2) Space Complexity - O(N^2)
        // Copy the matrix in image 2D matrix and perform the indexes operation simply
        vector<vector<int>> image = matrix;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[j][n-1-i] = image[i][j];
            }
        }

        // Approach 2 - Time Complexity - O(N^2) Space Complexity - O(1)
        // Transpose the matrix
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(i != j){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        // reverse the matrix along column wise
        for(int i = 0; i < n; i++){
            reverse(begin(matrix[i]), end(matrix[i]));
        }
    }
};

int main(){
    // Driver Code
    return 0;
}