#include<iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a,b;
	a = n/10;
	b = n%10;
	if(a == 7){
		cout<<"Yes"<<endl;
	}else if(b == 7){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}
