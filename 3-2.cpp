#include<iostream>
using namespace std;

class stack{
    private:
    int max;
    int top = -1;
    int *arr;
    int *minarr;
    void incSize(){
        max += 10;
        int *list = new int[max];
        int *list2 = new int[max];
        for(int i = 0; i < max-10; i++){
            list[i] = arr[i];
            list2[i] = minarr[i];
        }
        delete arr;
        delete minarr;
        arr = list;
        minarr = list2;
    }
    public:
    stack();
    stack(int);
    void push(int);
    void pop();
    void see_all();
    bool is_empty();
    void see_min();
    ~stack(){
        delete arr;
        delete minarr;
    }
};

stack::stack(){
    max = 10;
    arr = new int[max];
    minarr = new int[max];
}

stack::stack(int n){
    max = n;
    arr = new int[max];
    minarr = new int[max];
}

void stack::push(int n){
    if(top >= max-1){
        incSize();
    }
    if(top == -1){
        minarr[top+1] = n;
    }
    else if(minarr[top] > n){
        minarr[top+1] = n;
    }
    else{
        minarr[top+1] = minarr[top];
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
    for(int i = 0; i < top+1; i++){
        cout << minarr[i] << ' ';
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

void stack::see_min(){
    if(top == -1){
        cout << "The stack is empty" << endl;
    }
    else{
        cout << "The minimum value in the stack is " << minarr[top] << endl;
    }
}

int main(){
    stack pile(1);
    pile.pop();
    pile.push(5);
    pile.see_all();
    pile.push(6);
    pile.see_min();
    // pile.pop();
    pile.push(7);
    pile.see_min();
    pile.see_all();
    return 0;
}