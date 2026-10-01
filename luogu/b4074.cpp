#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,a[100000];
	int sum1 = 0,sum2 = 0,sum3 = 0,sum4 = 0;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(a[i] >= 90){
			sum1++;
		}else if(a[i] >= 80 && a[i] < 90){
			sum2++;
		}else if(a[i] >= 60 && a[i] < 80){
			sum3++;
		}else{
			sum4++;
		}
	}
	cout<<sum1<<endl;
	cout<<sum2<<endl;
	cout<<sum3<<endl;
	cout<<sum4<<endl;
}
