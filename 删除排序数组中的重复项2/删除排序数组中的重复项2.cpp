#include<iostream>
#include<vector>
using namespace std;


//allowed at most twice

int removeDuplicates(vector<int>& nums){
	int index = 0;
	int count = 1;
	for (int i = 1; i < nums.size(); i++){

		/*	这种写法直接改成如下写法
		if (nums[index] == nums[i] && count<2){
			nums[++index] = nums[i];
			count++;
		}
		if (nums[index] != nums[i]){
			nums[++index] = nums[i];
			count = 1;
		}*/

		if (nums[index] == nums[i]){

			if (count<2){
				nums[++index] = nums[i];
				count++;
			}

		}else{
			nums[++index] = nums[i];
			count = 1;
		}

	}

	return index + 1;
}

int main(int argc, char* argv[]){

	vector<int> v{ 1, 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 6 };

	int len = removeDuplicates(v);
	for (int i = 0; i < len; i++){
		cout << v[i] << endl;
	}

	return 0;
}