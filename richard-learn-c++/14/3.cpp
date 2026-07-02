#include<bits/stdc++.h>

using namespace std;

int main(){
	int a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1 < a2){
		if(b1 < a2){
			cout<<0;
		}else if(b2 < b1){
			cout<<b2 - a2<<endl;
		}else{
			cout<<b1 - a2<<endl;
		}
	}else{
		if(b2 < a1){
			cout<<0;
		}else if(b2 < b1){
			cout<<b2 - a1<<endl;
		}else{
			cout<<b1 - a1<<endl;
		}
	}
	return 0;

}
