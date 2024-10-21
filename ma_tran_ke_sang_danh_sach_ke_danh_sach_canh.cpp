/*Đồ thị vô hướng*/
#include<bits/stdc++.h>
using namespace std;

vector<int> dinh[1001];
vector<pair<int,int>> canh;

int main(){
    int n;cin>>n;
    int a[n][n];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==1){
                dinh[i].push_back(j);
                canh.push_back({i,j});
            }
        }
    }
    for(auto x : canh){
        cout << x.first << " " <<x.second << endl;;
    }
    cout <<endl;
    for(int i=1;i<=n;i++){
        cout << i << ": ";
        sort(dinh[i].begin(),dinh[i].end());
        for(int x:dinh[i]){
            cout << x << " ";
        }
        cout << endl;
    }
	return 0;
}