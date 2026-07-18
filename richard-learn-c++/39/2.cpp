#include<bits/stdc++.h>

using namespace std;

int mian(){
	int n,sum1 = 0,sum2 = 0;
	cin>>n;
	for(int i = 1;i <= n;i++){
		sum1 += i;
	}
	for(int i = 1;i <= n;i++){
		int x;
		cin>>x;
		sum2 += x;
	}
	cout<<sum1 - sum2<<endl;
}
