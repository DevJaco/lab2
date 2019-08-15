// size_capacity.cpp
// Vector size versus capacity

#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec;
    cout << "vec: size: " << vec.size() 
         << " capacity: " << vec.capacity() << endl;

    for(int i = 0; i < 24; i++) {
        vec.push_back(i);
        cout << "vec: size: " << vec.size() 
             << " capacity: " << vec.capacity() << endl;
    }

    return 0;
}

// Exercise 2.1
// Vector capacity is the size of the array used to store the vector. 
// Vector size is the number of elements that the vector contains which is directly controlled by the number of elements added to the vector.
// The capacity of a vector is always equal to or greater than the vector size. The benefit of using a vector over an array is dynamic size.
// The vector capacity grows by reallocating memory to allow more elements to be added as needed. 