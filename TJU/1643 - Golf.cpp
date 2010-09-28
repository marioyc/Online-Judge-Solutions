#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int p,s,caso=1;
    
    while(1){
        scanf("%d %d",&p,&s);
        
        if(p==0) break;
        
        printf("Hole #%d\n",caso);
        caso++;
        
        if(s==1) printf("Hole-in-one.\n\n");
        else if(p==s) printf("Par.\n\n");
        else if(p-s==1) printf("Birdie.\n\n");
        else if(s-p==1) printf("Bogey.\n\n");
        else if(p-s==2) printf("Eagle.\n\n");
        else if(p-s==3) printf("Double Eagle.\n\n");
        else printf("Double Bogey.\n\n");
    }
    
    return 0;
}
