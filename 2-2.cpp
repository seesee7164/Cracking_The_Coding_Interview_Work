#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
using namespace std;

struct Node{
    int value;
    Node *Next;
    Node (){
        value = 0;
        Next = nullptr;
    }
    Node (int n){
        value = n;
        Next = nullptr;
    }
    Node (int n, Node * i){
        value = n;
        Next = i;
    }
    ~Node (){
        delete this;
    }
};

void ShowList(Node * Head){
    Node * current = Head;
    while(current != nullptr){
        cout << current -> value << ' ';
        current = current -> Next;
    }
    cout << endl;
}

Node * temp = current -> Next -> Next;
while(temp -> val == this -> val){
    temp = temp -> Next;
}
current -> Next = temp;

int main(){
    srand(time(NULL));
    Node * head = new Node(rand() % 10);
    Node * current = head;
    for(int i = 0; i < 10; i++){
        Node * next = new Node(rand() % 10);
        current -> Next = next;
        current = next;
    }
    ShowList(head);
    return 0;
}