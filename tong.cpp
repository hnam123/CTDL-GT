#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n; cin>>n;
    long long a[n],tmp;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
    }
    for(int i=0;i<n;i++){
       cout << a[i]<< ' ';
    }

    return 0;
}
