#include<cstdio>

using namespace std;

bool M[5][5];
bool used[5][5];
int ans[9];
int cont;

void routes(){
    if(cont==8){
        for(int i=0;i<9;i++) printf("%d",ans[i]+1);
        printf("\n");
        
        return;
    }
    
    for(int i=0;i<5;i++){
        if(M[ans[cont]][i] && !used[ans[cont]][i]){
            used[ans[cont]][i]=true;
            used[i][ans[cont]]=true;
            ans[++cont]=i;
            
            routes();
            
            cont--;
            used[ans[cont]][i]=false;
            used[i][ans[cont]]=false;
        }
    }
}

int main(){    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            M[i][j]=false;
            used[i][j]=false;
        }
    }
    
    M[0][1]=M[0][2]=M[0][4]=true;
    M[1][0]=M[1][2]=M[1][4]=true;
    M[2][0]=M[2][1]=M[2][3]=M[2][4]=true;
    M[3][2]=M[3][4]=true;
    M[4][0]=M[4][1]=M[4][2]=M[4][3]=true;
    
    cont=0;
    ans[0]=0;
    routes();
    
    return 0;
}
