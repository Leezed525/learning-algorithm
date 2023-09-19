#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int maxmoney = 0,sum = 0;
	string winner;
	for(int i = 0;i < n;i++){
		string name;
		int money = 0;
		int qimo,banji,lunwen;
		char ganbu,xibu;
		cin >> name >>  qimo >> banji >> ganbu >> xibu >> lunwen;
		if(qimo > 80 && lunwen >= 1)
			money += 8000;
		if(qimo > 85 && banji > 80)
			money += 4000;
		if(qimo > 90)
			money += 2000;
		if(xibu == 'Y' && qimo > 85)
			money += 1000;
		if(banji > 80 && ganbu == 'Y')
			money += 850;
		if(money > maxmoney){
			maxmoney = money;
			winner = name;
		}
		sum += money;
	}
	cout << winner << endl << maxmoney << endl << sum<< endl;
	return 0;
} 
