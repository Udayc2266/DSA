#include<bits/stdc++.h>
using namespace std;

int countDistint(vector<int>arr){
    unordered_set<int> s;
    for(int i = 0 ; i<arr.size();i++){
        s.insert(arr[i]); 
    }
    return s.size();
}

int main(){
    vector<int>arr = {4,3,2,5,6,7,3,4,2,1};

    return 0;
}