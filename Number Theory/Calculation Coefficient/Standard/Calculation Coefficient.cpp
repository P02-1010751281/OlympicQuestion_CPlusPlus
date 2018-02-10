#include <cstdio>

const long long Maxn = 1000 + 5;
const long long Mod = 10007;

long long A,B,K;
long long N,M;
long long Equation[Maxn][Maxn];

void Solve(){
	Equation[0][1] = 1;
	for(long long i = 1;i <= K;i++){
		for(long long j = 1;j <= i  + 1;j++)
			Equation[i][j] = (Equation[i - 1][j - 1] * A + Equation[i - 1][j] * B) % Mod;
	}
}

void Read(){
	scanf("%d%d%d%d%d",&A,&B,&K,&N,&M);
}

int main(){
	Read();
	Solve();
	printf("%lld",Equation[K][N + 1]);
	return 0;
}
