#include <cstdio>
#include <cstring>

using namespace std;

char s1[201],s2[201],s3[401];
int L1,L2,L3,memo[201][201];

int solve(int n, int m){
    if(n+m==L3) return 1;
    if(memo[n][m]!=-1) return memo[n][m];
    
    int aux = 0;
    
    if(n<L1 && s1[n]==s3[n+m]) aux |= solve(n+1,m);
    if(m<L2 && s2[m]==s3[n+m]) aux |= solve(n,m+1);
    
    memo[n][m] = aux;
    return aux;
}

int main(){
    int T,pos1,pos2,ans;
    bool done;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%s %s %s",s1,s2,s3);
        L1 = strlen(s1); L2 = strlen(s2);
        L3 = L1+L2;
        
        memset(memo,-1,sizeof(memo));
        ans = solve(0,0);
        
        printf("Data set %d: ",tc);
        
        if(ans==1) printf("yes\n");
        else printf("no\n");
    }
    
    return 0;
}
