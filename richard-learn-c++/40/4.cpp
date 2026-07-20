#include<bits/stdc++.h>

using namespace std;

int a[100001]; 
int n,l = 1;

int main(){
	int max = 1;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 2;i <= n;i++){
		if(a[i] > a[i - 1]){
			l++;
		}else{
			l = 1;
		}
		if(l > max){
			max = l;
		}
	}
	cout<<max<<endl;
}
