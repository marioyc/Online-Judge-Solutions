/*
ID:zion_ba1
LANG:C++
TASK:hamming
*/

#include <cstdio>

using namespace std;

int L[64],aux[64],n;

int N,B,D,MAX;
bool solved=true;

void search(int num){
    if(solved) return;
    
    if(n==N){
        solved=true;
        for(int i=0;i<N;i++) L[i]=aux[i];
        return;
    }
    
    int dist;
    bool valid;
    
    for(int i=num;i<MAX;i++){
        valid=true;
        
        for(int j=0;j<n && valid;j++){
            dist=__builtin_popcount(i ^ aux[j]);
            if(dist<D) valid=false;
        }
        
        if(valid){
            aux[n++]=i;
            search(i+1);
            n--;
            
            if(solved) return;
        }
    }
}

int main(){
    freopen("hamming.in","r",stdin);
    freopen("hamming.out","w",stdout);
    
    scanf("%d %d %d",&N,&B,&D);
    MAX=(1<<B);
    
    solved=false;
    aux[0]=0;
    n=1;
    search(1);
    
    for(int i=0;i<N;i++){
        printf("%d",L[i]);
        
        if(i%10==9 || i==N-1) printf("\n");
        else printf(" ");
    }
    
    return 0;
}
