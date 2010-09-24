#include<cstdio>
#include<algorithm>

using namespace std;

int n,cont,max_num;
char map[4][5];
int M[4][4];

void backtracking(int r, int c){
    if(r==n){
        max_num=max(max_num,cont);
        
        return;
    }
    
    if(M[r][c]==-1){
        cont++;
        M[r][c]=cont;
        for(int i=c-1;i>=0 && M[r][i]!=0;i--) if(M[r][i]==-1) M[r][i]=cont;
        for(int i=c+1;i<n && M[r][i]!=0;i++) if(M[r][i]==-1) M[r][i]=cont;
        for(int i=r-1;i>=0 && M[i][c]!=0;i--) if(M[i][c]==-1) M[i][c]=cont;
        for(int i=r+1;i<n && M[i][c]!=0;i++) if(M[i][c]==-1) M[i][c]=cont;
        
        backtracking(c==n-1? r+1:r,(c+1)%n);        
        
        M[r][c]=-1;
        for(int i=c-1;i>=0 && M[r][i]!=0;i--) if(M[r][i]==cont) M[r][i]=-1;
        for(int i=c+1;i<n && M[r][i]!=0;i++) if(M[r][i]==cont) M[r][i]=-1;
        for(int i=r-1;i>=0 && M[i][c]!=0;i--) if(M[i][c]==cont) M[i][c]=-1;
        for(int i=r+1;i<n && M[i][c]!=0;i++) if(M[i][c]==cont) M[i][c]=-1;
        cont--;
    }
    
    backtracking(c==n-1? r+1:r,(c+1)%n);
}

int main(){    
    cont=0;    
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        for(int i=0;i<n;i++) scanf("%s",map[i]);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                M[i][j]=(map[i][j]=='X'? 0:-1);
        
        max_num=0;
        
        backtracking(0,0);
        
        printf("%d\n",max_num);
    }
    
    return 0;
}
