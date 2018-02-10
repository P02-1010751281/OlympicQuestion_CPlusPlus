#include <cstdio>

const int maxn = 1000;

bool Used[maxn];
int Permutation[maxn],Lenth;

void FullPermutation(int Len){
	if(Len <= Lenth){
		for(int i = 1; i <= Lenth;i++){
			if(!Used[i]){
				Permutation[Len] = i;
				Used[i] = 1;
				FullPermutation(Len+1);
				Used[i] = 1;
			}
		}
	} else for(int i = 1;i < Len;i++) printf("%d",Permutation[i]);
	return ;
}

int main(){
	scanf("%d",&Lenth);
	FullPermutation(1);
	return 0;
}