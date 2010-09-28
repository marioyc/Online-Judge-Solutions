#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int n;
int di[]={0,1,0,-1};
int dj[]={1,0,-1,0};
int M[99][99];
int visited[99][99];
bool ok;

int dfs(int x, int y)
{
    if(visited[x][y]) return 0;
    int ax=1;
    int I,J;
    visited[x][y]=true;
    for(int i=0;i<4;i++){
        I=x+di[i];
        J=y+dj[i];
        if(I>=0&&I<n&&J>=0&&J<n&&M[x][y]==M[I][J]) ax+=dfs(I,J);
    }
    return ax;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int x,y;
    string s;
    while(true){
        cin>>n;
        if(n==0) break;
        
        memset(M,0,sizeof(M));
        memset(visited,false,sizeof(visited));
        
        getline(cin,s);
        for(int i=0;i<n-1;i++){
            getline(cin,s);
            istringstream is(s);
            while(is>>x>>y) M[x-1][y-1]=i+1;
        }
        
        ok=true;
        
        for(int i=0;i<n && ok;i++){
            for(int j=0;j<n && ok;j++){
                if(!visited[i][j] && dfs(i,j)!=n) ok=false;
            }
        }
        if(ok) cout<<"good"<<endl;
        else cout<<"wrong"<<endl;
    }

    return 0;
}
