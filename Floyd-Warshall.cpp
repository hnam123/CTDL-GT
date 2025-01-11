#include <bits/stdc++.h>
using namespace std;

void Floyd(vector<vector<int>>&dist){
		int n = dist.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][j] == -1) {
					dist[i][j] = 1e9;
				}
				if (i == j) dist[i][j] = 0;
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][j] == 1e9) {
					dist[i][j] = -1;
				}
			}
		}
	}



int main() {
	int V,E;
	cin>>V>>E;
	vector<vector<int>> dist(V, vector<int>(V, -1));
	for(int i = 0;i<V;i++){
		for(int j = 0;j<V;j++){
			dist[i][j]=1e9;
			if (i == j) {
			dist[i][j] = 0;
			}
		}
	}
	for(int i = 0;i<V;i++){
		int x,y,w;cin>>x>>y>>w;
		dist[x][y] = w;
	}
	Floyd(dist);
	for (auto row : dist) {
		for (auto cell : row) {
			cout << cell << " ";
		}
		cout << endl;
	}
	return 0;
}

