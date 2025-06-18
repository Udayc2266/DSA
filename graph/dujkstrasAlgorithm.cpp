#include<bits/stdc++.h>
using namespace std;


class Edge{
    public:
        int v; 
        int wt;

        Edge(int v, int wt){
            this->v = v;
            this ->wt = wt;
        }
};

void dujkstrasAlgorithum(int src , vector<vector<Edge>> graph ,int v ){      //0((E + V)*logV) due to prorityQ

    priority_queue<pair<int,int> , vector<pair<int, int>>, greater<pair<int,int>>> pq; //pair(dis[v],v)
    vector<int> dist(v,INT_MAX);
    pq.push(make_pair(0,src));
    dist[src] = 0;
    while(pq.size()>0){
        int u = pq.top().second;
        pq.pop();

        vector<Edge> edges = graph[u];
        for(Edge e: edges){

            if(dist[e.v]> dist[u]+e.wt ){
                dist[e.v] = dist[u]+e.wt;
                pq.push(make_pair(dist[e.v],e.v));
            }

        }

    }
    
        for(int d: dist){
            cout<<d<<" ";
        }
        

}


int main(){

    int v= 6;
    vector<vector<Edge>> graph(v);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));

    graph[2].push_back(Edge(4,3));

    graph[3].push_back(Edge(5,1));

    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(2,5));

    dujkstrasAlgorithum(0,graph,v);
    return 0;
}