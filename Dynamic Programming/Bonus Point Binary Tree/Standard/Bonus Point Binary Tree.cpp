#include <algorithm>
#include <cstdio>

const int Maxn = 500 + 5;

int Node;
int Array[Maxn];

struct Tree{
	long long N;
	int Root;
}Equation[Maxn][Maxn];

void Dp(){
	for(int L = 1;L < Node;++ L){
		Equation[L][L + 1].N = Equation[L][L].N + Equation[L + 1][L + 1].N;
		Equation[L][L + 1].Root = L;
	}
	int R;
	long long Tmp;
	for(int k = 2;k < Node;++ k){
		for(int L = 1;L <= Node;++ L){
			R = L + k;
			for(int j = L + 1;j < R;++ j){
				Tmp = Equation[L][j - 1].N * Equation[j + 1][R].N + Array[j];
				if(Tmp > Equation[L][R].N){
					Equation[L][R].N = Tmp;
					Equation[L][R].Root = j;
				}
//				Equation[L][R] = std::max(Equation[L][R],Equation[L][j - 1] * Equation[j + 1][R] + Array[j]);
			}
		}
	}
}

void Read(){
	scanf("%d",&Node);
	for(int i = 1;i <= Node;++ i){
		scanf("%d",&Array[i]);
		Equation[i][i].N = Array[i];
		Equation[i][i].Root = i;
	}
}

void Print(int L,int R){
	if(L == R) printf("%d ",Equation[L][L].Root);
	else {
		printf("%d ",Equation[L][R].Root);
		if(L < Equation[L][R].Root)
			Print(L,Equation[L][R].Root - 1);
		if(R > Equation[L][R].Root)
			Print(Equation[L][R].Root + 1,R);
	}
}

int main(){
	Read();
	Dp();
	printf("%lld\n",Equation[1][Node].N);
	Print(1,Node);
	return 0;
}
