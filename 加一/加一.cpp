#include<iostream>
#include<vector>
using namespace std;


/*
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
	
	示例 1:

	输入: [1,2,3]
	输出: [1,2,4]
	解释: 输入数组表示数字 123。

	示例 2:

	输入: [4,3,2,1]
	输出: [4,3,2,2]
	解释: 输入数组表示数字 4321。

	边界考虑
	示例 3:

	输入: [9]
	输出: [1,0]
	解释: 输入数组表示数字 10。
*/

vector<int> plusOne(vector<int> &digits){

	vector<int> result = digits;
	int index = result.size() - 1;
	int carry_mark = 0;	//进位标记
	while (index >= 0){

		

		if ((result[index] + 1) < 10){
			result[index] += 1;
			carry_mark = 0;
			break;
		}
		else{
			carry_mark = (result[index] + 1) / 10;			//进位标记
			result[index] = (result[index] + 1) % 10;			//
			
			index--;
		}
		
	}

	//vector容器如何从头插入一个元素
	if (carry_mark > 0){
		result.insert(result.begin(), carry_mark);
	}

	return result;
}


int main(int argc, char* argv[]){

	vector<int> v{ 9 };

	vector<int> result = plusOne(v);

	
	for (vector<int>::iterator it = result.begin(); it != result.end(); it++){
		cout << *it ;
	}

	return 0;
}