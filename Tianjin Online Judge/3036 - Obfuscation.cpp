#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int prev[1002];
char M[10000][101];
int str[1002];
int N;

void print(int m){
    if(m!=0){
        print(prev[m]);
        printf("%s",M[str[m]]);
        if(m!=N) printf(" ");
    }
}

int main(){    
    int T,n,m,l,pos;
    char s[1001];
    long long dp[1002];
    bool ok;
    int cont[26];
    int c[10000][26];
    bool start;
    
    scanf("%d",&T);
    
    for(int caso=1;caso<=T;caso++){
        scanf("%s",s);
        m=strlen(s);
        
        scanf("%d",&n);
        
        for(int i=0;i<n;i++) scanf("%s",M[i]);
        
        for(int i=0;i<n;i++){
            fill(c[i],c[i]+26,0);
            l=strlen(M[i]);
            for(int j=0;j<l;j++) c[i][M[i][j]-'a']++;
        }
        
        fill(dp,dp+m+1,0);
        dp[0]=1;
        
        for(int i=0;i<m;i++){
            if(dp[i]!=0){
                for(int j=0;j<n;j++){
                    l=strlen(M[j]);
                    
                    if(i+l>m) continue;
                    
                    fill(cont,cont+26,0);                                     
                    
                    for(int k=0;k<l;k++) cont[s[i+k]-'a']++;
                    
                    ok=true;
                    
                    for(int k=0;k<26;k++) ok&=(cont[k]==c[j][k]);
                    
                    ok&=(M[j][0]==s[i]);
                    ok&=(M[j][l-1]==s[i+l-1]);
                    
                    if(ok){
                        dp[i+l]+=dp[i];
                        prev[i+l]=i;
                        str[i+l]=j;
                    }
                }
            }
        }
        
        if(dp[m]==0) printf("impossible\n");
        else if(dp[m]>1) printf("ambiguous\n");
        else{
            N=m;
            print(m);
            printf("\n");
        }
        
    }
    
    return 0;
}
