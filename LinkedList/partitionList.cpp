#include<bits/stdc++.h> 
using namespace std; 


 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

    ListNode* part(ListNode* head,int x){
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy , *fw = head,*prev = dummy;
        dummy->next = head;
        bool bigN = false;
        int i = 1;
        while(fw){
            int temporary = fw->val;
            if(fw->val>=x){
                prev = fw;
                fw = fw->next ;
                bigN = true;
            }
            else if(fw->val<x && bigN){
                ListNode* tmp = curr->next;
                curr->next = fw;
                prev->next = fw->next;
                curr = fw;
                fw = fw->next;
                curr->next = tmp;
            }
            else {curr = curr->next; prev = fw;  fw=fw->next; }
        }
        head = dummy->next;
        return head;
    }
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        return part(head ,x);
    }


void display(ListNode * head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
}
int main(){
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(4);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(2);
    ListNode* e = new ListNode(5);
    ListNode* f = new ListNode(2);
    a->next = b;
    b->next =c;
    c->next = d;
    d->next =e;
    e->next =f;
    display(partition(a,3));
    return 0;
}