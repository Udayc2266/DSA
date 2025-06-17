#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int>* l;
public:
    Graph(int v){

        this->v = v;
        l = new list<int> [v];


    }

    // weghtedGraph : list<pair<int,int>>[v]

    void addEdge(int u , int v){

        l[u].push_back(v);
        l[v].push_back(u);

    }

    void print(){
        for(int u =0 ; u<v; u++){
            list<int> neighbors = l[u];
            cout<<u<<"->";
            for(int v: neighbors){

                cout<<v<<",";

            }
            cout<<endl;
        }
    }

    bool UndirectedCycleHelpper(int src , int par , vector<bool> &vis){     //0(E+V)

        vis[src] =  true;
        list<int> neighbors = l[src];

        for(int v :  neighbors){
            if(!vis[v]){
                if(UndirectedCycleHelpper(v,src,vis)){
                    return true;
                };
            }else{
                if( v != par){
                    return true;
                }
            }

        }
        return false;

    }

    bool isCycleUndirected(){

        vector<bool> vis(v,false);
        return UndirectedCycleHelpper(0,-1,vis);

    }

};

int main(){

    Graph g(5);
    g.addEdge(0, 1);
    
    g.addEdge(0, 2);
    g.addEdge(0, 3);

    g.addEdge(1,2);
    g.addEdge(3, 4);
    g.print();
    cout<<g.isCycleUndirected();
   

     
    
    return 0;
}