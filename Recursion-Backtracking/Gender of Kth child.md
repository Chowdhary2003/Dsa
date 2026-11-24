# Gender of Kth child

> **Note:** The problem summary below is inferred from the supplied C++ implementation and filename; the original full problem statement was not present in the archive.

## Problem summary

Determine whether the k-th child in the n-th generation is Male or Female. The implementation recursively maps the child to its parent and flips the parent's gender for a second child.

## C++ Implementation

```cpp
string kthChildNthGeneration(int n, long long int k)
{
	// Base Condition
	if(n == 1 or k == 1)
	{
		return "Male";
	}
	// Parent of the Kth child of Nth generation
	long long int par = (k + 1)/2;

	// Recursively find the gender of the parent
	string parGender = kthChildNthGeneration(n - 1, par);

	// If Kth child of Nth generation is the first child of its parent
	if(k == 2 * par - 1)
	{
		return parGender;
	}
	// If Kth child of Nth generation is the second child of its parent
	else
	{
		if(parGender == "Male")
		{
			return "Female";
		}
		else
		{
			return "Male";
		}
	}
}
```
