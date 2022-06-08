#include<bits/stdc++.h>
using namespace std;
    bool isOperator(char exp){
    switch(exp){
        case '+':
        case '*':
        case '/':
        case '-':
        return true;
    }
    return false;
}
int Operator(int a , int b , char op){
    int tmp = 0;
    if(op == '-') {
        return a - b;
    }
    else if(op == '+') {
        return a + b;
    }
    else if(op == '*') {
        return a * b;
    }
    else if(op == '/') {
       return a / b;
    }
    return tmp;
}
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S){
        stack<int> p;
        for(auto exp : S){
            if(isOperator(exp)){
                int a,b;
                b = p.top();
                p.pop();
                a = p.top();
                p.pop();
                int tmp = Operator(a,b,exp);
                p.push(tmp);
            }
            else{
               // int tmpexp = exp-'0';
                p.push(exp-'0');
            }
        }
    return p.top();
    }
int main(){
    string s = "231*+9-";
    cout<<evaluatePostfix(s);
    return 0;
}