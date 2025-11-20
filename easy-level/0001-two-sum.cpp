#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Solution >>>
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> rest (2);
    for (int i=0; i<nums.size()-1; i++) {
      for (int j=i+1; j<nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          rest[0] = i, rest[1] = j;
          return rest;
        }
      }
    }
    return rest;
  }

  // two pass hash table
  vector<int> twoSum2(vector<int>& nums, int target) {
    unordered_map<int, int> hash;
    for (int i=0; i<nums.size(); i++) {
      hash[nums[i]] = i;
    }

    for (int i=0; i<nums.size(); i++) {
      int comp = target - nums[i];
      if (hash.find(comp) != hash.end() && hash[comp] != i) {
        return {hash[comp], i};
      }
    }
    return {};
  }

  // one pass hash table
  vector<int> twoSum3(vector<int>& nums, int target) {
    unordered_map<int, int> hash;
    for (int i=0; i<nums.size(); i++) {
      int comp = target - nums[i];
      if (hash.find(comp) != hash.end() && hash[comp] != i) {
        return {hash[comp], i};
      }
      hash[nums[i]] = i;
    }
    return {};
  }
};
// Solution <<<

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<int> v = {2,7,11,15};
  int t = 9;
  for ( auto& x : sol.twoSum(v,t)) {
    cout << x << " ";
  }
  return 0;
}