#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_VAL 500001

int X[MAX_VAL],szX;

int getCompressed(int ind){
    int lo = 0,hi = szX-1,mi;
    
    while(lo!=hi){
        mi = (lo+hi)>>1;
        
        if(X[mi]<ind) lo = mi+1;
        else hi = mi;
    }
    
    return lo+1;
}

int start[MAX_VAL],end[MAX_VAL];

void update(int T[], int idx, bool aug){
    for(int x = idx;x<=MAX_VAL;x += (x & -x))
        if(aug) ++T[x];
        else --T[x];
}

int F(int T[], int idx){
    int ret = 0;
    
    for(int x = idx;x>0;x -= (x & -x))
        ret += T[x];
    
    return ret;
}

int main(){
    int N,M;
    scanf("%d %d%*[\r\n ]",&N,&M);
    
    char type[M];
    int A[M],B[M],sys[M],nSys = 0;
    
    for(int i = 0;i<M;++i){
        scanf("%c %d",&type[i],&A[i]);
        if(type[i]=='P') sys[nSys++] = i;
        if(type[i]=='M') --A[i];
        if(type[i]!='B') scanf("%d",&B[i]);
        scanf("%*[\r\n ]");
    }
    
    int diff[M];
    memset(diff,0,sizeof(diff));
    
    szX = 0;
    
    for(int i = 0;i<M;++i){
        if(type[i]=='P'){
            X[szX] = A[i]; ++szX;
            X[szX] = B[i]; ++szX;
        }else if(type[i]=='M'){
            int ind = sys[A[i]];
            diff[ind] += B[i];
            
            X[szX] = A[ind]+diff[ind]; ++szX;
            X[szX] = B[ind]+diff[ind]; ++szX;
        }else{
            X[szX] = A[i]; ++szX;
        }
    }
    
    sort(X,X+szX);
    
    int sz2 = 1;
    
    for(int i = 1;i<szX;++i){
        if(X[i]!=X[sz2-1]){
            X[sz2] = X[i];
            ++sz2;
        }
    }
    
    szX = sz2;
    
    memset(diff,0,sizeof(diff));
    
    for(int i = 0;i<M;++i){
        if(type[i]=='P'){
            update(start,getCompressed(A[i]),true);
            update(end,getCompressed(B[i]),true);
        }else if(type[i]=='M'){
            int ind = sys[A[i]];
            
            update(start,getCompressed(A[ind]+diff[ind]),false);
            update(end,getCompressed(B[ind]+diff[ind]),false);
            
            diff[ind] += B[i];
            
            update(start,getCompressed(A[ind]+diff[ind]),true);
            update(end,getCompressed(B[ind]+diff[ind]),true);
        }else{
            printf("%d\n",F(start,getCompressed(A[i]))-F(end,getCompressed(A[i])-1));
        }
    }
    
    return 0;
}
