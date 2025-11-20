#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    return ranges::lower_bound(nums, target) - nums.begin();
  }
};

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}