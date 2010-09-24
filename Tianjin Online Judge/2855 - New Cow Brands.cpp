#include<cstdio>
#include<algorithm>

using namespace std;

int N,start,end,cont;
char M[15][27];
int sz[15];
char s[16];
bool used[26];

void generate(int n){
    if(cont>end) return;
    
    if(n==N){
        cont++;
        
        if(cont>=start && cont<=end){
            for(int i=0;i<N;i++) putchar(s[i]);
            putchar('\n');
        }
        
        return;
    }
    
    for(int i=0;i<sz[n];i++){
        if(used[M[n][i]-'A']) continue;
        used[M[n][i]-'A']=true;
        s[n]=M[n][i];
        generate(n+1);
        used[M[n][i]-'A']=false;
    }
}

int main(){    
    scanf("%d %d %d",&N,&start,&end);
    
    for(int i=0;i<N;i++) scanf("%s",M[i]);
    for(int i=0;i<N;i++) sz[i]=strlen(M[i]);    
    for(int i=0;i<N;i++) sort(M[i],M[i]+sz[i]);
    
    cont=0;
    for(int i=0;i<26;i++) used[i]=false;
    
    generate(0);
    
    return 0;
}
