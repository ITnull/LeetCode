#include<iostream>
#include<vector>
#include<algorithm>   ///
using namespace std;


/*	�� nums2 �ϲ��� nums1 ��
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

���: [1,2,2,3,5,6]
*/


//ʹ��vector��insert()��Ԫ�ػᱻ���뵽��һ������ָ��Ԫ�ص�ǰ��
//emplace()������ᱻ���뵽��������ָ��Ԫ�صĺ���
//void merge(int A[], int m, int B[], int n)

void merge(vector<int>& A, int m, vector<int>& B, int n){

	int i = m + n - 1;
	int j = m - 1;
	int k = n - 1;
	A.resize(i+1);		//������봦��

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