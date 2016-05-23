#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<utility>
#include<queue>
#define MAXLEN 10
using namespace std;

int row=8, col=8;
int xx[]={-1,-2,-2,-1, 1, 2,2,1};
int yy[]={-2,-1, 1, 2,-2,-1,1,2};

int find_res(int sr,int sc,int tr,int tc)
{
    queue<pair<pair<int,int>,int> > q;
    q.push(make_pair(make_pair(sr,sc),0));

    int step,m,n,mm,nn,i,j,r,c;
    bool visited[MAXLEN][MAXLEN];

    memset(visited,false,sizeof(visited));
    visited[sr][sc] = true;
    int arr[MAXLEN][MAXLEN];
    arr[sr][sc] = 0;
    int res;

    while(!q.empty())
    {
        r = q.front().first.first;
        c = q.front().first.second;
        step = q.front().second;
        q.pop();
       // printf("%d %d %d\n",r,c,step);
        if(r==tr && c==tc)
        {
            res = step;
            break;
        }

        for(i=0;i<8;i++)
        {
            m = r+xx[i];
            n = c+yy[i];

            if(m>=0 && m<row && n>=0 && n<col)
            {
                if(!visited[m][n])
                {
                    visited[m][n] = true;
                    q.push(make_pair(make_pair(m,n),step+1));
                    arr[m][n] = step+1;
                }
            }
        }
    }
    return arr[tr][tc];
}

int main()
{
    int sr,sc,tr,tc,t;
    char r1[2],r2[2];

    scanf("%d",&t);
    while(t--)
    {
       // printf("Start\n");
        scanf("%s%s",r1,r2);
       // printf("Done\n");
        sr = row - (r1[1]-'0');
        sc = r1[0]-'a';
        tr = row - (r2[1]-'0');
        tc = r2[0]-'a';
        //printf("%d %d %d %d\n",sr,sc,tr,tc);
        printf("%d\n",find_res(sr,sc,tr,tc));
    }
    return 0;
}
