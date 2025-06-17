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
    bool isByParites(){

        queue <int> q;
        vector<bool> vis(v,false);
        vector<int> color(v,-1);

        q.push(0);
        color[0]=0;
        vis[0]= true;

        while(q.size()>0){
            int curr = q.front();
            q.pop();
            list<int> neighbors = l[curr];
            for(int v: neighbors){
                if(!vis[v]){

                    vis[v]= true;
                    color[v] = 1;
                    q.push(v);

                }else{
                    if(color[v]==color[curr]){
                        return false;
                    }
                }
            }

        }
        return true;

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

   

     
    
    return 0;
}