#include<iostream>
using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    return haystack.find(needle);
  }
};

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}