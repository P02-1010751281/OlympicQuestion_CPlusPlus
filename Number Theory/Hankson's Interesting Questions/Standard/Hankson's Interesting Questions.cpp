#include <algorithm>
#include <cstdio>
#include <cmath>

int Times;
long long A0,A1,B0,B1;

long long Gcd(long long X,long long Y){
	return (X % Y) ? Gcd(Y,X % Y) : Y;
}

long long Lcm(long long X,long long Y){
	return X * Y / Gcd(X,Y);
}

long long Solve(){
	long long Ans = 0;
	for(long long i = 1;i * i <= B1;i++){
		if(!(B1 % i)){
			if(Gcd(A0,i) == A1 && Lcm(B0,i) == B1) Ans++;
			if(B1 / i == i) continue;
			if(Gcd(B1 / i,A0) == A1 && Lcm(B1 / i,B0) == B1) Ans++;
		}
	}	
	return Ans;
}

void Read(){
	scanf("%d",&Times);
	while(Times--){
		scanf("%lld%lld%lld%lld",&A0,&A1,&B0,&B1);
		printf("%lld\n",Solve());
	}
}

int main(){
	Read();
	return 0;
}
