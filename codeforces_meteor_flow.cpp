#include <bits/stdc++.h>
using namespace std;
int main(){
	int t,tm,dm,tdm=0,temp,c=0;
	cin>>t;
	priority_queue<int> pq;
	while(t--){
		cin>>tm>>dm;
		pq.push(dm);
		tdm+=dm;
		if(tm<tdm){
			temp=pq.top();
			pq.pop();
			tdm-=temp;
			c++;
		}
	}
	cout<<c<<endl;
}
