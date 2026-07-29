#include<bits/stdc++.h>

using namespace std;

int main(){
        int a[1001][1001];
        int n,m;
        cin>>m>>n;
        for(int i = 1;i <= m;i++){
                for(int j = 1;j <= n;j++){
                        cin>>a[i][j];
                }
        }
        for(int i = 1;i <= n;i++){
                for(int j = 1;j <= m;j++){
                        cout<<a[j][i]<<" ";
                }
		cout<<endl;
	}
}
