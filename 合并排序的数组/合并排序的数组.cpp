#include<iostream>
#include<vector>
#include<algorithm>   ///
using namespace std;


/*	将 nums2 合并到 nums1 中
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
*/


//使用vector的insert()：元素会被插入到第一个参数指向元素的前面
//emplace()：对象会被插入到迭代器所指定元素的后面
//void merge(int A[], int m, int B[], int n)

void merge(vector<int>& A, int m, vector<int>& B, int n){

	int i = m + n - 1;
	int j = m - 1;
	int k = n - 1;
	A.resize(i+1);		//这个必须处理

	while (j >= 0 && k >= 0){
		if (B[k] >= A[j]){
			A[i] = B[k];
			k--;
			i--;
		}
		else{
			A[i] = A[j];
			i--;
			j--;
		}
	}
	while (k > 0){
		A[i] = B[k];
		k--;
		i--;
	}
	
}


int main(int argc, char* argv[]){

	vector<int> nums1{ 1, 2, 3 ,10};
	vector<int> nums2{ 2, 5, 6 };
	merge(nums1, 4, nums2, 3);

	for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); it++){
		cout << *it << " ";
	}














	return 0;
}