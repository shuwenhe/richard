#include<iostream>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int i = a;
	while(i <= b){
		if(i % 5 == 0 || i % 7 == 0){
			cout<<i<<endl;
		}
		i = i + 1;
	}
}
