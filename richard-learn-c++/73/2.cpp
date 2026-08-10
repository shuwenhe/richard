#include<bits/stdc++.h>

using namespace std;

int h,m,s;

int main(){
	scanf("%d:%d:%d",&h,&m,&s);
	switch(h){
		case 23:
		case 0:
			printf("zi\n");
			break;
		case 1:
		case 2:
			printf("chou\n");
			break;
		case 3:
                case 4:
                        printf("yin\n");
                        break;
		case 5:
                case 6:
                        printf("mao\n");
                        break;
		case 7:
                case 8:
                        printf("chen\n");
                        break;
	        case 9:
                case 10:
                        printf("si\n");
                        break;
		case 11:
                case 12:
                        printf("wu\n");
                        break;
		case 13:
                case 14:
                        printf("wei\n");
                        break;
		case 15:
                case 16:
                        printf("shen\n");
                        break;
		case 17:
                case 18:
                        printf("you\n");
                        break;
		case 19:
                case 20:
                        printf("xv\n");
                        break;
		case 21:
                case 22:
                        printf("hai\n");
                        break;
	}
}
