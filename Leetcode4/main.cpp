#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() + nums2.size() % 2 == 0) {//���ƭ�
			for (int i = 0, j = 0, median = (nums1.size() + nums2.size()) / 2 + 1; median--) {
				if (nums1[i] < nums2[j] || j>nums2.size()) {//�ĤG�ӱ���Onum2�w��
					i++;
				}
				else {
					j++;
				}
			}
			return;
		}
		else {//�_�ƭ�
			return;
		}
	}
};

int main() {
	vector<int> v1 = { 1,3 };
	vector<int> v2 = { 2 };
	Solution S;
	S.findMedianSortedArrays(v1, v2);
}