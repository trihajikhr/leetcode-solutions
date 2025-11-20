#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int ans = 0, r = nums.size()-1;
    for(int i=nums.size()-1; i>=0; i--){
      if(nums[i] == val){
        swap(nums[i], nums[r--]);
        ans++;
      }
    }

    return nums.size()-ans;
  }
};

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}