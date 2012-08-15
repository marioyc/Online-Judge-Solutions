#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct word{
    int ind,len,sum,need;
    
    word(){}
    
    bool operator < (word X)const{
        if(sum > 0 && X.sum <= 0) return true;
        if(sum <= 0 && X.sum > 0) return false;
        
        if(sum > 0) return need < X.need;
        return need + sum > X.need + X.sum;
    }
}W[1000];

int N;
int memo[1000][10001];
bool choose[1000][10001];

int solve(int pos, int sum){
    if(pos == N){
        if(sum == 0) return 0;
        return -2;
    }
    
    int &ret = memo[pos][sum];
    
    if(ret == -1){
        ret = solve(pos + 1,sum);
        choose[pos][sum] = false;
        
        if(sum >= W[pos].need){
            int aux = solve(pos + 1,sum + W[pos].sum);
            
            if(aux != -2 && W[pos].len + aux > ret){
                ret = W[pos].len + aux;
                choose[pos][sum] = true;
            }
        }
    }
    
    return ret;
}

int main(){
    scanf("%d",&N);
    
    char s[10001];
    
    for(int i = 0;i < N;++i){
        scanf("%s",s);
        
        W[i].ind = i + 1;
        W[i].len = strlen(s);
        W[i].sum = 0;
        W[i].need = 0;
        
        for(int k = 0;k < W[i].len;++k){
            if(s[k] == '(') ++W[i].sum;
            else --W[i].sum;
            
            W[i].need = max(W[i].need,-W[i].sum);
        }
    }
    
    sort(W,W + N);
    memset(memo,-1,sizeof memo);
    
    printf("%d ",solve(0,0));
    
    int M = 0,ans[1000];
    
    for(int i = 0,sum = 0;i < N;++i){
        if(choose[i][sum]){
            ans[M++] = W[i].ind;
            sum += W[i].sum;
        }
    }
    
    printf("%d\n",M);
    
    for(int i = 0;i < M;++i)
        printf("%d ",ans[i]);
    
    return 0;
}
