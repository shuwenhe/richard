#include<bits/stdc++.h>

using namespace std;

int main(){
        long long a,b;
        cin>>a>>b;
        long long c = 1;
        if(a == 1){
                cout<<1<<endl;
                return 0;
        }
        for(int i = 1;i <= b;i++){
                if(c > 1e9 / a){  
                        cout<<-1<<endl;
                        return 0;
                }
                c *= a;
        }
        cout<<c<<endl;
}

