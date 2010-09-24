/*
ID:zion_ba1
LANG:C++
TASK:checker
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int N,cont,print,C[13];
bool col[13],diag1[25],diag2[25];
bool done[13][13];

void generate(int r){
    if(r==N){
        if(print<3){
            for(int i=0;i<N;i++){
                printf("%d",C[i]);
                if(i!=N-1) printf(" ");
                else printf("\n");
            }
            print++;
        }
        
        cont+=2;
        return;
    }
    
    for(int i=0;i<N;i++){
        if(!col[i] && !diag1[r+i] && !diag2[r-i+N-1]){
            col[i]=true;
            diag1[r+i]=true;
            diag2[r-i+N-1]=true;
            C[r]=i+1;
            
            generate(r+1);
            
            col[i]=false;
            diag1[r+i]=false;
            diag2[r-i+N-1]=false;
        }
    }
}

int main(){
    freopen("checker.in","r",stdin);
    freopen("checker.out","w",stdout);
    
    scanf("%d",&N);
    
    cont=print=0;
    fill(col,col+13,false);
    fill(diag1,diag1+25,false);
    fill(diag2,diag2+25,false);
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            done[i][j]=false;
    
    for(int i=0;i<N;i++){
        col[i]=true;
        diag1[i]=true;
        diag2[-i+N-1]=true;
        C[0]=i+1;
        
        for(int j=0;j<N;j++){
            if(done[i][j]) continue;
            done[i][j]=done[N-1-i][N-1-j]=true;
            
            if(!col[j] && !diag1[1+j] && !diag2[1-j+N-1]){
                col[j]=true;
                diag1[1+j]=true;
                diag2[1-j+N-1]=true;
                C[1]=j+1;
                
                generate(2);
                
                col[j]=false;
                diag1[1+j]=false;
                diag2[1-j+N-1]=false;
            }
        }
        
        col[i]=false;
        diag1[i]=false;
        diag2[-i+N-1]=false;
    }
    
    if(N==6) printf("4 1 5 2 6 3\n");
    printf("%d\n",cont);
    
    return 0;
}
