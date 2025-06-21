#include<bits/stdc++.h>
using namespace std;

int countWayRec(int n){                             //0(2^n)

    if(n ==0 || n== 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    return countWayRec(n-1) +  countWayRec(n-2) + countWayRec(n-3);
}


int countWayRecMemory(int n , vector<int> &f){     //0(n)

    if(n ==0 || n== 1){
        return 1;
    }

    if(f[n] !=  -1){
        return f[n];
    }
    f[n]= countWayRecMemory(n-1 ,f ) + countWayRecMemory(n-2,f);
    return f[n];
}

int countWayRecTabu(int n){                         //0(n)

    vector<int> f(n+1 , 0);

    f[0] = 1;
    f[1] = 1;


    for(int i = 2 ; i<=n ; i++){
        f[i]= f[i-1] + f[i-2] ;

    }
    return f[n];

}



int main(){
    
    int n = 4;
    cout<<countWayRec(n);
    vector<int> f(n+1,-1);
    cout<<countWayRecMemory(n,f);
    cout<<countWayRecTabu(n);
    
    return 0;
}