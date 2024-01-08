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
 class campare{
     public:
     bool operator()(ListNode* a ,ListNode* b ){
         return a -> val > b -> val;
    }
  
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* ,vector<ListNode*>,campare > minHeap;

        int k = lists.size();
        if(k == 0 ) return NULL;

        // insertion of first element of every ll
        for(int i=0; i<k ;i++){
            if(lists[i] != NULL)
                minHeap.push(lists[i]);     
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!minHeap.empty()){
            ListNode* temp = minHeap.top();
            minHeap.pop();
            // temp may or may not be the first element of ans ll
            if(head == NULL){
                // temp is first element
                head = temp;
                tail = temp;         
            }
            else{
                 //temp is not first element of the linked list
                    tail -> next = temp;
                    tail = temp;
            }
            if(tail->next != NULL)
             minHeap.push(tail->next);
        }
        return head;
    }
};