#pragma once
#include <iostream>
#include <vector>

using namespace std;

class VectorException : public std::exception
{
private:
    int error_number_ = 0;

public:
    VectorException(const int& error)
    {
        error_number_ = error;
    }

    const char* What()
    {
        switch (error_number_)
        {
        case 1:
        {
            return "index is out of array range";
            break;
        }
        case 2:
        {
            return "the size cannot be negative";
            break;
        }
        case 3:
        {
            return "the size of the array is too low";
            break;
        }
        default:
        {
            break;
        }
        }
    }
};


template<typename T>
class Vector
{
private:


    int size_ = 0;
    int capacity_ = 0;
    T* vector_;


public:

    class iterator
    {
    public:

        iterator(T* ptr) : ptr_(ptr) { }
        iterator operator++() { iterator i = *this; ptr_++; return i; }
        iterator operator++(int junk) { ptr_++; return *this; }
        T& operator*() { return *ptr_; }
        T* operator->() { return ptr_; }
        bool operator==(const iterator& rhs) { return ptr_ == rhs.ptr_; }
        bool operator!=(const iterator& rhs) { return ptr_ != rhs.ptr_; }


    private:
        T* ptr_;
    };

    class const_iterator
    {
    public:


        const_iterator(T* ptr) : ptr_(ptr) { }
        const_iterator operator++() { const_iterator i = *this; ptr_++; return i; }
        const_iterator operator++(int junk) { ptr_++; return *this; }
        const T& operator*() { return *ptr_; }
        const T* operator->() { return ptr_; }
        bool operator==(const const_iterator& rhs) { return ptr_ == rhs.ptr_; }
        bool operator!=(const const_iterator& rhs) { return ptr_ != rhs.ptr_; }


    private:
        T* ptr_;
    };

    class reverse_iterator
    {
    public:
        reverse_iterator(T* ptr) : ptr_(ptr) { }
        reverse_iterator operator++() { reverse_iterator i = *this; ptr_--; return i; }
        reverse_iterator operator++(int junk) { ptr_--; return *this; }
        T& operator*() { return *ptr_; }
        T* operator->() { return ptr_; }
        bool operator==(const reverse_iterator& rhs) { return ptr_ == rhs.ptr_; }
        bool operator!=(const reverse_iterator& rhs) { return ptr_ != rhs.ptr_; }

    private:
        T* ptr_;
    };

    class const_reverse_iterator
    {
    public:
        const_reverse_iterator(T* ptr) : ptr_(ptr) { }
        const_reverse_iterator operator++() { const_reverse_iterator i = *this; ptr_--; return i; }
        const_reverse_iterator operator++(int junk) { ptr_--; return *this; }
        const T& operator*() { return *ptr_; }
        const T* operator->() { return ptr_; }
        bool operator==(const const_reverse_iterator& rhs) { return ptr_ == rhs.ptr_; }
        bool operator!=(const const_reverse_iterator& rhs) { return ptr_ != rhs.ptr_; }

    private:
        T* ptr_;
    };



    iterator begin() { return iterator(vector_); }

    iterator end() { return iterator(vector_ + size_); }

    reverse_iterator rbegin() { return reverse_iterator(&vector_[size_ - 1]); }

    reverse_iterator rend() { return reverse_iterator(vector_ - 1); }

    const_reverse_iterator crbegin() const { return const_reverse_iterator(&vector_[size_ - 1]); }

    const_reverse_iterator crend() const { return const_reverse_iterator(vector_ - 1); }

    const_iterator cbegin() const { return const_iterator(vector_); }

    const_iterator cend() const { return const_iterator(vector_ + size_); }

    int get_capacity() const { return capacity_; }

    int get_size() const { return size_; }

    bool is_empty() const { return size_ == 0; }

    void reserve(const int value)
    {
        capacity_ = value;

        T* arr = new T[size_ + value];
        for (int i = 0; i < size_; ++i)
        {
            arr[i] = vector_[i];
        }

        delete[]vector_;
        vector_ = arr;
        arr = nullptr;

    }

    void push_back(const T& value)
    {
        T* arr;
        if (capacity_ <= 0)
        {
            arr = new T[size_ + 1];
            for (int i = 0; i < size_; ++i)
            {
                arr[i] = vector_[i];
            }
            arr[size_] = value;
            delete[]vector_;
            vector_ = arr;
            arr = nullptr;
            ++size_;

        }
        else
        {
            vector_[size_] = value;
            if (capacity_ > 0)
            {
                --capacity_;
            }
            ++size_;
        }




    }
    void shrink_to_fit()
    {
        capacity_ = 0;

        T* arr = new T[size_];
        for (int i = 0; i < size_; ++i)
        {
            arr[i] = vector_[i];
        }

        delete[]vector_;
        vector_ = arr;
        arr = nullptr;

    }

    void pop_back()
    {
        T* arr = new T[size_ - 1];

        for (int i = 0; i < size_ - 1; ++i)
        {
            arr[i] = vector_[i];
        }


        delete[]vector_;
        vector_ = arr;
        arr = nullptr;
        --size_;
    }

    void insert(const int& index, const T& value)
    {
        T* arr;
        if (capacity_ <= 0)
        {
            arr = new T[size_ + 1];
            for (int i = 0, j = 0; j < size_; ++i, ++j)
            {
                if (i == index)
                {
                    arr[i] = value;
                    ++i;

                }
                arr[i] = vector_[j];
            }

            delete[]vector_;
            vector_ = arr;
            arr = nullptr;


        }
        else
        {
            for (int i = size_; i > 0; i--)
            {
                if (i == index)
                {
                    vector_[i] = value;
                    break;
                }
                else
                {
                    vector_[i] = vector_[i - 1];
                }
            }

        }

        ++size_;

    }

    void clear()
    {
        size_ = 0;
        capacity_ = 0;
        T* arr = new T[size_ + capacity_];
        delete[] vector_;
        vector_ = arr;
        arr = nullptr;
    }

    void assign(const int& quantity, const T& value)
    {
        T* arr;
        arr = new T[quantity];
        size_ = quantity;
        capacity_ = 0;

        for (int i = 0; i < quantity; i++)
        {
            arr[i] = value;
        }


        delete[]vector_;
        vector_ = arr;
        arr = nullptr;
    }

    void resize(const int& new_size)
    {
        if (new_size <= 0)
        {
            throw VectorException(2);
        }

        T* arr = new T[new_size];

        for (int i = 0; i < new_size; ++i)
        {
            arr[i] = vector_[i];
        }

        vector_ = nullptr;
        vector_ = arr;
        arr = nullptr;

        size_ = new_size;
    }

    T at(const int& index)
    {
        if (index < 0 || index > size_ - 1)
        {
            throw VectorException(1);
        }
        else
        {
            return vector_[index];
        }

    }  T& front() { return vector_[0]; }

    T& back() { return vector_[size_ - 1]; }

    T* data() { return this->vector_; }

    T* rdata() { return this->vector_ + (size_ - 1); }

    Vector(const Vector& v)
    {
        this->size_ = v.size_;
        this->capacity_ = v.capacity_;

        vector_ = new T[size_ + capacity_];

        for (int i = 0; i < size_; i++)
        {
            vector_[i] = v.vector_[i];
        }

    }

    Vector(const int& new_size, const T& value)
    {
        if (new_size <= 0)
        {
            throw VectorException(2);
        }
        vector_ = new T[new_size];
        size_ = new_size;

        for (int i = 0; i < size_; ++i)
        {
            vector_[i] = value;
        }
    }

    Vector() { vector_ = new T[size_]; }

    ~Vector()
    {
        delete[]vector_;
        vector_ = nullptr;
    }

    int count(const T& value)
    {
        int counter = 0;

        for (int i = 0; i < size_; ++i)
        {
            if (vector_[i] == value)
            {
                ++counter;
            }
        }

        if (counter < 0)
        {
            counter = 0;
        }

        return counter;
    }

    T& operator = (const Vector& v)
    {
        this->size_ = v.get_size();
        T* arr = new T[v.get_size()];

        if (size_ > 0 && v.get_size() > 0)
        {
            for (int i = 0; i < size_; ++i)
            {
                arr[i] = v.vector_[i];
            }

            delete[] vector_;
            vector_ = arr;
            arr = nullptr;
        }
        else
        {
            throw VectorException(3);
        }

    }

    T& operator [](const int& index)
    {
        if (index < 0 || index > size_ - 1)
        {
            throw VectorException(1);
        }

        return vector_[index];
    }

    bool operator == (const Vector& another)
    {
        if (this->get_size() != another.get_size())
        {
            return false;
        }

        for (int i = 0; i < this->get_size(); ++i)
        {
            if (this->vector_[i] != another.vector_[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator != (const Vector& another)
    {
        if (this->get_size() != another.get_size())
        {
            return true;
        }

        for (int i = 0; i < this->get_size(); ++i)
        {
            if (this->vector_[i] != another.vector_[i])
            {
                return true;
            }
        }
        return false;
    }

    Vector operator + (const Vector& another)
    {
        if (this->get_size() > another.get_size() || this->get_size() == another.get_size())
        {
            for (int i = 0; i < another.get_size(); ++i)
            {
                this->vector_[i] += another.vector_[i];
            }
        }
        else
        {
            this->reserve(another.get_size() - this->get_size());
            int i = 0;
            for (; i < this->get_size(); ++i)
            {
                this->vector_[i] += another.vector_[i];
            }

            for (; i < another.get_size(); ++i)
            {
                this->vector_[i] = another.vector_[i];
            }
            size_ += capacity_;
            capacity_ = 0;
        }
        return *this;
    }

};


