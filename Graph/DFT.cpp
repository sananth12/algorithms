#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<list>
#include<queue>
using namespace std;

class graph
{
    int v;
    list<int>  *adj;
    list<int>::iterator it;
    public:
        graph(int V)
        {
            this->v=V+1;
            adj= new list<int>[V];
        }
        void addEdge(int u,int v)
        {
            adj[u].push_back(v);
        }
        void BFT(int x)
        {
            bool visited[v];
            for(int i=0;i<v;i++)
                visited[i]=false;
            queue<int> Q;
            Q.push(x);

            while(!Q.empty())
            {
                cout<<Q.front()<<"->";
                Q.pop();
                for(it = adj[x].begin(); it != adj[x].end(); ++it)
                {
                    if(!visited[*it])
                    {
                        visited[*it] = true;
                        Q.push(*it);
                    }
                }
            }
        }
};
int main()
{
   int n,e;
   cout<<"No. of vertices:";
   cin>>n;
   graph G(n);
   cout<<"No. of edges:";
   cin>>e;
   for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        G.addEdge(u,v);
        G.addEdge(v,u);  // for undirected graph
    }
   int x;
   cout<<"BFT on vertex:";
   cin>>x;
   G.BFT(x);

return 0;
}
