#include<iostream>
#include<vector>
using namespace std;


int removeDuplicates(vector<int>& nums){
	int index = 0;
	for (int i = 1; i < nums.size(); i++){
		if (nums[index] != nums[i]){
			nums[++index] = nums[i];
		}
	}

	return index+1;
}

int main(int argc, char* argv[]){

	vector<int> v{ 1, 1, 2, 3, 4, 4, 4, 5 };
	int len = removeDuplicates(v);
	for (int i = 0; i < len; i++){
		cout << v[i] << endl;
	}

	return 0;
}