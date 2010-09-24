#include<cstdio>
#include<cstring>

using namespace std;

int inv(int &a, int &mod){
    for(int i=1;i<mod;i++)
        if((a*i)%mod==1) return i;    
}

int main(){    
    int n,k,k_inv,plaincode,ciphercode[71];
    char ciphertext[71];
    
    while(1){
        scanf("%d",&k);
        if(k==0) break;
        
        scanf("%s",ciphertext);
        
        n=strlen(ciphertext);
        
        for(int i=0;i<n;i++){
            if(ciphertext[i]=='_') ciphercode[i]=0;
            else if(ciphertext[i]=='.') ciphercode[i]=27;
            else ciphercode[i]=ciphertext[i]-'a'+1;
        }
        
        k_inv=inv(k,n);
        
        for(int i=0;i<n;i++){
            plaincode=((k_inv*i)%n+ciphercode[(k_inv*i)%n])%28;
            
            if(plaincode==0) printf("_");
            else if(plaincode==27) printf(".");
            else printf("%c",'a'+plaincode-1);
        }
        
        printf("\n");
    }
    
    return 0;
}
