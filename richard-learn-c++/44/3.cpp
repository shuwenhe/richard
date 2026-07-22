#include<bits/stdc++.h>

using namespace std;

int main(){
	int girl[1001],boy[1001];
	int n,g1 = 0,b1 = 0;
	cin>>n;
	for(int i = 1;i <= n;i++){
		int a,b;
		cin>>a>>b;
		if(b == 0){
			g1++;
			girl[g1] = a;
		}else{
			boy[++b1] = a;
		}
	}
	n = g1;
	for(int i = 1;i <= n;i++){
               for(int j = 1;j <= n - i;j++){
                       if(girl[j] > girl[j + 1]){
                               int t = girl[j];
                               girl[j] = girl[j + 1];
                               girl[j + 1] = t;
                       }
               }--
       }
       n = b1;
       for(int i = 1;i <= n;i++){
              for(int j = 1;j <= n - i;j++){
                      if(boy[j] > boy[j + 1]){
                              int t = boy[j]; 
                              boy[j] = boy[j + 1];
                              boy[j + 1] = t;
		      }
               }
       }
}
