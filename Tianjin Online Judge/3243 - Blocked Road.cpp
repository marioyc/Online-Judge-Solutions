#include <cstdio>
#include <algorithm>

using namespace std;

int N,tree[100001];

void update(int idx, int val){
    while(idx<=N){
        tree[idx]+=val;
		idx+=(idx&-idx);
	}
}

int F(int idx){
    int sum=0;
	while(idx>0){
		sum+=tree[idx];
		idx-=(idx&-idx);
	}
	return sum;
}

int main(){
    int T,Q,type,u,v,total,f;
    bool blocked[100001];
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&N,&Q);
        
        fill(tree,tree+N+1,0);
        for(int i=1;i<=N;i++) update(i,1);
        
        fill(blocked,blocked+N+1,0);
        total=N;
        
        for(int i=0;i<Q;i++){
            scanf("%d",&type);
            
            if(type==0){
                scanf("%d",&u);
                
                if(blocked[u]){
                    update(u,1);
                    total++;
                }else{
                    update(u,-1);
                    total--;
                }
                
                blocked[u]^=1;
            }else{
                scanf("%d %d",&u,&v);
                
                if(u>v) swap(u,v);
                
                f=F(v-1)-F(u-1);
                
                if(f==v-u || total-f==N-v+u) printf("1\n");
                else printf("0\n");
            }
        }
    }
    
    return 0;
}
