#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N;
    int reversed;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        reversed=0;
        
        for(int i=0;i<31;i++)
            if((N&(1<<i))!=0) reversed|=(1<<(30-i));
        
        while(reversed!=0 && reversed%2==0) reversed/=2;
        
        printf("%d\n",reversed);
    }
    
    return 0;
}
