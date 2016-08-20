#include <bits/stdc++.h>
using namespace std;
#define linf 2000000000000000000LL
#define bit(mask,i) ((mask>>i)&1)
const int mb=63;
long long c[mb+1][mb+1];
int bcount(long long x){
	int res=0;
	for(;x;x&=(x-1)){
		res++;
	}
	return res;
}
long long solve(long long x,int k){
	long long answer=(k==bcount(x));
	for(int i=mb;i>=0&& k>=0;i--){
		if(bit(x,i)){
			answer+=c[i][k--];
		}
	}
	return answer;
}
int main(){
	c[0][0]=1;
	for(int i=1;i<=mb;i++){
		for(int j=0;j<=i;j++){
			c[i][j]=c[i-1][j]+((j)?(c[i-1][j-1]):0);
		}
	}
	long long count;
	int k;
	cin>>count>>k;
	long long l=1,r=linf/2;
	while(l<r){/*this is a  binary search because  the function is monotone......
				the amount of numbers with exactly k 1-bits on a segment n+2........2*(n+1)
				more or equal to the amount of such numbers on segment n+1..........2*n.
				(Reason:n+1 and 2*(n+1) have equal number of 1-bits)*/
		long long m=l+(r-l)/2;
		if(solve(m*2,k)-solve(m,k)<count){/*to find the amount of numbers on segment L.......R which exactly have k i-bits
										it is sufficient to  calculate this number for segment 1........L
										then the answer will be F(1.....R)-F(1......L-1)*/
			l=m+1;
		}
		else
		{
			r=m;
		}
	}
	cout<<l;
	return 0;
}
