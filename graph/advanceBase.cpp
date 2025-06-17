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

    void bfsHelpper(int st ,vector<bool> vis ){             //0(V + E)
        queue<int> q;
        
        q.push(st);
        vis[st] = true;
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

    void bfs(){

        vector<bool> vis(v,false);
        for(int i =0; i<v ; i++){
            if(!vis[i]){

                bfsHelpper(i,vis);
                cout<<endl;

            }

        }

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
    for(int i =0 ; i<v;i++){

        if(!vis[i]){
            dfsHelpper(i,vis) ;
            cout<<endl;
        }

    }
    

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