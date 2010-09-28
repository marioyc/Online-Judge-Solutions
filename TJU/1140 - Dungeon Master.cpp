#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

bool visited[30][30][30];
vector< vector < string > > v1;
int x,y,z;

int di[]={-1,1,0,0,0,0};
int dj[]={0,0,-1,1,0,0};
int dk[]={0,0,0,0,-1,1};

struct nodo
{
    
    int a;
    int b;
    int c;
    int costo;
    
    nodo(int x, int y, int z, int w)
    {
        a=x;
        b=y;
        c=z;
        costo=w;
    }
    
};

void bfs(int a,int b, int c)
{
    queue<nodo> Q;
    
    Q.push(nodo(a,b,c,0));
    
    memset(visited,false,sizeof(visited));
    
    visited[a][b][c]=true;
    
    int j,k,l,I,J,K;
    
    while(!Q.empty())
    {
        nodo aux=Q.front();
        Q.pop();
        
        j=aux.a;
        k=aux.b;
        l=aux.c;
        if(v1[l][k][j]=='E')
        {
            printf("Escaped in %d minute(s).\n", aux.costo);//;cout<<"Escaped in "<<aux.costo<<" minute(s)."<<endl;
            return;
        }
        
        for(int i=0;i<6;i++)
        {
            I=j+di[i];
            J=k+dj[i];
            K=l+dk[i];
            if(I>=0 && I<x && J>=0 && J<y && K>=0 && K<z && !visited[I][J][K] && v1[K][J][I]!='#')
            {
                Q.push(nodo(I,J,K,aux.costo + 1));
                visited[I][J][K]=true;
            }
        }
        
    }
    printf("Trapped!\n");
    return;
}

int main(){
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    vector<string> v2;
    string s;
    
    int m,n,p;
    
    while(true)
    {
        scanf("%d %d %d", &z, &y, &x);
        if(x==0 && y==0 && z==0) break;
        
        v1.clear();
        
        for(int i=0;i<z;i++)
        {
            
            v2.clear();
            for(int j=0;j<y;j++)
            {
                cin>>s;
                v2.push_back(s);                
            }
            v1.push_back(v2);
        }
        for(int i=0;i<z;i++)
        {
            for(int j=0;j<y;j++)
            {
                for(int k=0;k<x;k++)
                {
                    if(v1[i][j][k]=='S')
                    {
                        m=k;
                        n=j;
                        p=i;
                        goto xx;
                    }
                }
            }
        }
        
        xx:
        bfs(m,n,p);
        
    }    

    return 0;
}
