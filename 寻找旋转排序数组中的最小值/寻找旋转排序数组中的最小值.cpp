#include<iostream>
#include<vector>
#include<algorithm>   ///
#include<map>
using namespace std;

//数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
//[1,2,3]
int findMin(vector<int>& nums) {

	int len=nums.size();
	//注意nums个数为0,1,2的处理
	if (len == 0){
		return 0;
	}
	else if (len == 1){
		return nums[0];
	}

	int start = 0;
	int end = len - 1;
	int ret=0;
	while (start < end){
		int mid = (start + end) / 2;

		if (start == mid){
			ret = nums[start] < nums[end] ? nums[start] : nums[end];
			break;
		}

		if (nums[start] < nums[mid] && nums[mid] <= nums[end]){		//没有发生旋转，边界问题注意事项
			end = mid;
		}
		else if (nums[start] <= nums[mid]){
			start = mid;
		}
		else{
			end = mid;
		}
	}

	return ret;
}

int main(int argc, char* argv[]){

	vector<int> v{ 1, 2, 3 };
	cout << findMin(v) << endl;

	return 0;
}
