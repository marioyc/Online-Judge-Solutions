#include<cstdio>

using namespace std;

int main(){    
    int n,m;
    char M[10][11];
    char N[10][11];
    int dr[]={1,-1,0,0,1,1,-1,-1};
    int dc[]={0,0,1,-1,1,-1,1,-1};
    int r,c,cont;
    bool lose=false;
    
    scanf("%d",&n);
    
    for(int i=0;i<n;i++) scanf("%s",M[i]);
    for(int i=0;i<n;i++) scanf("%s",N[i]);
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(N[i][j]=='x' && M[i][j]=='*') lose=true;
    
    if(lose){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(M[i][j]=='*') N[i][j]='*';
    }
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(N[i][j]=='x'){
                cont=0;
                for(int k=0;k<8;k++){
                    r=i+dr[k];
                    c=j+dc[k];
                    
                    if(r>=0 && r<n && c>=0 && c<n && M[r][c]=='*') cont++;
                }
                N[i][j]='0'+cont;
            }
    
    for(int i=0;i<n;i++) printf("%s\n",N[i]);
    
    return 0;
}
