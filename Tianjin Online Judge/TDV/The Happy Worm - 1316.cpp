#include <iostream>

using namespace std;

bool M[10000][10000];

int main(){
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int t,n,m,k,ax,cont;
    
    cin>>t;
    
    for(int i=0;i<t;i++){
        cin>>m>>n>>k;
        
        for(int j=0;j<m;j++)
            for(int l=0;l<n;l++) M[j][l]=0;
        
        for(int j=0;j<k;j++){
            cin>>ax>>cont;
            M[ax-1][cont-1]=1;
        }
        
        cont=0;
        
        for(int j=1;j<=m;j++){
            ax=0;
            for(int l=1;l<=n;l++){
                if(M[j-1][l-1]) ax++;
                else{
                    if(ax>1) cont++;
                    ax=0;
                }
            }
            if(ax>1) cont++;
        }
        
        for(int j=1;j<=n;j++){
            ax=0;
            for(int l=1;l<=m;l++){
                if(M[l-1][j-1]) ax++;
                else{
                    if(ax>1) cont++;
                    ax=0;
                }
            }
            if(ax>1) cont++;
        }
        cout<<cont<<endl;
    }

    return 0;
}
