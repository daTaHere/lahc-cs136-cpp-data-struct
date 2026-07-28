#pragma once

template<class elemType>
int seqOrdSearch(const elemType list[], int length, const elemType& item)
{
    // Write the function definition here
    for (int i = 0; i < length; i++) {
        if (list[i] == item)
            return i;
    }
    return -1; // return -1 if item not found
} //end seqOrdSearch

template <typename elemType>
void modifiedBubbleSort(elemType list[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 1; j < length-i; j++) {
            if (list[j] < list[j - 1]) {
                int temp = list[j];
                list[j] = list[j - 1];
                list[j - 1] = temp;
            }
        }
    }
}