#include <cstdio>
#include <cstring>

using namespace std;

int VE,VC,CE,CC;

char s[16];
int a[16],N;
long long memo[15][26][5][5];
bool vowel[26];

long long count(int n, int c, int count_equal, int count_consec){
    if(vowel[c] && (count_equal>VE || count_consec>VC)) return 0;
    if(!vowel[c] && (count_equal>CE || count_consec>CC)) return 0;
    if(n==N) return 1;
    
    if(memo[n][c][count_equal][count_consec]!=-1) return memo[n][c][count_equal][count_consec];
    
    if(a[n]!=-1){
        memo[n][c][count_equal][count_consec]=count(n+1,a[n],a[n]==c? count_equal+1:1,vowel[c]==vowel[a[n]]? count_consec+1:1);
    }else{
        memo[n][c][count_equal][count_consec]=0;
        
        for(int i=0;i<26;i++)
            memo[n][c][count_equal][count_consec]+=count(n+1,i,i==c? count_equal+1:1,vowel[c]==vowel[i]? count_consec+1:1);
    }
    
    return memo[n][c][count_equal][count_consec];
}

int main(){
    scanf("%d %d %d %d",&VE,&VC,&CE,&CC);
    scanf("%s",s);
    
    N=strlen(s);
    
    for(int i=N-1;i>=0;i--)
        if(s[i]=='*') a[i]=-1;
        else a[i]=s[i]-'a';
    
    for(int i=0;i<26;i++) vowel[i]=0;
    vowel['a'-'a']=1;
    vowel['e'-'a']=1;
    vowel['i'-'a']=1;
    vowel['o'-'a']=1;
    vowel['u'-'a']=1;
    
    for(int i=0;i<N;i++)
        for(int j=0;j<26;j++)
            for(int x=0;x<5;x++)
                for(int y=0;y<5;y++)
                    memo[i][j][x][y]=-1;
    
    printf("%lld\n",count(0,0,0,0));
    
    return 0;
}
