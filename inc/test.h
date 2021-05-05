#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std

class Solution{
public:
	bool search(vector<int> nums, int target){
		int first = 0, last = nums.size();
		while(first != last){
			mid = first + (last - first)/2;
			if(nums[mid] == target){
				return true;
			}	
			if(nums[first] < nums[mid]) //first到mid必为递增
				if(nums[frist] <= target && target < nums[mid])
					last = mid;
				else
					first = mid + 1;
			else if(nums[first] > nums[mid])
				if(nums[mid] < target && target <= nums[last])
					first = mid +1;
				else
					last = mid;
			else
				first++;
				
					
		}

		return false;
		
	}
};


#endif
