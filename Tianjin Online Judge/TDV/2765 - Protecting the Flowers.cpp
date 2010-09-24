#include<iostream>
#include<vector>

using namespace std;

struct cow{
    int T,D;
    
    cow(int a, int b){
        T=a;
        D=b;
    }
    
    bool operator < (cow X) const{
        if(T!=X.T) return T<X.T;
        return D>X.D;
    }
};

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    vector<cow> L;
    int N,T,D;
    long long sum,min_D;
    
    scanf("%d",&N);
    
    sum=0;
    
    for(int i=0;i<N;i++){
        scanf("%d %d",&T,&D);
        L.push_back(cow(T,D));
        sum+=D;
    }
    
    sort(L.begin(),L.end());
    
    min_D=0;
    
    for(int i=0;i<N;i++){
        sum-=L[i].D;
        min_D+=2*L[i].T*sum;
    }
    
    cout<<min_D<<endl;
    
    return 0;
}
