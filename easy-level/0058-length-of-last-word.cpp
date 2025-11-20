#include<iostream>
#include<sstream>
using namespace std;

// Solutions >>>
class Solution {
public:
  int lengthOfLastWord(string s) {
      stringstream ss(s);
      string prev;
      while (ss >> prev);
      return prev.length();
  }

  int lengthOfLastWord2(string s) {
      int len = 0, r = s.length()-1;
      while (r >= 0 && s[r]==' ') r--;
      while (r >= 0 && s[r]!=' ')r--, len++;
      return len;
  }
};
// Solutions <<<

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  getline(cin, s);
  Solution sol;
  cout << sol.lengthOfLastWord2(s);
  return 0;
}