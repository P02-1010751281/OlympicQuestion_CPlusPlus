#include <cstdio>

const int Maxn = 50000 + 5;
const int Mod = 10007;

int N,M;
int Left,Right;
int Time[Maxn],Sum[Maxn],Position;

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

//int Binary(){
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

int Binary(){
	int Midium;
	while(Left < Right){
		Midium = (Left + Right) / 2;
		if(Check(Midium)) Right = Midium;
		else Left = Midium;
	}
	return Left;
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
	printf("%d",Binary());
	return 0;
}
