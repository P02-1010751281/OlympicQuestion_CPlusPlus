#include <algorithm>
#include <cstdio>

const int Maxn = 100 + 5;

int Lenth;
int Array[Maxn];
int Equation[Maxn][Maxn],Sum[Maxn][Maxn];

void Read(){
	scanf("%d",&Lenth);
	for(int i = 1;i <= Lenth;i++)
		scanf("%d",&Array[i]);
}

void Prepare(){
	for(int i = 1;i <= Lenth;i++)
		for(int j = i;j <= Lenth;j++)
			Sum[i][j] = Sum[i][j - 1] + Array[j];
}

int DP(){
	Prepare();
	for(int l = Lenth;l >= 1;l--){
		for(int r = l + 1;r <= Lenth;r++){
//			if(l <= r){
				int Min = 0x7fffffff;
				for(int Mid = l;Mid < r;Mid++){
					Min = std::min(Min,Equation[l][Mid] + Equation[Mid + 1][r] + Sum[l][r]);
				}
				Equation[l][r] = Min;
//			}
		}
	}
	return Equation[1][Lenth];
}

int main(){
	Read();
	printf("%d",DP());
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
