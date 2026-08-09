#include<bits/stdc++.h>

using namespace std;

int main(){
	int x,n;
	cin>>x>>n;
	if((n - 1 + x) % 7 == 1){
		cout<<"Monday";
	}else if((n - 1 + x) % 7 == 2){
		cout<<"Tuesday";
	}else if((n - 1 + x) % 7 == 3){
		cout<<"Wednesday";
	}else if((n - 1 + x) % 7 == 4){
		cout<<"Thursday";
	}else if((n - 1 + x) % 7 == 5){
		cout<<"Friday";
	}else if((n - 1 + x) % 7 == 6){
		cout<<"Saturday";
	}else if((n - 1 + x) % 7 == 7){
		cout<<"Sunday";
	}
}
