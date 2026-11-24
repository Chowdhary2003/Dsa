# kth largest subarray sum

## Problem statement

> **Inferred summary:** Given an integer array and k, find the k-th largest sum among all contiguous subarrays. The source includes a min-heap approach and a sorting approach.
>
> The original C++ file did not include a complete problem statement; this summary is inferred from the file name and implementation.

## C++ implementation

```cpp
//If time efficiency is more important and the array is relatively small, 

/*
    Time Complexity: O(N ^ 2 * log(K))
    Space Complexity: O(K)

    where ‘N’ is the length of the given array/list.
	And 'K' is the given number.
*/

#include <queue>

int getKthLargest(vector<int> &arr, int k)
{
	int n = arr.size();

	//	To store the subarray sums.
	priority_queue<int, vector<int>, greater<int>> minHeap;

	for (int i = 0; i < n; i++)
	{
		//	To store the current subarray sum.
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum = sum + arr[j];

			if (minHeap.size() < k)
			{
				minHeap.push(sum);
			}
			else
			{
				if (minHeap.top() < sum)
				{
					//	Pop the minimum element.
					minHeap.pop();
					minHeap.push(sum);
				}
			}
		}
	}

	//	Top-most element is the k-th largest subarray sum.
	return minHeap.top();
} 








// If space efficiency is crucial and the array is not too large

/*
    Time Complexity: O(N ^ 2 * log(N)
    Space Complexity: O(N ^ 2)

    where ‘N’ is the length of the given array/list.
*/

#include <algorithm>

int getKthLargest(vector<int> &arr, int k)
{
	int n = arr.size();

	//	To store the subarray sum of every possible subarray.
	vector<int> bin;

	for (int i = 0; i < n; i++)
	{
		//	Stores the subarray sum.
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			sum = sum + arr[j];
			bin.push_back(sum);
		}
	}

	//	Sort in non-increasing order.
	sort(bin.begin(), bin.end(), greater<int>());

	return bin[k - 1];
}
```
