#include<bits/stdc++.h>

using namespace std;

int main(){
	int t[101],n;
	cin>>n;
	for(int i = 0;i <= 100;i++){
		t[i] = 0;          
	}
	for(int i = 1;i <= n;i++){
		int x;
		cin>>x;
		t[x]++;
	}
	int ma = 0;
	for(int i = 0;i <= 100;i++){
		if(t[i] > ma){
			ma = t[i];
		}
	}
	for(int i = 0;i <= 100;i++){
		if(t[i] == ma){
			cout<<i<<" ";   
		}
	}
}
