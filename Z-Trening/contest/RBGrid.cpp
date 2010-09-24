#include<cstdio>

using namespace std;

char M[1000][1000];
int n,m;

bool count(int r, int c){
    if(M[r][c]!='B') return false;
    if(r==0 || r==n-1 || c==0 || c==m-1) return false;    
    if(M[r-1][c]!='B') return false;
    if(M[r][c-1]!='B') return false;
    if(M[r+1][c]!='B') return false;
    if(M[r][c+1]!='B') return false;
    return true;
}

int main(){    
    scanf("%d %d",&n,&m);
    
    for(int i=0;i<n;i++) scanf("%s",M[i]);
    
    int cont=0;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(count(i,j)) cont++;
    
    printf("%d\n",cont);
    
    return 0;
}
