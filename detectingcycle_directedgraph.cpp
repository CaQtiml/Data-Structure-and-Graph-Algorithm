#include "bits/stdc++.h"
using namespace std;
vector<int> adj[600000];
bool visit[600000];
void dfs(int u)
{
	for(auto v : adj[u])
	{
		if(visit[v]) 
		{
			cout << "LOOP";
			exit(0);
		}
		visit[v]=1;
		dfs(v);
		visit[v]=0;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M;
	cin >> N >> M;
	for(int i=1;i<=M;i++)
	{
		int u,v;
		cin >> u >> v ;
		adj[u].emplace_back(v);
	}
	
	for(int i=1;i<=N;i++)
	{
		visit[i]=1;
		dfs(i);
		visit[i]=0;
	}
	cout << "NO LOOP";
}
//doesn't test with strong testcase