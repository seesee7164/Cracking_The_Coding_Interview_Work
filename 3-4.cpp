#include<iostream>
using namespace std;

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
    int pop();
    int peek();
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

int stack::pop(){
    if(top == -1){
        // cout << "The stack is already empty" << endl;
    }
    else{
        int n = arr[top--];
        return n;
    }
    return NULL;
}

int stack::peek(){
    if(top == -1){
        // cout << "The stack is empty" << endl;
    }
    else{
        return arr[top];
    }
    return NULL;
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

class alternateQueue{
    private:
    stack S1;
    stack S2;
    bool reversed = false;
    public:
    void push(int);
    int pop();
    int peek();
};
void alternateQueue::push(int n){
    if(reversed){
        int q = S2.pop();
        while(q != NULL){
            S1.push(q);
            q = S2.pop();
        }
        reversed = false;
    }
    S1.push(n);
}
int alternateQueue::pop(){
    if(S1.is_empty()&&S2.is_empty()){
        cout << "The Queue is empty." << endl;
        return NULL;
    }
    else if(!reversed){
        int q = S1.pop();
        while(q!= NULL){
            S2.push(q);
            q = S1.pop();
        }
        reversed = true;
    }
    return S2.pop();
}
int alternateQueue::peek(){
    if(S1.is_empty()&&S2.is_empty()){
        cout << "The Queue is empty." << endl;
        return NULL;
    }
    else if(!reversed){
        int q = S1.pop();
        while(q!= NULL){
            S2.push(q);
            q = S1.pop();
        }
        reversed = true;
    }
    return S2.peek();
}

int main(){
    alternateQueue pile;
    pile.pop();
    pile.push(5);
    cout << pile.peek() << endl;
    pile.push(6);
    cout << pile.peek() << endl;
    pile.pop();
    cout << pile.peek() << endl;
    pile.push(7);
    cout << pile.peek() << endl;
    return 0;
}