#include <iostream>

//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1->2->3->4->5
// 5->4->3->2->1
// https://leetcode-cn.com/problems/reverse-linked-list/
class Solution {
public:
  ListNode* node;
  ListNode* reverseList(ListNode* head) {
      ListNode *temp = nullptr; // 临时保存的指针
      ListNode *res = temp;  // 保存已经反转之后的链表，最终需要返回的指针
      while (head) {
          temp = head;   // 指向当前需要反转的结点1
          head = head->next; // 当前结点指向下一个结点2

          temp->next = res;    // 切断当前结点和后面结点之间的联系，指向已经反转之后的结点
          res = temp;     // 保存已经反转之后的指针
      }
      return res;
  }
};

void PrintList(ListNode *node) {
  if (node == nullptr) std::cout << "node is nullptr" << std::endl;
  while(node) {
    std::cout << node->val << " ";
    node = node->next;
  }
  std::cout << std::endl;
}

int main(int args, char **argv) {
  std::cout << "hello lch ! " << std::endl;
  Solution solution;
  ListNode *temp = new ListNode(-1);   // 头结点不能为空，不然没有next
  ListNode *test = temp;
  solution.node = temp;
  for (int i = 0; i < 10; i++) {
    temp->next = new ListNode(i);
    temp = temp->next;
  }
  (void)PrintList(test);
  (void)PrintList(solution.node);
  temp = solution.reverseList(solution.node);
  (void)PrintList(temp);
  delete temp;
  delete test;
  std::cout << "end lch ! " << std::endl;
  return 0;
}