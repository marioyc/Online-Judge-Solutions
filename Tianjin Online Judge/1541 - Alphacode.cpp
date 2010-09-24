#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    long long a,b,c;
    int L;
    char s[5001];
    
    while(1){
        scanf("%s",s);
        if(s[0]=='0') break;
        L=strlen(s);
        
        b=1; c=0;
        for(int i=1;i<=L;i++){
            a=0;
            if(s[i-1]!='0') a+=b;
            if(i>=2 && (s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<='6'))) a+=c;
            c=b; b=a;
        }
        
        printf("%ld\n",a);
    }
    
    return 0;
}
