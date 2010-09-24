/*
ID:zion_ba1
LANG:C++
TASK:preface
*/

#include <iostream>

using namespace std;

int cnt[7];
char letra[7]={'I','V','X','L','C','D','M'};

void contar(int x){
    int d[4];
    
    for(int i=0;i<4;i++){
        d[i]=x%10;
        x/=10;
    }
    
    if(d[3]==1) cnt[6]++;
    else if(d[3]==2) cnt[6]+=2;
    else if(d[3]==3) cnt[6]+=3;
    
    if(d[2]==1) cnt[4]++;
    else if(d[2]==2) cnt[4]+=2;
    else if(d[2]==3) cnt[4]+=3;
    else if(d[2]==4 || d[2]==6){
        cnt[4]++;
        cnt[5]++;
    }else if(d[2]==5) cnt[5]++;
    else if(d[2]==7){
        cnt[4]+=2;
        cnt[5]++;
    }else if(d[2]==8){
        cnt[4]+=3;
        cnt[5]++;
    }else if(d[2]==9){
        cnt[4]++;
        cnt[6]++;
    }
    
    if(d[1]==1) cnt[2]++;
    else if(d[1]==2) cnt[2]+=2;
    else if(d[1]==3) cnt[2]+=3;
    else if(d[1]==4 || d[1]==6){
        cnt[2]++;
        cnt[3]++;
    }else if(d[1]==5){
        cnt[3]++;
    }else if(d[1]==7){
        cnt[2]+=2;
        cnt[3]++;
    }else if(d[1]==8){
        cnt[2]+=3;
        cnt[3]++;
    }else if(d[1]==9){
        cnt[2]++;
        cnt[4]++;
    }
    
    if(d[0]==1) cnt[0]++;
    else if(d[0]==2) cnt[0]+=2;
    else if(d[0]==3) cnt[0]+=3;
    else if(d[0]==4 || d[0]==6){
        cnt[0]++;
        cnt[1]++;
    }else if(d[0]==5) cnt[1]++;
    else if(d[0]==7){
        cnt[0]+=2;
        cnt[1]++;
    }else if(d[0]==8){
        cnt[0]+=3;
        cnt[1]++;
    }else if(d[0]==9){
        cnt[0]++;
        cnt[2]++;
    }
}

int main(){
    freopen("preface.in","r",stdin);
    freopen("preface.out","w",stdout);
    
    int n; 
    cin>>n;
    
    for(int i=0;i<7;i++) cnt[i]=0;
    
    for(int i=1;i<=n;i++) contar(i);
    
    for(int i=0;i<7;i++){
        if(cnt[i]==0) continue;
        cout<<letra[i]<<" "<<cnt[i]<<endl;
    }
    
    return 0;
}
