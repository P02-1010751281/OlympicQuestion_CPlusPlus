#include <cstdio>

const int Maxn = 50000 + 5;
const int Mod = 10007;

int N,M;
int Left,Right;
int Time[Maxn],Sum[Maxn],BeginPosition[Maxn];

bool Check(int Ans){
	int TmpDay = 1,TmpTime = 0;
	for(int i = 1;i <= N;i++){
		if(TmpTime + Time[i] > Ans){
			TmpDay ++;
			TmpTime = Time[i];
		} else TmpTime += Time[i];
	}
	return TmpDay <= Ans;
}

//int Birinary(){
//	int Midium,Ans = Right;
//	while(Left <= Right){
//		Midium = (Left + Right) / 2;
//		if(Check(Midium)) {
//			Ans = Ans > Midium ? Midium : Ans;
//			Right = Midium - 1;
//		}
//		else Left = Midium + 1;
//	}
//	return Ans;
//}

int Birinary(){
	int Midium,Ans = Right;
	while(Left < Right){
		Midium = (Left + Right) / 2;
		if(Check(Midium)) Right = Midium;
		else Left = Midium;
	}
	return Left;
}

int PrepareDp(int Ans){
	for(int i = 1;i <= N;i++) Sum[i] = Sum[i-1] + Time[i];
	int Position = 1;
	for(int i = 1;i <= N;i++){
		while(Position < i && Sum[i] - Sum[Position - 1] > Ans) Position++;
		PositionBegin[i] = Position - 1;
	}
}

int DP(){
	int X = 
}

void Read(){
	scanf("%d%d",&N,&M);
	M++;
	for(int i = 1;i <= N;i++) {
		scanf("%d",&Time[i]);
		Left = Time[i] <= Left ? Left : Time[i];
		Right += Time[i];
	}
}

int main(){
	Read();
	int Ans = Birinary();
	printf("%d",Ans);
	PrepareDp(Ans);
	DP();
	return 0;
}
