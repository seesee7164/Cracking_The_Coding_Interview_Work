#include<iostream>
using namespace std;

//To do this, I would make the stack have 3 times its initial height and I would
//keep track of three different tops. I would also modify the program to take in 
//the index of the stack which is being changed for each operation. I would modify
//incSize so that whenever one of the two early stack is incremented, it moves the
//later stacks starting point later on and also moves top when it is copying the full
//array. I would also keep trac of each individual stacks size so that the push
//operation will know exactly when to incSize.

class stack{
    private:
    int max;
    int top = -1;
    int *arr;
    void incSize(){
        max += 10;
        int *list = new int[max];
        for(int i = 0; i < max-10; i++){
            list[i] = arr[i];
        }
        delete arr;
        arr = list;
    }
    public:
    stack();
    stack(int);
    void push(int);
    void pop();
    void see_all();
    bool is_empty();
    ~stack(){
        delete arr;
    }
};

stack::stack(){
    max = 10;
    arr = new int[max];
}

stack::stack(int n){
    max = n;
    arr = new int[max];
}

void stack::push(int n){
    if(top >= max-1){
        incSize();
    }
    arr[++top] = n;
}

void stack::pop(){
    if(top == -1){
        cout << "The stack is already empty" << endl;
    }
    else{
        top--;
    }
}

void stack::see_all(){
    for(int i = 0; i < top+1; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}

bool stack::is_empty(){
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    stack pile(1);
    pile.pop();
    pile.push(5);
    pile.push(6);
    pile.pop();
    pile.push(7);
    pile.see_all();
    return 0;
}