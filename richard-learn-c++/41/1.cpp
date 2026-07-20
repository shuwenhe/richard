#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[101],n;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		int minid = i;
		for(int j = i + 1;j <= n;j++){
			if(a[j] < a[minid]){
				minid = j;
			}
			int t = a[i];
			a[i] = a[minid];
			a[minid] = t;
		}
	}
	for(int i = 1;i <= n;i++){
		cout<<a[i]<<" ";
	}
}
