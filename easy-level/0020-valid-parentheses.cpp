#include<iostream>
#include<stack>
using namespace std;

// Solution >>>
class Solution {
public:
  bool isValid(string s) {
    stack<char> brack;
    for (char& c : s) {
      if (c=='(' || c=='[' || c=='{') {
        brack.push(c);
      } else {
        if (brack.empty()) return false;
        if (c==')' && brack.top()=='(') brack.pop();
        else if (c==']' && brack.top() == '[') brack.pop();
        else if (c=='}' && brack.top() == '{') brack.pop();
        else return false;
      }
    }

    if (!brack.empty()) return false;
    return true;
  }

  bool isValid2(string s) {
    stack<char> input;
    for(char c : s){
      if(c=='[' || c=='{' || c=='(') input.push(c);
      else {
        if(input.empty()) return false;
        char a = input.top();
        if((c==')' && a != '(') ||
           (c=='}' && a != '{') ||
           (c==']' && a != '[')
        ) return false;
        input.pop();
      }
    }
    return input.empty();
  }
};
// Solution <<<

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol;
  string s; cin >> s;
  cout << sol.isValid(s);
  return 0;
}