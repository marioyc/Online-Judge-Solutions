/*
ID:zion_ba1
LANG:C++
TASK:runround
*/

#include <cstdio>
#include <vector>

using namespace std;

vector<int> L;
int D[9],d;
bool used[10];

int M,ans=-1;

bool check(){
    bool in_cycle[d];
    for(int i=0;i<d;i++) in_cycle[i]=false;
    
    int pos=0;
    
    for(int i=0;i<d;i++){
        if(in_cycle[pos]) return false;
        in_cycle[pos]=true;
        pos=(pos+D[pos])%d;
    }
    
    if(pos!=0) return false;
    return true;
}

int num(){
    int aux=0;
    for(int i=0;i<d;i++) aux=aux*10+D[i];
    return aux;
}

void generate(int n){
    int aux=num();
    
    if(aux>M){
        if(check() && (ans==-1 || aux<ans)) ans=aux;
        if(aux>M || (ans!=-1 && aux>ans)) return;
    }
    
    if(n==9) return;
    
    for(int i=1;i<=9;i++){
        if(used[i]) continue;
        
        D[n]=i; d++;
        used[i]=true;
        
        generate(n+1);
        
        d--;
        used[i]=false;
    }
}

int main(){
    freopen("runround.in","r",stdin);
    freopen("runround.out","w",stdout);
    
    scanf("%d\n",&M);
    
    d=0;
    for(int i=1;i<=9;i++) used[i]=false;
    
    generate(0);
    
    printf("%d\n",ans);
    
    return 0;
}
