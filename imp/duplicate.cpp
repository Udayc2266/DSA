#include<bits/stdc++.h>
using namespace std;

void duplicate(string str , string ans , int i , int map[26]){

    if( i == str.size()){
        cout<<"ans : "<<ans<<endl;
    }
    char ch = str[i];
    int mapInd = (int)(ch - 'a');
    if(map[mapInd]){
        duplicate( str ,  ans ,  i+1 ,  map);
    }else{
        map[mapInd] == true;
        duplicate( str ,  ans+ch ,  i+1 ,  map);
    }

 }

int main(){
    string str = "sdeaswdasa";
    string ans = "";
    int map[26] = {false};
    duplicate(str , ans , 0 , map);
    

    return 0;
}