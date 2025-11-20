#include<iostream>
#include<vector>
using namespace std;

// Solution >>>
class Solution {
public:
  bool isPalindrome(int x) {
    string s = to_string(x);
    for(int i=0; i<s.length()/2; i++){
      if(s[i] != s[s.length()-i-1]){
        return false;
      }
    }
    return true;
  }

  bool isPalindrome2(int x) {
    if (x < 0) return false;
    vector<int> data;
    while (x > 0) {
      int temp = x % 10;
      data.push_back(temp);
      x /= 10;
    }

    for (int i=0; i<data.size()/2; i++) {
      if (data[i] != data[data.size()-i-1]) {
        return false;
      }
    }
    return true;
  }

    bool isPalindrome3(int x) {
      if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

      int rev = 0;

      while (x > rev) {
        int digit = x % 10;
        rev = rev * 10 + digit;
        x /= 10;
      }

      return (x == rev || x == rev / 10);
    }
};
// Solution <<<

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  return 0;
}