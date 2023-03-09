template<typename T>
class Vector
{
private:


    int size = 0;
    int capacity = 0;
    T* vector;


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



    iterator begin() { return iterator(vector); }

    iterator end() { return iterator(vector + size); }

    reverse_iterator rbegin() { return reverse_iterator(&vector[size - 1]); }

    reverse_iterator rend() { return reverse_iterator(vector - 1); }

    const_reverse_iterator crbegin() const { return const_reverse_iterator(&vector[size - 1]); }

    const_reverse_iterator crend() const { return const_reverse_iterator(vector - 1); }

    const_iterator cbegin() const { return const_iterator(vector); }

    const_iterator cend() const { return const_iterator(vector + size); }

    int get_capacity() const { return capacity; }

    int get_size() const { return size; }

    bool is_empty() const { return size == 0; }

    void reserve(const int value)
    {
        capacity = value;

        T* arr = new T[size + value];
        for (int i = 0; i < size; ++i)
        {
            arr[i] = vector[i];
        }

        delete[]vector;
        vector = arr;
        arr = nullptr;

    }

    void push_back(const T& value)
    {
        T* arr;
        if (capacity <= 0)
        {
            arr = new T[size + 1];
            for (int i = 0; i < size; ++i)
            {
                arr[i] = vector[i];
            }
            arr[size] = value;
            delete[]vector;
            vector = arr;
            arr = nullptr;
            ++size;

        }
        else
        {
            vector[size] = value;
            if (capacity > 0)
            {
                capacity--;
            }
            ++size;
        }




    }

    void shrink_to_fit()
    {
        capacity = 0;

        T* arr = new T[size];
        for (int i = 0; i < size; ++i)
        {
            arr[i] = vector[i];
        }

        delete[]vector;
        vector = arr;
        arr = nullptr;

    }

    void pop_back()
    {
        T* arr = new T[size - 1];

        for (int i = 0; i < size - 1; ++i)
        {
            arr[i] = vector[i];
        }


        delete[]vector;
        vector = arr;
        arr = nullptr;
        size--;
    }

    void insert(const int& index, const T& value)
    {
        T* arr;
        if (capacity <= 0)
        {
            arr = new T[size + 1];
            for (int i = 0, j = 0; j < size; ++i, ++j)
            {
                if (i == index)
                {
                    arr[i] = value;
                    ++i;

                }
                arr[i] = vector[j];
            }

            delete[]vector;
            vector = arr;
            arr = nullptr;


        }
        else
        {
            for (int i = size; i > 0; i--)
            {
                if (i == index)
                {
                    vector[i] = value;
                    break;
                }
                else
                {
                    vector[i] = vector[i - 1];
                }
            }

        }

        ++size;

    }

    void clear()
    {
        size = 0;
        capacity = 0;
        T* arr = new T[size + capacity];
        delete[] vector;
        vector = arr;
        arr = nullptr;
    }

    void assign(const int& quantity, const T& value)
    {
        T* arr;
        arr = new T[quantity];
        size = quantity;
        capacity = 0;

        for (int i = 0; i < quantity; i++)
        {
            arr[i] = value;
        }


        delete[]vector;
        vector = arr;
        arr = nullptr;
    }

    T at(const int& index)
    {
        if (index < 0 || index > size - 1)
        {
            throw 1;
        }
        else
        {
            return vector[index];
        }

    }

    T& front() { return vector[0]; }

    T& back() { return vector[size - 1]; }

    T* data() { return this->vector; }

    string What(const int& error_number)
    {
        if (error_number == 1)
        {
            return "index is out of array range ";
        }
        if (error_number == 3)
        {
            return "the size of the array is too low";
        }
    }

    Vector(const Vector& v)
    {
        this->size = v.size;
        this->capacity = v.capacity;

        vector = new T[size + capacity];

        for (int i = 0; i < size; i++)
        {
            vector[i] = v.vector[i];
        }

    }

    Vector() { vector = new T[size]; }

    ~Vector()
    {
        delete[]vector;
        vector = nullptr;
    }

    int count(const T& value)
    {
        int counter = 0;

        for (int i = 0; i < size; ++i)
        {
            if (vector[i] == value)
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
        this->size = v.get_size();
        T* arr = new T[v.get_size()];

        if (size > 0 && v.get_size() > 0)
        {
            for (int i = 0; i < size; ++i)
            {
                arr[i] = v.vector[i];
            }

            delete[] vector;
            vector = arr;
            arr = nullptr;
        }
        else
        {
            throw 3;
        }

    }

    T& operator [](const int& index)
    {
        if (index < 0 || index > size - 1)
        {
            throw 1;
        }

        return vector[index];
    }

    bool operator == (const Vector& another)
    {
        if (this->get_size() != another.get_size())
        {
            return false;
        }

        for (int i = 0; i < this->get_size(); ++i)
        {
            if (this->vector[i] != another.vector[i])
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
            if (this->vector[i] != another.vector[i])
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
                this->vector[i] += another.vector[i];
            }
        }
        else
        {
            this->reserve(another.get_size() - this->get_size());
            int i = 0;
            for (; i < this->get_size(); ++i)
            {
                this->vector[i] += another.vector[i];
            }

            for (; i < another.get_size(); ++i)
            {
                this->vector[i] = another.vector[i];
            }
            size += capacity;
            capacity = 0;
        }
        return *this;
    }

};


