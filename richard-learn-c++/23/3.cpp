#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,x = 0;
	cin>>n;
	for(;n != 0;n = n / 10){
		x = 10 * x + n % 10;
	}
	cout<<x<<endl;
}
