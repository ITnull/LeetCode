#include<iostream>
#include<vector>
#include<algorithm>   ///
#include<map>
using namespace std;


/*
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/


//ʹ��mapʵ�֣���������
vector<int> twoSum01(vector<int> &numbers, int target){

	vector<int> result;
	map<int, int> m;			//���map<��Ӧ��ֵ������>

	for (int i = 0; i < numbers.size(); i++){
		m[numbers[i]] = i;
	}

	for (int i = 0; i < numbers.size(); i++){
		int temp = target - numbers[i];

		auto it = m.find(temp);

		if (it != m.end() && it->second > i){  

			//��Ҫ�����ظ�
			result.push_back(i);		//[0,1]
			result.push_back(it->second);
			break;	//
		}
	}

	return result;
}


//ʹ���������мб�
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
			//��ֹ����
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