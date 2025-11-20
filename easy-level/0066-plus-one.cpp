#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

// Solutions >>>
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool next = true;
        for(int i=digits.size()-1; i>=0; i--){
            if(next) digits[i]++;
            if(digits[i]==10){
                digits[i]=0;
                next = true;
                if(i==0){
                    digits.insert(digits.begin(), 1);
                }
                continue;
            }
            return digits;
        }

        return digits;
    }
};
// Solutions <<<

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}