#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct cow{
    int v,x;
    
    bool operator < (cow X) const{
        return v<X.v;
    }
};

long long tree1[20001];
long long tree2[20001];

void update(long long T[], int idx, int val){
    for(;idx<20001;idx+=(idx & -idx)) T[idx]+=val;
}

long long F(long long T[], int idx){
    long long sum=0;
    
    for(;idx>0;idx-=(idx & -idx)) sum+=T[idx];
    
    return sum;
}

int main(){    
    int N;
    
    cin>>N;
    
    vector<cow> a(N);
    
    for(int i=0;i<N;i++) cin>>a[i].v>>a[i].x;
    
    sort(a.begin(),a.end());
    
    memset(tree1,0,sizeof(tree1));
    memset(tree2,0,sizeof(tree2));
    
    long long ans=0;
    
    update(tree1,a[0].x,1);
    update(tree2,a[0].x,a[0].x);
    
    long long s1,n1,s2,n2;
    
    for(int i=1;i<N;i++){
        n1=F(tree1,a[i].x);
        s1=F(tree2,a[i].x);
        
        n2=F(tree1,20000);
        s2=F(tree2,20000);
        
        ans+=a[i].v*(n1*a[i].x-s1+(s2-s1)-(n2-n1)*a[i].x);
        
        update(tree1,a[i].x,1);
        update(tree2,a[i].x,a[i].x);
    }
    
    cout<<ans<<endl;
    
    return 0;
}
