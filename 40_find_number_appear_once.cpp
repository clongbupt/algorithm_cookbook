/**
 * 题意一个数组中有两个数只出现一次，其他数均成对出现
 *
 * 求异或能判断数组中唯一一个只出现一次的数字， 两个这样的数字需要将数组进行拆分
 *
 * 按照异或结果为1的位置对数组进行拆分  该位置为1的子数组可以求出一个值  另外的子数组可以求出另外一个值
 *
 * 注意由于是对异或结果进行移位， 注意循环溢出的问题   index_of_1 < 8*(sizeof(int))
 */

void find_number_appear_once(int data[], int length, int num1, int num2){
	int result_exclusive_or = 0;

	for(int i=0; i<length; i++)
		result_exclusive_or ^= data[i];

	int index_of_1 = 0;
	while((result_exclusive_or & 1 == 0 ) && (index_of_1 < 8*(sizeof(int) ) ) ){
		result_exclusive_or >> 1;
		index_of_1 ++;
	}

	num1 = num2 = 0;

	for(int i=0; i<length; i++){
		if((data[i] >> index_of_1) & 1)
			num1 ^= data[i];
		else
			num2 ^= data[i];
	}
}