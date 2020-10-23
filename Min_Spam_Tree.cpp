#include<iostream>
#include<vector>
#include <queue>

using namespace std;

typedef pair<long long,int> PII;
const int MAX = 1e4+5;
bool marked[MAX];
vector<PII> adj[MAX];

long long prim(int x)
{
    priority_queue<PII , vector<PII> , greater<PII>> Q;
    int y=0;
    long long min_cost=0;
    PII p;
    Q.push(make_pair(0,x));
    while(!Q.empty())
    {
        p=Q.top();
        Q.pop();
        x=p.second;
        if(marked[x]==true)
            continue;
        min_cost+=p.first;
        marked[x]=true;
        for(int i=0;i<adj[x].size();i++)
        {
            y=adj[x][i].second;
            if(marked[y]==false)
            {
                Q.push(adj[x][i]);
            }
        }
    }
    return min_cost;
}

int main()
{
    int n,m,x,y;
    long long weight,min_cost;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>weight;
        adj[x].push_back(make_pair(weight,y));
        adj[y].push_back(make_pair(weight,x));
    }
    min_cost=prim(1);
    cout<<min_cost<<endl;
    return 0;
}
