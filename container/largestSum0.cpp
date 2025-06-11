#include<bits/stdc++.h>
using namespace std;

int largestSum0(vector<int> arr){
    unordered_map<int,int>m;
    int sum = 0;
    int ans = 0;
    for(int j = 0 ; j<arr.size(); j++){

        sum += arr[j];
        if(m.count(sum)){

            int currLeg = j-m[sum];
            ans = max(ans, currLeg);

        }else{

            m[sum]=j;

        }


    }
    return ans;
}

int main(){
    vector<int> arr = {15,-2,2,-8,1,7,10};
    cout<<largestSum0(arr);
    return 0;
}