/*
ID: zion_ba1
LANG: C++
TASK: milk
*/

#include <cstdio>
#include <algorithm>

using namespace std;

struct farmer{
    int P,A;
    
    farmer(){
    }
    
    bool operator < (farmer X) const{
        return P<X.P;
    }
};

int main(){
    freopen("milk.in","r",stdin);
    freopen("milk.out","w",stdout);
    
    int N,M;
    
    scanf("%d %d",&N,&M);
    
    farmer F[M];
    
    for(int i=0;i<M;i++) scanf("%d %d",&F[i].P,&F[i].A);
    sort(F,F+M);
    
    int cost=0;
    
    for(int i=0;N>0;i++){
        if(N>F[i].A){
            cost+=F[i].P*F[i].A;
            N-=F[i].A;
        }else{
            cost+=F[i].P*N;
            N=0;
        }
    }
    
    printf("%d\n",cost);
    
    return 0;
}
