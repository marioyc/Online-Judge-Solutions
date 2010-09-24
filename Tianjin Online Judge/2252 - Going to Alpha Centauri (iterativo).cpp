#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct planet{
    int n,D;
    
    planet(int a, int b){
        n=a;
        D=b;
    }
    
    bool operator < (planet X) const{
        return D<X.D;
    }
};

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,aux;
    int dp[1000];
    int D[1000];
    vector< vector<int> > L;
    vector<planet> v;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i=0;i<N;i++) scanf("%d",&D[i]);
        
        L.clear();
        L.resize(N);
        v.clear();
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d",&aux);
                if(aux==1 && D[j]<D[i]) L[i].push_back(j);
            }
            
            v.push_back(planet(i,D[i]));
        }
        
        sort(v.begin(),v.end());
        
        dp[N-1]=1;
        
        for(int i=0;i<N;i++){
            if(v[i].n==N-1) continue;
            
            aux=0;
            
            for(int j=0;j<L[v[i].n].size();j++) aux+=dp[L[v[i].n][j]];
            
            dp[v[i].n]=aux;
        }
        
        if(dp[0]==0) printf("impossible\n");
        else printf("%d\n",dp[0]);
    }
    
    return 0;
}
