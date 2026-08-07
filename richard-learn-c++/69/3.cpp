#include<bits/stdc++.h>

using namespace std;

int a,b;

bool isprime(int x){
	for(int i = 2;i <= x - 1;i++){
		if(x % i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	cin>>a>>b;
	for(int i = a;i <= b;i++){
		if(isprime(i)){
			cout<<i<<endl;
		}
	}
}
