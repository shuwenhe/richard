#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,x;
	cin>>n;
	int mx = 0,mi = 1000000000;
	for(int i = 1;i <= n;i++){
		cin>>x;
		if(x > mx){
			mx = x;
		}
		if(x < mi){
			mi = x;
		}
	}
	cout<<mx<<" "<<mi<<endl;
}
