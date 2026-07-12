#include<iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int m = n / 2;
	for(int i = 1;i <= m + 1;i++){
		for(int j = 1;j <= m + 1 - i;j++){
			cout<<" ";
		}
		for(int j = 1;j <= 2 * i - 1;j++ ){
			cout<<"+";
		}
		cout<<endl;
	}
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= i;j++){
			cout<<" ";
		}
		for(int j = 1;j <= 2 * (m - i) + 1;j++){
			cout<<"+";
		}
		cout<<endl;
	}
	
}
