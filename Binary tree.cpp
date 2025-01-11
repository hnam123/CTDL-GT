#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<int>Child[n];
	for(int i = 1;i<n;i++){
		int x,y;
		cin>>x>>y;
		Child[x].push_back(y);
	}
	
	bool is_binary_tree = true;
    for(int i = 0;i<n;i++){
    	if( Child[i].size()>2){
    		is_binary_tree = false;
            break;
		}
	}
	
    if (is_binary_tree){
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
	return 0;
}

