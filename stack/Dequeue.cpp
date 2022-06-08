#include<bits/stdc++.h> 
using namespace std; 

struct Node{
    int val ;
    Node* next;
    Node* prev;
    Node(int x){
        val  = x;
        prev = NULL;
        next = NULL;
    }
    Node(int x,Node* prev, Node* next){
        val  = x;
        this->prev = prev;
        this->next = next;
    }
};
void display(Node* head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
}
void nextPrev(Node* &a,Node* b,Node* c){
    a->prev = b;
    a->next = c;
}
// forStack
void sPush(int x,Node* &curr){
    if(!curr) {curr = new Node(x); return; }
    Node* tmp = new Node(x);
    curr->next = tmp;
    tmp->prev = curr;
    curr = curr->next;
}
int sPop(Node* &curr){
    if(!curr) return -1;
    int tmp = curr->val;
    curr = curr->prev;
    if(curr) curr -> next = NULL;
    return tmp;
}
void sTop(Node* &curr){
    cout<< curr->val<<" "; return;
}
void sEmpty(Node* &curr){
    if(curr) {
        cout<<"false "; 
        return;
    }
    cout<<"true ";
}
void sDisplay(Node* &curr){
    while(curr){
        cout<<sPop(curr)<<" ";
    }
}
int main(){
    //Node *a,*b,*c,*d,*e;
    //a = new Node(1);
    //b = new Node(2);
    //c = new Node(3);
    //d = new Node(4);
    //e = new Node(5);

   // nextPrev(a,NULL,b);
   // nextPrev(b,a,c);
   // nextPrev(c,b,d);
   // nextPrev(d,c,e);
   // nextPrev(e,d,NULL);
    Node* curr = NULL;
    sPush(4,curr);
    sPush(5,curr);
    sPop(curr);
    sPush(6,curr);
    sTop(curr);
    sPush(7,curr);
    sEmpty(curr);
    sDisplay(curr);
    sEmpty(curr);
}