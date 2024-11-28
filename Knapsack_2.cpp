#include<bits/stdc++.h>
using namespace std;

struct item{
	int p;
	int wt;
	
	item(int p,int wt){
		this->p = p;
		this->wt= wt;
	}
};

bool cmp(item a, item b){
	double r1 = (double)a.p / (double)a.wt;
    double r2 = (double)b.p / (double)b.wt;
    return r1 > r2;
}

int knapSack(int W, item a[], int n)
{
	
   sort(a,a+n,cmp);
   double res = 0.0;
   for(int i = 0;i<n;i++){
   		if(a[i].wt<=W){
   			W-=a[i].wt;
   			res+=a[i].p;
		   }
		else{
			res+=a[i].p*((double)W/(double)a[i].wt);
			break;
		}
   }
   return res;
}

int main()
{
    int W = 50;
    item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << knapSack(W, arr, n) << endl;
    return 0;
}
