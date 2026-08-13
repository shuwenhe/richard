#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[11],h;
	for(int i = 1;i <= 10;i++){
		cin>>a[i];
	}
	cin>>h;
	int x = 0;
	for(int i = 1;i <= 10;i++){
		if(a[i] <= h + 30){
			x++;
		}
	}
	cout<<x<<endl;
}
