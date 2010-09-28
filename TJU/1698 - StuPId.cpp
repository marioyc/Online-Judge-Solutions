#include<cstdio>
#include<cstring>

using namespace std;

int solve(int a, int &b){
    for(int i=0;i<10;i++)
        if((a*i+b)%10==0) return i;
}

int main(){    
    int T,n,sum,ind,x;
    char s[8];
    
    scanf("%d",&T);
    
    for(int i=1;i<=T;i++){
        scanf("%s",s);
        n=strlen(s);
        
        sum=0;
        
        for(int j=0;j<n;j++){
            if(s[n-1-j]=='?') ind=j;
            else{
                switch(j%3){
                    case 0:
                        sum+=9*(s[n-1-j]-'0');
                        break;
                    case 1:
                        sum+=3*(s[n-1-j]-'0');
                        break;
                    case 2:
                        sum+=7*(s[n-1-j]-'0');
                        break;
                }
            }
        }
        
        sum%=10;
        
        switch(ind%3){
            case 0:
                x=solve(9,sum);
                break;
            case 1:
                x=solve(3,sum);
                break;
            case 2:
                x=solve(7,sum);
                break;
        }
        
        s[n-1-ind]='0'+x;
        
        printf("Scenario #%d:\n%s\n\n",i,s);
    }
    
    return 0;
}
