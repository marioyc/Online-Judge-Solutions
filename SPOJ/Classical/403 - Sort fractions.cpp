#include <cstdio>
#include <vector>

using namespace std;

int MAX_DEN,Fnum[7600457],Fden[7600457],sz;

// Stern-Brocot Tree - build(0,1,1,1);
void build(int lnum = 0, int lden = 1, int rnum = 1, int rden = 1){
    int a = lnum+rnum,b = lden+rden;
    if(b>MAX_DEN) return;
    
    build(lnum,lden,a,b);
    
    Fnum[sz] = a;
    Fden[sz] = b;
    ++sz;
    
    build(a,b,rnum,rden);
}

int main(){
    int T,Q,ind;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&MAX_DEN,&Q);
        
        sz = 0;
        build();
        
        while(Q--){
            scanf("%d",&ind);
            
            if(ind==1) puts("0/1");
            else if(ind==sz+2) puts("1/1");
            else{
                ind -= 2;
                printf("%d/%d\n",Fnum[ind],Fden[ind]);
            }
        }
    }
    
    return 0;
}
