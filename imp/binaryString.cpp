#include<bits/stdc++.h>
using namespace std;

void binaryPair(int n , int lastPlace  , string ans){

    if(n == 0){

        cout<<ans<<endl;
        return;

    }
    if( lastPlace != 1){
        binaryPair(n-1, 0 , ans+'0');
        binaryPair(n-1, 1, ans+'1');

    }else{

        binaryPair(n-1, 0 , ans+'0');

    }

    
}

int main(){
    string ans = "";
    

    binaryPair(10,0,ans);
    

    return 0;
}