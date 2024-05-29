#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
    int prev2 = 1, prev1 = 1;

    for (int i = 2; i <= n; i++)
    {
        int curr_i = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr_i;
    }

    return prev1;
}

int main()
{
    int n;
    cin >> n;
    cout << climbStairs(n) << endl;

    return 0;
}