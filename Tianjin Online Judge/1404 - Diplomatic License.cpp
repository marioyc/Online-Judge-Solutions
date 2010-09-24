#include<iostream>
#include<vector>

using namespace std;

int main(){    
    vector<double> x;
    vector<double> y;
    int n;
    double a,b;
    
    while(scanf("%d",&n)==1){
        x.clear();
        y.clear();
        
        for(int i=0;i<n;i++){
            scanf("%lf %lf",&a,&b);
            x.push_back(a);
            y.push_back(b);
        }
        
        printf("%d",n);
        
        for(int i=0;i<n;i++) printf(" %.6lf %.6lf",(x[i]+x[(i+1)%n])/2,(y[i]+y[(i+1)%n])/2);
        printf("\n");
    }
    
    return 0;
}

