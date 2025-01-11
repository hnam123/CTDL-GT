#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  	const int INF = 1e9;
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        vector<int> d(10000,INF);
        d[src]=0;
    	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > Q;
    	Q.push({0,src});
	while(!Q.empty()){
		pair<int,int> top = Q.top();
		Q.pop();
		int u = top.second;
		int kc = top.first;
		if(kc > d[u]) continue;
		for(auto it:adj[u]){
			int v =it.first;
			int w = it.second;
			if(d[v]>d[u]+w){
				d[v]=d[u]+w;
				Q.push({d[v],v});
			}
		}
	}
	    return d;
    }
};
int main(){
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
		int src;
        cin >> src;
        
        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);
        
        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
