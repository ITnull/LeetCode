#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int> &height) {
	height.push_back(0); // Ìí¼ÓĞéÄâ¾ØĞÎÌõ
	stack<int> st;
	int n = height.size();
	int maxArea = 0;
	int h, w;

	for (int i = 0; i < n; i++) {
		if (st.empty() || height[st.top()] < height[i])
			st.push(i);
		else {
			while (!st.empty() && height[i] <= height[st.top()]) {
				h = height[st.top()];
				st.pop();
				w = st.empty() ? i : i - (st.top() + 1);
				maxArea = max(maxArea, h * w);
			}
			st.push(i);
		}
	}

	return maxArea;
}


int main(int argc, char* argv[]){

	vector<int> v{ 2, 1, 5, 6, 2, 3 };

	cout << largestRectangleArea(v) << endl;

	return 0;
}
