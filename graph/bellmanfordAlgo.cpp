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

void bellmanfordAlgo(vector<vector<Edge>> graph, int src, int v){    //0(V*E)

    vector<int> dist(v,INT_MAX);
    dist[src]= 0;
    for(int i = 0; i<v-1;i++){
        for(int u =0 ; u<v ;u++){
            for(Edge e: graph[u]){ 
                if(dist[e.v]> dist[u]+e.wt ){
                    dist[e.v] = dist[u]+e.wt;
            }

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

    bellmanfordAlgo(graph,0,v);
    return 0;
}