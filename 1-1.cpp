#include <iostream>
#include <vector>
using namespace std;

//the challenge for this will be doing it without any additional data structures
//I will be assuming that a capitalized letter is the same as a lowercase one
//I am also assuming that the string will only contain characters (e.g. no spaces etc)
//The main purpose of these assumptions is to limit the number of possibilities for
//the characters and ensure that the program will run in O(1) time.

bool testUnique(string S){
    int n = S.size();
    if(S.size() > 26){
        return false;
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j< n; j++){
            if(S[i] == S[j] || (int)S[i] == (int)S[j] + 32 || (int)S[i] == (int)S[j] - 32){
                return false;
            }
        }
    }
    return true;
}

int main(){
    string test1 = "testing";
    string test2 = "Testing";
    string test3 = "teasing";
    bool var = testUnique(test2);
    if(var){
        cout << "The string is composed of unique characters" << endl;
    }
    else{
        cout << "The string is not composed of unique characters" << endl;
    }
    return 0;
}