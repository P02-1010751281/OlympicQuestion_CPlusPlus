#include <cstdio>

const int Maxn = 7000000 + 5;

long long BagWeight,ThingsKinds,TotalKinds;
long long Answer[Maxn],Weight[Maxn],Value[Maxn],ThingsNumber[Maxn];

long long Max(long long X,long long Y){
	return X > Y ? X : Y;
}

void ReadAndPrepare(){
	long long TmpW,TmpV,TmpN;
	scanf("%lld%lld%lld",&TmpW,&TmpV,&TmpN);
	if(TmpN == -1) 
		TmpN = BagWeight / TmpW;
	for(long long i = 1;i <= TmpN;i <<= 1){
		Weight[++TotalKinds] = TmpW * i;
		Value[TotalKinds] = TmpV * i;
		TmpN -= i;
	}
	if(TmpN > 0){
		Weight[++TotalKinds] = TmpW * TmpN;
		Value[TotalKinds] = TmpV * TmpN;
	}
}

void Dp(){
	for(long long i = 1;i <= TotalKinds;i++)
		for(long long j = BagWeight;j >= Weight[i];j--)
			Answer[j] = Max(Answer[j - Weight[i]] + Value[i],Answer[j]);
}

int main(){
	scanf("%lld%lld",&ThingsKinds,&BagWeight);
	for(long long i = 1;i <= ThingsKinds;i++) 
		ReadAndPrepare();
	Dp();
	printf("%lld",Answer[BagWeight]);
	return 0;
}
