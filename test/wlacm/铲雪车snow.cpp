#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while(n--){
		long long int x,y;
	    cin>>x>>y;
	    long long int x1,y1,x2,y2;
	    double sum=0;
	    while(cin>>x1>>y1>>x2>>y2){
	        sum+=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	    }
	    double ans=sum*2/1000/20;
	    long long int h=(int)(ans);
	    long long int f=(int)((ans-h)*60+0.5);
	    printf("%lld:%02lld\n",h,f);
	}  
    return 0;
}
