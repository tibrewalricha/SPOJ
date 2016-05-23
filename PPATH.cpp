#include<cstdio>
#include<string>
#include<vector>
#include<sstream>
#include<queue>
#include<iostream>
#include<cstring>
#include<utility>
#include<climits>
#define min(a,b) (a<b?a:b)
#define MAXLEN 10000
using namespace std;

vector<string> prime;
vector<vector<int> > graph;

void find_prime()
{
    int p[MAXLEN],i,j;
    for(i=0;i<MAXLEN;i++)
        p[i] = 1;
    for(i=2;i*i<MAXLEN;i++)
    {
        if(p[i])
        {
            for(j=i*i;j<MAXLEN;j+=i)
                p[j]=0;
        }
    }

    for(i=1000;i<=9999;i++)
    {
        if(p[i]==0)
            continue;
        stringstream ss;
        ss<<i;
        prime.push_back(ss.str());
    }
}

void make_graph()
{
    string s1,s2;
    int i,len = prime.size(),j,k,x;

    for(i=0;i<len;i++)
    {
        vector<int> r;
        graph.push_back(r);
    }

    for(i=0;i<len;i++)
    {
        s1 = prime[i];
        for(j=i+1;j<len;j++)
        {
            s2 = prime[j];
            x=0;
            for(k=0;k<4;k++)
            {
                if(s1[k]!=s2[k])
                    x++;
            }
            if(x==1)
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
}

int bfs(int s,int e)
{
    queue<pair<int,int> >q;
    bool visited[prime.size()];
    memset(visited,false,sizeof(visited));

    q.push(make_pair(s,0));
    visited[s] = true;

    int i,x,step,u;

    while(!q.empty())
    {
        x = q.front().first;
        step = q.front().second;
        q.pop();
        if(x==e)
            return step;

        //cout<<prime[x]<<" "<<step<<endl;
        visited[x] = true;
        for(i=0;i<graph[x].size();i++)
        {
            u = graph[x][i];
            if(!visited[u])
            {
                visited[u] = true;
                q.push(make_pair(u,step+1));
            }
        }
    }
    return -1;
}

int main()
{
    int s,e,i,j,t,res;
    string start,end1;

    find_prime();
    make_graph();

    scanf("%d",&t);
    while(t--)
    {
        cin>>start>>end1;
        for(i=0;i<prime.size();i++)
        {
            if(prime[i].compare(start)==0)
                s = i;
            if(prime[i].compare(end1)==0)
                e = i;
        }

        res = bfs(s,e);
        if(res==-1)
            printf("Impossible\n");
        else
            printf("%d\n",res);
    }
    return 0;
}
