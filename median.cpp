#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;cin>>n;
    vector<double> a(n);
    for(int i = 0;i<n;i++){
        cin>> a[i];
    }
    for(int i = 1;i<n;i++){
		double median;
        int size = i;
        if (size % 2 == 0) {
            median = (a[size / 2 - 1] + a[size / 2]) / 2.0;
            cout<< median << endl;
        } else {
            median = a[size / 2];
            cout<< median<< endl;
        }
	}
    return 0;
}
