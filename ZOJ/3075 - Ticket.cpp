#include <cstdio>
#include <queue>

using namespace std;

typedef long long LL;

struct cost{
    int ind;
    LL val;
    
    cost(){}
    
    cost(int _ind, LL _val){
        ind = _ind; val = _val;
    }
    
    bool operator < (cost X)const{
        return val>X.val;
    }
}aux;

int main(){
    int N,min_days,max_days,F,price[100000];
    
    while(scanf("%d %d %d %d",&N,&min_days,&max_days,&F)==4){
        for(int i = 0;i<N;++i)
            scanf("%d",&price[i]);
        
        priority_queue<cost> Q1,Q2;
        
        for(int i = min_days;i<=max_days;++i)
            Q1.push(cost(i,price[i]));
        
        for(int i = max_days+1;i<N;++i)
            Q2.push(cost(i,price[i]+1LL*i*F));
        
        LL ans = -1,tmp;
        
        for(int i = 0;i+min_days+1<N;++i){
            if(!Q1.empty()){
                while(!Q1.empty()){
                    aux = Q1.top();
                    
                    if(aux.ind>=i+min_days+1 && aux.ind<=i+max_days){
                        tmp = price[i]+aux.val;
                        if(ans==-1 || tmp<ans) ans = tmp;
                        break;
                    }else Q1.pop();
                }
            }
            
            if(i+max_days+1<N) Q1.push(cost(i+max_days+1,price[i+max_days+1]));
            
            if(!Q2.empty()){
                while(!Q2.empty()){
                    aux = Q2.top();
                    
                    if(aux.ind>i+max_days){
                        tmp = price[i]+aux.val-1LL*(i+max_days+1)*F;
                        if(ans==-1 || tmp<ans) ans = tmp;
                        break;
                    }else Q2.pop();
                }
            }
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
