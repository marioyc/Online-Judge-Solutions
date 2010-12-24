#include <cstdio>

using namespace std;

const int MOD = 1000000007;
int seq[50000],tree[4*50000];

void init(int node, int a, int b){
    if(a==b) tree[node] = seq[a];
    else{
        int mid = (a+b)>>1;
        init(2*node+1,a,mid);
        init(2*node+2,mid+1,b);
        
        tree[node] = ((long long)tree[2*node+1]*tree[2*node+2])%MOD;
    }
}

int query(int node, int a, int b, int x1, int x2){
    if(a>x2 || b<x1) return 1;
    if(a>=x1 && b<=x2) return tree[node];
    
    int mid = (a+b)>>1;
    return ((long long)query(2*node+1,a,mid,x1,x2)*query(2*node+2,mid+1,b,x1,x2))%MOD;
}

void update(int node, int a, int b, int x, int val){
    if(a==b) tree[node] = val;
    else{
        int mi = (a+b)>>1;
        
        if(x<=mi) update(2*node+1,a,mi,x,val);
        else update(2*node+2,mi+1,b,x,val);
        
        tree[node] = ((long long)tree[2*node+1]*tree[2*node+2])%MOD;
    }
}

void readInt(int &n){
    int sign = 1;
    char c;
    bool found = false;
    n = 0;
    
    while(true){
    	c = getc(stdin);
    	
        switch(c){
            case '-' :
                sign = -1;
                found = true;
                break;
            case ' ':
                if(found) goto jump;
                break;
            case '\n':
                if(found) goto jump;
                break;
            default:
                if(c>='0' && c<='9'){
                    n = n*10+c-'0';
                    found = true;
                }else goto jump;
                break;
        }
    }
    
    jump:
        n *= sign;
}

int main(){
    int T,N,Q;
    
    readInt(T);
    
    while(T--){
        readInt(N);
        for(int i = 0;i<N;++i) readInt(seq[i]);
        init(0,0,N-1);
        
        scanf("%d",&Q);
        
        for(int q = 0,type,x1,x2,val;q<Q;++q){
            readInt(type);
            
            if(type==0){
                readInt(x1); readInt(x2);
                printf("%d\n",query(0,0,N-1,x1-1,x2-1));
            }else{
                readInt(x1); readInt(val);
                update(0,0,N-1,x1-1,val);
            }
        }
    }
    
    return 0;
}
