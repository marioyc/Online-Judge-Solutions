#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int len[3],d[3][51];

void add(int lena, int a[], int lenb, int b[], int &lenc, int c[]){
    lenc = 0;
    
    for(int i = 0,cr = 0;i < lena || i < lenb || cr;++i, cr /= 10){
        if(i < lena) cr += a[i];
        if(i < lenb) cr += b[i];
        c[i] = cr % 10;
        ++lenc;
    }
}

int trie[4000000][10],cont = 1;
int ind[4000000];

void add(int n, int L, int num[]){
    int pos = 0;
    
    for(int i = L - 1;i >= max(0,L - 40);--i){
        if(trie[pos][ num[i] ] == 0){
            ind[cont] = n;
            trie[pos][ num[i] ] = cont++;
        }
        
        pos = trie[pos][ num[i] ];
    }
}

int find(int L, char *s){
    int pos = 0;
    
    for(int i = 0;i < L;++i){
        if(trie[pos][ s[i] - '0' ] == 0) return -1;
        pos = trie[pos][ s[i] - '0' ];
    }
    
    return ind[pos];
}

int main(){
    d[0][0] = 1;
    len[0] = 1;
    
    d[1][0] = 1;
    len[1] = 1;
    
    add(0,len[0],d[0]);
    
    for(int n = 2,i = 0,j = 1,k = 2;n < 100000;++n){
        add(len[i],d[i],len[j],d[j],len[k],d[k]);
        
        if(len[k] > 50){
            for(int i = 1;i < len[k];++i) d[k][i - 1] = d[k][i];
            --len[k];
            
            for(int i = 1;i < len[j];++i) d[j][i - 1] = d[j][i];
            --len[j];
        }
        
        add(n,len[k],d[k]);
        
        i = (i == 2? 0 : i + 1);
        j = (j == 2? 0 : j + 1);
        k = (k == 2? 0 : k + 1);
    }
    
    int tc = 1,T,L;
    char s[41];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%s",s);
        L = strlen(s);
        printf("Case #%d: %d\n",tc++,find(L,s));
    }
    
    return 0;
}
