#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,H[1000][1000],l[1000],r[1000];
char M[1000][1001],S[] = {'a', 'b', 'c', 'w', 'x', 'y', 'z'};
bool X[1000][1000];

// 'w' -> 'a' or 'b'
// 'x' -> 'b' or 'c'
// 'y' -> 'a' or 'c'
// 'z' -> 'a', 'b' or 'c'

int solve(char c){
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            if(c=='a'){
                X[i][j] = (M[i][j]=='a' || M[i][j]=='w' || M[i][j]=='y' || M[i][j]=='z');
            }else if(c=='b'){
                X[i][j] = (M[i][j]=='b' || M[i][j]=='w' || M[i][j]=='x' || M[i][j]=='z');
            }else if(c=='c'){
                X[i][j] = (M[i][j]=='c' || M[i][j]=='x' || M[i][j]=='y' || M[i][j]=='z');
            }else{
                X[i][j] = (M[i][j]==c);
            }
        }
    }
    
    for(int i = 0;i<m;++i)
        H[0][i] = (X[0][i]? 1 : 0);
    
    for(int i = 1;i<n;++i)
        for(int j = 0;j<m;++j)
            H[i][j] = (X[i][j]? H[i-1][j]+1 : 0);
    
    int ret = 0;
    
    for(int i = 0;i<n;++i){
        l[0] = -1;
        
        for(int j = 1;j<m;++j){
            l[j] = j-1;
            
            while(l[j]>=0 && H[i][l[j]]>=H[i][j])
                l[j] = l[l[j]];
        }
        
        r[m-1] = m;
        
        for(int j = m-2;j>=0;--j){
            r[j] = j+1;
            
            while(r[j]<m && H[i][r[j]]>=H[i][j])
                r[j] = r[r[j]];
        }
        
        for(int j = 0;j<m;++j)
            ret = max(ret,(r[j]-l[j]-1)*H[i][j]);
    }
    
    return ret;
}

int main(){
    while(scanf("%d %d",&n,&m)==2){
        for(int i = 0;i<n;++i)
            scanf("%s",M[i]);
        
        int ans = 0;
        
        for(int i = 0;i<7;++i)
            ans = max(ans,solve(S[i]));
        
        printf("%d\n",ans);
    }
    
    return 0;
}
