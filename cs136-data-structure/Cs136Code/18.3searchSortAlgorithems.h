#pragma once

using namespace std;

//============== seqSort ===============
template<class elemType>
int seqOrdSearch(const elemType list[], int length, const elemType& item)
{
    // Write the function definition here
    for (int i = 0; i < length; i++) {
        if (list[i] == item)
            return i;
    }
    return -1; // return -1 if item not found
} 


//============== bubbleSort ===============
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

//============== insertionSort ===============
template <class elemType>
void insertionSort(elemType list[], int length)
{
    for (int firstOutOfOrder = 1; firstOutOfOrder < length;
        firstOutOfOrder++)
        if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
        {
            elemType temp = list[firstOutOfOrder];
            int location = firstOutOfOrder;

            do
            {
                list[location] = list[location - 1];
                location--;
            } while (location > 0 && list[location - 1] > temp);

            list[location] = temp;
        }
} 


// ============== Helper ===============
template <typename Type>
void printList(Type nums[], int length ) {
    for (int i = 0; i < length; i++) 
        cout << nums[i] << " ";
    cout << endl;
        
}