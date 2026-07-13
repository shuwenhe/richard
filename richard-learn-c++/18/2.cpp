#include<bits/stdc++.h>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	int i = a;
	while (i >= b){
	       	int a1,a2,a3,a4;
	       	a1 = i / 1000 % 10;
	       	a2 = i / 100 % 10;
		a3 = i / 10 % 10;
	        a4 = i % 10;
		if(a1 == 7 || a2 == 7 || a3 == 7 || a4 == 7){
		       	cout<<i<<endl;
			i = i - 1;
		}	
	}
	return 0;
}
