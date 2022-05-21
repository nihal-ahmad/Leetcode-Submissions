/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a,ListNode* b)
        {
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode*,vector<ListNode*>,cmp> findMinNode;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* tail = dummyNode;
       for(int i=0;i<lists.size();i++) 
       {
         if(lists[i]) findMinNode.push(lists[i]);
           
       }
        while(findMinNode.size())
        {
            ListNode* temp = findMinNode.top();
            findMinNode.pop();
            tail->next = temp;
            tail=temp;
            if(temp->next) findMinNode.push(temp->next);
        }
        return dummyNode->next;
    }
};