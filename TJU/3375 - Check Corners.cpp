#include <cstdio>
#include <algorithm>

using namespace std;

struct query{
    int id,r1,r2,c1,c2;
    
    query(){}
    
    query(int _id, int _r1, int _r2, int _c1, int _c2){
        id = _id;
        r1 = _r1; r2 = _r2;
        c1 = _c1; c2 = _c2;
    }
    
    bool operator < (query X)const{
        if(r1!=X.r1) return r1<X.r1;
        return r2<X.r2;
    }
}q[1000000];

int R,C,Q;
unsigned int M[300][300],tmp[300],RMQ[300][9],ans[1000000];
bool yes[1000000];

int main(){
    scanf("%d %d",&R,&C);
    
    for(int r = 0;r<R;++r)
        for(int c = 0;c<C;++c)
            scanf("%u",&M[r][c]);
    
    scanf("%d",&Q);
    
    for(int i = 0,r1,c1,r2,c2;i<Q;++i){
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
        --r1; --c1; --r2; --c2;
        q[i] = query(i,r1,r2,c1,c2);
    }
    
    sort(q,q+Q);
    
    for(int r1 = 0,pos = 0;r1<R && pos<Q;++r1){
        for(int c = 0;c<C;++c) tmp[c] = M[r1][c];
        
        for(int r2 = r1;r2<R && pos<Q && q[pos].r1==r1;++r2){
            for(int c = 0;c<C;++c) tmp[c] = max(tmp[c],M[r2][c]);
            
            if(q[pos].r2==r2){
                for(int c = 0;c<C;++c) RMQ[c][0] = tmp[c];
                
                for(int i = 1;(1<<i)<=C;++i)
                    for(int c = 0;c+(1<<i)-1<C;++c)
                        RMQ[c][i] = max(RMQ[c][i-1],RMQ[c+(1<<(i-1))][i-1]);
                
                while(pos<Q && q[pos].r1==r1 && q[pos].r2==r2){
                    int c1 = q[pos].c1,c2 = q[pos].c2,log = 0;
                    
                    while((1<<log)<=(c2-c1+1)) ++log;
                    --log;
                    
                    unsigned int max_val = max(RMQ[c1][log],RMQ[c2-(1<<log)+1][log]);
                    
                    ans[q[pos].id] = max_val;
                    yes[q[pos].id] = (M[r1][c1]==max_val || M[r1][c2]==max_val || M[r2][c1]==max_val || M[r2][c2]==max_val);
                    
                    ++pos;
                }
            }
        }
    }
    
    for(int i = 0;i<Q;++i){
        printf("%u ",ans[i]);
        if(yes[i]) puts("yes");
        else puts("no");
    }
    
    return 0;
}
