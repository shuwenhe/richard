#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[1001],n;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	int max = 0;
	for(int i = 1;i <= n - 1;i++){
		if(a[i] > a[i + 1]){
			if(a[i] - a[i + 1] > max){
				max = a[i] - a[i + 1];
			}
		}else{
			if(a[i + 1] - a[i] > max){
				max = a[i + 1] - a[i];
			}
		}
	}
	cout<<max<<endl;
}
