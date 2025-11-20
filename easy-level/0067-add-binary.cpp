#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;

// Solutions >>>
class Solution {
public:
    string addBinary(string a, string b) {
        string rest = "";
        int carry = 0, l = a.length()-1, r = b.length()-1;
        while (l >= 0 || r >= 0 ) {
            if (l >=0) {
                if (a[l] == '1') carry++;

                l--;
            }

            if (r >= 0) {
                if (b[r] == '1') carry++;

                r--;
            }

            if (carry == 0) {
                rest += '0';
            } else if (carry == 1) {
                rest += '1', carry = 0;
            } else if (carry == 2) {
                rest += '0', carry = 1;
            } else if (carry == 3) {
                rest += '1', carry = 1;
            }
        }

        if (carry) rest += '1';
        reverse(rest.begin(), rest.end());
        return rest;
    }

    string addBinary2(string a, string b) {
        #define len length()
        int carry = 0;
        if (a.len < b.len) swap(a,b);
        for (int i = 0; i < static_cast<int>(max(a.len, b.len)); i++) {

            if (static_cast<int>(a.length())-1-i >= 0) {
                if (a[a.len-1-i] == '1') carry++;
            }

            if (static_cast<int>(b.len)-1-i >= 0 ) {
                if (b[b.len-1-i] == '1') carry++;
            }

            if (carry == 0) {
                a[a.len-1-i] = '0';
            } else if (carry == 1) {
                a[a.len-1-i] = '1', carry = 0;
            } else if (carry == 2) {
                a[a.len-1-i] = '0', carry = 1;
            } else if (carry == 3) {
                a[a.len-1-i] = '0', carry = 1;
            }
        }

        if (carry) a.insert(a.begin(), '1');
        return a;
    }
};
// Solutions <<<

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    string a, b;
    cin >> a >> b;
    cout << sol.addBinary2(a,b);
    return 0;
}
