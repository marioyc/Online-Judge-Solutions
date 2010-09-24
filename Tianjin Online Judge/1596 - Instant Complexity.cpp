#include<cstdio>
#include<stack>

using namespace std;

struct pol{
    int P[11];
    
    pol(){
    }
    
    pol(int a){
        P[0]=a;
        for(int i=1;i<11;i++) P[i]=0;
    }
};

pol Add(pol &a, pol b){
    pol c;
    
    for(int i=0;i<11;i++) c.P[i]=a.P[i]+b.P[i];
    
    return c;
}

pol Mult(pol &a){
    pol b;
    
    b.P[0]=0;
    for(int i=1;i<11;i++) b.P[i]=a.P[i-1];
    
    return b;
}

pol Mult(int &n, pol &a){
    pol b;
    
    for(int i=0;i<11;i++) b.P[i]=n*a.P[i];
    
    return b;
}

void print(pol &a){
    int gr=0;
    
    for(int i=10;i>=1 && gr==0;i--) if(a.P[i]!=0) gr=i;
    
    for(int i=gr;i>=1;i--){
        if(a.P[i]==0) continue;
        
        if(i!=gr) printf("+");        
        if(a.P[i]!=1) printf("%d*",a.P[i]);
        if(i==1) printf("n");
        else printf("n^%d",i);
    }
    
    if(gr==0) printf("%d",a.P[0]);
    else if(a.P[0]!=0) printf("+%d",a.P[0]);
    
    printf("\n\n");
}

int main(){    
    int T,n;
    char s[15];
    stack<pol> Q;    
    pol ans,x,y;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%s",s);
        
        for(int i=0;i<11;i++) x.P[i]=0;
        
        ans=pol(0); x=pol(1);
        
        while(1){
            scanf("%s",s);
            
            if(s[0]=='O'){
                scanf("%d",&n);
                ans=Add(ans,Mult(n,x));
            }else if(s[0]=='L'){
                Q.push(x);
                
                scanf("%s",s);
                
                if(s[0]=='n') x=Mult(x);
                else{
                    sscanf(s,"%d",&n);
                    x=Mult(n,x);
                }
            }else{
                if(Q.empty()) break;
                else{
                    x=Q.top();
                    Q.pop();
                }
            }
        }
        
        printf("Program #%d\nRuntime = ",tc);
        print(ans);
    }
    
    return 0;
}
