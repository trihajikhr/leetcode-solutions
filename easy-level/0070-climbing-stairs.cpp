#include<iostream>
#include<sstream>
#include<array>
using namespace std;

// Solutions >>>
class Solution {
public:
    int climbStairs(int n) {
        array<int, 3> stair{};
        constexpr int MOD = 3;
        stair[0]=1;
        stair[1]=1;
        for(int i=2; i<=n; i++){
            stair[i % MOD] = stair[(i+1) % MOD] + stair[(i+2) % MOD];
        }
        return stair[n % MOD];
    }
// Solutions <<<

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    return 0;
}