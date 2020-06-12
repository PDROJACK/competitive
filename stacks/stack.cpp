#include<bits/stdc++.h>

using namespace std;

class Stack {
    private: 
        int* arr;
        int sz;
        int top;
        bool isFull();
        bool isEmpty();
    public:
        Stack(int);
        int getTop();
        void push(int);
        void pop();
};

Stack::Stack(int s): arr{new int[s]}, sz{s}, top{-1} {
    for(int i=0;i<s;++i){
        arr[i]=0;
    }
};

bool Stack::isEmpty(){
    if(top==-1) return true;
    return false;
}

bool Stack::isFull(){
    if(top==sz-1) return true;
    return false;
}

int Stack::getTop(){
    if(isEmpty()) return -1;
    return arr[top];
}

void Stack::push(int a){
    if(isFull()) {
        cout<<"Stack Overflow\n";
        return;
        }
    top+=1;
    arr[top] = a;
}

void Stack::pop(){
    if(isEmpty()) {
        cout<<"Stack Underflow\n";
        return;
        }
    top-=1;
}

int main() {
    Stack s{4};
    for(int i=0;i<4;i++){
        s.push(i);
    }
    s.push(4);
    cout<<s.getTop();
    return 0;
}