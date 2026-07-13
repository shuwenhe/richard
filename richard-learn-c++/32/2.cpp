#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	bool t = false;
	while(n != 0){
		if(n % 10 == 7){
			t = true;
			break;
		}
		n = n / 10;
	}
	if(t){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}
