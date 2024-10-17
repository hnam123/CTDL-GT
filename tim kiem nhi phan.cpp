#include<iostream>
using namespace std;

void Arr_in(int a[],int n){
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
}
int timkiem(int a[],int n, int b){
	int Low = 0;
	int High = n-1;
	while (Low<High){
		int Mid = (Low+High)/2;
		if(a[Mid] == b){
			return 1;
		}
		else if(a[Mid]<b){
			Low = Mid+1;
		}	
		else{
			High = Mid - 1;
		}
	}
	return 0;
}
int main(){
	int n;cin>>n;
	int a[n];
	Arr_in(a,n);
	int b;cin>>b;
	if(timkiem(a,n,b)==1){
		cout << "True";
	}
	else {
		cout<"false";
	}
	return 0;
}
