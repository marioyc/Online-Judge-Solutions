#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,m;
    char c[100][3];
    bool valid[26];
    bool M1[100][100],M2[100][100],found;
    
    scanf("%d\n",&N);
    
    for(int tc=1;tc<=N;tc++){
        scanf("%d\n",&m);
        
        for(int i=0;i<m;i++) scanf("%c%c%c\n",&c[i][0],&c[i][1],&c[i][2]);
        
        fill(valid,valid+26,false);
        
        for(int i=0;i<26;i++) fill(M1[i],M1[i]+26,false);
        
        for(int i=0;i<m;i++){
            valid[c[i][0]-'A']=true;
            valid[c[i][2]-'A']=true;
            if(c[i][1]=='<') M1[c[i][0]-'A'][c[i][2]-'A']=true;
            else M1[c[i][2]-'A'][c[i][0]-'A']=true;
        }
        
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                M2[i][j]=M1[i][j];
        
        for(int k=0;k<26;k++){
            if(!valid[k]) continue;
            for(int i=0;i<26;i++){
                if(!valid[i]) continue;
                for(int j=0;j<26;j++){
                    if(!valid[j]) continue;
                    M2[i][j]|=M2[i][k]&M2[k][j];
                }
            }
        }
        
        printf("Case %d:\n",tc);
        
        found=false;
        
        for(int i=0;i<26;i++){
            if(!valid[i]) continue;
            for(int j=0;j<26;j++){
                if(!valid[j]) continue;
                if(M2[i][j] && !M1[i][j]){
                    printf("%c<%c\n",i+'A',j+'A');
                    found=true;
                }
            }
        }
        
        if(!found) printf("NONE\n");
    }
    
    return 0;
}
