#include <cstdio>

using namespace std;

int memo[31][2][2][2];

int solve(int n, int a, int b, int c){
    if(n==0){
        if(a==0 && b==0 && c==0) return 1;
        return 0;
    }
    
    if(memo[n][a][b][c]!=-1) return memo[n][a][b][c];
    
    int aux;
    
    if(a==0){
        if(b==0){
            if(c==0) aux=solve(n-1,1,1,1)+solve(n-1,0,0,1)+solve(n-1,1,0,0);
            else aux=solve(n-1,0,0,0)+solve(n-1,1,1,0);
        }else{
            if(c==0) aux=solve(n-1,1,0,1);
            else aux=solve(n-1,1,0,0);
        }
    }else{
        if(b==0){
            if(c==0) aux=solve(n-1,0,0,0)+solve(n-1,0,1,1);
            else aux=solve(n-1,0,1,0);
        }else{
            if(c==0) aux=solve(n-1,0,0,1);
            else aux=solve(n-1,0,0,0);
        }
    }
    
    memo[n][a][b][c]=aux;
    return aux;
}

int main(){
    for(int i=0;i<=30;i++)
        for(int a=0;a<2;a++)
            for(int b=0;b<2;b++)
                for(int c=0;c<2;c++)
                    memo[i][a][b][c]=-1;
    
    int N;
    
    while(1){
        scanf("%d",&N);
        if(N==-1) break;
        
        printf("%d\n",solve(N,0,0,0));
    }
    
    return 0;
}
