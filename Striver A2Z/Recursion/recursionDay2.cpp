#include <bits/stdc++.h>
using namespace std;

// Print vector
void printVector(vector<int> &v){
    cout << "[ ";
    for (auto it : v){
        cout << it << " ";
    }
    cout << "]" << endl;
}

// Summation of first N numbers
// parameterized way
int sumOfNParameterizedWay(int N, int i, int sum){
    if (i > N){
        return sum;
    }
    sumOfNParameterizedWay(N, i + 1, sum + i);
}

// functional way
int sumOfNFunctionalWay(int N){
    if (N == 0){
        return 0;
    }
    return (N + sumOfNFunctionalWay(N - 1));
}

// Reverse an array
// arr[] = {1,2,3,4,2};

// using two pointer
void revArr1(vector<int> &v, int low, int high){
    if (low >= high){
        return;
    }
    swap(v[low], v[high]);
    revArr1(v, low + 1, high - 1);
}

// using single pointer
void revArr2(vector<int> &v, int i, int n){
    if(i >= n/2){
        return;
    }
    swap(v[i], v[n-i-1]);
    revArr2(v,i+1,n);
}

// Check if a string is Palindrome or not
// return true or false
bool checkPalindrome(string& s, int low, int len){
    if(low >= len/2){
        return true;
    }
    if((s[low] != s[len-low-1])){
        return false;
    }
    return checkPalindrome(s,low+1,len);
}

// Multiple Recursion Calls
// Fibonacci Number
int fibonacciSeries(int n){
    if(n <= 1){
        return n;
    }
    return fibonacciSeries(n-1)+fibonacciSeries(n-2);
}

// Print all subSequences
// a contigous/ non-contigous sequences, which follows the order.
// arr[] = {3,1,2}
// can be done using PowerSet algorithm but here we will do with recursion

// 1st intuition we use "take/ not-take"
// TC - O((2^n)*n)
void printSubSequences(vector<int> &v, int idx, vector<int>& ds){
    if(idx >= v.size()){
        printVector(ds);
        return;
    }
    
    // take condition
    ds.push_back(v[idx]);
    printSubSequences(v,idx+1,ds);

    // not take condition
    ds.pop_back();
    printSubSequences(v,idx+1,ds);
}

// Printing Subsequences whose sum is K
void printSubSequencesSumK(vector<int> &v, int idx, vector<int>& ds, int K){
    
    // take it

    // not take it
}
int main(){
    // int sum = sumOfNParameterizedWay(5, 1, 0);
    // int sum = sumOfNFunctionalWay(5);
    // cout << sum << endl;

    // vector<int> v = {1, 2, 3, 4, 2};
    // revArr1(v, 0, 4);
    // revArr2(v, 0, 5);
    // printVector(v);

    // string s = "MADAM";
    // int len = s.length();
    // cout << checkPalindrome(s,0,len);
    // cout << fibonacciSeries(5) << endl;

    vector<int> v = {3,1,2};
    vector<int> res;

    printSubSequences(v,0,res);
    return 0;
}