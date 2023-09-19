/*
数位dp，保留余数是为了能与高位数一起确定是否能被13整除，记录是否含13是为了确定在前面不含13的情况下
能否直接累加数据，前两项含义和一般数位dp相同，i位数首位为t的记录。 
*/
#include <iostream>
#include <cstring>
#include <string>
 
using namespace std;
 
int dp[12][12][2][15];
 
int main()
{
    memset(dp,0,sizeof(dp));
    int q=10;
    for (int i=0;i<=9;i++)
        dp[1][i][0][i]=1;
    for (int i=2;i<=10;i++)
    {
        for (int t=0;t<=9;t++)
        {
            for (int k=0;k<=9;k++)
            {
                int s=(t*q)%13;
                for (int j=0;j<=12;j++)
                {
                    dp[i][t][1][j]+=dp[i-1][k][1][(13-s+j)%13];                  
                    if (t==1&&k==3)
                        dp[i][t][1][j]+=dp[i-1][k][0][(13-s+j)%13];
                    else
                        dp[i][t][0][j]+=dp[i-1][k][0][(13-s+j)%13];
                }
            }
        }
        q=q*10;
    } 
    int a;
    while (cin>>a)
    {
        int sum=0;
        a=a+1;
        string s;
        int r=1;
        while (a>0)
        {
            int t=a%10;
            char a1=t+48;
            s=a1+s;
            a=a/10;
            if (a>0)
                r=r*10;
        }
        int l=s.length()-1;
        int m=0;
        int p=0;
        for (int i=0;i<=l;i++)
        {
            int c=s[i]-48;
            int f=m%13;
            for (int t=0;t<c;t++)
            {
                sum+=dp[l-i+1][t][1][(13-f)%13];
                if ((m/r+t)%100==13||p==1)
                    sum+=dp[l-i+1][t][0][(13-f)%13];
            }
            m=m+c*r;
            if ((m/r)%100==13)
                p=1;
            r=r/10;
        }
        cout<<sum<<endl;
    }
    return 0;
}