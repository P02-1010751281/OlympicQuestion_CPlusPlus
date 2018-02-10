#include <cstdio>

const int Maxn = 100000 + 5;

int Array[Maxn],Equation[Maxn];
int Lenth;

int Dp(){
	int MaxLen = 0;
	for(int i = 1;i <= Lenth;i++){
		for(int j = 1;j < i;j++){
			if(Array[j] > Array[i] && Equation[j] > Equation[i])
				Equation[i] = Equation[j];
		}
		if((++Equation[i]) > MaxLen) MaxLen = Equation[i];
	}
	return MaxLen;
}

void Read(){
	scanf("%d",&Lenth);
	for(int i = 1;i <= Lenth;i++) scanf("%d",&Array[i]);
}

int main(){
	Read();
	printf("%d",Dp());
	return 0;
}
