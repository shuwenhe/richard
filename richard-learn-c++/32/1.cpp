#include<bits/stdc++.h>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	for(int i = a; i <= b;i++){
		if(i == 1)
			continue;
		bool t = true;
		for(int j = 2;j <= i - 1;j++){
			if(i % j == 0){
				t = false;
				break;
			}
		}
		if(t){
			cout<<i<<endl;
		}
	}
}
