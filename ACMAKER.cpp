#include<cstdio>
#include<sstream>
#include<cstring>
#include<string>
#include<iostream>
#define MAXLEN 200
using namespace std;

int main()
{
    char s[MAXLEN];
    string st[MAXLEN],acr="",insig[MAXLEN];

    int i=0,j=0,in,n,k;

    scanf("%d",&n);
    for(i=0;i<n;i++)
        cin>>insig[i];

    getchar();
    fgets(s,MAXLEN,stdin);
    i=0;
    while(i<strlen(s)-1)
    {
        st[j] = "";
        while(s[i]!=' ' && s[i]!='\n')
        {
            st[j]+=s[i];
            i++;
        }
        i++;
        if(j==0 && acr.length()==0)
        {
            acr = st[j];
            j=0;
        }
        else
        {
            bool c=false;
            for(k=0;k<n;k++)
            {
                if(st[j].compare(insig[k])==0)
                {
                    c=true;
                    break;
                }
            }
            if(!c)
                j++;
        }
    }

    return 0;
}
