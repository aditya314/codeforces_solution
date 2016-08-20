#include <bits/stdc++.h>
using namespace std;
int main(){
	const int n=5;
	int hm[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>hm[i][j];
		}
	}
	vector <int> q(n,0);
	for(int k=0;k<n;k++){
		q[k]=k;
	}
	int cm(0);
	do{
		int result=hm[q[0]][q[1]]+hm[q[1]][q[0]];
		result+=hm[q[1]][q[2]]+hm[q[2]][q[1]];
		result+=2*(hm[q[2]][q[3]]+hm[q[3]][q[2]]);
		result+=2*(hm[q[3]][q[4]]+hm[q[4]][q[3]]);
		if(result>cm){
			cm=result;
		}
	}while(next_permutation(q.begin(),q.end()));
	cout<<cm;
	return 0;
}
