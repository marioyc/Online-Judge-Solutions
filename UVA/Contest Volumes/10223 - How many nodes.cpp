#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    long long C[]={1,2,5,14,42,132,429,1430,4862,16796,58786,208012,742900,2674440,9694845,35357670,129644790,477638700,1767263190};

    long long n;

    while(cin>>n){
        for(int i=0;i<19;i++){
            if(C[i]==n){
                cout<<i+1<<endl;
                break;
            }
        }
    }
}
