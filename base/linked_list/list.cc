/*
 * @Author: changheng.liu 
 * @Date: 2022-06-20 16:15:22 
 * @Last Modified by: changheng.liu
 * @Last Modified time: 2022-06-21 15:48:18
 */
#include "./list.h"
#include <iostream>

// @description: 创建单链表
LinkList::LinkList() {
  head = new Node();
  head->val = 0;
  head->next = nullptr;
}

// @description: 销毁单链表
LinkList::~LinkList() {
  delete head;
}

// @description: 创建n个结点的单链表
void LinkList::CreatLinkList(int n) {
  Node *pnew, *ptemp;
  ptemp = head;
  if (n < 0) {
    std::cout << "input linklist size is error" << std::endl;
    return;
  }
  for (int i = 0; i < n; i++) {
    pnew = new Node();
    pnew->val = static_cast<DataType>(i);
    pnew->next = nullptr;
    ptemp->next = pnew;  // 增加新节点
    ptemp = pnew;        // 节点后移一位
  }
}

// @description: 遍历链表
void LinkList::TraceLinkList() {
  if (head == nullptr || head->next == nullptr) {
    std::cout << "linklist is null" << std::endl;
  }
  Node *temp = head;
  int index = 0;
  while (temp->next != nullptr) {
    temp = temp->next;
    std::cout << "linklist index is " << index++;
    std::cout << ", linklist val is " << temp->val << std::endl;
  }
}

// @description: 获取链表长度
int LinkList::GetLength() {
  int count = 0;
  Node *node = head->next;
  while(node != nullptr) {
    ++count;
    node = node->next;
  }
  return count;
}

// @description: 判断链表是否为空
bool LinkList::IsEmpty() {
  if (head->next == nullptr) {
    return true;
  }
  return false;
}

// @description: 查找指定数据的地址
Node *LinkList::Find(DataType data) {
  Node *node = head;
  if (node == nullptr) {
    std::cout << "find link list is nullptr" << std::endl;
    return nullptr;
  } else {
    while(node->next != nullptr) {
      if (node->val == data) {
        return node;
      }
      node = node->next;
    }
    return nullptr;
  }
}

// @description: 尾部插入指定数据
void LinkList::InsertElemAtEnd(DataType data) {
  Node *new_node = new Node();  // 新增的结点
  new_node->val = data;
  new_node->next = nullptr;
  Node *temp = head;
  if (head == nullptr) {
    head = new_node;
  } else {
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = new_node;  // 新增结点加入尾部
  }
}


// @description: 指定位置插入数据
void LinkList::InsertElemAtIndex(DataType data, int n) {
  if (n < 1 || GetLength() < n) {
    std::cout << "input value error" << std::endl;
  } else {
    Node *node = new Node();
    node->val = data;
    int count = 1;
    Node *temp = head;
    while (count < n) {  // 遍历n
      temp = temp->next;
      count++;
    }
    node->next = temp->next;
    temp->next = node;
  }
}

// @description: 头部插入指定数据
void LinkList::InsertElemAtHead(DataType data) {
  Node *new_node = new Node();
  new_node->val = data;
  Node *temp = head;   // 防止修改head指向
  if (head == nullptr) {
    head = new_node;
  }
  new_node->next = temp->next;
  temp->next = new_node;
}

// @description: 删除尾部元素
void LinkList::DeleteElemAtEnd() {
  Node *node = head;
  Node *temp = nullptr;
  if (node->next == nullptr) {
    std::cout << "link list is nullptr" << std::endl;
  } else {
    while (node->next != nullptr) {
      temp = node;
      node = node->next;
    }
    delete node;
    node = nullptr;
    temp->next = nullptr;
  }
}

// @description: 删除全部元素
void LinkList::DeleteAll() {
  Node *node = head->next;
  Node *temp = new Node();
  while (node != nullptr) {
    temp = node;
    node = node->next;
    head->next = node;
    temp->next = nullptr;
    delete temp;
  }
  head->next = nullptr;
}

// @description: 删除指定数据
void LinkList::DeleteElemVal(DataType data) {
  Node *temp = Find(data);
  if (temp == head->next) {
    DeleteElemAtHead();
  } else {
    Node *node = head;
    while(node->next != temp) {
      node = node->next;
    }
    node->next = temp->next;
    delete temp;
    temp = nullptr;
  }
}

// @description: 删除头部元素
void LinkList::DeleteElemAtHead() {
  Node *node = head;
  if (node == nullptr || node->next == nullptr) {
    std::cout << "link list is nullptr" << std::endl;
  } else {
    Node *temp = nullptr;
    node = node->next;
    temp = node->next;
    delete node;
    node = nullptr;
    head->next = temp;
  }
}

// @description: 遍历链表
void LinkList::ReverseLinkList() {
  // 1->2->3->4->5
  // 5->4->3->2->1
  // https://leetcode-cn.com/problems/reverse-linked-list/
  Node *node = head;
  if (node == nullptr || head->next == nullptr) {
    std::cout << "link list is nullptr" << std::endl;
    return;
  }
  node = node->next;
  Node *temp = nullptr;  // 临时保存的指针
  Node *new_list = temp;  // 保存已经反转之后的链表，最终需要返回的指针
  while (node != nullptr) {  // 循环遍历每一个变量
    temp = node;   // 指向当前需要反转的结点1
    node = node->next;   // 当前结点指向下一个结点2
    
    temp->next = new_list;   // 切断当前结点和后面结点之间的联系，指向已经反转之后的结点
    new_list = temp;   // 保存已经反转之后的指针
  }
  head->next = new_list;
}

// @description: 递归遍历链表
Node* LinkList::RecReverseLinkList(Node *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  Node *new_head = RecReverseLinkList(head->next);  // 递归
  head->next->next = head;  // 改变head->next的指向
  head->next = nullptr;  // head->next赋值为nullptr
  return new_head;
}

void LinkList::RecReverseLinkListFun() {
  head->next = RecReverseLinkList(head->next);
}