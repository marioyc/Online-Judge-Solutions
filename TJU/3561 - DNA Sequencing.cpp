#include <cstdio>

using namespace std;

int main(){
    int M,F;
    scanf("%d %d",&M,&F);
    
    char s1[20][26],s2[20][26];
    
    for(int i=0;i<M;++i) scanf("%s",s1[i]);
    for(int i=0;i<F;++i) scanf("%s",s2[i]);
    
    int ans[M][F];
    
    for(int i=0;i<M;++i) for(int j=0;j<F;++j){
        ans[i][j] = 0;
        
        for(int k=0;k<M;++k){
            if(k==i) continue;
            bool child = true;
            for(int l=0;l<25;++l)
                if(s1[k][l]!=s1[i][l] && s1[k][l]!=s2[j][l])
                    child = false;
            if(child) ++ans[i][j];
        }
        
        for(int k=0;k<F;++k){
            if(k==j) continue;
            bool child = true;
            for(int l=0;l<25;++l)
                if(s2[k][l]!=s1[i][l] && s2[k][l]!=s2[j][l])
                    child = false;
            if(child) ++ans[i][j];
        }
    }
    
    for(int i=0;i<M;++i){
        printf("%d",ans[i][0]);
        for(int j=1;j<F;++j) printf(" %d",ans[i][j]);
        printf("\n");
    }
    
    return 0;
}
