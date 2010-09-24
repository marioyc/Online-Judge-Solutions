#include <iostream>
#include <algorithm>

using namespace std;

int N;
bool M1[1000][1000],M2[1000][1000],M3[1000][1000];
//M1[i][j] : ~a_i && ~a_j
//M2[i][j] : a_i && a_j
//M3[i][j] : ~a_i && a_j
bool search1[1000],search2[1000];
//search1[i] : a_i
//search2[i] : ~a_i

bool Solve(){
    for(int i=0;i<N;i++){
        search1[i]=M2[i][i];
        search2[i]=M1[i][i];
        for(int j=0;j<N;j++) if(M2[i][j] && M3[j][i]) search1[i]=true;
        for(int j=0;j<N;j++) if(M1[i][j] && M3[i][j]) search2[i]=true;
    }
    
    for(int i=0;i<N;i++) if(search1[i] && search2[i]) return true;
    
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(M1[i][j] && search1[i] && search1[j]) return true;
            if(M2[i][j] && search2[i] && search2[j]) return true;
            if(M3[i][j] && search1[i] && search2[j]) return true;
            if(M3[j][i] && search1[j] && search2[i]) return true;
        }
    }
    
    return false;
}

int main(){
    int M,a,b;
    
    while(scanf("%d%d",&N,&M)==2){
        for(int i=0;i<N;i++) fill(M1[i],M1[i]+N,false);
        for(int i=0;i<N;i++) fill(M2[i],M2[i]+N,false);
        for(int i=0;i<N;i++) fill(M3[i],M3[i]+N,false);
        
        for(int i=0;i<M;i++){
            scanf("%d %d",&a,&b);
            if(a>0 && b>0) M1[a-1][b-1]=M1[b-1][a-1]=1;
            else if(a<0 && b<0) M2[-a-1][-b-1]=M2[-b-1][-a-1]=1;
            else if(a>0 && b<0) M3[a-1][-b-1]=1;
            else M3[b-1][-a-1]=1;
        }
        
        if(Solve()) printf("0\n");
        else printf("1\n");
    }
    
    return 0;
}
