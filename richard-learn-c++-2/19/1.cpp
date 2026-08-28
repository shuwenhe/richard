#include<bits/stdc++.h>

using namespace std;

struct Node{
	int s;
	Node *next;
}*head,a[81];

int n;

int main(){
	cin>>n;
	head = NULL;
	for(int i = 1;i <= n;i++){
		cin>>a[i].s;
		if(head == NULL){
			head = &a[i];
		}else{
			if(a[i].s < head -> s){
				a[i].next = head;
				head = &a[i];
			}else{
				Node *p = head;
				for(Node *v = head;v ;v = v -> next){
					if(a[i].s > v -> s){
						p = v;
					}else{
						break;
					}
				}
				a[i].next = p -> next;
				p -> next = &a[i];
			}
		}
	}
	for(Node *v = head;v;v = v -> next){
		cout<<v -> s<<"  ";
	}
	cout<<endl;
}
