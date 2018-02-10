#include<cstdio>
#include<cstring>

int A[50000],B[50000];
int ALen,BLen,Len,Quotient;
char Ac[50000],Bc[50000];

void Print(){
	if(Len == -1) printf("%d",Quotient);
	else {
		printf("%d...",Quotient-1);
		A[Len] = 0;
		for(int i = 0;i < Len;i++){
			A[i] += B[i];
			if(A[i] >= 10){
				A[i+1] += (A[i]/10);
				A[i] %= 10;
				if(i+1 >= Len) Len++;
			}
		}
		for(int i = Len-1;i > 0 && A[i] == 0;i--) Len--;
		while(Len) printf("%d",A[--Len]);
	} 
}

bool Minus(){
	Quotient++;
	for(int i = 0;i <= Len;i++) A[i] -= B[i];
	for(int i = 0;i <= Len;i++) {
        if(A[i] < 0){
			A[i+1] --;
			if(A[i+1] < 0 && i == Len) continue;
            A[i] += 10;
        }
    }
    for(Len+=1;Len >= 0 && A[Len] == 0;) Len--; 
    if (A[Len] <= 0) return 0;
    return 1;
}

void Prepare(){
	Len = (ALen = strlen(Ac)-1) >= (BLen = strlen(Bc)-1) ? ALen : BLen;
    for(int i = 0;i <= ALen;i++) A[ALen-i] = Ac[i]-'0';
    for(int i = 0;i <= BLen;i++) B[BLen-i] = Bc[i]-'0';
} 

void Divide(){
	while(Minus());
	Print();
}

int main(){
	scanf("%s",Ac);
	scanf("%s",Bc);
	Prepare();
	Divide();
    return 0;
} 
