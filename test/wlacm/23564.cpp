#include <bits/stdc++.h>
using namespace std;

int f;
int G[510][510];//??
int du[510];//????
int start;//???
int minnum=0x3f3f3f3f;
stack<int> ans;
//?????????????,
//?????????,????
//??????????????,????????????

void dfs(int n)//?dfs
{
    for(int i=1;i<=500;i++)
    {
        if(G[n][i])
        {
            G[n][i]--;
            G[i][n]--;
            dfs(i);
        }
    }
    ans.push(n);//?????
}

void find_start()//???
{
    for(int i=1;i<=500;i++)//????
        if(du[i]%2==1)//???????
        {
                start=i;//??
                return;//??
        }
}

int main()
{
    cin>>f;//????
    for(int i=0;i<f;i++)
    {
        int a,b;
        cin>>a>>b;
        G[a][b]++;
        G[b][a]++;
        minnum=min(minnum,min(a,b));
        //?????????????
        //?????????????1
        //????????????
        du[a]++;
        du[b]++;
    }
    find_start();
    if(start==0)
        dfs(minnum);
    else
        dfs(start);

    while(!ans.empty())//??
    {
        cout<<ans.top()<<endl;
        ans.pop();
    }
    return 0;       
}
