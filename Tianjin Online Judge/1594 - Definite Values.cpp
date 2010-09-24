#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n,test_case=1;;
    
    char c1,c2;
    
    int mask;
    
    while(1){
        scanf("%d\n",&n);
        if(n==0) break;
        
        printf("Program #%d\n",test_case);
        test_case++;
        
        mask=1;
        
        for(int i=0;i<n;i++){
            scanf("%c = %c\n",&c1,&c2);
                        
            c1-='a';
            c2-='a';
            
            if((mask&(1<<c2))!=0)  mask|=(1<<c1);
            else if((mask&(1<<c1))!=0) mask-=(1<<c1);
        }
        
        n=__builtin_popcount(mask);
        
        if(n==0) printf("none\n\n");
        else{
            for(int i=0,j=0;j<n;i++){
                if((mask&(1<<i))!=0){
                    printf("%c ",'a'+i);
                    j++;
                }
            }
            printf("\n\n");
        }
    }

    return 0;
}
