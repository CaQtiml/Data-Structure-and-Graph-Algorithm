#include "bits/stdc++.h"
using namespace std;
vector<int> adj[600000];
int deg[600000];

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
		//adj[v].emplace_back(u);
		//deg[u]++;
		deg[v]++;
	}
	queue<int> q;
	for(int i=1;i<=N;i++)
	{
		if(deg[i]==0) q.emplace(i);
	}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto v : adj[u])
		{
			if(deg[v]>0)
			{
				//deg[u]--;
				if(--deg[v]==0)
				{
					q.emplace(v);
				}
			}
		}
	}
	for(int i=1;i<=N;i++)
	{
		cout << deg[i] << "\n";
	}
	//cout << "NO LOOP";
}
//doesn't test with strong testcase