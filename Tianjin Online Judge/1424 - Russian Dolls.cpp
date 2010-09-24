#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_DOLLS 100

struct doll{
    int h,d,w;
    
    doll(){}
    
    bool operator < (doll X)const{
        if(h!=X.h) return h>X.h;
        if(d!=X.d) return d>X.d;
        return w>X.w;
    }
    
    bool canContain(doll &X)const{
        return (h-2*w>=X.h && d-2*w>=X.d);
    }
}D[2*MAX_DOLLS];

int N;
bool M[2*MAX_DOLLS+1][2*MAX_DOLLS+1];
int memo[2*MAX_DOLLS+1][2*MAX_DOLLS+1][2*MAX_DOLLS+1];

int solve(int pos1, int pos2, int next, int n, int m){
    if(n>N || m>N) return 3;
    if(n==N && m==N) return 0;
    
    int &aux = memo[pos1][pos2][n];
    if(aux!=-1) return aux;
    
    if(M[pos1][next] && solve(next,pos2,next+1,n+1,m)!=3) return aux = 1;
    if(M[pos2][next] && solve(pos1,next,next+1,n,m+1)!=3) return aux = 2;
    
    return aux = 3;
}

int main(){
    int A[MAX_DOLLS],B[MAX_DOLLS];
    bool first_tc = true;
    
    while(true){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i=2*N-1;i>=0;--i) scanf("%d %d %d",&D[i].h,&D[i].d,&D[i].w);
        sort(D,D+(2*N));
        
        memset(M,true,sizeof(M));
        
        for(int i=1;i<=2*N;++i)
            for(int j=1;j<=2*N;++j)
                M[i][j] = D[i-1].canContain(D[j-1]);
        
        memset(memo,-1,sizeof(memo));
        
        for(int pos1=0,pos2=0,next=1,n=0,m=0;next<=2*N;++next){
            int aux = solve(pos1,pos2,next,n,m);
            
            if(aux==1){
                A[n] = next-1;
                ++n;
                pos1 = next;
            }else{
                B[m] = next-1;
                ++m;
                pos2 = next;
            }
        }
        
        if(!first_tc) printf("\n");
        first_tc = false;
        
        for(int i=0;i<N;++i) printf("%d %d %d\n",D[A[i]].h,D[A[i]].d,D[A[i]].w);
        printf("-\n");
        for(int i=0;i<N;++i) printf("%d %d %d\n",D[B[i]].h,D[B[i]].d,D[B[i]].w);
    }
    
    return 0;
}
