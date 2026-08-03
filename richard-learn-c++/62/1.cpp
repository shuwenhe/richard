#include<bits/stdc++.h>

using namespace std;

int a[100],n,l = 0;

int main(){
	cin>>n;
	while(n > 0){
		l++;
		a[l] = n % 2;
		n /= 2;
	}
	for(int i = l;i >= 1;i--){
		cout<<a[i];
	}
	cout<<endl;
}
