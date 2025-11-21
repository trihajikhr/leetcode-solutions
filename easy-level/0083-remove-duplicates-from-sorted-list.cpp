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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* temp = head;

        while (temp && temp->next) {
            if (temp->val == temp->next->val) {
                ListNode* del = temp->next;
                temp->next = temp->next->next;
                delete del;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ListNode * head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(2);
    ListNode * temp = head->next->next->next;

    temp->next = new ListNode(3);
    temp->next->next = new ListNode(3);

    Solution sol;
    ListNode * rest = sol.deleteDuplicates(head);
    temp = rest;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}