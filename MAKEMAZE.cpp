#include<cstdio>
#include<cstring>
#define MAXLEN 25
using namespace std;

char arr[MAXLEN][MAXLEN];
int er,ec,row,col;
int rr[]={-1,1,0,0},cc[]={0,0,1,-1};
bool visited[MAXLEN][MAXLEN];
bool exit;

bool find_res(int x,int y)
{
    if((x==row-1 || y==col-1 || x==0 || y==0) && arr[x][y]=='.' && (x!=er || y!=ec))
    {
        if(!exit)
        {
            exit=true;
        }
        else
            return false;
    }

    visited[x][y] = true;

    int i,j,r,c;

    for(i=0;i<4;i++)
    {
        r = x+rr[i];
        c = y+cc[i];
        if(arr[r][c]=='#')
            continue;

        if(!visited[r][c] && r>=0 && r<row && c>=0 && c<col)
        {
            if(!find_res(r,c))
                return false;
        }
    }
    return true;
}

int main()
{
    int t,i,j,count=0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&row,&col);
        for(i=0;i<row;i++)
        {
            scanf("%s",arr[i]);
        }


        ec=er=-1;

        for(j=0;j<col;j++)
        {
            if(arr[0][j]=='.')
            {
                ec = j;
                er = 0;
                break;
            }
            else if(arr[row-1][j]=='.')
            {
                er = row-1;
                ec = j;
                break;
            }
        }
        if(ec==-1)
        {
            for(i=0;i<row;i++)
            {
                if(arr[i][0]=='.')
                {
                    er = i;
                    ec = 0;
                    break;
                }
                else if(arr[i][col-1]=='.')
                {
                    er = i;
                    ec = col-1;
                    break;
                }
            }
        }

        count=0;
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(i==0 || i==row-1 || j==0 || j==col-1)
                {
                    if(arr[i][j]=='.')
                        count++;
                }
            }
        }

        if((er==-1 && ec==-1) || count!=2)
        {
            printf("invalid\n");
            continue;
        }
        memset(visited,false,sizeof(visited));
        exit = false;
        if(find_res(er,ec) && exit)
            printf("valid\n");
        else
            printf("invalid\n");
    }
    return 0;
}
