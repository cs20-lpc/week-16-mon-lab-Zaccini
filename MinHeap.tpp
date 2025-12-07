template <typename T>
void MinHeap<T>::siftUp(int i) {
    while (i > 0 && data[parent(i)] > data[i]) {
        swap(data[i], data[parent(i)]);
        i = parent(i);
    }
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    int n = size();

    while (true) {
        int leftChild  = left(i);
        int rightChild = right(i);
        int smallest   = i; 

        if (leftChild < n && data[leftChild] < data[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < n && data[rightChild] < data[smallest]) {
            smallest = rightChild;
        }

        if (smallest == i) break;

        swap(data[i], data[smallest]);
        i = smallest;
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    data.push_back(value);
    siftUp(size() - 1);
}

template <typename T>
T MinHeap<T>::removeRoot() {
    if (empty())
        throw runtime_error("Heap is empty");
    T rootValue = data[0];
    data[0] = data.back();
    data.pop_back();
    if (!empty()){
        siftDown(0);
    }
    return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

    swap(data[index], data.back());
    data.pop_back();

     if (index >= size()) return;
    siftUp(index);
    siftDown(index);
}
