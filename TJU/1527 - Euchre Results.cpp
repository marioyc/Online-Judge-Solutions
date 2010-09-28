#include<iostream>
using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int a,b,c,d,e,f;
    int s1,s2;
    while(true){
        scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
        if(a==0 && b==0 && c==0 && d==0 && e==0 && f==0) break;
        s1=a+c+e;
        s2=b+d+f;
        cout<<"Anna's won-loss record is "<<(2*s2-s1)/3<<"-"<<(2*s1-s2)/3<<"."<<endl;
    }
    return 0;
}
