#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a = n / 100;
	int b = n / 10 % 10;
	int c = n % 10;
	int sum = 0;
	for(int i = 1;i <= 3;i++){
		if(a % 2 != 0 || b % 2 != 0 || c % 2 != 0){
			sum++;
		}
        }
	if(sum >= 2){
		cout<<"Odd";
	}else{
		cout<<"Even";
	}
}
