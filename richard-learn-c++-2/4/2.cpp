#include<bits/stdc++.h>

using namespace std;

int n,a1,a2,a3,b1,b2,b3;

int calc(int x,int y){
	int z = n / x;
	if(n % x != 0){
		++z;
	}
	return z * y;
}

int main(){
	cin>>n;
	cin>>a1>>b1;
	cin>>a2>>b2;
	cin>>a3>>b3;
	int x1 = calc(a1,b1);
	int x2 = calc(a2,b2);
	int x3 = calc(a3,b3);
	printf("%d\n",min(min(x1,x2),x3));
}
