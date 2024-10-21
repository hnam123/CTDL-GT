#include<bits/stdc++.h>
using namespace std;

vector <int> ke[1001];

int main(){
    int n,m;
    cin>>n>>m;
    int a[n][n];
    for(int i = 1 ;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=0;
        }
    }
    for(int i = 0;i<m;i++){
        int x,y;
        cin>>x>>y;
        a[x][y]=a[y][x]=1;
    }
    for(int i = 1 ;i<=n;i++){
        for(int j = 1;j<=n;j++){
           cout << a[i][j] <<" ";
        }
        cout <<endl;
    }
    return 0;
}