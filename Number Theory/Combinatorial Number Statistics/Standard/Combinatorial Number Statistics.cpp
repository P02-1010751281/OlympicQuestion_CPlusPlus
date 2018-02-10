#include <cstdio>

const int Maxn = 2000 + 5;

int C_Number[Maxn][Maxn];
int Equation[Maxn][Maxn];
int T,K;
int M,N;

int Prepare(){
	C_Number[1][1] = 1;
	for(int i = 0;i <= 2000;i++) 
		C_Number[i][0] = 1;
	for(int i = 2;i <= 2000;i++){
		for(int j = 1;j <= i;j++)
			Equation[i][j] = Equation[i - 1][j] + Equation[i][j - 1] - Equation[i - 1][j - 1] + ((C_Number[i][j] = (C_Number[i - 1][j] + C_Number[i - 1][j - 1]) % K) ? 0 : 1);
		Equation[i][i + 1] = Equation[i][i];
	}
}

void Solve(){
	for(int i = 1;i <= T;i++){
		scanf("%d%d",&N,&M);
		M = M > N ? N : M;
		printf("%d\n",Equation[N][M]);
	} 
}
 
void Read(){
	scanf("%d%d",&T,&K);
}

int main(){
	Read();
	Prepare();
	Solve();
	return 0;
}
