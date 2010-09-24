#include<iostream>
#include<cmath>

#define PI acos(-1)

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    double AB,dist;
    double x1,y1,x2,y2,CMD,ENF;
    
    while(cin>>x1>>y1>>x2>>y2>>CMD>>ENF){
        AB=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
        
        dist=AB*(1/tan(CMD*PI/180)+1/tan(ENF*PI/180));
        
        printf("%.3f\n",dist);
    }
}
