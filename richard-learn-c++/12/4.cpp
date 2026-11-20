#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin>>n;
	m = n % 3;
	if(m == 2){
		cout<<n + 1<<endl;
		return 0;
	}
	cout<<n - m<<endl;
}
