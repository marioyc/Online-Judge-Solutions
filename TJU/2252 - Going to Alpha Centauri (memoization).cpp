#include<cstdio>
#include<vector>

using namespace std;

vector< vector<int> > L;
int memo[1000];
int D[1000];
int N;

int total(int n){
    if(n==N-1) return 1;
    
    if(memo[n]!=-1) return memo[n];
    
    int cont=0;
    
    for(int i=0;i<L[n].size();i++) cont+=total(L[n][i]);
    
    memo[n]=cont;
    
    return cont;
}

int main(){
    int aux;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i=0;i<N;i++) scanf("%d",&D[i]);
        
        L.clear();
        L.resize(N);
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d",&aux);
                if(aux==1 && D[j]<D[i]) L[i].push_back(j);
            }
        }
        
        fill(memo,memo+N,-1);
        
        if(total(0)==0) printf("impossible\n");
        else printf("%d\n",memo[0]);
    }
    
    return 0;
}
