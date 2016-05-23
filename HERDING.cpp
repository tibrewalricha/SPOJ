#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#define MAXLEN 1010
using namespace std;

char arr[MAXLEN][MAXLEN];
int visited[MAXLEN][MAXLEN];
int row,col,count=0,res=0;

void bfs(int x,int y)
{
    if(x<0 || x>=row || y<0 || y>=col)
        return;

    if(visited[x][y]==-1)
    {
        visited[x][y] = count;
        switch(arr[x][y])
        {
            case 'E' : bfs(x,y+1);
                        break;
            case 'W' : bfs(x,y-1);
                        break;
            case 'N' : bfs(x-1,y);
                        break;
            case 'S' : bfs(x+1,y);
                        break;
        }
        visited[x][y] = count;
    }
    else
    {
        count = visited[x][y];
        return;
    }
}

int main()
{
    int r,c,i,j;

    scanf("%d%d",&r,&c);
    for(i=0;i<r;i++)
        scanf("%s",arr[i]);

    row = r;
    col = c;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            visited[i][j]=-1;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(visited[i][j]==-1)
            {
                count = res+1;
                bfs(i,j);
                if(count>res)
                    res++;
            }
        }
    }
    printf("%d\n",res);
    return 0;
}
