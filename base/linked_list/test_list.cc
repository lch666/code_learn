/*
 * @Author: changheng.liu 
 * @Date: 2022-06-20 16:15:30 
 * @Last Modified by: changheng.liu
 * @Last Modified time: 2022-06-20 16:32:48
 */
#include "./list.h"
#include <iostream>

void LinkListPrint() {
  std::cout << "1.创建单链表   2.遍历单链表   3.获取单链表的长度   4.判断单链表是否为空   5.获取节点\n";
  std::cout << "6.在尾部插入指定元素   7.在指定位置插入指定元素   8.在头部插入指定元素\n";
  std::cout << "9.在尾部删除元素   10.删除所有元素   11.删除指定元素   12.在头部删除元素\n";
  std::cout << "13.遍历反转链表   14.递归反转链表   0.退出" << std::endl;
}

void LinkListTest() {
  LinkList list;
  int index;
  do {
    (void)LinkListPrint();
    std::cout << "input index to execute" << std::endl;
    std::cin >> index;
    switch (index) {
    case 1:
      int length;
      std::cout << "input link list length" << std::endl;
      std::cin >> length;
      list.CreatLinkList(length);
      break;
    case 2:
      list.TraceLinkList();
      break;
    case 3:
      std::cout << "link list length is " << list.GetLength() << std::endl;
      break;
    case 4:
      if (list.IsEmpty() == true) {
        std::cout << "link list is empty" << std::endl;
      } else {
        std::cout << "link list is not empty" << std::endl;
      }
      break;
    case 5:
      DataType data;
      std::cout << "input data you want get" << std::endl;
      std::cin >> data;
      std::cout << "the data val is " << list.Find(data)->val << std::endl;
      break;
    case 6:
      DataType end_data;
      std::cout << "add data in the end of link list" << std::endl;
      std::cin >> end_data;
      list.InsertElemAtEnd(end_data);
      break;
    case 7:
      DataType index_data;
      int i;
      std::cout << "input data" << std::endl;
      std::cin >> index_data;
      std::cout << "input index" << std::endl;
      std::cin >> i;
      list.InsertElemAtIndex(index_data, i);
      break;
    case 8:
      DataType head_data;
      std::cout << "inset data at head" << std::endl;
      std::cin >> head_data;
      list.InsertElemAtHead(head_data);
      break;
    case 9:
      list.DeleteElemAtEnd();
      break;
    case 10:
      list.DeleteAll();
      break;
    case 11:
      DataType delete_data;
      std::cout << "input data you want to delete" << std::endl;
      std::cin >> delete_data;
      list.DeleteElemVal(delete_data);
      break;
    case 12:
      list.DeleteElemAtHead();
      break;
    case 13:
      list.ReverseLinkList();
      break;
    case 14:
      list.RecReverseLinkListFun();
    default:
      break;
    }
  } while (index != 0);
}

void TestReverseLinkList() {
  LinkList list;
  std::cout << "before reserse link list" << std::endl;
  list.CreatLinkList(10);
  list.TraceLinkList();
  std::cout << "after reserse link list" << std::endl;
  list.ReverseLinkList();
  list.TraceLinkList();
}

int main() {
  std::cout << "hello lch !!!" << std::endl;
  (void)LinkListTest();
  (void)TestReverseLinkList();
  std::cout << "end lch !!!" << std::endl;
  return 0;
}