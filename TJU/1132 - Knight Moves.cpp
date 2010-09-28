#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};

struct nodo
{
    int ind1;
    int ind2;
    int costo;
    nodo(int a, int b, int c)
    {
        ind1=a;
        ind2=b;
        costo=c;
    }
};

int dfs(int a, int b, int m, int n)
{
    queue<nodo> Q;
    
    Q.push(nodo(a,b,0));
    
    while(!Q.empty())
    {
        nodo aux=Q.front();
        Q.pop();
        
        if(aux.ind1==m && aux.ind2==n) return aux.costo;
        
        for(int i=0;i<8;i++)
        {
            int I=aux.ind1+dx[i];
            int J=aux.ind2+dy[i];
            if(I>=1 && J>=1 && I<=8 && J<=8)
            Q.push(nodo(I,J,aux.costo+1));
        }
        
    }
    
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string s1,s2;
    int x1,y1,x2,y2;
    while(cin>>s1>>s2)
    {
        x1=s1[0]-'a'+1;
        y1=s1[1]-'0';
        x2=s2[0]-'a'+1;
        y2=s2[1]-'0';

        cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<dfs(x1,y1,x2,y2)<<" knight moves."<<endl;
    }//To get from e2 to e4 takes 2 knight moves.

    return 0;
}
