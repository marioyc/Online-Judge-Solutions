#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int mcd(int a, int b){
    if(a%b==0) return b;
    return mcd(b,a%b);
}

int main(){    
    bool p[46341];
    vector<int> P;
    
    fill(p,p+46341,true);
    p[0]=p[1]=false;
    
    for(int i=2;i<46341;i++){
        if(p[i]){
            P.push_back(i);
            for(int j=2;j*i<46341;j++) p[j*i]=false;
        }
    }
    
    long long N;
    int n=P.size();
    int pot,cont;
    
    while(1){
        cin>>N;
        if(N==0) break;
        
        pot=-1;
        
        for(int i=0;i<n;i++){
            if(N%P[i]==0){
                cont=0;
                while(N%P[i]==0){
                    N/=P[i];
                    cont++;
                }
                if(pot==-1) pot=cont;
                else pot=mcd(pot,cont);
            }
        }
        
        if(pot==-1) pot=1;
        if(N<0){
            while(pot%2==0) pot>>=1;
        }
        
        cout<<pot<<endl;
    }
    
    return 0;
}
