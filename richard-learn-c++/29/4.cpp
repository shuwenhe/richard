#include<bits/stdc++.h>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int t = 1;
	for(int i = 1;i <= a;i++){
		for(int j = 1;j <= b;j++){
			cout<<t<<" ";
			t++;
		}
		cout<<endl;
	}
}
