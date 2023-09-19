#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	string s;
	cin >> k >> s;
	for(int i = 1;i <= 3 + 2 * k;i++){
		if(i == 1){
			for(int j = 0;j < s.length();j++){
				if(j != 0)
					printf(" ");
				switch(s[j]){
					case '1' :
					case '4' :{
						for(int l = 0;l < 2 + k;l++)	printf(" ");
						break;
					}
					case '2' :
					case '3' :
					case '5' :
					case '6' :
					case '7' :
					case '8' :
					case '9' :
					case '0' :{
						printf(" ");
						for(int l = 0;l < k;l++)	printf("-");
						printf(" ");
						break;
					}
				}
			}
			cout << endl;
		}
		else if(i > 1 && i <= 1 + k){
			for(int j = 0;j < s.length();j++){
				if(j != 0)
					printf(" ");
				switch(s[j]){
					case '1' :
					case '2' :
					case '3' :
					case '7' :{
						for(int l = 0;l < 1 + k;l++)	printf(" ");
						printf("|");
						break;
					}
					case '5':
					case '6':{
						printf("|");
						for(int l = 0;l < 1 + k;l++)	printf(" ");
						break;
					}
					case '4':
					case '8':
					case '9':
					case '0':{
						printf("|");
						for(int l = 0;l < k;l++)	printf(" ");
						printf("|");
						break;
					}
						
				}
				
			}
			printf("\n");
		}
		else if(i == 2 + k){
			for(int j = 0;j < s.length();j++){
				if(j != 0)
					printf(" ");
				switch(s[j]){
					case '1' :
					case '0' :
					case '7' :{
						for(int l = 0;l < 2 + k;l++)	printf(" ");
						break;
					}
					case '2' :
					case '3' :
					case '4' :
					case '5' :
					case '6' :
					case '8' :
					case '9' :{
						printf(" ");
						for(int l = 0;l < k;l++)	printf("-");
						printf(" ");
						break;
					}	
				}
				
			}
			printf("\n");
		}
		else if(i > 2 + k && i < 3 + 2 * k){
			for(int j = 0;j < s.length();j++){
				if(j != 0)
					printf(" ");
				switch(s[j]){
					case '1' :
					case '3' :
					case '7' :
					case '4' :
					case '5' :
					case '9' :{
						for(int l = 0;l < 1 + k;l++)	printf(" ");
						printf("|");
						break;
					}
					case '2' :{
						printf("|");
						for(int l = 0;l < 1 + k;l++)	printf(" ");
						break;
					}
					case '6' :
					case '8' :
					case '0' :{
						printf("|");
						for(int l = 0;l < k;l++)	printf(" ");
						printf("|");
						break;
					}	
				}
				
			}
			printf("\n");
		}
		else{
			for(int j = 0;j < s.length();j++){
				if(j != 0)
					printf(" ");
				switch(s[j]){
					case '1' :
					case '7' :
					case '4' :{
						for(int l = 0;l < 2 + k;l++)	printf(" ");
						break;
					}
					case '2' :
					case '3' :
					case '6' :
					case '8' :
					case '0' :
					case '5' :
					case '9' :{
						printf(" ");
						for(int l = 0;l < k;l++)	printf("-");
						printf(" ");
						break;
					}	
				}
			
			}	
			printf("\n");
		}
	}
	return 0;
} 
