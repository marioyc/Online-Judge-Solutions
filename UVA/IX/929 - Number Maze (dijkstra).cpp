#include <cstdio>
#include <queue>

using namespace std;

struct node{
    int r,c,cost;
    
    node(){
    }
    
    node(int _r, int _c, int _cost){
        r=_r;
        c=_c;
        cost=_cost;
    }
    
    bool operator < (node X) const{
        return cost>X.cost;
    }
};

int M[999][999],min_cost[999][999];
bool solved[999][999];

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T,R,C,r,c;
    int dr[]={0,0,1,-1};
    int dc[]={1,-1,0,0};
    
    scanf("%d",&T);
    
    for(int tc=0;tc<T;tc++){
        scanf("%d %d",&R,&C);
        
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                scanf("%d",&M[i][j]);
        
        for(int i=0;i<R;i++) fill(min_cost[i],min_cost[i]+C,-1);
        for(int i=0;i<R;i++) fill(solved[i],solved[i]+C,false);
        
        priority_queue<node> Q;
        node aux;
        
        Q.push(node(0,0,M[0][0]));
        min_cost[0][0]=M[0][0];
        
        while(1){
            aux=Q.top();
            Q.pop();
            
            if(solved[aux.r][aux.c]) continue;
            solved[aux.r][aux.c]=true;
            
            if(aux.r==R-1 && aux.c==C-1){
                printf("%d\n",aux.cost);
                break;
            }
            
            for(int i=0;i<4;i++){
                r=aux.r+dr[i];
                c=aux.c+dc[i];
                
                if(r>=0 && r<R && c>=0 && c<C && (min_cost[r][c]==-1 || (min_cost[r][c]>min_cost[aux.r][aux.c]+M[r][c]))){
                    min_cost[r][c]=min_cost[aux.r][aux.c]+M[r][c];
                    Q.push(node(r,c,min_cost[r][c]));
                }
            }
        }
    }
    
    return 0;
}
