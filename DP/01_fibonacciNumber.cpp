include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int solve(int i, vector<int>& dp){
        if(i <= 1) return i;

        if(dp[i] != -1) return dp[i];
        return dp[i] = solve(i-1, dp) + solve(i-2, dp);
    }

    int fib(int n) {
        vector<int> dp(n+1, 0);
        // return solve(n, dp);

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};

int main(){
    // driver code
    return 0;
}