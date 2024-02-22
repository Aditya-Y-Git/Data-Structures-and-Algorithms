#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack{
    int top;
    public:
        int a[MAX];
        Stack(){
            top = -1;
        }
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};

bool Stack :: push(int x){
    if(top >= (MAX-1)){
        cout<<"Stack Overflow"<<endl;
        return false;
    }
    else{
        a[++top] = x;
        cout<<x<<" is pushed to the stack"<<endl;
    }
}
int Stack :: pop(){
    if(top < 0){
        cout<<"Stack underflow"<<endl;
        return 0;
    }
    else{
        int num = a[top];
        cout<<num<<" is popped from stack"<<endl;
        top--;
        return num;
    }
}
int Stack :: peek(){
    if(top < 0){
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    else{
        cout<<"Top element is "<<a[top]<<endl;
        return a[top];
    }
}
bool Stack :: isEmpty(){
    return top<0;
}

int main(){
    Stack st = Stack();
    st.push(5);
    st.push(6);
    st.peek();
    st.pop();
    st.pop();
    st.pop();
    st.peek();
    cout<<st.isEmpty();
    return 0;
}