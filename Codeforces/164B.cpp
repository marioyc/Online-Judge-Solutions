#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

#define MAXL 1000000
#define MAXVAL 1000001

int a[MAXL],b[MAXL],c[MAXL];
int ind[MAXVAL];
int dp[MAXL];

int main(){
    int LA,LB;
    
    scanf("%d %d",&LA,&LB);
    
    for(int i = 0;i < LA;++i) scanf("%d",&a[i]);
    for(int i = 0;i < LB;++i) scanf("%d",&b[i]);
    
    memset(ind,-1,sizeof ind);
    
    for(int i = 0;i < LB;++i)
        ind[ b[i] ] = i;
    
    bool found = false;
    
    for(int i = 0;i < LA;++i){
        if(ind[ a[i] ] != -1){
            found = true;
            
            int s = ind[ a[i] ];
            
            for(int j = 0;j < LA;++j) c[j] = a[(i + j) % LA];
            for(int j = 0;j < LA;++j) a[j] = c[j];
            
            for(int j = 0;j < LB;++j) c[j] = b[(s + j) % LB];
            for(int j = 0;j < LB;++j) b[j] = c[j];
            
            break;
        }
    }
    
    for(int i = 0;i < LB;++i)
        ind[ b[i] ] = i;
    
    if(!found){
        puts("0");
        return 0;
    }
    
    int pref = 1,end = 0;
    
    while(pref < LA){
        if(ind[ a[pref] ] == -1) break;
        
        int nxt = ind[ a[pref] ];
        
        if(nxt > end){
            end = nxt;
            ++pref;
        }else break;
    }
    
    if(pref == LA){
        printf("%d\n",LA);
        return 0;
    }
    
    for(int i = LA - 1;i > 0;--i){
        if(ind[ a[i] ] == -1) dp[i] = 0;
        else{
            int s = ind[ a[i] ];
            
            if(i == LA - 1){
                if(pref == 0) dp[i] = 1;
                else{
                    int lo = 1,hi = pref,mi;
                    
                    while(lo < hi){
                        int mi = (lo + hi + 1) >> 1;
                        
                        int pos = ind[ a[mi - 1] ];
                        
                        if(pos >= s) hi = mi - 1;
                        else lo = mi;
                    }
                    
                    dp[i] = 1 + lo;
                }
            }else{
                if(dp[i + 1] == 0) dp[i] = 1;
                else{
                    int lo = 1,hi = dp[i + 1],mi;
                    int s2 = ind[ a[i + 1] ];
                    
                    while(lo < hi){
                        int mi = (lo + hi + 1) >> 1;
                        
                        if(ind[ a[(i + mi) % LA] ] < s2){
                            if(ind[ a[ (i + mi) % LA] ] >= s || s2 < s) hi = mi - 1;
                            else lo = mi;
                        }else{
                            if(s2 >= s || ind[ a[ (i + mi) % LA] ] < s) lo = mi;
                            else hi = mi - 1;
                        }
                    }
                    
                    dp[i] = 1 + lo;
                }
            }
        }
    }
    
    int ans = pref;
    
    for(int i = 1;i < LA;++i)
        ans = max(ans,dp[i]);
    
    printf("%d\n",ans);
    
    return 0;
}
