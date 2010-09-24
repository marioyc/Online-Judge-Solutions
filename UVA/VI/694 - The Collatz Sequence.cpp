#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    long long A,L;
    int cont,caso=1;
    
    while(1){
        cin>>A>>L;
        if(A<0 && L<0) break;
        
        cout<<"Case "<<caso<<": A = "<<A<<", limit = "<<L<<", number of terms = ";
        caso++;
        
        cont=0;
        
        while(A<=L && A!=1){
            if(A%2==0) A/=2;
            else A=3*A+1;
            
            cont++;
        }
    
        if(A==1) cont++;
    
        cout<<cont<<endl;
    }

    return 0;
}
