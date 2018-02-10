#include<cmath>
#include<cstdio>
#include<cstring>

int A[50000],B[50000],Ans[100000],ALen,BLen,Len;
char Ac[50000],Bc[50000];
bool Flag = 0; /*记录负号*/ 

void Print(){
	if(Flag) printf("-"); /*输出 膈应的情况下的负号*/
	if(Ans[Len] == -1) printf("-");
	else printf("%d",Ans[Len]); 
	for(int i = Len-1;i >= 0;i--) printf("%d",Ans[i]);
} /*输出 */

void Minus(){
	for(int i = 0;i < Len;i++){
		Ans[i] += (A[i]-B[i]); /*当前A数第j位-B数第i位 */
		if(Ans[i] < 0){
			Ans[i+1] --;
			Ans[i] += 10;
		} /*借位 */
	}
	for(int i = Len;i > 0 && Ans[i] == 0;i--) Len--; 
}  /*运算 */

void Prepare(){
	ALen = strlen(Ac);  /*计算A长度 */
	BLen = strlen(Bc);  /*计算B长度 */
	if(ALen >= BLen){
		Len = ALen;
		for(int i = 0;i < ALen;i++) A[ALen-i-1] = Ac[i]-'0';
		for(int i = 0;i < BLen;i++) B[BLen-i-1] = Bc[i]-'0';
	} else {
		Flag = 1; /*记录负号*/ 
		Len = BLen;
		for(int i = 0;i < ALen;i++) B[ALen-i-1] = Ac[i]-'0';
		for(int i = 0;i < BLen;i++) A[BLen-i-1] = Bc[i]-'0';
	}  /*倒存储，方便运算 Tips:减法有个很膈应的事，把长的要放前面，还要记录负号*/
	// Len = ALen >= BLen ? ALen : BLen;
}

int main(){
	scanf("%s",Ac); /*读入 */
	scanf("%s",Bc); /*读入 */
	Prepare();
	Minus();
	Print();
	return 0;
}
