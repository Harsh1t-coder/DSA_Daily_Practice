#include<bits/stdc++.h> 
using namespace std; 

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int x){
        val = x;
        prev = next = child = NULL;
    }
};

    Node* flat(Node* curr){
        Node *dummy = new Node(-1),*prev = dummy;
        dummy->next = curr;
        stack<Node*> s;
        while(curr || !s.empty() ){
            
            if(!curr && !s.empty()){
                curr = s.top(); 
                s.pop(); 
                curr->prev = prev; 
                prev->next = curr;
            }
            
            if(!curr->child) {prev = curr; curr = curr->next; }
            
            else{
                if(curr->next) s.push(curr->next);
                prev = curr;
                curr  = curr->child;
                prev->child = NULL;
                curr->prev = prev;
                prev->next = curr; 
                }
        }
        return dummy->next;
}
    
    Node* flatten(Node* head) {
        if(!head) return NULL;
        if(!head->child && !head->next) return head;
        flat(head);
        return head;        
    }

    void display(Node* head){
        while(head){
            cout<<head->val<<" ";
            head = head->next;
        }
    }
    int main(){
        Node *head = new Node(1);
        Node *b = new Node(2);
        Node *c = new Node(3);
        head->child = b;
        b->child = c;
        flatten(head);
        display(head);
        return 0;
    }

