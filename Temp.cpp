Breakdown,
dry run,
walkthrough,
visual representation,
illustration,
overview
eaxmple walkthrough



could you make the best solution based on factors like efficiency, readability,clarity, conciseness,correctness,robustness,simplicity and maintainability for me to prepare for my coding interview in c++



Square Root

#include <iostream>

int findSquareRoot(int n) {
    if (n == 0 || n == 1) {
        return n;  // Return n if it is 0 or 1
    }

    int low = 1, high = n;
    int result = 0;

    // Perform binary search
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if mid is the square root
        if (mid * mid == n) {
            return mid;
        }
        
        // If mid^2 is less than n, discard the lower half
        if (mid * mid < n) {
            low = mid + 1;
            result = mid;  // Track the floor of the square root
        }
        // If mid^2 is greater than n, discard the upper half
        else {
            high = mid - 1;
        }
    }

    return result;  // Return the largest integer less than or equal to the square root
}






Find nth root of m

#include <iostream>
#include <cmath>

int nthRoot(int n, int m) {
    if (m == 0) return 0;  // nth root of 0 is 0 for any n.
    if (n == 1) return m;   // nth root of m when n=1 is m itself.

    // Binary search to find the integer nth root
    int left = 1, right = m;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long power = 1;
        
        // Calculate mid^n using a loop to avoid overflow
        for (int i = 0; i < n; i++) {
            power *= mid;
            if (power > m) break; // Early exit if power exceeds m
        }

        if (power == m) {
            return mid;  // mid^n == m, return mid
        } else if (power < m) {
            left = mid + 1;  // We need a larger number
        } else {
            right = mid - 1; // We need a smaller number
        }
    }
    
    return -1;  // If no integer root is found
}




Koko Eating Bananas


 // Helper function to check if Koko can finish eating in h hours with speed k
    bool canFinish(const std::vector<int>& piles, int h, int k) {
        int totalHours = 0;
        for (int pile : piles) {
            totalHours += std::ceil((double)pile / k); // Calculate hours for this pile
            if (totalHours > h) {
                return false; // If the total hours exceed h, return false
            }
        }
        return totalHours <= h; // Return if we can finish within h hours
    }

    // Function to find the minimum k such that Koko can eat all bananas within h hours
    int minEatingSpeed(std::vector<int>& piles, int h) {
        // Binary search for the smallest k (speed)
        int left = 1, right = *std::max_element(piles.begin(), piles.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, h, mid)) {
                right = mid; // If Koko can finish with speed mid, try smaller speeds
            } else {
                left = mid + 1; // If not, try larger speeds
            }
        }
        
        return left; // The smallest k is the answer
    }



Minimum Number of Days to Make m Bouquets


// Helper function to check if we can make m bouquets by a given day
bool canMakeBouquets(const vector<int>& bloomDay, int day, int m, int k) {
    int bouquets = 0;
    int flowers = 0;
    
    for (int i = 0; i < bloomDay.size(); ++i) {
        if (bloomDay[i] <= day) {
            flowers++;
        } else {
            flowers = 0;
        }
        
        if (flowers == k) {
            bouquets++;
            flowers = 0; // Reset after making a bouquet
        }
    }
    
    return bouquets >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    
    // Edge case: if not enough flowers to make m bouquets
    if (n < m * k) {
        return -1;
    }

    // Binary search over the bloom days
    int left = *min_element(bloomDay.begin(), bloomDay.end());
    int right = *max_element(bloomDay.begin(), bloomDay.end());
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canMakeBouquets(bloomDay, mid, m, k)) {
            result = mid;
            right = mid - 1; // Try to find a smaller day
        } else {
            left = mid + 1; // Increase the day
        }
    }
    
    return result;
}







Find the Smallest Divisor Given a Threshold

// Helper function to compute the sum of ceil(num / divisor) for all nums
int getSumOfDivisions(const std::vector<int>& nums, int divisor) {
    int sum = 0;
    for (int num : nums) {
        sum += (num + divisor - 1) / divisor;  // This is equivalent to ceil(num / divisor)
    }
    return sum;
}

// Function to find the smallest divisor such that the sum of divisions is <= threshold
int smallestDivisor(const std::vector<int>& nums, int threshold) {
    // Binary search for the smallest divisor
    int low = 1, high = *std::max_element(nums.begin(), nums.end());
    
    while (low < high) {
        int mid = low + (high - low) / 2;  // Avoid overflow
        if (getSumOfDivisions(nums, mid) <= threshold) {
            high = mid;  // Try smaller divisors
        } else {
            low = mid + 1;  // Try larger divisors
        }
    }
    return low;  // low should be the smallest divisor
}





Capacity To Ship Packages Within D Days

 // Function to check if it's possible to ship with the given capacity within 'days' days
    bool canShip(const vector<int>& weights, int days, int capacity) {
        int currentWeight = 0;
        int dayCount = 1; // Start with the first day

        for (int weight : weights) {
            if (currentWeight + weight > capacity) {
                dayCount++;  // Start a new day
                currentWeight = weight;
                if (dayCount > days) {
                    return false; // Exceeded the allowed days
                }
            } else {
                currentWeight += weight;
            }
        }
        return true; // Successfully shipped within 'days' days
    }

    // Function to find the minimum ship capacity using binary search
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());  // Lower bound is the heaviest package
        int right = accumulate(weights.begin(), weights.end(), 0); // Upper bound is the sum of all weights

        // Perform binary search on capacity
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canShip(weights, days, mid)) {
                right = mid;  // Try smaller capacity
            } else {
                left = mid + 1;  // Try larger capacity
            }
        }

        return left;  // The least capacity found that can ship the packages within 'days' days
    }


Kth Missing Positive Number

int findKthMissing(const std::vector<int>& arr, int k) {
    int current = 1;  // Start checking from the first positive integer
    int missingCount = 0;  // To track how many numbers have been skipped
    int i = 0;  // Pointer to traverse the array

    while (missingCount < k) {
        // If current number is found in the array, move to the next number
        if (i < arr.size() && arr[i] == current) {
            ++i;
        } else {
            // Otherwise, it is a missing number
            ++missingCount;
            if (missingCount == k) {
                return current;  // Return the kth missing number
            }
        }
        ++current;  // Check the next number
    }

    return -1;  // This should never be reached if the input is valid
}





 Allocate Books

// Function to check if it's possible to allocate books to students such that
// no student gets more than 'maxPages' pages.
bool isAllocationPossible(const vector<int>& books, int m, int maxPages) {
    int studentCount = 1;  // Start with the first student
    int currentSum = 0;    // Pages assigned to the current student
    
    for (int pages : books) {
        // If adding this book exceeds 'maxPages', allocate it to the next student
        if (currentSum + pages > maxPages) {
            studentCount++;
            currentSum = pages;  // Start with this book for the new student
            
            if (studentCount > m) {
                return false;  // More students are required than allowed
            }
        } else {
            currentSum += pages;  // Add this book to the current student
        }
    }
    
    return true;  // Allocation is possible
}

// Main function to find the optimal maximum pages using binary search
int allocateBooks(const vector<int>& books, int m) {
    int n = books.size();
    
    // Edge case: if there are fewer books than students, it's impossible
    if (n < m) return -1;

    int low = *max_element(books.begin(), books.end());   // The largest book must be assigned to at least one student
    int high = accumulate(books.begin(), books.end(), 0); // Sum of all pages, one student gets all books
    
    // Perform binary search for the optimal maximum pages
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        if (isAllocationPossible(books, m, mid)) {
            high = mid;  // Try to minimize the maximum pages
        } else {
            low = mid + 1;  // Increase the 'maxPages' since it's not feasible
        }
    }

    return low;  // The smallest possible maximum pages
}




Split Array Largest Sum

// Function to check if we can split the array into k subarrays with a maximum sum of 'maxSum'
bool canSplit(const vector<int>& nums, int k, int maxSum) {
    int subarrayCount = 1;  // We start with one subarray
    int currentSum = 0;

    for (int num : nums) {
        if (currentSum + num > maxSum) {
            // If adding this element exceeds maxSum, start a new subarray
            subarrayCount++;
            currentSum = num;  // Start new subarray with this element
            if (subarrayCount > k) {
                return false;  // If we need more than k subarrays, return false
            }
        } else {
            currentSum += num;  // Add to the current subarray
        }
    }
    return true;  // It's possible to split into k subarrays
}

// Main function to find the minimized largest sum
int splitArray(const vector<int>& nums, int k) {
    // The minimum possible largest sum is the maximum element, and the maximum is the sum of all elements
    int left = *max_element(nums.begin(), nums.end());
    int right = accumulate(nums.begin(), nums.end(), 0);

    while (left < right) {
        int mid = left + (right - left) / 2;  // Avoid overflow

        if (canSplit(nums, k, mid)) {
            right = mid;  // Try to minimize the largest sum
        } else {
            left = mid + 1;  // Increase the sum
        }
    }
    return left;  // The minimized largest sum is found
}



Painter's Partition

// Helper function to check if it's possible to paint the boards with maxTime as the limit
bool canPaint(const vector<int>& boards, int n, int k, int maxTime) {
    int painters = 1;  // Start with one painter
    int current_time = 0;
    
    for (int i = 0; i < n; ++i) {
        if (current_time + boards[i] > maxTime) {
            painters++;  // Need a new painter
            current_time = boards[i];  // Start new painter with this board
            if (painters > k) {
                return false;  // If number of painters exceeds k, it's not possible
            }
        } else {
            current_time += boards[i];  // Add board to the current painter's time
        }
    }
    
    return true;  // It's possible to paint with the given maxTime
}

// Function to find the minimum time to paint all boards with k painters
int minTimeToPaint(const vector<int>& boards, int n, int k) {
    // Edge case: only one painter, must paint all boards
    if (k == 1) {
        return accumulate(boards.begin(), boards.end(), 0);
    }

    // Edge case: more painters than boards, each painter takes one board
    if (k >= n) {
        return *max_element(boards.begin(), boards.end());
    }

    // Binary search for the minimum maximum time
    int low = *max_element(boards.begin(), boards.end());  // Max board length
    int high = accumulate(boards.begin(), boards.end(), 0);  // Sum of all board lengths
    
    while (low < high) {
        int mid = low + (high - low) / 2;  // Avoid overflow

        if (canPaint(boards, n, k, mid)) {
            high = mid;  // Try to minimize the maxTime
        } else {
            low = mid + 1;  // Increase the time
        }
    }

    return low;  // The minimum maximum time
}


Median of Two Sorted Arrays

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    // Ensure nums1 is the smaller array to minimize binary search range
    if (nums1.size() > nums2.size()) {
        std::swap(nums1, nums2);
    }

    int m = nums1.size(), n = nums2.size();
    int left = 0, right = m;

    while (left <= right) {
        // Partition the first array nums1 at index i
        int i = left + (right - left) / 2;
        // Partition the second array nums2 at index j
        int j = (m + n + 1) / 2 - i;

        // Elements to the left of the partitions
        int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
        // Elements to the right of the partitions
        int minRight1 = (i == m) ? INT_MAX : nums1[i];
        int minRight2 = (j == n) ? INT_MAX : nums2[j];

        // If partition is correct
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            // If total length is odd, return the max of the left partition
            if ((m + n) % 2 == 1) {
                return std::max(maxLeft1, maxLeft2);
            } else {
                // If total length is even, return the average of the two middle elements
                return (std::max(maxLeft1, maxLeft2) + std::min(minRight1, minRight2)) / 2.0;
            }
        } 
        // If partition in nums1 is too far left, move it to the right
        else if (maxLeft1 > minRight2) {
            right = i - 1;
        } 
        // If partition in nums2 is too far left, move partition in nums1 to the right
        else {
            left = i + 1;
        }
    }

    // If we reach here, the arrays were not sorted or have an issue
    throw std::invalid_argument("Input arrays are not sorted.");
}





K-th element of two Arrays


// Function to find the kth element in the merged sorted arrays a and b
int findKthElement(const vector<int>& a, const vector<int>& b, int k) {
    int m = a.size();
    int n = b.size();

    // Ensure that we binary search on the smaller array for efficiency
    if (m > n) {
        return findKthElement(b, a, k);  // Swap a and b
    }

    int low = 0, high = m;

    while (low <= high) {
        int i = (low + high) / 2;         // Partition index for array a
        int j = k - i;                    // Partition index for array b

        // Handle out of bounds conditions
        int aLeft = (i > 0) ? a[i - 1] : INT_MIN;  // Left element of a partition, -∞ if i is 0
        int aRight = (i < m) ? a[i] : INT_MAX;     // Right element of a partition, ∞ if i is m
        int bLeft = (j > 0) ? b[j - 1] : INT_MIN;  // Left element of b partition, -∞ if j is 0
        int bRight = (j < n) ? b[j] : INT_MAX;     // Right element of b partition, ∞ if j is n

        // Check if the partition is correct
        if (aLeft <= bRight && bLeft <= aRight) {
            // If we have found the kth element
            return max(aLeft, bLeft);
        }
        else if (aLeft > bRight) {
            // Move the partition of a[] to the left
            high = i - 1;
        }
        else {
            // Move the partition of a[] to the right
            low = i + 1;
        }
    }

    // If we reach here, it means there was an issue (invalid inputs or something unexpected)
    throw runtime_error("Input arrays are not sorted or there's an issue with the partitioning logic.");
}
