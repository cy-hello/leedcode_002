/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 把单链表的基础知识过一遍
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode l3(0);   
        ListNode *preNode = &l3;  
        int addNumber = 0;  
        ListNode *b1 = l1, *b2 = l2;  
        while(b1!=NULL || b2!=NULL || addNumber>0)//当l1和l2不为空或者addNumber>0任意一个条件成立  
        {  
            ListNode *node = new ListNode(0);//临时的结构体指针  
            int val1 = b1 ? b1->val : 0;//如果b1不为空，val1=b1->val,否则为空  
            int val2 = b2 ? b2->val : 0;//如果b2不为空，val2=b2->val,否则为空  
            b1 = b1 ? b1->next : NULL;//如果b1不为空，b1指向下一个链表节点,否则为空  
            b2 = b2 ? b2->next: NULL;//如果b1不为空，b1指向下一个链表节点,否则为空  
            node->val = (val1 + val2 + addNumber) % 10;  //超过10需要进位
            addNumber = (val1 + val2 + addNumber) / 10;  
            preNode->next = node;  
            preNode = node;  
        }  
        return l3.next;  
    }
};