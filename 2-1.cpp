#include iostream
using namespace std;

struct Node{
    int value;
    Node *Next;
};

class list{
    private:
    Node* Head;
    Node* Tail;
    public:
    void insertEnd(int n){
        Node* temp = new Node;
        temp -> value = n;
        temp.Next = NULL;
        if(Head == NULL){
            Head = temp;
            Tail = temp;
            temp = NULL;
        }
        else{
            Tail -> Next = temp;
            Tail = temp;
        }
    }
    void deleteEnd(){
        Node* cur = Head;
        while(cur -> Next != NULL)
    }
    list(){
        Head = NULL;
        Tail = NULL;
    }
    addNext(int n){
        
    }
}