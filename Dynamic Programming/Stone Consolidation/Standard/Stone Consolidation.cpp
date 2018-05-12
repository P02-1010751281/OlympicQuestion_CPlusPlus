#include <algorithm>
#include <cstdio>

const int Maxn = (400 + 5) << 1;

int Lenth;
int Array[Maxn];
int EquationMin[Maxn][Maxn],EquationMax[Maxn][Maxn];
int Sum[Maxn];

void Read(){
	scanf("%d",&Lenth);
	for(int i = 1;i <= Lenth;++ i){
		scanf("%d",&Array[i]);
		Array[i + Lenth] = Array[i];
		Sum[i] = Sum[i - 1] + Array[i];
	}
	for(int i = Lenth + 1;i <= (Lenth << 1);++ i)
		Sum[i] = Sum[i - 1] + Array[i];
}

void DP(){
	for(int l = (Lenth << 1) - 1;l;-- l){
		for(int r = l + 1;r < Lenth + l && r <= (Lenth << 1);++ r){
			EquationMin[l][r] = 0x7fffffff;
			for(int Mid = l;Mid < r;++ Mid){
				EquationMin[l][r] = std::min(EquationMin[l][r],EquationMin[l][Mid] + EquationMin[Mid + 1][r] - Sum[l - 1] + Sum[r]);
				EquationMax[l][r] = std::max(EquationMax[l][r],EquationMax[l][Mid] + EquationMax[Mid + 1][r] - Sum[l - 1] + Sum[r]);
			}
		}
	}
}

void Ans(){
	int Min = 0x7fffffff,Max = 0;
	for(int i = 1;i <= Lenth;++ i){
		Min = std::min(Min,EquationMin[i][i + Lenth - 1]);
		Max = std::max(Max,EquationMax[i][i + Lenth - 1]);
	}
	printf("%d\n",Min);
	printf("%d",Max);
}

int main(){
	Read();
	DP();
	Ans();
	return 0;
}
/*
//#include <queue>
#include <cstdio>

const int Maxn = 100 + 5;

int Lenth;
int Array[Maxn];
//std::priority_queue < int > PQueue;
	
void Read(){
	scanf("%d",&Lenth);
	for(int i = 1;i <= Lenth;i++)
		scanf("%d",&Array[i]);
}
*/
/*
int Greedy(){
	int Ans = 0;
	for(int i = 1;i <= Lenth;i++)
		PQueue.push(-Array[i]);
	while(PQueue.size() > 1){
		int Tmp = PQueue.top();
		PQueue.pop();
		Tmp += PQueue.top();
		Ans += -Tmp;
		PQueue.pop();
		PQueue.push(Tmp);
	}
	return Ans;
}//?
*/
/*
int main(){
	Read();
//	printf("%d",Greedy());
	return 0;
}
*/
//CODEVS 1048
