#include<bits/stdc++.h>

using namespace std;

const int size = 1001;

int m,q[size + 1],front = 1,rear = size;

int main(){
	cin>>m;
	for(int i = 1;i <= m;i++){
		char s[11];
		cin>>s;
		if(s[0] == 'q'){
			int k;
			cin>>k;
			if(size - front + 1 >= k){
				cout<<q[front + k - 1];
			}else{
				cout<<q[k - (size - front + 1)];
			}
		}else if(s[1] == 'u'){
			int x;
			cin>>x;
			rear = rear % size + 1;
		}else{
			front = front % size + 1;
		}
	}
}
