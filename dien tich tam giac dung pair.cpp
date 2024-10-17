#include <bits/stdc++.h> 
using namespace std; 

int main() {
pair<int,int> p[3];
for(int i=0;i<3;i++){
	cin >> p[i].first >> p[i].second;
}
	cout << 0.5*abs((p[1].first-p[0].first)*(p[2].second- p[0].second)-(p[2].first-p[0].first)*(p[1].second-p[0].second)) << endl;
return 0;
}
