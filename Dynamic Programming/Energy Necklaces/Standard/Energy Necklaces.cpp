#include <algorithm>
#include <cstdio>

const int Maxn = 1000 + 5;

struct bead{
	int Head;
	int Tail;
}Bead[Maxn];

int Sum;
int Equation[Maxn][Maxn];

int Dp(){
	for(int k = 1;k < Sum;k++){
		for(int L = 1;L <= Sum*2-1;L++){
			int R = L + k;
			for(int Mid = L;Mid < R;Mid++){
				Equation[L][R] = std::max(Equation[L][R],Equation[L][Mid] + Equation[Mid + 1][R] + Bead[L].Tail * Bead[Mid].Head * Bead[R].Head);
				//printf("L:%d R:%d %d\n",L,R,Equation[L][R]);
			}
		}
	}
//	int Ans = 0x7fffffff;
	int Ans = 0;
	for(int i = 1;i <= Sum;i++)
		Ans = std::max(Ans,Equation[i][i + Sum - 1]);
	return Ans;	
}

void Read(){
	scanf("%d",&Sum);
	for(int i = 1;i <= Sum;i++){
		scanf("%d",&Bead[i].Head);
		Bead[i + 1].Tail = Bead[i].Head;
	}
	Bead[1].Tail = Bead[Sum].Head;
	for(int i = 1;i <= Sum;i++)
		Bead[Sum + i] = Bead[i];
}

int main(){
	Read();
	printf("%d",Dp());
	return 0;
}
