#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}


};

// Solution >>>
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i=m; i< m+n; i++) {
            nums1[i]=nums2[i-m];
        }

        ranges::sort(nums1);
    }
};
// Solution <<<

auto main() -> int {
    return 0;
}