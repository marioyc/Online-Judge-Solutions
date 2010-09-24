#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    int T;
    char M[9][10];
    bool ok;
    bool r[9][9];
    bool c[9][9];
    bool sq[9][9];
    int cont_r[9];
    int cont_c[9];
    int cont_sq[9];
    
    scanf("%d",&T);
    
    for(int sc=1;sc<=T;sc++){
        for(int i=0;i<9;i++) scanf("%s",M[i]);
        
        for(int i=0;i<9;i++){
            fill(r[i],r[i]+9,false);
            fill(c[i],c[i]+9,false);
            fill(sq[i],sq[i]+9,false);
            fill(cont_r,cont_r+9,0);
            fill(cont_c,cont_c+9,0);
            fill(cont_sq,cont_sq+9,0);
        }
        
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(M[i][j]!='0'){
                    cont_r[i]++;
                    r[i][M[i][j]-'0'-1]=true;
                    cont_c[j]++;
                    c[j][M[i][j]-'0'-1]=true;
                    cont_sq[i/3*3+j/3]++;
                    sq[i/3*3+j/3][M[i][j]-'0'-1]=true;
                }
        
        ok=false;
        
        while(!ok){
            ok=true;
            
            
            for(int i=0;i<9;i++)
                for(int j=0;j<9;j++)
                    if(M[i][j]=='0'){
                        ok=false;
                        if(cont_r[i]==8){
                            cont_r[i]++;
                            cont_c[j]++;
                            cont_sq[i/3*3+j/3]++;
                            
                            for(int k=0;k<9;k++)
                                if(!r[i][k]){
                                    r[i][k]=true;
                                    c[j][k]=true;
                                    sq[i/3*3+j/3][k]=true;
                                    M[i][j]='0'+k+1;
                                }
                        }else if(cont_c[j]==8){
                            cont_r[i]++;
                            cont_c[j]++;
                            cont_sq[i/3*3+j/3]++;
                            
                            for(int k=0;k<9;k++)
                                if(!c[j][k]){
                                    r[i][k]=true;
                                    c[j][k]=true;
                                    sq[i/3*3+j/3][k]=true;
                                    M[i][j]='0'+k+1;
                                }
                        }else if(cont_sq[i/3*3+j/3]==8){
                            cont_r[i]++;
                            cont_c[j]++;
                            cont_sq[i/3*3+j/3]++;
                            
                            for(int k=0;k<9;k++)
                                if(!sq[i/3*3+j/3][k]){
                                    r[i][k]=true;
                                    c[j][k]=true;
                                    sq[i/3*3+j/3][k]=true;
                                    M[i][j]='0'+k+1;
                                }
                        }
                    }
        }
        
        printf("Scenario #%d:\n",sc);
        for(int i=0;i<9;i++) printf("%s\n",M[i]);
        printf("\n");
    }
    
    return 0;
}
