#include<iostream>
#include<vector>
using namespace std;

class Graph
{
    int v=0;
    bool visited[10000];
    vector<int> adj[10000];

    public:
    Graph(int v)
    {
        this->v=v;
        for(int i=0;i<v;i++)
        {
            visited[i]=false;
        }
    }

    void addEdge(int x,int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    void dfs(int head)
    {
        visited[head]=true;
        for(int i=0;i<adj[head].size();i++)
        {
            if(visited[adj[head][i]]==false)
            {
                dfs(adj[head][i]);
            }
        }
    }

    int check()
    {
        int count=0;
        for(int i=1;i<v+1;i++)
        {
            if(visited[i]==0)
            {
                count++;
            }
        }
        return count;
    }

};

int main()
{
    int m,n;
    cin>>n>>m;

    Graph g(n);

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }
    
    int head=0;
    cin>>head;

    g.dfs(head);

    int ret=g.check();
    cout<<ret;

    return 0;
}
