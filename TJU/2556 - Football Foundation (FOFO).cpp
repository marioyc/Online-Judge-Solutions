#include <cstdio>
#include <cstring>

using namespace std;

char M[500][501];
int visited[500][500];

int main(){
    int R,C,r,c,cont;
    
    while(true){
        scanf("%d %d %d",&R,&C,&c);
        if(R==0) break;
        
        for(int i = 0;i<R;++i) scanf("%s",M[i]);
        
        memset(visited,-1,sizeof(visited));
        r = cont = 0;
        visited[r][--c] = 0;
        
        while(true){
            if(M[r][c]=='N') --r;
            else if(M[r][c]=='S') ++r;
            else if(M[r][c]=='E') ++c;
            else --c;
            ++cont;
            
            if(r<0 || r>=R || c<0 || c>=C){
                printf("%d step(s) to exit\n",cont);
                break;
            }
            
            if(visited[r][c]!=-1){
                printf("%d step(s) before a loop of %d step(s)\n",visited[r][c],cont-visited[r][c]);
                break;
            }
            
            visited[r][c] = cont;
        }
    }
    
    return 0;
}
