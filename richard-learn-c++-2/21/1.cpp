#include<bits/stdc++.h>

using namespace std;

struct student{
	int yu,shu,ying;
	int tot,id;
}stu[310];

bool cmp(student a,student b){
	if(a.tot != b.tot){
		return a.tot > b.tot;
	}else if(a.yu != b.yu){
		return a.yu > b.yu;
	}else{
		return a.yu < b.yu;
	}
}

int main(){
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>stu[i].yu>>stu[i].shu>>stu[i].ying;
		stu[i].tot = stu[i].yu + stu[i].shu + stu[i].ying;
		stu[i].id = i;
	}
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			if(cmp(stu[j],stu[i])){
				swap(stu[j],stu[i]);
			}
		}
	}
	for(int i = 1;i <= 5;i++){
		cout<<stu[i].id<<" "<<stu[i].tot<<endl;
	}
}
