#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
        for(int i = 2;i <= n;i++){
		if(n % i == 0){
			bool t = true;
			for(int j = 2;j <= i - 1;j++){
				if(i % j == 0){
					t = false;
					break;
				}
			}
			if(t){
				while(n % i == 0){
					n = n / i;
					cout<<i<<" ";
				}
			}
		}
	}
}
