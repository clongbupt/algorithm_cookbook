/**
 * 不用四则运算做加法
 *
 * 不考虑进位的加法  可以用位运算中的异或来代替
 *
 * 进位用求与来进行
 *
 * 一直到无进位为止
 */

int Add (int num1, int num2){
	int sum, carry;

	carry = 1;
	while(carry != 0){
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;

		num1 = sum;
		num2 = carry;
	}
}