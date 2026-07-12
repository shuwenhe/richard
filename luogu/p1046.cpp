#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[10];
	int h;
	cin>>h;
	h = h + 30;
	int sum = 0;
	for(int i = 0;i <= 9;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= 10;i++){
		if(a[i] >= h){
			sum++;
		}
	}
	cout<<sum<<endl;
}
