/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        unordered_map<Node*,Node*> copyListAddress;
        Node* dummyNode = head;
        while(dummyNode)
        {Node* copy =  new Node(dummyNode->val);
            copyListAddress[dummyNode] = copy;
               
            dummyNode=dummyNode->next;
        }
        dummyNode = head;
        while(dummyNode)
        {
           copyListAddress[dummyNode]->next = copyListAddress[dummyNode->next];
              copyListAddress[dummyNode]->random = copyListAddress[dummyNode->random];
            dummyNode = dummyNode->next;
            
        }
        return copyListAddress[head];
    }
};