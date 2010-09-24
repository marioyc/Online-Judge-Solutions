#include<iostream>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int r,w,l;
    int caso=1;
    
    while(1){
        scanf("%d",&r);
        if(r==0) break;
        
        scanf("%d %d",&w,&l);
        
        if(w*w+l*l>4*r*r) printf("Pizza %d does not fit on the table.\n",caso);
        else printf("Pizza %d fits on the table.\n",caso);
        caso++;
    }
    
    return 0;
}
