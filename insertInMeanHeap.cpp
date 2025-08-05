#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vectorSize;
    cin >> vectorSize;
    vector<int> heapVector(vectorSize);

    for (int i = 0; i < vectorSize; i++)
    {
        cin >> heapVector[i];
    }

    int desiredValue;
    cin >> desiredValue;
    heapVector.push_back(desiredValue);

    int currentIndex = heapVector.size() - 1;
    int parentIndex = (currentIndex - 1) / 2;

    while (parentIndex >= 0)
    {
        if (heapVector[parentIndex] > heapVector[currentIndex])
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

    for (int integerValue : heapVector)
    {
        cout << integerValue << " ";
    }

    return 0;
}