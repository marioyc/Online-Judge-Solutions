#include <cstdio>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    int M[100][100];
    
    for(int i = 0;i<N;++i)
        for(int j = 0;j<N;++j)
            scanf("%d",&M[i][j]);
    
    for(int i = 0;i<2*N-1;++i){
        for(int c = 0;c<=i && c<N;++c){
            int r = i-c;
            if(r>=0 && r<N) printf("%d ",M[r][c]);
        }
    }
    
    return 0;
}
