#include <bits/stdc++.h>
using namespace std;

// Print Name N times using recursion
void printNames(int i, int n){
    if (i > n){
        return;
    }
    cout << "Hey, Rishi" << endl;
    printNames(i + 1, n);
}
// Print Linearly from 1 to N using recursion
void printNumbers(int i, int n){
    if (i > n){
        return;
    }
    cout << (i + 1) << " ";
    printNumbers(i + 1, n);
}
// Print from N to 1 using recursion
void printNumbersReverse(int n){
    if (n < 1){
        return;
    }
    cout << n << " ";
    printNumbersReverse(n - 1);
}
// Print Linearly from 1 to N (But by Backtracking)
void printNumbersBT(int i, int n){
    if (i < 1){
        return;
    }
    printNumbersBT(i - 1, n);
    cout << i << " ";
}
// Print from N to 1 (By Backtracking)
void printNumbersReverseBT(int i, int n){
    if (i > n){
        return;
    }
    printNumbersReverseBT(i + 1, n);
    cout << i << " ";
}

int main(){
    // printNames(0, 5);
    // printNumbers(0, 5);
    // printNumbersReverse(5);
    // printNumbersBT(4, 4);
    printNumbersReverseBT(0, 4);
    return 0;
}