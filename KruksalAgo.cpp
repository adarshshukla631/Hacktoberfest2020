#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class Graph{
    int V;
    list<pair<int,pair<int,int>>> l;

    int find(int x,int parent[]){
        //base case
        if(parent[x]==-1){
            return x;
        }
        //path compression
        return parent[x]=find(parent[x],parent);
    }

    void union_set(int a,int b,int parent[],int s1,int s2,int rank[]){

        //rank of union
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }else{
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
    }

    public:
        Graph(int V){
            this->V=V;
        }
        
        void addEdge(int u,int v,int wt){
            l.push_back(make_pair(wt,make_pair(u,v)));
        }

        int kruksal(){
            int* parent=new int[V];
            int* rank=new int[V];
            int cost=0;
            for(int i=0;i<V;i++){
                parent[i]=-1;
                rank[i]=1;
            }
            l.sort();
            for(auto edge:l){
                int a=edge.second.first;
                int b=edge.second.second;
                int wt=edge.first;
                int s1=find(a,parent);
                int s2=find(b,parent);
                if(s1!=s2){
                    union_set(a,b,parent,s1,s2,rank);
                    cost+=wt;
                }
            }
            return cost;
        }

};

int main(){
  Graph g(5);
  g.addEdge(0,1,1);
  g.addEdge(0,2,2);
  g.addEdge(0,3,2);
  g.addEdge(1,2,2);
  g.addEdge(2,3,3);
  g.addEdge(1,3,3);
  g.addEdge(3,4,6);
  cout<<g.kruksal();
}