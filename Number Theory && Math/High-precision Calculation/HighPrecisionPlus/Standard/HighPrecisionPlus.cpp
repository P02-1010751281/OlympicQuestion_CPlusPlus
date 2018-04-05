#include<cstdio>
#include<cstring>

int A[50000],B[50000],Ans[100000],ALen,BLen,Len;
char Ac[50000],Bc[50000];

void Print(){
	for(int i = Len-1;i >= 0;i--) printf("%d",Ans[i]);
} /*输出 */

void Plus(){
	for(int i = 0;i < Len;i++){
		Ans[i] += (A[i]+B[i]); /*当前A数第i位*B数第i位 */
		if(Ans[i] >= 10){
			Ans[i+1] += (Ans[i]/10);
			Ans[i] %= 10;
			if(i+1 >= Len) Len++; /*计算位数 */
		} /*进位 */
	}
	for(int i = Len-1;i > 0 && Ans[i] == 0;i--) Len--;
} /*运算 */

void Prepare(){
	ALen = strlen(Ac); /*计算A长度 */
	BLen = strlen(Bc); /*计算B长度 */
	for(int i = 0;i < ALen;i++) A[ALen-i-1] = Ac[i]-'0'; /*倒存储，方便运算 */
	for(int i = 0;i < BLen;i++) B[BLen-i-1] = Bc[i]-'0'; /*倒存储，方便运算 */
	Len = ALen >= BLen ? ALen : BLen;
} /*运算 准备*/

int main(){
	scanf("%s",Ac); /*读入 */
	scanf("%s",Bc); /*读入 */
	Prepare();
	Plus();
	Print();
	return 0;
}
