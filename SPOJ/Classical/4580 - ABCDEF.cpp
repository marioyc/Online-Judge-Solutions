#include <cstdio>
#include <algorithm>

using namespace std;

void readInt(int &n){
    int sign = 1;
    char c;
    bool found = false;
    n = 0;
    
    while(true){
    	c = getc(stdin);
    	
        switch(c){
            case '-' :
                sign = -1;
                found = true;
                break;
            case ' ':
                if(found) goto jump;
                break;
            case '\n':
                if(found) goto jump;
                break;
            default:
                if(c>='0' && c<='9'){
                    n = n*10+c-'0';
                    found = true;
                }else goto jump;
                break;
        }
    }
    
    jump:
        n *= sign;
}

int szB,szC,contB[1000000],contC[1000000];
int B[1000000],C[1000000];

int main(){
    int N;
    readInt(N);
    
    int A[N];
    
    for(int i = 0;i<N;++i)
        readInt(A[i]);
    
    szB = szC = 0;
    
    for(int a = 0;a<N;++a)
        for(int b = 0;b<N;++b)
            for(int c = 0;c<N;++c)
                B[szB++] = A[a]*A[b]+A[c];
    
    for(int d = 0;d<N;++d)
        if(A[d]!=0)
            for(int e = 0;e<N;++e)
                for(int f = 0;f<N;++f)
                    C[szC++] = A[d]*(A[e]+A[f]);
    
    sort(B,B+szB);
    sort(C,C+szC);
    
    int n = 1,m = 1;
    contB[0] = contC[0] = 1;
    
    for(int i = 1;i<szB;++i){
        if(B[i]!=B[n-1]){
            B[n] = B[i];
            contB[n] = 1;
            ++n;
        }else ++contB[n-1];
    }
    
    for(int i = 1;i<szC;++i){
        if(C[i]!=C[m-1]){
            C[m] = C[i];
            contC[m] = 1;
            ++m;
        }else ++contC[m-1];
    }
    
    long long ans = 0;
    
    for(int i = 0,j = 0;i<n && j<m;){
        if(B[i]==C[j]) ans += (long long)contB[i]*contC[j];
        
        if(B[i]>C[j]) ++j;
        else if(B[i]<C[j]) ++i;
        else{
            ++i;
            ++j;
        }
    }
    
    printf("%lld\n",ans);
    
    return 0;
}
