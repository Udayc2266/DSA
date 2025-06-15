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

    void bfs(){             //0(V + E)
        queue<int> q;
        vector<bool> vis(v,false);
        q.push(0);
        vis[0] = true;
        while(q.size()>0){
            int u = q.front();
            q.pop();
            cout<<u<<" ";
            list<int> neighbors = l[u];
            for(int v: neighbors){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }

        }
        cout<<endl;
    }

    void dfsHelpper(int u , vector<bool> &vis){            //0(V + E)

        vis[u] = true;
        cout<<u<<" ";
        list<int> neighbours = l[u];
        for(int v: neighbours){
            if(!vis[v]){
                dfsHelpper(v, vis);

            }
        }

    }

    void dfs(){

    vector<bool> vis(7,false);
    dfsHelpper(0,vis) ;

    }

    bool hasPathHelpper(int src, int dist , vector<bool> &vis){ //0(E + V)
        if(src == dist){
            return true;
        }
        vis[src] = true;
        list<int> neighbours = l[src];
        for(int i : neighbours){
            if(!vis[i]){
                hasPathHelpper(i,dist,vis);
                return true;
            }
            
        }
        return false;
    }

    bool hasPath(int src, int dist){


        vector<bool> vis(v , false);
        return hasPathHelpper(src, dist ,vis);



    }
};

int main(){

    Graph g(5);
    g.addEdge(0, 1);
    
    g.addEdge(1, 2);
    g.addEdge(1, 3);

    g.addEdge(2, 4);
    g.addEdge(3, 3);
    g.print();
    g.bfs();

    
    g.dfs() ;

     
    
    return 0;
}