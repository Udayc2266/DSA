#include<bits/stdc++.h>
using namespace std;

void nextGreatest(vector <int> arr , vector<int> ans){

    stack<int> s;
    int idx = sizeof(arr)-1;
    ans[idx] = -1;
    s.push(arr[idx]);
    for(int idx = idx-1 ; idx >= 0 ; idx--){

        int curr = arr[idx];
        while(!s.empty() && curr>= s.top()){
            s.pop();
        }
        if(s.empty()){
            ans[idx] = -1;
        }else{
            ans[idx] = s.top();
        }
        s.push(curr);
    }

    for(int i = 0 ; i<sizeof(arr)-1 ;i++){
        cout<<ans[i]<<" ";
        
    }
    cout<<endl;
}

int main(){

    vector<int> arr = {6, 8, 0 , 1 , 3};

    vector<int> ans = {0,0,0,0,0};

    nextGreatest(arr,ans);
    return 0;
}