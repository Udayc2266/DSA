#include<bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    list<pair<int,int>>* l;
    bool isUndir;
public:
    Graph(int v  , bool isUndir = true){

        this->v = v;
        l = new list<pair<int,int>> [v];
        this->isUndir = isUndir;


    }

    // weghtedGraph : list<pair<int,int>>[v]

    void addEdge(int u , int v, int wt){

        l[u].push_back(make_pair(v,wt));
        if(isUndir){
            l[v].push_back(make_pair(u,wt));
        }
    }

  


    void prismAlgo(int src){

        priority_queue<pair<int,int> , vector<pair<int, int>>, greater<pair<int,int>>> pq;  //(wt , v)
        
        vector<bool> mst(v,false);
        pq.push(make_pair(0,src));

        int ans = 0;

        while(pq.size()>0){
            int u = pq.top().second;
            int cost = pq.top().first;
            pq.pop();

            if(!mst[u]){
                mst[u] = true;
                ans+=cost;
                list<pair<int,int> > neighbors = l[u];
                for(pair<int,int> e :neighbors){
                    pq.push(make_pair(e.second,e.first));
                }

            }

        }
        cout<<ans;


    }

};

int main(){

    Graph g(5);
    g.addEdge(0, 1,2);
    
    g.addEdge(1, 2,6);
    g.addEdge(1, 3,4);

    g.addEdge(2, 4,7);
    g.addEdge(3, 3,4);
    g.prismAlgo(0);
  
 

    
    return 0;
}