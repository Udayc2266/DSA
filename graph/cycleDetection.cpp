#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int>* l;
    bool isUndir;
public:
    Graph(int v  , bool isUndir = true){

        this->v = v;
        l = new list<int> [v];
        this->isUndir = isUndir;


    }

    // weghtedGraph : list<pair<int,int>>[v]

    void addEdge(int u , int v){

        l[u].push_back(v);
        if(isUndir){

            l[v].push_back(u);

        }
        

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

    bool DirectedCycleHelpper(int src ,  vector<bool>&vis, vector<bool>&recPath){
        vis[src] = true;
        recPath[src] = true;
        list<int> neighbors = l[src];

        for(int v : neighbors){
            if(!vis[v]){

                if(DirectedCycleHelpper(v,vis , recPath)){       //recPath[src] = false;  ? doute
                    return true;
                }

            }else{
                if(recPath[v]){
                    return true;
                }
            }
        }

        recPath[src] = false;
        return false;
    }

    bool isCycleDirected(){

        vector<bool> vis(v,false);
        vector<bool> recPath(v, false);
        for(int i = 0; i<v ; i++){

            if(!vis[i]){
                if(DirectedCycleHelpper(i,vis,recPath)){
                    return true;
                }
            }

        }
        return false ;

    }

};

int main(){

    Graph g(5 , false);
    g.addEdge(0, 1);
    
    g.addEdge(0, 2);
    g.addEdge(0, 3);

    g.addEdge(1,2);
    g.addEdge(3, 4);
    g.print();
    cout<<g.isCycleUndirected();
   

     
    
    return 0;
}