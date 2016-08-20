#include <bits/stdc++.h>
using namespace std;
int searchit(long int n,long int *x,long int low,long int high){
    long int mid=low+(high-low)/2;
    if (low<=high){
        if(n>=x[mid]){
            return searchit(n,x,mid+1,high);
        }
        else{
            return searchit(n,x,low,mid-1);
        }
    }
    else{
        return mid;
    }
}
int main(){
    long int n,i,q,j;
    cin>>n;
    long int x[n];
    for(i=0;i<n;i++){
        cin>>x[i];
    }
    sort(x,x+n);
    cin>>q;
    long int m[q];
    for(i=0;i<q;i++){
        cin>>m[i];
    }
    int c;
    for(i=0;i<q;i++){
        c=searchit(m[i],x,0,n-1);
        cout<<c<<endl;
    }
return 0;
}
