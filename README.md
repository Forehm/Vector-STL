#Vector-STL
It is a copy of vector from the standard template library. It works the same way, but it has some more methods that I find useful and interesting. This project is open-source so you can use it in your works, IDK why you need it, but here you can add your custom methods. This vector is still supported so I will add more and more methods for comfortable work;
This class is compatible with an std::vector and will use std exceptions soon...
The project requires C++17 and x86
Functionality:
1) begin() - the same as in std::vector
2) end() - the same as in std::vector
3) rbegin() - the same as in std::vector
4) rend() - the same as in std::vector
5) crbegin() - the same as in std::vector
6) crend() - the same as in std::vector
7) cbegin() - the same as in std::vector
8) cend() - the same as in std::vector
9) get_capacity() - returns the capacity
10) get_size() - returns size of the container 
11) is_empty() - returns true if the container is empty
12) reserve(const size_t value) - 
    void push_back(const T& value)
    void shrink_to_fit()
    void pop_back()
    void insert(const size_t& index, const T& value)
    void clear()
    void assign(const size_t& quantity, const T& value)
    void resize(const size_t& new_size)
    T at(const size_t& index)
    T& front()
    T& back() 
    T* data()
    T* rdata() 
    Vector(const Vector& v)
    Vector(const vector<T>& v)
    Vector(const size_t& new_size)
    Vector(const size_t& new_size, const T& value)
    Vector() 
    ~Vector()
    size_t count(const T& value)
    T& operator = (const Vector& v)
    T& operator = (const vector<T>& v)
    T& operator [](const int& index)
    bool operator != (const Vector& another)
    Vector operator + (const Vector& another)
