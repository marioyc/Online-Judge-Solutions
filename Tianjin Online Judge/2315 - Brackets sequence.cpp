#include <cstdio>
#include <cstring>

#define min(a,b) a<b? a:b

using namespace std;

char s[101];
int memo[100][101];

int solve(int a, int n){
    if(n==0) return 0;
    
    if(memo[a][n]!=-1) return memo[a][n];
    
    if((s[a]==']') || (s[a]==')')) memo[a][n]=1+solve(a+1,n-1);
    else{
        int aux=n;
        
        for(int i=a;i<a+n;i++){
            if((s[a]=='[' && s[i]==']') || (s[a]=='(' && s[i]==')')) aux=min(aux,solve(a+1,i-1-a)+solve(i+1,a+n-1-i));            
            else aux=min(aux,1+solve(a+1,i-a)+solve(i+1,a+n-1-i));
        }
        
        memo[a][n]=aux;        
    }
    
    return memo[a][n];
}

void print(int a, int n){
    if(n==0) return;
    
    if(s[a]==']'){
        printf("[]");
        print(a+1,n-1);
    }else if(s[a]==')'){
        printf("()");
        print(a+1,n-1);
    }else{
        int aux=solve(a,n);
        
        for(int i=a;i<a+n;i++){
            if((s[a]=='[' && s[i]==']') || (s[a]=='(' && s[i]==')')){
                if(aux==solve(a+1,i-1-a)+solve(i+1,a+n-1-i)){
                    printf("%c",s[a]);
                    print(a+1,i-1-a);
                    printf("%c",s[i]);
                    print(i+1,a+n-1-i);
                    break;
                }
            }else{
                if(aux==1+solve(a+1,i-a)+solve(i+1,a+n-1-i)){
                    printf("%c",s[a]);
                    print(a+1,i-a);
                    if(s[a]=='(') printf(")");
                    else printf("]");
                    print(i+1,a+n-1-i);
                    break;
                }
            }
        }
    }
}

int main(){    
    scanf("%s",s);
    int n=strlen(s);
    
    for(int i=0;i<n;i++)
        for(int j=0;j<=n;j++) memo[i][j]=-1;
    
    print(0,n);
    printf("\n");
    
    return 0;
}
