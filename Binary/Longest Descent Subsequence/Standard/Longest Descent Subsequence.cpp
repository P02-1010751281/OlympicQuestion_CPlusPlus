#include <algorithm>
#include <cstdio>

const int Maxn = 10000;

int SeqLen,SubLen;
int Sequence[Maxn],Subsequence[Maxn];

int BinaryChop(int Left,int Right,int Standard){
	int Middle = (Left + Right)/2;
	return Left == Right ? Left : (Subsequence[Middle] <= Standard ? BinaryChop(Middle+1,Right,Standard) : BinaryChop(Left,Middle,Standard));
}

void LDS(){
	for(int i = SeqLen;i >= 1;i--){
		if(Sequence[i] > Subsequence[SubLen]) Subsequence[++SubLen] = Sequence[i];
//		else Subsequence[BinaryChop(1,SubLen,Sequence[i])] = Sequence[i];
		else *std::lower_bound(Subsequence+1,Subsequence+SubLen+1,Sequence[i]) = Sequence[i];
	}
}

int main(){
//	freopen("in.txt", "r", stdin);
	scanf("%d",&SeqLen);
	for(int i = 1;i <= SeqLen;i++) scanf("%d",&Sequence[i]);
	LDS();
	printf("%d\n",SubLen);
//	for(int i = 1;i <= SubLen;i++) printf("%d ",Subsequence[i]);
	return 0;
}
