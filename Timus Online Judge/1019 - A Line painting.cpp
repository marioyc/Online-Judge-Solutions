#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[5000],b[5000];
char color[5000];

int X[10002],sz;
bool white[10001];

int main(){
    int N;
    scanf("%d",&N);
    
    X[0] = 0; X[1] = 1000000000; sz = 2;
    
    for(int i = 0;i<N;++i){
        scanf("%d %d %c",&a[i],&b[i],&color[i]);
        X[sz] = a[i]; ++sz;
        X[sz] = b[i]; ++sz;
    }
    
    sort(X,X+sz);
    
    int sz2 = 1;
    
    for(int i = 1;i<sz;++i){
        if(X[i]!=X[sz2-1]){
            X[sz2] = X[i];
            ++sz2;
        }
    }
    
    sz = sz2;
    memset(white,true,sizeof(white));
    
    for(int i = 0;i<N;++i){
        int lo = 0,hi = sz-1,mi;
        
        while(lo<hi){
            mi = (lo+hi)/2;
            
            if(X[mi]<a[i]) lo = mi+1;
            else hi = mi;
        }
        
        int pos = lo;
        bool c = (color[i]=='w'? true : false);
        
        while(X[pos]!=b[i]){
            white[pos] = c;
            ++pos;
        }
    }
    
    int ans = 0, x = 0, y = 0;
    int cur = 0, cur_x = 0;
    
    for(int i = 0;i+1<sz;++i){
        if(white[i]){
            if(cur==0) cur_x = X[i];
            cur += X[i+1]-X[i];
            
            if(cur>ans){
                ans = cur;
                x = cur_x;
                y = X[i+1];
            }
        }else cur = 0;
    }
    
    printf("%d %d\n",x,y);
    
    return 0;
}
