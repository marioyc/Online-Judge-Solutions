#include<iostream>
#include<cmath>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int s,cant,caso=1;
    
    int final_sz;
    
    while(1){
        scanf("%d",&s);
        
        if(s==0) break;
        
        s=(s+1)/2;
        
        s=s+(s+1)/2;
        
        cant=ceil(s/1860000.0);
        
        printf("File #%d\nJohn needs %d floppies.\n\n",caso,cant);        
        caso++;
    }
    
    return 0;   
}
