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

};

// forStack
class Stack{
    public:
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
};
// for Queue
class Queue{
    public:
    void qPush(int x, Node* &front, Node* &rear){
        if(!rear) {rear = new Node(x); front = rear; return;}
        Node* tmp = new Node(x);
        rear -> next = tmp;
        tmp->next = NULL;
        tmp->prev = rear;
        rear = rear->next;
    }
    void qPop(Node* &front){
        if(!front) cout<<-1<<" ";
        int tmp = front->val;
        front = front->next;
        front->prev = NULL;
    }
    void qTop(Node* &front){
        cout<<front->val<<" ";
    }
    void qDisplay(Node* &front,Node* &rear){
        while(front){
            cout<<front->val<<" ";
            front = front->next;
        }
        front = rear = NULL;
    }
    void qEmpty(Node* &front, Node* &rear){
        if(front && rear) {cout<<"false " ; return;}
        cout<<"true";
    }
};
int main(){
    Node *a,*b,*c,*d,*e;
    Node* curr = NULL;
    Stack s ;
    s.sPush(4,curr);
    s.sPush(5,curr);
    s.sPop(curr);
    s.sPush(6,curr);
    s.sTop(curr);
    s.sPush(7,curr);
    s.sEmpty(curr);
    s.sDisplay(curr);
    s.sEmpty(curr);
    cout<<endl;
    Node* front = NULL , *rear = NULL;
    Queue q;
    q.qPush(1,front,rear);
    q.qPush(2,front,rear);
    q.qPush(3,front,rear);
    q.qPush(4,front,rear);
    q.qPush(5,front,rear);
    q.qPop(front);
    q.qPush(6,front,rear);
    q.qPop(front);
    q.qEmpty(front,rear);
    q.qDisplay(front,rear);
    q.qEmpty(front,rear);
}