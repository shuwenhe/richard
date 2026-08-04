#include<bits/stdc++.h>

using namespace std;

int main(){
	int a[110],n,l = 0;
	scanf("%d",&n);
	while(n > 0){
		l++;
		a[l] = n % 8;
		n /= 8;
	}
	for(int i = l;i >= 1;i--){
		printf("%d",a[i]);
	}
}
