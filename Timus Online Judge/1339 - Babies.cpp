#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 250000

int outL[MAXN + 1],outR[MAXN + 1];
bool inL[MAXN + 1],inR[MAXN + 1];
int ans[MAXN + 1];
bool used[MAXN + 1];

int main(){
    int K;
    
    scanf("%d",&K);
    
    for(int i = 1;i <= K;++i){
        scanf("%d",&outL[i]);
        inR[ outL[i] ] = true;
    }
    
    for(int i = 1;i <= K;++i){
        scanf("%d",&outR[i]);
        inL[ outR[i] ] = true;
    }
    
    memset(ans,-1,sizeof ans);
    memset(used,false,sizeof used);
    
    for(int i = 1;i <= K;++i){
        if(outL[i] != 0 && !inL[i]){
            int l = i,r;
            
            while(outL[l] != 0){
                r = outL[l];
                ans[l] = r;
                used[r] = true;
                
                if(outR[r] != 0) l = outR[r];
                else break;
            }
        }
    }
    
    for(int i = 1;i <= K;++i){
        if(!inR[i] && outR[i] != 0){
            int r = i,l;
            
            while(outR[r] != 0){
                l = outR[r];
                ans[l] = r;
                used[r] = true;
                
                if(outL[l] != 0) r = outL[l];
                else break;
            }
        }
    }
    
    for(int i = 1;i <= K;++i){
        if(ans[i] == -1 && outL[i] != 0 &&  !used[ outL[i] ]){
            int l = i,r;
            
            while(outL[l] != 0){
                r = outL[l];
                ans[l] = r;
                used[r] = true;
                
                if(outR[r] != 0 && ans[ outR[r]] == -1) l = outR[r];
                else break;
            }
        }
    }
    
    for(int i = 1,j = 1;i <= K;++i){
        if(ans[i] == -1){
            while(used[j]) ++j;
            ans[i] = j++;
        }
    }
    
    for(int i = 1;i <= K;++i){
        if(i > 1) putchar(' ');
        printf("%d",ans[i]);
    }
    
    return 0;
}
