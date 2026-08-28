#include<bits/stdc++.h>

using namespace std;

struct Node{
	int v;
	Node *next;
}*head,*tail,a[100001];

int n;

int main(){
	cin>>n;
	head = tail = NULL;
	for(int i = 1;i <= n;i++){
		cin>>a[i].v;
		if(head == NULL){
			head = tail = &a[i];
		}else{
			tail -> next = &a[i];
			tail = &a[i];
		}
	}
	Node *p1 = head,*p2 = head -> next;
	while(p2 != tail){
		p1 = p1 -> next;
		p2 = p2 -> next -> next;
	}
	cout<<p1 -> v<<endl;
}
