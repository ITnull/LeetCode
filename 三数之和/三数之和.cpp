#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//a+b+c=0 
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());

	auto last = nums.end() - 2;
	for (auto i = nums.begin(); i < last; i++){
		auto j = i + 1;
		auto k = nums.end() - 1;

		if (i > nums.begin() && *i == *(i - 1)) 
			continue;

		while (j < k){
			//*i+*j+*k=0;		--> *j+*k=-*i;
			if (*j + *k + *i > 0){
				k--;
				while ( *k == *(k + 1) && j < k ){
					k--;
				}
			}
			else if (*j + *k + *i < 0){
				j++;
				while ( *j == *(j - 1) && j < k ){
					j++;
				}
			}
			else{
				result.push_back({ *i, *j, *k });
				j++;
				k--;
				
				while (*j == *(j - 1) && *k == *(k + 1) && j < k){
					j++;
				}
			}
		}
	}

	return result;
}

int main(int argc, char* argv[]){
	//{-1 0 1 2 -1 -4}.
	vector<int> v{ -1, 0, 1, 2, -1, -4 };
	//vector<int> v{ 0, 0, 0, 0 };		//答案中不可以包含重复的三元组

	vector<vector<int>> result = threeSum(v);
	for (int i = 0; i < result.size();i++){
		for (int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}