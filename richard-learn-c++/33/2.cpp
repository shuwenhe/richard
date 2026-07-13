#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,max = 0,a,b,c;
	cin>>n;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			for(int k = 1;k <= n;k++){
				if(i + j + k == n && i * j * k > max){
					max = i * j * k;
					a = i;
					b = j;
					c = k;
				}
			}
		}
	}
	cout<<a<<" "<<b<<" "<<c<<" "<<endl;
}
