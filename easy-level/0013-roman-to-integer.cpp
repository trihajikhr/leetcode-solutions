#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Solution >>>
class Solution {
public:
  int romanToInt(string s) {
        unordered_map<char, int> roman = {
          {'I',1},
          {'V',5},
          {'X',10},
          {'L',50},
          {'C', 100},
          {'D', 500},
          {'M', 1000}
        };

    int rest = 0;
    for (int i=0; i<s.length(); i++) {
      if (i != s.length()-1) {
        if (roman[s[i+1]] > roman[s[i]]) {
          rest += roman[s[i+1]] - roman[s[i]];
          i++;
          continue;
        }
      }
      rest += roman[s[i]];
    }
    return rest;
  }
};
// Solution <<<

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  string s; cin >> s;
  cout << sol.romanToInt(s) << "\n";
  return 0;
}