#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,B,H,W;
    scanf("%d %d %d %d",&N,&B,&H,&W);
    
    int cost[H],cap[H][W],best;
    bool found=false;
    
    for(int i=0;i<H;i++){
        scanf("%d",&cost[i]);
        for(int j=0;j<W;j++) scanf("%d",&cap[i][j]);
        sort(cap[i],cap[i]+W);
    }
    
    for(int i=0;i<H;i++){
        if(cap[i][W-1]>=N && cost[i]*N<=B){
            if(!found){
                found=true;
                best=cost[i]*N;
            }else best<?=cost[i]*N;
        }
    }
    
    if(!found) printf("stay home\n");
    else printf("%d\n",best);
    
    return 0;
}
