#include<bits/stdc++.h>
using namespace std;

void purmitationn (string str ,string subset){
    if(str.size()==0){
        cout<<subset<<" ";
        return;
    }
    for(int i =  0 ; i < str.size() ; i++){
        char ch = str[i];
        purmitationn(str.substr(0,i) + str.substr(i+1, str.size()-1-i),subset+ch);
    }
}

int main(){

    string str = "abc";
    string subset = ""; 
    purmitationn(str,subset);
    return 0;
}