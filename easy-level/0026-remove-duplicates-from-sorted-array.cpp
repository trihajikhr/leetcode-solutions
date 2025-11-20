#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int idx = 0;
    for(int i=0; i<nums.size(); i++){
      if(nums[idx] != nums[i]){
        nums[++idx] = nums[i];
      }
    }

    return idx+1;
  }
};

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}