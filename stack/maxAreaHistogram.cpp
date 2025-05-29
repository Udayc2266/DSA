#include<bits/stdc++.h>
using namespace std;

void maxAreaHistogram(vector<int> height){
    vector<int> nsl(height.size());
    vector<int> nsr(height.size());
    stack<int> s;

    nsl[0] = -1;
    s.push(0);

    for(int i =1; i<height.size() ; i++ ){
        int curr = height[i];
        while(!s.empty() && curr<=height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsl[i] = -1;
        }else{
            nsl[i] = s.top();
        }
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }

    nsr[height.size() -1] =height.size();
    s.push(height.size()-1);

    for(int i = height.size()-2 ; i>=0 ; i--){
        int curr = height[i];
        while(!s.empty() && curr<=height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsr[i] =height.size() ;
        }else{
            nsr[i] = s.top();
        }
        s.push(i);
    }

    int maxArea =0;

    for(int i =0 ; i< height.size() ; i++){
        int h = height[i];
        int w = (nsr[i] - nsl[i])-1;

        int area = h*w;

        maxArea= max(maxArea , area);
    }

    cout<<"max area : "<<maxArea;
}

int main(){
    vector <int> height = {2,1,5,6,2,3};

    maxAreaHistogram(height);
    return 0;
}