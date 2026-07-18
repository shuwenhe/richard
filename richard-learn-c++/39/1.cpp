#include<bits/stdc++.h>

using namespace std;

int main(){
	bool t[1001];
	int n;
	for(int i = 0;i <= 1000;i++){
		t[i] = false;
	}
	cin>>n;
	for(int i = 1;i <= n - 1;i++){
		int x;
		cin>>x;
		t[x] = true;
	}
	for(int i = 1;i <= n;i++){
		if(t[i] == false){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
