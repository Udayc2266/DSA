#include<bits/stdc++.h>
using namespace std;



class Edge{
    public:
        int u ;
        int v;
        int wt;

        Edge(int u , int v , int wt){
            this->u = u;
            this->v = v;
            this->wt = wt;
        }

        
};

class Graph{
    public:
        vector<Edge> edges;
        int v;
        vector<int> par;
        vector<int> rank;

        Graph(int v){

            this->v = v;
            for(int i = 0 ; i<v ;i++){
                par.push_back(i);
                rank.push_back(0);
            }

        }

        int find(int x){
            if(par[x]==x){
                return x;
            }
            return par[x] = find(par[x]);
        }

        void unionByRank(int u , int v){
            int  parA = find(u);
            int parB = find(v);

            if(rank[parA] ==  rank[parB]){
                par[parB] = parA ;
                rank[parA]++;
            }else if(rank[parA] > rank[parB]){
                par[parB] = parA;
            }else{
                par[parA] = parB;
            }
        }

        void addEdge(int u, int v, int wt) {
            edges.push_back(Edge(u, v, wt));
        }

        void kruskals(){                //0(ElogE)
            sort(edges.begin(), edges.end(),[](Edge &a , Edge &b){return a.wt < b.wt ;});
            int minCost = 0;
            for(int i =0 ;i<edges.size(); i++){
                Edge e = edges[i];
                int parU = e.u;
                int parV = e.v;
                if(par[parU] != par[parV]){ //No Cycle

                    unionByRank(parU,parV);
                    minCost += e.wt;

                    

                }
            }
            cout<<minCost;
        }
};

int main(){

    Graph g(4);
    g.addEdge(0,1,10);
    g.addEdge(0,2,15);
    g.addEdge(0,3,30);
    g.addEdge(0,3,40);
    g.addEdge(0,3 ,50);
    g.kruskals();

    
    return 0;
}