#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class ArrayList{

//set sets the value at position
//get gets the value at position
//append appends the value to the end of the array -- extend the array if necessary
//insert moves everything down, inserts the value at position, and extends the array to accommodate new value

private:
    T* arr;
    int size;
    int capacity;
    void increaseCapacity();

public:
    ArrayList();
    ArrayList(int size);
    ArrayList(const ArrayList<T>& other);
    ~ArrayList();
    ArrayList& operator=(const ArrayList<T>& other);
    T get(int pos);
    void set(int pos, T value);
    void append(T value);
    void insert(int pos, T value);
};

template <class T>
ArrayList<T>::ArrayList() {

}

template <class T>
ArrayList<T>::ArrayList(int size) {

}

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& other) {

}

template <class T>
ArrayList<T>::~ArrayList() {

}

template <class T>
ArrayList<T>::ArrayList& operator=(const ArrayList<T>& other) {

}



//set the position to value where pos is between 0 and size
template <class T>
void ArrayList<T>::set(int pos, T value) {
    if (pos < 0 || pos > size) {
 //       throw invalid_argument("index out of bounds");
    }
    *(arr+pos) = value;
}

template <class T>
T ArrayList<T>::get(int pos) {
    if (pos < 0 || pos >= size) {
 //       throw invalid_argument("index out of bounds");
    }
    return *(arr+pos);
}

//Appends a value to the end of the array
//The array will automatically resize as necessary
template <class T>
void  ArrayList<T>::append(T value) {
    if (size == capacity) {
        increaseCapacity();
    }
    *(arr+size) = value;
}

//Insert value at pos. All elements > pos are shifted right.
template <class T>
void ArrayList<T>::insert(int pos, T value) {
    if (size == capacity) {
        increaseCapacity();
    }
    for(int i=size-1; i>=position; i--) {
        *(arr + i + 1) = *(arr+i);
    }
    *(arr+pos) = value;
    size++;
}

template <class T>
void ArrayList<T>::increaseCapacity() {
    capacity = capacity * 2;
    T* tmp = new T[capacity];
    for (int i=0; i<size; i++) {
        *(tmp+i) = *(arr+i);
    }
    delete [] arr;
    arr = tmp;
}

int main()
{
    ArrayList<int> test;
    test.append(5);
    test.append(3);
    test.set(0, 9);
    cout << "Test[0]" << test.get(0) << endl;
    ArrayList<int> test2;
    test2 = test;
    cout << "Hello world!" << endl;
    return 0;
}
