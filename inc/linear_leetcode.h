# ifndef LINEAR_LEETCODE_h
# define LINEAR_LEETCODE_h

# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

/**
Description:
Given a sorted array, remove the duplicates in place such that each element appear only once
and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example, Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2].
**/

// LeetCode, Remove Duplicates from Sorted Array
// 时间复杂度 O(1), 空间复杂度 O(1)
class Remove_Dup{
public:
    int removeDuplicates_1(vector<int>& nums){
        if(nums.empty()) return 0;

        int index = 0;
        for(int i=1; i < nums.size(); i++){
            if(nums[i] != nums[index]){
                nums[++index] = nums[i];
            }
        }

        return index+1;
    }

    int removeDuplicates_2(vector<int>& nums){
        return distance(nums.begin(), unique(nums.begin(), nums.end()));
    }

    int removeDuplicates_3(vector<int>& nums){
        return distance(nums.begin(), removeDuplicates_3(nums.begin(), nums.end(), nums.begin()));

    }

    template<typename InIt, typename OutIt>
    OutIt removeDuplicates_3(InIt first, InIt end, OutIt output){
        while(first != end){
            *output++ = *first;
            first = upper_bound(first, end, *first);
        }
        
        return output;
    }
};

/**
Description:
Follow up for ”Remove Duplicates”: What if duplicates are allowed at most twice?
For example, Given sorted array A = [1,1,1,2,2,3],
Your function should return length = 5, and A is now [1,1,2,2,3]
**/

class Remove_Dup_twice{
public:
    int removeDuplicates_1(vector<int>& nums){
        if(nums.size() <= 2) return nums.size();

        int index = 2;

        for(int i = 2; i < nums.size(); i++){
            // if(nums[index] != nums[i-2]){  //错误写法
            if(nums[index-2] != nums[i]){ 
                nums[index++] = nums[i];
            }
        }

        return index;
    }

    int removeDuplicates_2(vector<int>& nums){
        const int n = nums.size();
        int index = 0;
        for (int i = 0; i < n; i++){
            if(i > 0 && i < n-1 && nums[i-1] == nums[i] && nums[i] == nums[i+1] )
                continue;

            nums[index++] = nums[i];
        }

        return index;
    }
};

/**
二分查找
**/

// LeetCode, Search in Rotated Sorted Array
// 时间复杂度 O(log n) 空间复杂度O(1)
class Search_in_Rotated_Sorted_Array{
public:
    /**
    Description:
    Suppose a sorted array is rotated at some pivot unknown to you beforehand.
    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
    You are given a target value to search. If found in the array return its index, otherwise return -1.
    You may assume no duplicate exists in the array.
    **/
    int search(vector<int>& nums, int target){
        int first =0, last = nums.size();
        
        while(first != last){
            int mid = first + (last - first)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[first] <= nums[mid]){
                if(nums[first] <= target && target < nums[mid]){
                    last = mid;
                }
                else{
                    first = mid + 1;
                }
            }
            else{
                if(nums[mid] < target && target <= nums[last-1]){
                    first = mid + 1;
                }
                else{
                    last = mid;
                }
            }
        }
    }
    /**
    Description:
    Follow up for ”Search in Rotated Sorted Array”: What if duplicates are allowed?
    Would this affect the run-time complexity? How and why?
    Write a function to determine if a given target is in the array.
    **/
   bool search_inc_dup(const vector<int>&  nums, int target){
        int first = 0, last = nums.size();
        
        while(first != last){
            const int mid = first + (last - first)/2;
            if(nums[mid] == target)
                return true;
            if(nums[first] < nums[mid])  // 前半段必然是递增的
                if(nums[first] <= target && target < nums[mid] )
                    last = mid;
                else
                    first = mid +1;
            else if(nums[first] > nums[mid])  //后半段必然是递增的
                if(nums[mid] < target && target <= nums[last-1] ) 
                    first = mid + 1;
                else
                    last = mid;   
            else
                // skip duplicate one
                first++;
        }

        return false;        
   }
};


#endif
