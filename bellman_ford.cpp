#include "bits/stdc++.h"
using namespace std;
const int INF = 1e9+29;
#define ii pair<int,int>
vector<ii> adj[200000];
#define f first
#define s second
int main()
{
	int n,m,st=1;
	cin >> n >> m ;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v,w);
	}
	vector<int> dist(n+5,INF);
	dist[st]=0;
	for(int rob=1;rob<=n-1;rob++)
	{
		for(int i=0;i<n;i++)
		{
			for(auto j : adj[i])
			{
				dist[j.f]=min(dist[j.f],dist[i]+j.s);
			}
		}
	}
	//for(int i=2;i<=n;i++) cout << dist[i] << " ";
	bool negcycle=false;
	for(int i=0;i<n;i++)
	{
		for(auto j : adj[i])
		{
			if(dist[j.f]>dist[i]+j.s) negcycle = true;
		}
	}
	if(negcycle) cout << "1";
	else cout << "0";
}