#include<iostream>

using namespace std;

int main(){
    int T,days,K,I,J;
    int D[16];
    int M[2][20][20];
    int di[]={0,0,0,1,-1};
    int dj[]={0,1,-1,0,0};
    
    scanf("%d",&T);
    
    for(int caso=0;caso<T;caso++){
        scanf("%d",&days);
        
        for(int i=0;i<16;i++) scanf("%d",&D[i]);
        
        for(int i=0;i<20;i++)
            for(int j=0;j<20;j++) scanf("%d",&M[0][i][j]);
        
        for(int k=1;k<=days;k++){
            for(int i=0;i<20;i++){
                for(int j=0;j<20;j++){                    
                    K=0;
                    
                    for(int a=0;a<5;a++){
                        I=i+di[a];
                        J=j+dj[a];                        
                        if(I>=0 && I<20 && J>=0 && J<20) K+=M[(k-1)%2][I][J];
                    }
                    
                    M[k%2][i][j]=M[(k-1)%2][i][j]+D[K];
                    if(M[k%2][i][j]>3) M[k%2][i][j]=3;
                    else if(M[k%2][i][j]<0) M[k%2][i][j]=0;
                }
            }
        }
        
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                if(M[days%2][i][j]==0) printf(".");
                else if(M[days%2][i][j]==1) printf("!");
                else if(M[days%2][i][j]==2) printf("X");
                else if(M[days%2][i][j]==3) printf("#");
            }
            printf("\n");
        }
        if(caso!=T-1) printf("\n");
    }
    
    return 0;
}
