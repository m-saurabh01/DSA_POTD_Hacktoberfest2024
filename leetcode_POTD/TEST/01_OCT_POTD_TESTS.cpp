/*

problem link "https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/?envType=daily-question&envId=2024-10-01"

*/
#include <bits/stdc++.h>
#include <cassert>

using namespace std;

class Solution
{
public:
    bool canArrange(vector<int>& arr, int k)
    {
        if (k == 1) return true;  // Special case when k = 1

        vector<int> freq(k, 0);
        for (int num : arr) {
            int rem = num % k;
            if (rem < 0) {
                rem += k;
            }
            freq[rem]++;
        }

        if (freq[0] % 2 != 0) {
            return false;
        }

        for (int i = 1; i <= k / 2; i++) {
            if (freq[i] != freq[k - i]) {
                return false;
            }
        }

        return true;
    }
};

void runTestCases()
{
    Solution sol;

    // Test Case 1: Basic test case with typical inputs
    vector<int> arr1 = {1, 2, 3, 4, 5, 10};
    int k1 = 5;
    assert(sol.canArrange(arr1, k1) == true);

    // Test Case 2: Test case with negatives and positives
    vector<int> arr2 = {-10, 10, -5, 5};
    int k2 = 5;
    assert(sol.canArrange(arr2, k2) == true);

    // Test Case 3: Test case where sum condition cannot be satisfied
    vector<int> arr3 = {1, 2, 3, 4, 5};
    int k3 = 5;
    assert(sol.canArrange(arr3, k3) == false);

    // Test Case 4: Test case with all elements zero
    vector<int> arr4 = {0, 0, 0, 0};
    int k4 = 3;
    assert(sol.canArrange(arr4, k4) == true);

    // Test Case 5: Test case with odd number of zeros
    vector<int> arr5 = {0, 0, 0};
    int k5 = 2;
    assert(sol.canArrange(arr5, k5) == false);

    // Test Case 6: Performance test with large array (All elements divisible by k)
    vector<int> arr6(1e5, 10);
    int k6 = 10;
    assert(sol.canArrange(arr6, k6) == true);

    // Test Case 7: Test case with non-divisible sum condition
    vector<int> arr7 = {-3, 1, 2, -4, 7, 5};
    int k7 = 3;
    assert(sol.canArrange(arr7, k7) == false);

    // Test Case 8: Test case with k = 1
    vector<int> arr8 = {1, 2, 3, 4, 5};
    int k8 = 1;
    assert(sol.canArrange(arr8, k8) == true);

    // Test Case 9: Test case where sum condition cannot be satisfied with random values
    vector<int> arr9 = {2, 9, 4, 7, 1, 8};
    int k9 = 5;
    assert(sol.canArrange(arr9, k9) == false);

    // Test Case 10: Test case with large numbers
    vector<int> arr10 = {-1e9, 1e9, -5e8, 5e8};
    int k10 = 1e9;
    assert(sol.canArrange(arr10, k10) == true);

    // Test Case 11: Test case with random values (Robustness)
    vector<int> arr11 = {-10, 50, 0, 50, -10};
    int k11 = 20;
    assert(sol.canArrange(arr11, k11) == false);

    cout << "All test cases passed!" << endl;
}

int main()
{
    runTestCases();
    return 0;
}
