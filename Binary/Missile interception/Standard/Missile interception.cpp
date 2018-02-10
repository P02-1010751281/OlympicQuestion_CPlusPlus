#include <algorithm>
#include <cstdio>

const int Maxn = 100000+5;

int SeqLen,SubLen;
int Sequence[Maxn],Subsequence[Maxn];

int BirinaryChop(int Left,int Right,int Standard){
	int Middle = (Left + Right)/2;
	return Left == Right ? Left : (Subsequence[Middle] <= Standard ? BirinaryChop(Middle+1,Right,Standard) : BirinaryChop(Left,Middle,Standard));
}

void LUDS(){
	SubLen = 0;
	for(int i = SeqLen;i >= 1;i--){
		if(Sequence[i] >= Subsequence[SubLen]) Subsequence[++SubLen] = Sequence[i];
//		else Subsequence[BinaryChop(1,SubLen+1,Sequence[i])] = Sequence[i];
		else *std::upper_bound(Subsequence+1,Subsequence+SubLen+1,Sequence[i]) = Sequence[i];
	}
}

void LIS(){
	SubLen = 0;
	for(int i = 1;i <= SeqLen;i++){
		if(Sequence[i] > Subsequence[SubLen]) Subsequence[++SubLen] = Sequence[i];
//		else Subsequence[BinaryChop(1,SubLen,Sequence[i])] = Sequence[i];
		else *std::lower_bound(Subsequence + 1,Subsequence+SubLen+1,Sequence[i]) = Sequence[i];
	}
}

int main(){
//	freopen("in.txt", "r", stdin);
//	scanf("%d",&SeqLen);
//	for(int i = 1;i <= SeqLen;i++) scanf("%d",&Sequence[i]);
	while(scanf("%d",&Sequence[++SeqLen]) != EOF);
	SeqLen--;
	LUDS();
	printf("%d\n",SubLen);
	LIS();
	printf("%d",SubLen);
//	for(int i = 1;i <= SubLen;i++) printf("%d ",Subsequence[i]);
	return 0;
}
