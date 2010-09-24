#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int n[6];
int memo[6][22];

bool f(int i, int N){
    if(N==0) return true;
    if(i==6) return false;
    
    if(memo[i][N]!=-1) return memo[i][N];
    
    bool aux=false;
    
    for(int j=0;j<=n[i] && N>=j*(i+1);j++) aux|=f(i+1,N-j*(i+1));
    
    memo[i][N]=aux;
    
    return aux;
}

int main(){
    int N,caso=1,max;
    
    while(1){
        scanf("%d %d %d %d %d %d",&n[0],&n[1],&n[2],&n[3],&n[4],&n[5]);
        if(n[0]==0 && n[1]==0 && n[2]==0 && n[3]==0 && n[4]==0 && n[5]==0) break;
        
        N=0;
        for(int i=0;i<6;i++) N+=(i+1)*n[i];
        
        printf("Collection #%d:\n",caso);
        caso++;
                
        if(N%2==1) printf("Can't be divided.\n\n");
        else{
            memset(memo,-1,sizeof(memo));
            
            if(f(0,N/2)) printf("Can be divided.\n\n");
            else printf("Can't be divided.\n\n");
        }
    }
    
    return 0;
}
