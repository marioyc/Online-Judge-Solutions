#include<cstdio>
#include<algorithm>

using namespace std;

char M[1000][1001];
bool visited[1000][1000];
bool border_left[1000][1000];
int cont_right[1000][1000];

int main(){    
    int R,C,n,m;
    
    bool ok;
    int cont;
    
    while(1){
        scanf("%d %d",&R,&C);
        if(R==0) break;
        
        for(int i=0;i<R;i++) scanf("%s",M[i]);
        
        for(int i=0;i<R;i++){
            cont_right[i][C-1]=M[i][C-1]=='#'? 1:0;
            
            for(int j=C-2;j>=0;j--) cont_right[i][j]=M[i][j]=='#'? cont_right[i][j+1]+1:0;
            
            border_left[i][0]=M[i][0]=='#'? true:false;
            
            for(int j=1;j<C;j++) border_left[i][j]=M[i][j]=='#' && M[i][j-1]=='.'? true:false;
        }
        
        cont=0;
        ok=true;
        
        for(int i=0;i<R;i++) fill(visited[i],visited[i]+C,false);
        
        for(int r=0;r<R && ok;r++)
            for(int c=0;c<C && ok;c++)
                if(!visited[r][c] && M[r][c]=='#'){
                    cont++;
                    
                    n=cont_right[r][c];
                    
                    if(r>0 && c>0) if(visited[r-1][c-1]) ok=false;
                    
                    if(r>0) for(int i=0;i<n;i++) if(visited[r-1][c]) ok=false;
                    
                    if(r>0 && c<C-1) if(visited[r-1][c+1]) ok=false;
                    
                    m=1;
                    
                    for(int i=1;r+i<R && M[r+i][c]=='#';i++) m++;
                    
                    for(int i=0;i<m;i++) if(!border_left[r+i][c] || cont_right[r+i][c]!=n) ok=false;
                    
                    for(int i=0;i<m;i++) fill(visited[r+i]+c,visited[r+i]+c+n,true);
                }
        
        if(!ok) printf("Bad placement.\n");
        else printf("There are %d ships.\n",cont);
    }
    
    return 0;
}
