#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[100001],n,max = 0;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= 3;i++){
		max = i;
		for(int j = i + 1;j <= n;j++){
			if(a[j] > a[max]){
				max = j;
			}
		}
		t = a[i];
		a[i] = a[max];
		a[max] = t;
	}
	cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
}
