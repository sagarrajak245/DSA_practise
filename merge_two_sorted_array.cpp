#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
   void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
   {
      // Start from the end of both arrays
      int i = m - 1;     // Last element index of nums1
      int j = n - 1;     // Last element index of nums2
      int k = m + n - 1; // Last position in merged array

      // Compare elements from end and place larger one at the end
      while (i >= 0 && j >= 0)
      {
         if (nums1[i] > nums2[j])
         {
            nums1[k] = nums1[i];
            i--;
         }
         else
         {
            nums1[k] = nums2[j];
            j--;
         }
         k--;
      }

      // If elements are still left in nums2
      while (j >= 0)
      {
         nums1[k] = nums2[j];
         j--;
         k--;
      }
   }
};

// Main function to test the solution
int main()
{
   Solution solution;

   // Test case
   vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // Array 1 with extra space
   vector<int> nums2 = {2, 5, 6};          // Array 2
   int m = 3;                              // Number of elements in nums1
   int n = 3;                              // Number of elements in nums2

   // Merge arrays
   solution.merge(nums1, m, nums2, n);

   // Print merged array
   cout << "Merged array: ";
   for (int num : nums1)
   {
      cout << num << " ";
   }
   cout << endl;

   return 0;
}