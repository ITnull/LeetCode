#include<iostream>
#include<vector>
#include<algorithm>   ///
#include<map>
using namespace std;


/*
例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/

int threeSumClosest(vector<int>& nums, int target) {

	
	int result = 0;
	if (nums.size() < 3)
		return result;

	int minCloset = abs(nums[0] + nums[1] + nums[2] - target);
	result = nums[0] + nums[1] + nums[2];

	auto last = nums.end() - 2;
	auto k = nums.end()-1;

	for (auto i = nums.begin(); i < last; i++){

		auto j = i + 1;
		while (j < k){
			int temp = abs(*i + *j + *k - target);
			if (temp < minCloset){
				minCloset = temp;
				result = *i + *j + *k;
			}

			//j++;	不能直接这么写
			if (*i + *j + *k >target){
				k--;
			}
			else{
				j++;
			}
		}
	}

	return result;

}

int main(int argc, char* argv[]){

	vector<int> v{ 1, 1, -1, -1, 3 };
	int result = threeSumClosest(v, -1);
	cout << result << endl;

	return 0;
}