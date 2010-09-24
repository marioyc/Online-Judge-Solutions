#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int M[100][100];
bool visited[100][100];
int n;
int vi[]={-1,1,0,0};
int vj[]={0,0,1,-1};

int dfs(int a,int b)
{
    visited[a][b]=1;
    
    int I,J;
    int cont=1;
    
    for(int i=0;i<4;i++)
    {
        I=a+vi[i];
        J=b+vj[i];
        
        if(!(I>=0 && J>=0 && I<n && J<n)) continue;
        if(M[a][b]==M[I][J] && !visited[I][J]) cont+=dfs(I,J);
        
    }
    
    return cont;
}

int main(){
    
    bool ok;
    
    while(cin>>n)
    {
        if(n==0) break;
        
        string aux;
        getline(cin,aux);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                M[i][j]=n;
                
        for(int i=1;i<n;i++) 
        {
            string s;
            getline(cin,s);
            stringstream is(s);
            int x, y;
            while(is>>x>>y)
            {
                M[x-1][y-1] = i;
            }
        }
        
        memset(visited,0,sizeof(visited));
        
        ok=true;
        
        for(int i=0;i<n && ok;i++)
        {
            for(int j=0;j<n && ok ;j++)
            {
                if(!visited[i][j])
                {
                    if(dfs(i,j)!=n) ok=false;
                }
            }
        }
        
        if(ok) cout<<"good"<<endl;
        else cout<<"wrong"<<endl;
        
    }

    return 0;
}
