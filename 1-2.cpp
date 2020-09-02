#include <iostream>
#include <vector>
using namespace std;

bool checkPermutation(string S1, string S2){
    int n = S1.size();
    if(n != S2.size()){
        return false;
    }
    int list1[128] = {0};
    int list2[128] = {0};
    for(int i = 0; i < n; i++){
        list1[(int)S1[i]] +=1;
        list2[(int)S2[i]] +=1;
    }
    for(int i = 0; i < 128; i++){
        if(list1[i] != list2[i]){
            return false;
        }
    }
    return true;
}

int main(){
    string first = "first";
    string second = "second";
    string third = "dnoces";
    bool var = checkPermutation(third, second);
    if(var){
        cout << "The return state is true" << endl;
    }
    else{
        cout << "The return state is false" << endl;
    }
    return 0;
}