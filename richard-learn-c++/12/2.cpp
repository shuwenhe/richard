#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int hour,minute;
	hour = n / 60;
	minute = n % 60;
	if(hour <= 9){
		cout<<0<<hour;
	}else{
		cout<<hour;
	}
	cout<<":";
	if(minute <= 9){
		cout<<0<<minute;
	}else{
		cout<<minute;
	}
	return 0;
}
