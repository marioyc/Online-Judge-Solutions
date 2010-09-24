#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int M[1025][1025];
int sums_r[1025][1025];
int total[1025][1025];

int main(){    
    int T,d,n,m,r,c,x,cont;
    
    
    scanf("%d",&T);
    
    for(int caso=1;caso<=T;caso++){
        scanf("%d %d",&d,&n);
        
        for(int i=0;i<1025;i++) fill(M[i],M[i]+1025,0);
        
        for(int i=0;i<n;i++){
            scanf("%d %d %d",&r,&c,&m);
            M[r][c]+=m;
        }
        
        for(int j=0;j<1025;j++){
            sums_r[0][j]=0;
            
            for(int i=0;i<=d;i++) sums_r[0][j]+=M[i][j];
            
            for(int i=1;i<=d;i++) sums_r[i][j]=sums_r[i-1][j]+M[i+d][j];
            
            for(int i=d+1;i<1025-d;i++) sums_r[i][j]=sums_r[i-1][j]+M[i+d][j]-M[i-d-1][j];
            
            for(int i=1025-d;i<1025;i++) sums_r[i][j]=sums_r[i-1][j]-M[i-d-1][j];
        }
        
        for(int i=0;i<1025;i++){
            total[i][0]=0;
            
            for(int j=0;j<=d;j++) total[i][0]+=sums_r[i][j];
            
            for(int j=1;j<=d;j++) total[i][j]=total[i][j-1]+sums_r[i][j+d];
            
            for(int j=d+1;j<1025-d;j++) total[i][j]=total[i][j-1]+sums_r[i][j+d]-sums_r[i][j-d-1];
            
            for(int j=1025-d;j<1025;j++) total[i][j]=total[i][j-1]-sums_r[i][j-d-1];
        }        
        
        x=r=c=-1;
        
        for(int i=0;i<1025;i++)
            for(int j=0;j<1025;j++)
                if(total[i][j]>x){
                    x=total[i][j];
                    r=i;
                    c=j;
                }
        
        printf("%d %d %d\n",r,c,x);
    }
    
    return 0;
}
