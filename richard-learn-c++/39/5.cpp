#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,ma = 1,l = 1,a[1001];
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 2;i <= n;i++){
		if(a[i] == a[i - 1]){
			l++;
		}else{
			l = 1;
		}
		if(l > ma){
			ma = l;
		}
	}
	cout<<ma<<endl;
}
