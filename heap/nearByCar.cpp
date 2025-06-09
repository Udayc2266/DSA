#include<bits/stdc++.h>
using namespace std;

class Car{
    public:
        int idx;
        int distSq;

    Car(int idx,int distSq){
        this->idx = idx;
        this->distSq = distSq;
    }
    bool operator < (const Car &obj)const{

        return this->distSq < obj.distSq;

    }
};

void nearByCar(vector<pair<int,int>> pos,int k){      // 0(n)
    vector<Car> car;
    for(int i = 0 ; i<pos.size(); i++){
        int distSq = ((pos[i].first)*(pos[i].first)) + ((pos[i].second)*(pos[i].second));
        car.push_back(Car(i , distSq));

    }

    priority_queue<Car> pq(car.begin(),car.end()); //0(n)

    for(int i=0; i<k ; i++){ //)(klogn)
        cout << pq.top().idx<<endl;
        pq.pop();//0(logn)
    }
}

int main(){
    vector<pair<int,int>> pos;
    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));

    int k =2;

    return 0;
}