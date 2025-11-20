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
  ListNode * back = nullptr;

  void push_back(ListNode * &list, int value) {
    ListNode * create = new ListNode(value);
    if (list == nullptr) {
      list = create;
      back = create;
      return;
    }

    back->next = create;
    back = create;
  }

  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    vector<int> elem;
    ListNode * temp = list1;
    while (temp) {
      elem.push_back(temp->val);
      temp = temp->next;
    }

    temp = list2;
    while (temp) {
      elem.push_back(temp->val);
      temp = temp->next;
    }

    ranges::sort(elem);
    ListNode * rest = nullptr;
    for (const auto& x : elem) {
      push_back(rest, x);
    }
    return rest;
  }
};

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ListNode * head1 = new ListNode(5);
  head1->next = new ListNode(3);
  head1->next->next = new ListNode(4);

  ListNode * head2 = new ListNode(7);
  head2->next = new ListNode(10);
  head2->next->next = new ListNode(9);

  Solution sol;
  ListNode * rest = sol.mergeTwoLists(head1, head2);

  ListNode * temp = rest;
  while (temp) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  return 0;
}