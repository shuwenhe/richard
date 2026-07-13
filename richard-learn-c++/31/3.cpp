#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,sum = 0;
	cin>>n;      
	for(int i = 0;i <= n / 10;i++){
		for(int j = 0; j <= n / 5; j++){
			for(int k = 0;k <= n;k++){
				if(10 * i + 5 * j + k == n){
					sum++;
				}
			}
		}
	}
	cout<<sum<<endl;
}
//       例:cin>>13;
//       |10| 5 |1 |
//       ===========
//       |0 | 0 |13|
//       ===========
//       |0 | 1 |8 |
//       ===========
//       |0 | 2 |3 |
//       ===========
//       |1 | 0 |3 |
//       cout<<5;


