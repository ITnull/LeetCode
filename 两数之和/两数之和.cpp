#include<iostream>
#include<vector>
#include<algorithm>   ///
#include<map>
using namespace std;


/*
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/


//使用map实现，返回索引
vector<int> twoSum01(vector<int> &numbers, int target){

	vector<int> result;
	map<int, int> m;			//存放map<对应的值，索引>

	for (int i = 0; i < numbers.size(); i++){
		m[numbers[i]] = i;
	}

	for (int i = 0; i < numbers.size(); i++){
		int temp = target - numbers[i];

		auto it = m.find(temp);

		if (it != m.end() && it->second > i){  

			//还要避免重复
			result.push_back(i);		//[0,1]
			result.push_back(it->second);
			break;	//
		}
	}

	return result;
}


//使用排序后进行夹逼
vector<int> twoSum02(vector<int> &numbers, int target){

	vector<int> ret;

	sort(numbers.begin(),numbers.end());

	
	for (auto it = numbers.begin(); it != numbers.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	//2 7 11 15 45 50 100

	int i = 0;
	int j = numbers.size() - 1;

	while (i < j){

		if (numbers[i] + numbers[j] == target){

			ret.push_back(numbers[i]);
			ret.push_back(numbers[j]);
			//终止条件
			return ret;
		}
		else if (numbers[i] + numbers[j] > target){
			j--;
		}
		else{
			i++;
		}
	}


	return ret;
}

int main(int argc, char* argv[]){

	vector<int> v{ 100, 50, 45, 2, 7, 11, 15 };

	vector<int> result = twoSum02(v, 60);

	/*
	vector<int> result = twoSum01(v, 26);
	*/

	for (vector<int>::iterator it = result.begin(); it != result.end(); it++){
		cout << *it << " ";
	}
	

	return 0;
}