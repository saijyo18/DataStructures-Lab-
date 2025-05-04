//To implement a max heap 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        if (index && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            heapifyUp((index - 1) / 2);
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void deleteMax() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return;
        }

        cout << "Deleted element: " << heap[0] << endl;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void display() {
        if (heap.empty()) {
            cout << "Heap is empty.\n";
            return;
        }

        cout << "Heap elements: ";
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }

    void search(int key) {
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i] == key) {
                cout << "Element found at index " << i << endl;
                return;
            }
        }
        cout << "Element not found in heap.\n";
    }

    void heapSort() {
        vector<int> tempHeap = heap;
        vector<int> sorted;

        while (!heap.empty()) {
            sorted.push_back(heap[0]);
            deleteMax();
        }

        cout << "Heap sorted in descending order: ";
        for (int val : sorted)
            cout << val << " ";
        cout << endl;

        heap = tempHeap; // Restore original heap
    }
};

int main() {
    MaxHeap pq;
    int choice, value;

    do {
        cout << "\n Priority Queue ADT menu s\n";
        cout << "1. Insert\n2. Delete\n3. Display\n4. Search\n5. Sort (Heap Sort)\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;
            case 2:
                pq.deleteMax();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                pq.search(value);
                break;
            case 5:
                pq.heapSort();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
