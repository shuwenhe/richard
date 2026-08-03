#include<bits/stdc++.h>

using namespace std;

int a[100],n,l = 0;

int main(){
        cin>>n;
        while(n > 0){
                l++;
                a[l] = n % 16;
                n /= 16;
        }
        for(int i = l;i >= 1;i--){
		if(a[i] >= 10){
			printf("%c",a[i] + 'A' - 10);
		}else{
			cout<<a[i];
		}
        }
        cout<<endl;
}
