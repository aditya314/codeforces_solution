#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,n,i;
    double t=INT_MAX;
    cin>>a>>b;
    cin>>n;
    int x[n],y[n],v[n];
    double d[n];
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i]>>v[i];
        d[i]=sqrt(pow(a-x[i],2)+pow(b-y[i],2));
        if(t>(d[i]/v[i])){
            t=(d[i]/v[i]);
        }
    }
    printf("%lf",t);
    return 0;
}
