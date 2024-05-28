#include<bits/stdc++.h>
using namespace std;

// Type - 01  - Memoization Technique (Top-Down Approach)
// TC - O(N)
// SC - O(N) {recursive stack space} + O(N) {for dp size}
int fib(int n, vector<int>& dp){
    if(n <= 1) return n;

    if(dp[n] != -1){
        return dp[n];
    }

    return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}

int main(){
    int n;
    cin >> n;
    
    // vector<int> dp(n+1, -1);
    // cout << fib(n, dp);

    // Type - 02  - Tabulation Technique (Bottom-up Approach)
    // TC - O(N)
    // SC - O(N) {for dp size}
    // dp[0] = 0;
    // dp[1] = 1;

    // for(int i = 2; i <= n; i++){
    //     dp[i] = dp[i-1] + dp[i-2];
    // }

    // cout << dp[n];

    // Type - 03  - Tabulation Technique (Optimizing Space)
    // Optimal Solution
    // TC - O(N)
    // SC - O(1)
    int prev2 = 0, prev1 = 1;

    for(int i = 2; i <= n; i++){
        int curr_i = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr_i;
    }

    cout << prev1 << endl;

    return 0;
}