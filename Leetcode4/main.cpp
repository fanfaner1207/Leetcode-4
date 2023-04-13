#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Solution {
public:
	vector<int> sortarray(vector<int>& nums1, vector<int>& nums2, size_t nums1Size, size_t nums2Size, vector<int>& tmp) {
		size_t median = (nums1Size + nums2Size) / 2 + 1;
		for (int i = 0, j = 0; median > 0; median--) {
			if (j >= nums2Size) {
				tmp.push_back(nums1[i]);
				i++;
				continue;
			}
			else if (i >= nums1Size) {
				tmp.push_back(nums2[j]);
				j++;
				continue;
			}
			if (nums1[i] < nums2[j]) {//第二個條件是num2已空
				tmp.push_back(nums1[i]);
				i++;
			}
			else {
				tmp.push_back(nums2[j]);
				j++;
			}
		}
		return tmp;
	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> tmp;
		size_t nums1Size = nums1.size();
		size_t nums2Size = nums2.size();
		if ((nums1Size + nums2Size) % 2 == 0) {
			//偶數個
			tmp = sortarray(nums1, nums2, nums1Size, nums2Size, tmp);
			size_t tmpSize = tmp.size();
			return	(tmp[tmpSize - 1] + tmp[tmpSize - 2]) / 2.0;
		}
		else {
			//奇數個
			tmp = sortarray(nums1, nums2, nums1Size, nums2Size, tmp);
			size_t tmpSize = tmp.size();
			return tmp[tmpSize - 1];
		}
	}
};

int main() {
	vector<int> v1 = { 1,2 };
	vector<int> v2 = { 3,4 };
	Solution S;
	cout << fixed << setprecision(5) << S.findMedianSortedArrays(v1, v2) << endl;
}