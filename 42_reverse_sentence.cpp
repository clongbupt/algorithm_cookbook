/**
 * 诺基亚面试题
 *
 * 主要是对空格的判断和往下的走的计算
 *
 * 测试用例
 *
 * abc
 *
 * abc def
 *
 * 只有空格
 */

void reverse (char * start, char * end){
	if (start == null || end == null)
		return;
	char * tmp;
	while(start != end){
		*tmp = *start;
		*start = *end;
		*end = *tmp;
		start ++;
		end --;
	}
}

void reverse_sentence(char * sentence){

	if (sentence == null)
		return;

	int len = strlen(sentence);

	char * head = sentence;
	char * tail = sentence + len -1;

	reverse(head,tail);

	/*
	不适合只有空格的例子
	 */
	// char *begin = head;
	// char *end = head;
	// while(*head != '\0'){
	// 	head ++;
	// 	if(*head != " "){
	// 		end ++;
	// 	}
	// 	else{
	// 		reverse(begin,end);
	// 		head++;
	// 		if(* head!= '\0'){
	// 			end++;
	// 			end++;
	// 			begin = end;
	// 		}
	// 	}
	// }
	// reverse(begin,end);

	char *begin = head;
	char *end = head;

	while(*begin != '\0'){
		if(*begin == ' '){
			begin++;
			end++;
		}
		else if(*end == ' ' || *end == '\0'){
			reverse(begin,--end);
			end++;
			begin = end;
		}else{
			end++;
		}
	}
}