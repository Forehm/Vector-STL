# Vector-STL
It is a copy of vector from the standard template library. It works the same way, but it has some more methods that I find useful and interesting. This project is open-source so you can use it in your works, IDK why you need it, but here you can add your custom methods. This vector is still supported so I will add more and more methods for comfortable work;
This class is compatible with an std::vector and will use std exceptions soon...
### The project requires C++17 and x86
Functionality:
1) **begin()** - the same as in std::vector
2) **end()** - the same as in std::vector
3) **rbegin()** - the same as in std::vector
4) **rend()** - the same as in std::vector
5) **crbegin()** - the same as in std::vector
6) **crend()** - the same as in std::vector
7) **cbegin()** - the same as in std::vector
8) **cend()** - the same as in std::vector
9) **get_capacity** - returns the capacity
10) **get_size()** - returns size of the container 
11) **is_empty()** - returns true if the container is empty
12) **reserve(*const size_t value*)** - increases capacity
13) **push_back(*const T& value*)** - puts the value to in the end of the container
14) **shrink_to_fit()** - makes capacity 0
15) **pop_back()** - erases the last element
16) **insert(*const size_t& index, const T& value*)** - inserts the element value in the position of index
17) **clear()** - makes the container empty
18) **assign(*const size_t& quantity, const T& value*)** - assigns the quantity number of elements the value of value
19) **resize(*const size_t& new_size*)** - changes the size of the container
20) **at(*const size_t& index*)** - returns the reference to the element under the index
21) **front()** - returns the reference to the first element
22) **back()** - returns the reference to the last element
23) **data()** - returns the raw array
24) **rdata()** -  returns the raw arrays end
25) **Vector(*const Vector& v*)** - constructor
26) **Vector(*const std::vector<T>& v*)** - compatible constructor
27) **Vector(*const size_t& new_size*)** - constructor that can assign the size of the container
28) **Vector(*const size_t& new_size, const T& value*)** - constructor that can assign the size of the container with a value
29) **Vector()** - default constructor 
30) **~Vector()** - destructor
31) **count(*const T& value*)** - returns the count of the elements that have the special value
32) **operator = (*const Vector& v*)** - operator = 
33) **operator = (*const std::vector<T>& v*)** - compatible with std::vector operator =
34) **operator [](*const int& index*)** - operator []
35) **operator != (*const Vector& another*)** - returns true if the containers are not equal
36) **operator + (*const Vector& another*)** - if elements can be summarized, they will be. first element of the first Vector with the first element of the second one etc. Returns the new summarized Vector 
