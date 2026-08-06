#include<bits/stdc++.h>

using namespace std;

int n,cnt = 0;

void f2();

void f1(){
	cnt++;
	printf("function 1:%d\n",cnt);
	if(cnt < n){
		f2();
	}
}

void f2(){
	cnt++;
	printf("function 2:%d\n",cnt);
	if(cnt < n){
		f1();
	}
}

int main(){
	cin>>n;
	f1();
	return 0;
}
