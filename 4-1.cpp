#include<iostream>
#include<vector>
using namespace std;

//This is pseudocode for 4-1
struct node(){};
int main(){
    vector<node> visited;
    vector<node> stack;
    visited.pushback(S);
    stack.push_back(S);
    while(stack != empty){
        top = stack.pop;
        for all nodes next that top is connected to:
            stack.push_back(next)
            if(next == E){
                cout << "E has been found!" << endl;
                break;
            }
    }
}