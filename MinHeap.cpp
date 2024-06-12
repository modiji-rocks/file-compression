#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// Structure for tree nodes
struct Node {
    char character;
    int freq;
    Node *l, *r;

    Node(char c, int f)
        : character(c)
        , freq(f)
        , l(nullptr)
        , r(nullptr)
    {
    }
};

// Structure for min heap
struct Min_Heap {
    int size;
    vector<Node*> array;

    Min_Heap(int s)
        : size(s)
        , array(s)
    {
    }
};

// Function to create min heap
Min_Heap* createAndBuildMin_Heap(char arr[], int freq[],
                                 int unique_size)
{
    int i;

    // Initializing heap
    Min_Heap* Min_Heap = new Min_Heap(unique_size);

    // Initializing the array of pointers in minheap.
    // Pointers pointing to new nodes of character
    // and their frequency
    for (i = 0; i < unique_size; ++i) {
        Min_Heap->array[i] = new Node(arr[i], freq[i]);
    }

    int n = Min_Heap->size - 1;
    for (i = (n - 1) / 2; i >= 0; --i) {
        // Standard function for Heap creation
        Heapify(Min_Heap, i);
    }

    return Min_Heap;
}

