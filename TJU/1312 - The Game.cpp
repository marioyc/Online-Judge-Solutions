#include <cstdio>

using namespace std;

int main(){
    int T,M[19][19],cont;
    bool found;
    
    scanf("%d",&T);
    
    while(T--){
        for(int i = 0;i<19;++i)
            for(int j = 0;j<19;++j)
                scanf("%d",&M[i][j]);
        
        found = false;
        
        for(int i = 0;i<19 && !found;++i){
            for(int j = 0;j<19 && !found;++j){
                if(M[i][j]!=0){
                    if(i==0 || j==0 || M[i-1][j-1]!=M[i][j]){
                        cont = 0;
                        
                        while(i+cont<19 && j+cont<19 && M[i+cont][j+cont]==M[i][j])
                            ++cont;
                        
                        if(cont==5){
                            found = true;
                            printf("%d\n%d %d\n",M[i][j],i+1,j+1);
                            break;
                        }
                    }
                    
                    if(i==18 || j==0 || M[i+1][j-1]!=M[i][j]){
                        cont = 0;
                        
                        while(i-cont>=0 && j+cont<19 && M[i-cont][j+cont]==M[i][j])
                            ++cont;
                        
                        if(cont==5){
                            found = true;
                            printf("%d\n%d %d\n",M[i][j],i+1,j+1);
                            break;
                        }
                    }
                    
                    if(i==0 || M[i-1][j]!=M[i][j]){
                        cont = 0;
                        
                        while(i+cont<19 && M[i+cont][j]==M[i][j])
                            ++cont;
                        
                        if(cont==5){
                            found = true;
                            printf("%d\n%d %d\n",M[i][j],i+1,j+1);
                            break;
                        }
                    }
                    
                    if(j==0 || M[i][j-1]!=M[i][j]){
                        cont = 0;
                        
                        while(j+cont<19 && M[i][j+cont]==M[i][j])
                            ++cont;
                        
                        if(cont==5){
                            found = true;
                            printf("%d\n%d %d\n",M[i][j],i+1,j+1);
                            break;
                        }
                    }
                }
            }
        }
        
        if(!found) printf("0\n");
    }
    
    return 0;
}
