#include<bits/stdc++.h>

using namespace std;

int main(){
	const int size = 101;
	int n,m,q[size + 1],front = 1,rear = size;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		rear = rear % size + 1;
		q[i] = i;
	}
	int x = 0;
	while(rear % size + 1 != front){
		int y = q[front];
		front = front % size + 1;
		++x;
		if(x == m){
			cout<<y<<" ";
			x = 0;
		}else{
			rear = rear % size + 1;
			q[rear] = y;
		}
	}
}
