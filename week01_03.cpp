// Leetcode 21 合并两个有序链表
// 思路：新建链表，将两个链表的节点按顺序挨个比较，小的放新链表，同时
// 下一个节点的值跟另外一个链表的节点的值对比，以此类推；采用递归或循环均可；

#include <vector>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }

        ListNode* newHead = nullptr;
        if (l1->val < l2->val) {
            newHead = l1;
            newHead->next = mergeTwoLists(l1->next, l2);
        }else{
            newHead = l2;
            newHead->next = mergeTwoLists(l1, l2->next);
        }
        return newHead;

    }
};