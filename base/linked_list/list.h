/*
 * @Author: changheng.liu 
 * @Date: 2022-06-21 15:36:05 
 * @Last Modified by: changheng.liu
 * @Last Modified time: 2022-06-21 15:39:28
 */

using DataType = int;

struct Node {
  DataType val;   // 数据域
  Node *next;     // 指针域
};

class LinkList {
 private:
  Node *head;
 public:
  LinkList();
  ~LinkList();
  void CreatLinkList(int n);
  void TraceLinkList();
  int GetLength();
  bool IsEmpty();
  Node* Find(DataType val);
  void InsertElemAtIndex(DataType val, int n);
  void InsertElemAtHead(DataType val);
  void InsertElemAtEnd(DataType val);
  void DeleteElemAtHead();
  void DeleteElemAtEnd();
  void DeleteAll();
  void DeleteElemVal(DataType val);
  void ReverseLinkList();
  Node* RecReverseLinkList(Node *head);
  void RecReverseLinkListFun();
};