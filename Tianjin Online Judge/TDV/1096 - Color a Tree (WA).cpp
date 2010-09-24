#include<cstdio>
#include<queue>

using namespace std;

struct nodo{
    int n,C;
    
    nodo(){
    }
    
    nodo(int a, int b){
        n=a;
        C=b;
    }
    
    bool operator < (nodo X) const{
        return C>X.C;
    }
};

int main(){
    int N,R,cost,a,b;
    int C[1000];
    int father[1000];
    int sons[1000];
    nodo aux;
    
    while(1){
        scanf("%d %d",&N,&R);
        if(N==0 && R==0) break;
        
        for(int i=0;i<N;i++) scanf("%d",&C[i]);
        
        fill(sons,sons+N,0);
        
        for(int i=0;i<N-1;i++){
            scanf("%d %d",&a,&b);
            a--; b--;            
            father[b]=a;
            sons[a]++;
        }
        
        priority_queue<nodo> Q;
        
        for(int i=0;i<N;i++) if(sons[i]==0) Q.push(nodo(i,C[i]));
        
        cost=0;
        
        for(int i=N;i>=1;i--){
            aux=Q.top();
            Q.pop();
            
            cost+=i*aux.C;
            
            sons[father[aux.n]]--;
            if(sons[father[aux.n]]==0) Q.push(nodo(father[aux.n],C[father[aux.n]]));
        }
        
        printf("%d\n",cost);
    }
    
    return 0;
}
