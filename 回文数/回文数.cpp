#include<iostream>

using namespace std;


//˼����ֻ����һ�������

bool isPalindrome(int x) {

	if (x <= 0 ){
		return false;
	}

	//int y = x;

	//bool ret = false;

	int tmp=0;
	int t = 0;

	while (x>tmp){
		t = x % 10;
		x = x / 10;		
		tmp = tmp * 10 + t;
	}

	/*
	if (tmp == y){
		ret = true;
	}*/
	return x==tmp || x==tmp/10;
}

int NumberOfDigits(int nums){
	int count = 0;
	while (nums){
		count++;
		nums = nums / 10;
	}
	return count;
}


int main(int argc, char* argv[]){

	int nums=121;

	//cout << nums << "λ����" << NumberOfDigits(nums) << endl;

	if (isPalindrome(nums)){
		cout << "�ǻ�����." << endl;
	}
	else{
		cout << "���ǻ�����." << endl;
	}
	return 0;
}