#include<cstdio>
#include<cstring>

int A[50000],B[50000],Ans[100000],ALen,BLen,Len;
char Ac[50000],Bc[50000];

void Print(){
	for(int i = Len;i >= 0;i--) printf("%d",Ans[i]);
} /*输出 */

void Multiply(){
	for(int i = 0;i < Len;i++){
		for(int j = 0;j < Len;j++) {
			Ans[i+j] += (A[j]*B[i]); /*当前A数第j位*B数第i位 */
			if(Ans[i+j] >= 10){ 
				Ans[i+j+1] += (Ans[i+j]/10);
				Ans[i+j] %= 10;
				if(i+j+1 >= Len) Len = i+j+2; /*计算位数 */
			} /*进位 */
		}	
	}
	for(int i = Len;i > 0 && Ans[i] == 0;i--) Len--; 
} /*运算 */

void Prepare(){  
	ALen = strlen(Ac); /*计算A长度 */
	BLen = strlen(Bc); /*计算B长度 */
	for(int i = 0;i < ALen;i++) A[ALen-i-1] = Ac[i]-'0'; /*倒存储，方便运算 */
	for(int i = 0;i < BLen;i++) B[BLen-i-1] = Bc[i]-'0'; /*倒存储，方便运算 */
	Len = ALen >= BLen ? ALen : BLen;
}

int main(){
	scanf("%s",Ac); /*读入 */
	scanf("%s",Bc); /*读入 */
	Prepare();
	Multiply();
	Print();
	return 0;
}
