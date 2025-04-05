#include<iostream>

using namespace std;

void welcome(){
	cout<<"请输入您的大名！"<<endl;
        string name;
        cin>>name;
        cout<<"Hello"<<' '<<name<<endl;
}

void operation(){
	cout<<"开始计算..."<<endl;
	cout<<"计算两数加减乘除请按1  计算连加请按2";
	char z;
	cin>>z;
	if(z=='1'){
	double a,b;
	char c;
        cin>>a>>c>>b;
	  if(c == '+'){
		  cout<<a+b<<endl;
	  }else if(c == '-'){
		  cout<<a-b<<endl;
	  }else if(c == '*'){
		  cout<<a*b<<endl;
 	  }else if(c == '/'){
	 	  cout<<a/b<<endl;
	  }
	}else if(z == '2'){
		cout<<"请输出两个数，分别表示从几加到几"<<endl<<endl;
		int x;
		int y;
		int sum = 0;
		cin>>x>>y;
		for(int i = x;i <= y;i++){
			sum+=i;
		}
		cout<<x<<"加到"<<y<<"的和是"<<sum<<endl<<endl;
	}
	  
} 

int main(){
	cout<<"Hello World!"<<endl<<endl;
	printf("hello,richad i like my daddy mammy brother and coding\n");
	cout<<endl;
	printf("i like ai robot\n");
	cout<<endl;
	printf("I want to own a rocket\n");
	cout<<endl;
	printf("我想拥有一艘火箭\n");
	cout<<endl;
	cout<<"打招呼程序请按1  计算程序请按2"<<endl;
	string a;
	cin>>a;
	if(a == "1"){	
	   welcome();
	}else if(a == "2"){
		cout<<"进入计算逻辑"<<endl;
	   operation();
	}
	return 0;
}
