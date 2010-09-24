#include<iostream>
#include<algorithm>

using namespace std;

int main(){    
    long long a,b,c;
    int cont,n,m,x,y;
    
    while(cin>>a>>b>>c){
        cont=0;
        n=(b-a+1)/c;
        m=(b-a+1)-n*c;
        
        for(int i=0,j;i<c;i++){
            if(i>c/2 && (a+i)%c!=0 || (c%2==0 && i==c/2 && ((a+i)%c!=c/2 && (a+i)%c!=0))) continue;
            
            if(i<m) x=n+1;
            else x=n;
            
            if((a+i)%c==0) cont+=x/2;
            else if(c%2==0 && (a+i)%c==c/2) cont+=x/2;
            else{
                j=c-i;
                if(j<m) y=n+1;
                else y=n;
                cont+=min(x,y);
            }
        }
        
        cout<<cont<<endl;
    }
    
    return 0;
}
