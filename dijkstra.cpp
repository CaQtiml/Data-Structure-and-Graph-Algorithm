#include "bits/stdc++.h"
using namespace std;
typedef  pair<int,int> ii ;
typedef  vector<int> vi;
typedef  vector<pair<int,int>> vii;
#define INF 1000000000
#define pb emplace_back
#define mkp make_pair
//vector<ii> adj[1000000]; (for 1million node graph)
//dist[1000000]; (for 1million node graph)
int main()
{
    int V,E,s,u,v,w;
    cin >> V >> E >> s;
    vector<vii> adj;
    adj.assign(V+5,vii());
    for(int i=0;i<E;i++){
        cin >> u >> v >> w;
        adj[u].pb(ii(v,w)); 
        adj[v].pb(ii(u,w));
    }
    vi dist(V+5,INF);
    dist[s]=0;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.emplace(ii(0,s));
    while(pq.size()){
        ii fr=pq.top();
        pq.pop();
        int d=fr.first;
        int u=fr.second;
        if(d>dist[u]) continue;
        for(auto j:adj[u]){
            int src=j.first;
            int ww=j.second;
            if(dist[u]+ww<dist[src]){
                dist[src]=dist[u]+ww;
                pq.emplace(ii(dist[src],src));
            }
        }
    }
    for (int i = 0; i < V; i++) // index + 1 for final answer
        printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);
}
