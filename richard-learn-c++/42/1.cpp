#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[50001],n;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= 3;i++){
		int max = i;
		for(int j = i + 1;j <= n;j++){
			if(a[j] > a[max]){
				max = j;
			}
		}
		int t = a[i];
		a[i] = a[max];
		a[max] = t;
	}
	cout<<a[3]<<endl;
}
