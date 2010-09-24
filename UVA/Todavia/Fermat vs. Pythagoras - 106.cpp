#include<iostream>
#include<cmath>
#include<map>

using namespace std;

int mcd(int a, int b){
    if(a%b==0) return b;
    return mcd(b%a,a);
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,m,n,cont1,cont2;
    
    while(cin>>N){
        cont1=0;
        
        map<int, bool> M;
        
        for(int i=1;i<=N;i++){
            for(m=ceil(sqrt(i*1.0/2));m<sqrt(i);m++){
                n=round(sqrt(i-m*m));
                if(m*m+n*n==i){
                    if(mcd(mcd(m*m-n*n,2*m*n),m*m+n*n)==1) cont1++;
                    M[m*m-n*n]=1;
                    M[2*m*n]=1;
                    M[m*m+n*n]=1;
                }
            }
        }
        
        cont2=0;
        for(int i=1;i<=N;i++) if(!M[i]) cont2++;
        
        cout<<cont1<<" "<<cont2<<endl;
    }
    
    return 0;
}
