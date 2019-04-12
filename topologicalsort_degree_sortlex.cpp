#include "bits/stdc++.h"
using namespace std;
vector<int> adj[100010];
vector<int> ans;
int deg[100010];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        deg[v]++;
    }
    set<int> q;
    for(int i=1;i<=n;i++)
    {
        if(deg[i]==0) q.insert(i);
    }
    int cnt=n;
    while(!q.empty())
    {
        int u=*q.begin();
        q.erase(u);
        cnt--;
        ans.emplace_back(u);
        for(auto v : adj[u])
        {
            if(--deg[v]==0) q.insert(v);
        }
    }
    if(cnt!=0)printf("Sandro fails.");
    else for(auto i:ans)printf("%d ",i);
}