#include <bits/stdc++.h>
using namespace std;
int main(){
   long n,m,k,i,u,v,l,j;
   cin>>n>>m>>k;
   vector < list < pair<long long,long long> > > ver(n+1);
   for(i=1;i<=m;i++){
        cin>>u>>v>>l;
        ver[u].push_back(make_pair(v,l));
        ver[v].push_back(make_pair(u,l));
   }
   if(k==0){
        cout<<"-1"<<endl;
   }
   else{
        long long s;
        bool found=false;
        int arr[n+1];
        long long minimum=10000000001;
        vector<long long> v;
        for(i=0;i<k;i++){
            cin>>s;
            v.push_back(s);
            arr[s]=1;
        }
        for(i=0;i<k;i++){

            list< pair<long long, long long> >::iterator itr = ver[v[i]].begin();
            while (itr != ver[v[i]].end()){
                if(arr[(*itr).first]!=1){
                    minimum=(minimum>((*itr).second))?((*itr).second):minimum;
                    found=true;
                }
                itr++;
            }
        }
        if(found){
            cout<<minimum<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
   }
return 0;
}
