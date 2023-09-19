#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s,s1;
	int flag = 0;
	while(cin >> s1){
		for(int i = 0;i < s1.length();i++){
			if(s1[i] != 'E')
				s += s1[i];
			else {
				flag = 1;
				break;
			}	
		}
		if(flag)
			break;
	}	
	int ascore = 0,bscore = 0;
	for(int i = 0;i < s.length();i++){
		if(s[i] == 'W')
			ascore++;
		else 
			bscore++;
		if(max(ascore,bscore) >= 11 && max(ascore,bscore) - min(ascore,bscore) >= 2){
			printf("%d:%d\n",ascore,bscore);
			ascore = 0,bscore = 0;
		}
			
	}
	printf("%d:%d\n\n",ascore,bscore);
	ascore = 0,bscore = 0;
	for(int i = 0;i < s.length();i++){
		if(s[i] == 'W')
			ascore++;
		else 
			bscore++;
		if(max(ascore,bscore) >= 21 && max(ascore,bscore) - min(ascore,bscore) >= 2){
			printf("%d:%d\n",ascore,bscore);
			ascore = 0,bscore = 0;
		}	
	}
	printf("%d:%d\n",ascore,bscore);
	return 0;
}
