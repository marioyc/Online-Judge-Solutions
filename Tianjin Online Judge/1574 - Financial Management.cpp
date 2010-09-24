#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    freopen("in2.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    double sum,aux;
    
    sum=0;
    
    for(int i=0;i<12;i++){
        cin>>aux;
        sum+=aux;
    }
    
    printf("$%.2f\n",sum/12);
}
