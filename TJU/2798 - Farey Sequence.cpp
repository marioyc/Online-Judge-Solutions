#include <cstdio>
#include <vector>

using namespace std;

const int MAX_DEM = 3000;
vector<int> Fnum,Fdem;

// Stern-Brocot Tree
void build(int lnum, int ldem, int rnum, int rdem){
    int a = lnum+rnum,b = ldem+rdem;
    if(b>MAX_DEM) return;
    
    build(lnum,ldem,a,b);
    
    Fnum.push_back(a);
    Fdem.push_back(b);
    
    build(a,b,rnum,rdem);
}

int main(){
    build(0,1,1,1);
    
    int T,N,M = Fdem.size();
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        bool first = true;
        
        for(int i = 0;i<M;++i){
            if(Fdem[i]<=N){
                if(!first) putchar(',');
                first = false;
                printf("%d/%d",Fnum[i],Fdem[i]);
            }
        }
        
        putchar('\n');
    }
    
    return 0;
}
