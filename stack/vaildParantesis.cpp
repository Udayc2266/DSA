#include<bits/stdc++.h>
using namespace std;

bool validParenthesis(string str){
    stack <char> s;

    for(int i =0 ; i<str.size() ; i++){
        char curr = str[i];
        if(curr=='{' || curr=='('|| curr=='['){
            s.push(curr);
        }else {
            if(s.empty()){
                return false;
            int top = s.top();
            if((top == '(' && curr == ')') ||(top == '{' && curr == '}')||(top == '[' && curr == ']' )){
                s.pop();
            }else{
                return false;
            }

        }}
        

        
    }
    return s.empty();
}

bool dublicate(string str){

    stack<char> s;
    for(int i =0 ; i<str.size() ; i++){
        char curr = str[i];
        if(curr != ')'){
            s.push(curr);
        }else{
            if(s.top()=='('){
                return true;
            }
            while(s.top()!='('){
                s.pop();
            }
            s.pop();
            
        }
    }
    return false;

}


int main(){

    string s1 = "(a+b)";
    string s2 = "((a+b))";
    cout<<dublicate(s2);
    return 0;
}