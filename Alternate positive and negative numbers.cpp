void rearrange(int arr[], int n) {
    vector<int> positiveVec, negativeVec;

    // Separate positive and negative numbers into
    // separate vectors
    for (int i = 0; i < n; ++i) {
        if (arr[i] >= 0)
            positiveVec.push_back(arr[i]);
        else
            negativeVec.push_back(arr[i]);
    }

    int posIndex = 0, negIndex = 0, arrIndex = 0;
    bool positiveTurn = true;

    // Merge positive and negative numbers alternatively
    while (posIndex < positiveVec.size()
           && negIndex < negativeVec.size()) {
        if (positiveTurn)
            arr[arrIndex++] = positiveVec[posIndex++];
        else
            arr[arrIndex++] = negativeVec[negIndex++];
        positiveTurn = !positiveTurn;
    }

    // Fill the remaining positive numbers, if any
    while (posIndex < positiveVec.size())
        arr[arrIndex++] = positiveVec[posIndex++];

    // Fill the remaining negative numbers, if any
    while (negIndex < negativeVec.size())
        arr[arrIndex++] = negativeVec[negIndex++];
}
