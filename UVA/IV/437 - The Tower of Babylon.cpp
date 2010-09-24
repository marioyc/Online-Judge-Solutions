#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct block{
    int x,y,z;
    
    block(int a, int b, int c){
        x=a;
        y=b;
        z=c;
    }
    
    bool operator < (block X) const{
        if((x<X.x && y<X.y) || (x<X.y && y<X.x)) return true;
        return false;
    }
};

vector<block> v;
vector< vector<int> > L;
int dp[90];

int f(int n){
    if(dp[n]!=-1) return dp[n];
    
    int aux=0;
    
    for(int i=0;i<L[n].size();i++) aux=max(aux,f(L[n][i]));
    
    dp[n]=aux+v[n].z; 
    
    return aux+v[n].z;
}

int main(){    
    int n,N,caso=1,a,b,c,max_H;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        v.clear();
        
        for(int i=0;i<n;i++){
            scanf("%d %d %d",&a,&b,&c);
            v.push_back(block(a,b,c));
            v.push_back(block(b,c,a));
            v.push_back(block(c,a,b));
        }
        
        max_H=0;
        N=3*n;
        
        L.clear();
        L.resize(N);
        
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++) if(v[i]<v[j]) L[j].push_back(i);
        
        fill(dp,dp+N,-1);
        
        for(int i=0;i<N;i++) max_H=max(max_H,f(i));
        
        printf("Case %d: maximum height = %d\n",caso,max_H);
        caso++;
    }
    
    return 0;
}
