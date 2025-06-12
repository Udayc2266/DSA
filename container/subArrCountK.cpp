#include<bits/stdc++.h>
using namespace std;

int subArrCountK(vector<int> arr,int k){
    unordered_map<int,int>m;
    m[0]=1;
    int sum = 0;
    int ans = 0;
    for(int j = 0 ; j<arr.size(); j++){

        sum += arr[j];
        if(m.count(sum-k)){

            ans+= m[sum-k];

        }

        if(m.count(sum)){
            m[sum]++;
        }else{
            m[sum]=1;
        }


    }
    return ans;
}

int main(){
    vector<int> arr = {10,-2,2,-20,10};
    cout<<subArrCountK(arr,-10);
    return 0;
}