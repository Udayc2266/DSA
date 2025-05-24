#include<bits/stdc++.h>
using namespace std;

int friendPair(int n){
    if(n==1||n==2){
        return n;
    }

    return friendPair(n-1) + (n-1)*friendPair(n-2);

    
}

int main(){

    int a = friendPair(15);
    cout<<a<<endl;

    return 0;
}