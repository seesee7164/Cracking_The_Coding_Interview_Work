#include<iostream>
using namespace std;

char* repspace(char* orig, int true_count){
    int space_count;
    int actual_count = 0;
    while(orig[actual_count++] != '\0');
    cout << actual_count << endl;
    char next [actual_count];
    int dist = 0;
    for(int i = 0; i < true_count; i++){
        if(orig[i] == ' '){
            next[i + (dist++)] = '%';
            next[i + (dist++)] = '2';
            next[i + (dist++)] = '0';
        }
        else{
            next[i + dist] = orig[i];
        }
        cout << orig[i];
    }
    next[actual_count - 1] = '\0';
    return next;
}

int main(){
    char str [18] = "Mr John Smith    ";
    char * net = repspace(str, 13);
    int c = 0;
    while(net[c] != '\0'){
        cout << net[c];
        c++;
    }
    cout << endl;
    for(int i = 0; i < 17; i++){
        cout << net[i];
    }
    cout << endl;
}