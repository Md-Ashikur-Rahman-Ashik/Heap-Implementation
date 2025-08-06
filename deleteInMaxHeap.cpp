#include <bits/stdc++.h>
using namespace std;

void insertHeap(vector<int> &heapVector, int inputValue)
{
    heapVector.push_back(inputValue);
    int currentIndex = 0;

    if (heapVector.size() != 0)
    {
        currentIndex = heapVector.size() - 1;
    }
    else
    {
        currentIndex = 0;
    }

    int parentIndex = 0;
    if (currentIndex != 0)
    {
        parentIndex = (currentIndex - 1) / 2;
    }
    else
    {
        parentIndex = 0;
    }

    while (parentIndex >= 0)
    {
        if (heapVector[parentIndex] < heapVector[currentIndex])
        {
            swap(heapVector[parentIndex], heapVector[currentIndex]);
            currentIndex = parentIndex;
            parentIndex = (currentIndex - 1) / 2;
        }
        else
        {
            break;
        }
    }
}

void deleteHeap(vector<int> &heapVector)
{
    // heapVector[0] = heapVector[heapVector.size() - 1];
    heapVector[0] = heapVector.back();
    heapVector.pop_back();

    int currentIndex = 0;

    int heapSize = heapVector.size();

    while (true)
    {
        int leftChild = (currentIndex * 2) + 1;
        int rightChild = (currentIndex * 2) + 2;
        int leftValue = INT_MIN, rightValue = INT_MIN;

        if (leftChild < heapSize)
        {
            leftValue = heapVector[leftChild];
        }

        if (rightChild < heapSize)
        {
            rightValue = heapVector[rightChild];
        }

        if (leftValue > rightValue && leftValue > heapVector[currentIndex])
        {
            swap(heapVector[leftChild], heapVector[currentIndex]);
            currentIndex = leftChild;
        }
        else if (rightValue > leftValue && rightValue > heapVector[currentIndex])
        {
            swap(heapVector[rightChild], heapVector[currentIndex]);
            currentIndex = rightChild;
        }
        else
        {
            break;
        }
    }
}

void printHeap(vector<int> heapVector)
{
    for (int integerValue : heapVector)
    {
        cout << integerValue << " ";
    }
}

int main()
{
    // Array size 11
    // 42 21 17 9 13 11 6 2 3 7 5

    int vectorSize;
    cin >> vectorSize;

    vector<int> heapVector;

    for (int i = 0; i < vectorSize; i++)
    {
        int inputValue;
        cin >> inputValue;

        insertHeap(heapVector, inputValue);
    }

    deleteHeap(heapVector);
    printHeap(heapVector);

    return 0;
}