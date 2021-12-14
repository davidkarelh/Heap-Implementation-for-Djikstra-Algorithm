#include "Heap.cpp"

class PrioQueue {
    Heap pqueue;
    
    public:
        bool isEmpty() {
            return pqueue.length == 0;
        }

        void enqueue(ElType val) {
            pqueue.insert_data(val);
        }

        ElType dequeue() {
            return pqueue.delete_data();
        }
};