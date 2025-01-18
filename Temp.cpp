Breakdown,
dry run,
walkthrough,
visual representation,
illustration,
overview
eaxmple walkthrough



could you make the best solution based on factors like efficiency, readability,clarity, conciseness,correctness,robustness,simplicity and maintainability for me to prepare for my coding interview in c++





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





Row with max 1s


// Function to find the index of the first row with the maximum number of 1s
int rowWithMax1s(const vector<vector<int>>& arr) {
    int n = arr.size();  // number of rows
    int m = arr[0].size();  // number of columns
    
    int max_row_index = -1;  // To store the row index with the maximum 1s
    int max_ones = -1;  // To store the count of maximum 1s in any row
    
    // Iterate through each row
    for (int i = 0; i < n; ++i) {
        // Binary search to find the first 1 in the current row
        int left = 0, right = m - 1;
        
        // We perform binary search in each row
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // If we find 1, we move left to find the first 1
            if (arr[i][mid] == 1) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        // If left is within bounds, it gives us the number of 1s in the row
        int ones_in_row = m - left;
        
        // Update max_ones and max_row_index if this row has more 1s
        if (ones_in_row > max_ones) {
            max_ones = ones_in_row;
            max_row_index = i;
        }
    }
    
    return max_row_index;  // Return the index of the row with maximum 1s
}



Search a 2D Matrix

bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;  // Return false if matrix is empty
    }
    
    int m = matrix.size();    // Number of rows
    int n = matrix[0].size(); // Number of columns
    
    // Perform binary search on the entire matrix as if it's a 1D array
    int left = 0, right = m * n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // To avoid potential overflow
        
        // Convert the 1D index to 2D row and column
        int midValue = matrix[mid / n][mid % n];
        
        if (midValue == target) {
            return true;  // Target found
        } else if (midValue < target) {
            left = mid + 1;  // Search the right half
        } else {
            right = mid - 1; // Search the left half
        }
    }
    
    return false;  // Target not found
}




Search a 2D Matrix II

bool searchMatrix(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;  // Guard clause for empty matrix
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int row = 0, col = cols - 1;  // Start from top-right corner
    
    while (row < rows && col >= 0) {
        int current = matrix[row][col];
        
        if (current == target) {
            return true;  // Target found
        } else if (current > target) {
            --col;  // Move left
        } else {
            ++row;  // Move down
        }
    }
    
    return false;  // Target not found
}


Find a Peak Element II

// Helper function to find the peak element in the middle column
int findMaxInColumn(const vector<vector<int>>& mat, int col) {
    int maxRow = 0;
    int m = mat.size();
    
    for (int i = 1; i < m; ++i) {
        if (mat[i][col] > mat[maxRow][col]) {
            maxRow = i;
        }
    }
    
    return maxRow;
}

// Function to find a peak element
vector<int> findPeakElement(const vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    
    int left = 0, right = n - 1;
    
    // Binary search on columns
    while (left <= right) {
        int midCol = left + (right - left) / 2;
        
        // Find the row with the maximum element in the middle column
        int maxRow = findMaxInColumn(mat, midCol);
        
        // Compare the middle element with its neighbors
        int leftVal = (midCol > 0) ? mat[maxRow][midCol - 1] : -1;
        int rightVal = (midCol < n - 1) ? mat[maxRow][midCol + 1] : -1;
        
        // If the current element is greater than both neighbors, it's a peak
        if (mat[maxRow][midCol] >= leftVal && mat[maxRow][midCol] >= rightVal) {
            return {maxRow, midCol};
        }
        // If left neighbor is larger, move search to the left half
        else if (leftVal > mat[maxRow][midCol]) {
            right = midCol - 1;
        }
        // If right neighbor is larger, move search to the right half
        else {
            left = midCol + 1;
        }
    }
    
    return {}; // This should never be reached since the problem guarantees a peak
}





Median in a row-wise sorted Matrix

// Helper function to count how many elements in a row are <= mid using binary search
int countLessEqual(const vector<int>& row, int mid) {
    return upper_bound(row.begin(), row.end(), mid) - row.begin();
}

// Function to find the median in a row-wise sorted matrix
int findMedian(const vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    // Define the search range: the smallest and largest elements in the matrix
    int low = matrix[0][0];
    int high = matrix[m-1][n-1];
    
    // The position of the median (middle element)
    int medianPos = (m * n) / 2;

    // Perform binary search on the value range
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Count how many elements are <= mid
        int count = 0;
        for (int i = 0; i < m; i++) {
            count += countLessEqual(matrix[i], mid);
        }

        // If we have enough elements <= mid, the median is <= mid, so we search left
        if (count <= medianPos) {
            low = mid + 1;
        } else {
            // Otherwise, the median is greater than mid, so we search right
            high = mid - 1;
        }
    }
    
    // When low == high, we've found the median
    return low;
}



