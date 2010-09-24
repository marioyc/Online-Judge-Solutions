#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    bool M[20][20];
    int t,n,m,a,b;
    
    cin>>t;
    
    for(int caso=0;caso<t;caso++){
        cin>>n>>m;
        
        memset(M,0,sizeof(M));
        
        for(int i=0;i<m;i++){
            cin>>a>>b;
            a--;
            b--;
            M[a][b]=1;
        }
        
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    M[i][j]|=(M[i][k] && M[k][j]);
        
        bool ok=true;
        
        for(int i=0;i<n && ok;i++){
            for(int j=i+1;j<n && ok;j++){
                if(M[i][j] && M[j][i]) ok=false;
            }
        }
        
        if(ok) cout<<1<<endl;
        else cout<<0<<endl;
    }
}
