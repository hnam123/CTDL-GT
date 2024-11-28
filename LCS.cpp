#include<bits/stdc++.h>
using namespace std;

int main(){
	string A,B;
	cin >> A >> B;
	
	int n = A.size();
	int m = B.size();
	
	int a[n+1][m+1];
	memset(a,0,sizeof(a));
	
	for(int i = 1; i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(A[i]==B[j]){
				a[i][j]=a[i-1][j-1] + 1;
			}
			if(A[i]!=B[j]){
				a[i][j]=max(a[i-1][j],a[i][j-1]);
			}
		}
	}
	
	cout << a[n][m] << endl;
	string ans = "";
	
	while(n&&m){
		if(A[n-1]==B[m-1]){
			ans += A[n-1];
			n--;m--;
		}
		else{
			if(a[n][m-1] <= a[n-1][m]){
				n--;
			}
			else{
				m--;	
			}
		}
	}
	
	for(int i = 0;i<sizeof(ans);i++){
		cout << ans[i];
	}
	return 0;
}
