#include <stdio.h>

class Producer {
    int arr;  // internal array
    Producer(int n) { // generates std::array<T, N> ;
        // fill the array with random data
    }
    produce() { // fill the array with random data
    }
};

class Buffer {
    void push(int elem) {
    }
    // return nullptr or -1 when no more elements
    int pop() { // return an element at a time
    }
};

class Consumer {
    int arr; // Initially empty and must be filled when consume function is called
    void consume() {
        // Keep asking from Buffer the items till buffer becomes empty and
        // consumed/received items should be added to its internal array
    }
};

void verify(vector<int>& prod_arr, vector<int>& cons_arr)
{
    // Compare both arrays and print if both arrays are same or different.
}


int main()
{
    Producer p(10);
    Buffer buf;
    Consumer c;
    
    p.produce();  // if constructor of producer is not producing items
    p.write_to_buf();  // write all elements to Buffer
    c.consume();   // Consume all elements from buffer
    verify(p.get_arr(), c.get_arr());
    return 0;
}
