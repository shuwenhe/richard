#include<bits/stdc++.h>

using namespace std;

int main(){
        int a[1001],n,max = 0,times = 0;
        cin>>n;
        for(int i = 1;i <= n;i++){
                cin>>a[i];
        }
        for(int i = 1;i <= n - 2;i++){
                times = a[i] * a[i + 1] * a[i + 2];
                if(times > max){
                        max = times;
                }
        }
        cout<<max<<endl;
}
