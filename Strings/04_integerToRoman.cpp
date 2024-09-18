#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> i2R = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        string result = "";
        while(num > 0){
            for(int i = 0; i < 13; i++){
                if(num >= i2R[i].first){
                    int times = num / i2R[i].first;
                    num %= i2R[i].first;

                    while(times-- > 0){
                        result += i2R[i].second;
                    }
                    break;
                }
            }
        }

        return result;
    }
};

int main(){
    // Driver Code  
    return 0;
}