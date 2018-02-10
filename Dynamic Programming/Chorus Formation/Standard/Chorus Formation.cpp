#include <cstdio>
#include <iostream>

const int Maxn = 100000 + 5;
int Array[Maxn],LIS[Maxn],LDS[Maxn];
int Lenth;

int DpLIS(){
	for(int i = 1;i <= Lenth;i++){
		for(int j = 0;j < i;j++)
			if(Array[j] < Array[i] && LIS[j] > LIS[i])
				LIS[i] = LIS[j];
		LIS[i]++;
	}
}

void DpLDS(){
	for(int i = Lenth;i >= 1;i--){
		for(int j = Lenth;j > i;j--){
			if(Array[j] < Array[i] && LDS[j] > LDS[i])
				LDS[i] = LDS[j];
		}
		LDS[i]++;
	}
}

int Solve(){
	int Ans = 101;
	DpLIS();
	DpLDS();
	for(int i = 1;i <= Lenth;i++)
		Ans = std::min(Ans,Lenth - LIS[i] - LDS[i] + 1);
 	return Ans;
}

void Read(){
	scanf("%d",&Lenth);
	for(int i = 1;i <= Lenth;i++) scanf("%d",&Array[i]);
}

int main(){
	Read();
	printf("%d",Solve());
	return 0;
}
