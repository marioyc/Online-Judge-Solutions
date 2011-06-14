#include <cstdio>
#include <cstring>

using namespace std;

bool used[26],found = false;
int N,M[5][5],sumR[5],sumC[5],sumD1 = 0,sumD2 = 0,needR[5],needC[5],needD1,needD2,S;

void search(int n){
    //cout << "n = " << n << endl;
    if(found) return;
    
    if(n == 0){
        found = true;
        return;
    }
    
    if(used[n]) search(n-1);
    else{
        for(int r = 0;r < N;++r) for(int c = 0;c < N;++c){
            
            if(M[r][c] == 0 && sumR[r]+n <= S && sumC[c]+n <= S){
                sumR[r] += n;
                sumC[c] += n;
                M[r][c] = n;
                
                --needR[r];
                --needC[c];
                
                if(r == c) sumD1 += n, --needD1;
                if(r+c == N-1) sumD2 += n, --needD2;
                
                //cout << "r = " << r << ", c = " << c << ", sr = " << sumR[r] << ", sc = " << sumC[c] << ", sd1 = " << sumD1 << ", sd2 = " << sumD2 << ", need1 = " << needD1 << ", need2 = " << needD2 << endl;
                
                if(sumD1 <= S && sumD2 <= S && (needR[r] > 0 || sumR[r] == S) && (needC[r] > 0 || sumC[c] == S)
                    && (needD1 > 0 || sumD1 == S) && (needD2 > 0 || sumD2 == S))
                        search(n-1);
                
                if(found) return;
                
                sumR[r] -= n;
                sumC[c] -= n;
                M[r][c] = 0;
                
                ++needR[r];
                ++needC[c];
                
                if(r == c) sumD1 -= n, ++needD1;
                if(r+c == N-1) sumD2 -= n, ++needD2;
            }
        }
    }
}

int main(){
    scanf("%d",&N);
    S = N * (N*N + 1) / 2;
    
    memset(used,false,sizeof(used));
    memset(sumR,0,sizeof(sumR));
    memset(sumC,0,sizeof(sumC));
    
    for(int i = 0;i < N;++i)
        needR[i] = needC[i] = N;
    
    needD1 = needD2 = N;
    
    for(int i = 0;i < N;++i) for(int j = 0;j < N;++j){
        scanf("%d",&M[i][j]);
        
        if(M[i][j] != 0){
            used[M[i][j]] = true;
            sumR[i] += M[i][j]; --needR[i];
            sumC[j] += M[i][j]; --needC[j];
            if(i == j) sumD1 += M[i][j], --needD1;
            if(i+j == N-1) sumD2 += M[i][j], --needD2;
        }
    }
    
    search(N*N);
    
    if(found){
        for(int i = 0;i < N;++i){
            printf("%d",M[i][0]);
            for(int j = 1;j < N;++j) printf(" %d",M[i][j]);
            printf("\n");
        }
    }else puts("-1");
    
    return 0;
}
