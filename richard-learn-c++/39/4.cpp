#include<bits/stdc++.h>

using namespace std;

int main(){
        int a[1001],n;
        cin>>n;
        for(int i = 1;i <= n;i++){
                cin>>a[i];
        }
        bool flag = true;
        for(int i = 1;i <= n / 2;i++){
		if(a[i] != a[n + 1 - i]){
			flag = false;
			break; 
		}
        }
        if(flag == true){
                cout<<1;
        }else{
                cout<<0;
        }
}

