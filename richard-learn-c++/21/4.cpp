#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int x;
	int sum = 0;
	for(int i = 1;i <= n;i++){
		cin>>x;
		sum = sum + x;
	}
	cout<<sum<<endl;
}
