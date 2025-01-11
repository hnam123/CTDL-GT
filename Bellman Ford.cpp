#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
		// gia su khoang cach den cac dinh la INF
       vector<int> d(V,1e8);
       d[src]=0;
       
       for(int i=0;i<V;i++){
           for(auto it : edges){ 
               int u = it[0];
               int v = it[1];
               int w = it[2];
                if(d[u] != 1e8 && d[u]+w < d[v]){  
					// cap nhat lai gia tri cua d[v]
                    d[v] = d[u]+w;
                }
           }
       }
       // sau vong for tren cac trong so duong di van cai thien dc -> co chu trinh am
       for(auto it : edges){ 
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(d[u] != 1e8 && d[u]+w < d[v]){ 
                   return {-1};
            }    
       }
       return d;
};

int main(){
	int V,E;
	cin>>V>>E;
	
	vector<vector<int>> edges;
	
        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }
        
    int s;cin>>s;
	vector<int> res = bellmanFord(V,edges,s);
	
	for (int x:res) {
            cout << x << " ";
        }
	return 0;
}
