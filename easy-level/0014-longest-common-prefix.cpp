#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Solution >>>
class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    int idx = 0;
    while (true) {
      bool pass = true;
      for (int i=0; i<strs.size(); i++) {
        if (idx == strs[i].length() || strs[0][idx] != strs[i][idx]) {
          pass = false;
          break;
        }
      }
      if (!pass) break;
      idx++;
    }
    return strs[0].substr(0,idx);
  }
};
// Solution <<<

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  vector<string> str;
  for (int i=0; i<3; i++) {
    string s;
    cin >> s;
    str.push_back(s);
  }

  cout << sol.longestCommonPrefix(str);
  return 0;
}