#include<bits/stdc++.h>
using namespace std;

int fab(int n){             //0(2^n)
    if(n ==0 || n==1){
        return n;
    }
    return fab(n-1)+ fab(n-2);
}

int fabDP(int n , vector<int> &f){      //0(n)
    if(n ==0 || n==1){
        return n;
    }
    if(f[n] != -1){
        return f[n];
    }
    f[n]= fabDP(n-1,f)+ fabDP(n-2,f);
    return f[n];
}

int fabTab(int n){               //0(n) 
    vector<int> f(n+1,0);
    f[1]=1;
    f[0]=0;
    for(int i =2 ; i<n ; i++){
        f[n] = f[n-1] + f[n-2];
    }
    return f[n];
}

int main(){
    
    int n =40;
    vector<int> f(n+1, -1);
     cout<<fabDP(n,f);
    cout<<fab(n);
    cout<<fabTab(n);
    
    return 0;
}