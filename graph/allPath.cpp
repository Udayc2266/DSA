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

    void allPathHelpper(int src, int dst , vector<bool> &vis , string path ){ //0(E + V)
        if(src == dst){
            cout<<path<<dst;
            return;
        }

        vis[src] = true;
        path += to_string(src);
        list<int> neighbours = l[src];
        for(int v: neighbours){
            if(!vis[v]){
                allPathHelpper(v,dst,vis,path);
            }
        }

        path = path.substr(0 , path.size()-1);
        vis[src]= false;
    }

    void printAllPath(int src , int dst){

        vector<bool> vis(v,false);
        string path = "";
        allPathHelpper(src , dst, vis, path);

   }

};

int main(){

    Graph g(5 , false);
    g.addEdge(0, 1);
    
    g.addEdge(0, 2);
    g.addEdge(0, 3);

    g.addEdge(1,2);
    g.addEdge(3, 4);
    g.printAllPath(1,3);
  
   

     
    
    return 0;
}