// Heap Data Structure

#include <iostream>

using namespace std;

int left(int i)
{
    return 2 * i;
}

int right(int i)
{
    return 2 * i + 1;
}

/*int parent(int i)
{
    return i / 2;
}*/

// Max Heap implementation

void max_heapify(int heap[], int heap_size, int i)
{
    int l, r, largest, t;

    l = left(i); // left child index

    r = right(i); // right child index;

    if(l <= heap_size && heap[l] > heap[i])
    {
        largest = l; // Since heap[l] is greater, so it will be largest l
    }
    else
    {
        largest = i; // else largest will be i
    }

    if(r <= heap_size && heap[r] > heap[largest])
    {
        largest = r;
    }

    if(largest != i)
    {
           //t = heap[i];
          //heap[i] = heap[largest];
         //heap[largest] = t;

        swap(heap[i], heap[largest]);

        max_heapify(heap, heap_size, largest);
    }
}

// build heap

void build_max_heap(int heap[], int heap_size)
{
    int i;

    for(i = heap_size / 2; i >= 1; i--)
    {
        max_heapify(heap, heap_size, i);
    }
}

// heap sort
void heap_sort(int heap[], int heap_size)
{
    int i, t;

    build_max_heap(heap, heap_size);

    for(i = heap_size; i > 1; i--)
    {
        //t = heap[1];

        //heap[1] = heap[i];

        //heap[i] = t;

        swap(heap[1], heap[i]);

        heap_size -= 1;

        max_heapify(heap, heap_size, 1);
    }
}


int main()
{
    int h_size = 6;

    int hp[] = {0, 12, 11, 13, 5, 6, 7};

    //build_max_heap(hp,h_size);

    heap_sort(hp,h_size);

    for(int i=1; i<=h_size; i++)
    {
       if(i==h_size) cout << hp[i];

       else cout << hp[i] << " ---> ";
    }

    return 0;
}
