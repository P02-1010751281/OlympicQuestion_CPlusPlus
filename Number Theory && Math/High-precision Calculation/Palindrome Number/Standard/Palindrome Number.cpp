#include<cstdio>
#include<cstring>

int Hex;
char Ac[50000];
int A[50000],B[50000];
int Len;

void Print(){
	for(int i = Len;i >= 1;i--) printf("%d",A[i]);
	printf("	");
} 

void Prepare(){
	Len = strlen(Ac); 
	for(int i = 1;i <= Len;i++) {
		if(Ac[i - 1] >= '0' && Ac[i - 1] <= '9')
			A[i] = Ac[i - 1] - '0';
		else A[i] = Ac[i - 1] - 'A' + 10;
	} 
	for(int i = 1;i <= Len;i++) B[Len - i + 1] = A[i];
} 

void Plus(){
	for(int i = 1;i <= Len;i++){
		A[i] += B[i]; 
		if(A[i] >= Hex){
			A[i + 1] += A[i] / Hex;
			A[i] %= Hex;
			if(i + 1 > Len) Len++; 
		}
	}
	for(int i = Len;i >= 1 && A[i] == 0;i--) Len--;
	for(int i = 1;i <= Len;i++) B[i] = A[Len - i + 1];
//	Print();
} 

bool Solve(){
	Prepare();
	for(int i = 1;i <= 30;i++){
		Plus();
		int Sum = 0;
		for(int j = 1;j <= (Len / 2);j++){
			if(A[j] == A[Len - j + 1])
				Sum++;
			else break;
		}
//		printf("%d %d\n",Sum,Len / 2);
		if(Sum == (Len / 2)) {
			printf("STEP=%d",i);
			return true; 
		}
	}
	return false;
}

void Read(){
	scanf("%d",&Hex);
	scanf("%s",Ac);
}

int main(){
	Read();
	if(!Solve())
		printf("Impossible!");
	return 0;
}
