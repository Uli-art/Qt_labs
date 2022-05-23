#ifndef VECTORR_H
#define VECTORR_H

#include <stdexcept>

template <typename T>
class vector
{
public:
    vector() {
        array = new T[1];
        _capacity = 1;
        num_of_elements = 0;
    }

    vector(int n) {
        num_of_elements = n;
        while(_capacity <= n){
            _capacity *= 2;
        }
        array = new T[_capacity];
        for(int i = 0; i < n; ++i){
            array[i] = {};
        }
    }

    vector(int n, const T& val) {
        array = new T[n];
        for (int i = 0; i < n; ++i) {
            array[i] = val;
        }
        _capacity = n;
        num_of_elements = n;
    }

    vector(const vector& other) {
        if (num_of_elements) delete[] array;
        array = new T[other._capacity];
        for(int i = 0; i < other.size(); ++i) array[i] = other.array[i];
        num_of_elements = other.size();
        _capacity = other._capacity;
    }

    class iterator {
        T *data;

    public:
        iterator(T *data) : data(data) {}

        iterator(const iterator& other) {
            data = other.data;
        }

        iterator& operator ++() {
            this->data++;
            return *this;
        }

        iterator operator ++(int) {
            iterator tmp = *this;
            this->data++;
            return tmp;
        }

        iterator& operator --() {
            this->data--;
            return *this;
        }

        iterator operator --(int) {
            iterator tmp = *this;
            this->data--;
            return tmp;
        }

        bool operator >(const iterator& other) {
            return (this->data > other.data);
        }

        bool operator <(const iterator& other) {
            return (this->data < other.data);
        }

        bool operator !=(const iterator& other) {
            return (this->data != other.data);
        }

        bool operator ==(const iterator& other) {
            return (this->data == other.data);
        }

        void operator = (const iterator& other) {
            this->data = other.data;
        }

        T& operator *() {
            return *data;
        }

        iterator& operator +=(const int& n) {
            this->data += n;
            return *this;
        }

        iterator& operator -=(const int& n){
            return (*this += (-n));
        }

        iterator operator +(const int& n) {
            iterator tmp = *this;
            tmp.data += n;
            return tmp;
        }

        iterator operator -(const int& n) {
            return (*this + (-n));
        }

        int operator -(const iterator& other){
            return std::abs(this->data - other.data);
        }
    };

    class iterator_const {
        T const* data;

    public:
        iterator_const(T const* data) : data(data) {}

        iterator_const(const iterator_const& other) {
            data = other.data;
        }

        iterator_const& operator ++() {
            this->data++;
            return *this;
        }

        iterator_const operator ++(int) {
            iterator_const tmp = *this;
            this->data++;
            return tmp;
        }

        iterator_const& operator --() {
            this->data--;
            return *this;
        }

        iterator_const operator --(int) {
            iterator_const tmp = *this;
            this->data--;
            return tmp;
        }

        bool operator >(const iterator_const& other) {
            return (this->data > other.data);
        }

        bool operator <(const iterator_const& other) {
            return other > *this;
        }

        bool operator !=(const iterator_const& other) {
            return (this->data != other.data);
        }

        bool operator ==(const iterator_const& other) {
            return (this->data == other.data);
        }

        void operator = (const iterator_const& other) {
            this->data = other.data;
        }

        const T& operator *() {
            return *data;
        }

        iterator_const& operator +=(const int& n) {
            this->data += n;
            return *this;
        }

        iterator_const& operator -=(const int& n){
            return (*this += (-n));
        }

        iterator_const operator +(const int& n) {
            iterator_const tmp = *this;
            tmp.data += n;
            return tmp;
        }

        iterator_const operator -(const int& n) {
            return (*this + (-n));
        }

        int operator -(const iterator_const& other){
            return (this->data - other.data);
        }
    };

    class iterator_rev {
        T *data;

    public:
        iterator_rev(T *data) : data(data) {}

        iterator_rev(const iterator_rev& other) {
            data = other.data;
        }

        iterator_rev& operator --() {
            this->data++;
            return *this;
        }

        iterator_rev operator --(int) {
            iterator_rev tmp = *this;
            this->data++;
            return tmp;
        }

        iterator_rev& operator ++() {
            this->data--;
            return *this;
        }

        iterator_rev operator ++(int) {
            iterator_rev tmp = *this;
            this->data--;
            return tmp;
        }

        bool operator <(const iterator_rev& other) {
            return (this->data > other.data);
        }

        bool operator >(const iterator_rev& other) {
            return other > *this;
        }

        bool operator !=(const iterator_rev& other) {
            return (this->data != other.data);
        }

        bool operator ==(const iterator_rev& other) {
            return (this->data == other.data);
        }

        void operator = (const iterator_rev& other) {
            this->data = other.data;
        }

        T& operator *() {
            return *data;
        }

        iterator_rev& operator +=(const int& n) {
            this->data -= n;
            return *this;
        }

        iterator_rev& operator -=(const int& n){
            return (*this += (-n));
        }

        iterator_rev operator +(const int& n) {
            iterator_rev tmp = *this;
            tmp.data -= n;
            return tmp;
        }

        iterator_rev operator -(const int& n) {
            return (*this + (-n));
        }

        int operator -(const iterator_rev& other){
            return std::abs(this->data - other.data);
        }
    };

    class iterator_rev_const {
        T const* data;

    public:
        iterator_rev_const(T const* data) : data(data) {}

        iterator_rev_const(const iterator_rev_const& other) {
            data = other.data;
        }

        iterator_rev_const& operator --() {
            this->data++;
            return *this;
        }

        iterator_rev_const operator --(int) {
            iterator_rev_const tmp = *this;
            this->data++;
            return tmp;
        }

        iterator_rev_const& operator ++() {
            this->data--;
            return *this;
        }

        iterator_rev_const operator ++(int) {
            iterator_rev_const tmp = *this;
            this->data--;
            return tmp;
        }

        bool operator <(const iterator_rev_const& other) {
            return (this->data > other.data);
        }

        bool operator >(const iterator_rev_const& other) {
            return other > *this;
        }

        bool operator !=(const iterator_rev_const& other) {
            return (this->data != other.data);
        }

        bool operator ==(const iterator_rev_const& other) {
            return (this->data == other.data);
        }

        void operator = (const iterator_rev_const& other) {
            this->data = other.data;
        }

        const T& operator *() {
            return *data;
        }

        iterator_rev_const& operator +=(const int& n) {
            this->data -= n;
            return *this;
        }

        iterator_rev_const& operator -=(const int& n){
            return (*this += (-n));
        }

        iterator_rev_const operator +(const int& n) {
            iterator_rev_const tmp = *this;
            tmp.data -= n;
            return tmp;
        }

        iterator_rev_const operator -(const int& n) {
            return (*this + (-n));
        }

        int operator -(const iterator_rev_const& other){
            return std::abs(this->data - other.data);
        }
    };

    void assign(int num, const T& value){
        T* tmp = new T[num * 2];
        for(int i = 0; i < num; ++i){
            tmp[i] = value;
        }
        if (!num_of_elements) delete[] array;
        array = tmp;
        _capacity = num * 2;
        num_of_elements = num;
    }

    void assign(iterator _begin, iterator _end){
        T* tmp = new T[(_end - _begin) * 2];
        for(iterator i = _begin; i < _end; ++i){
            tmp[i - this->begin()] = *i;
        }
        if (!num_of_elements) delete[] array;
        array = tmp;
        _capacity = (_end - _begin) * 2;
        num_of_elements = _end - _begin;
    }

    T& at(int index){
        if (index >= num_of_elements || index < 0) {
            throw std::out_of_range("Wrong index");
        }
        return array[index];
    }

    T& back() {
        return array[num_of_elements - 1];
    }

    iterator begin() {
        iterator tmp(array);
        return tmp;
    }

    int capacity() {
        return _capacity;
    }

    iterator_const cbegin() {
        iterator_const tmp(array);
        return tmp;
    }

    iterator_const cend() {
        T* pointer = array + num_of_elements;
        iterator_const tmp(pointer);
        return tmp;
    }

    iterator_rev_const crbegin() {
        T* pointer = array + num_of_elements - 1;
        iterator_rev_const tmp(pointer);
        return tmp;
    }

    iterator_rev_const crend() {
        T* pointer = array - 1;
        iterator_rev_const tmp(pointer);
        return tmp;
    }

    void clear() {
        if (!empty()) {
            T* tmp = new T[1];
            if (!num_of_elements) delete[] array;
            array = tmp;
            _capacity = 1;
            num_of_elements = 0;
        }
    }

    T* data() {
        return array;
    }

    template <class... Args>
    void emplace(iterator_const position, Args&&... args) {
        int arr[] = {0, (void(insert(args, position, 1)), 0)...};
    }

    template <class... Args>
    void emplace_back (Args&&... args) {
        int arr[] = {0, (void(push_back(args)), 0)...};
    }

    bool empty() {
        return (num_of_elements == 0);
    }

    iterator end() {
        T* pointer = array + num_of_elements;
        iterator tmp(pointer);
        return tmp;
    }

    void erase (iterator_const _begin, iterator_const _end) {
        iterator_const arka(array);
        iterator_const end2(_end);
        int i = _begin - arka;
        while (end2 - arka < num_of_elements) {
            array[i] = *_end;
            ++end2;
            ++i;
        }
        num_of_elements -= _end - _begin;
    }

    T& front() {
        return array[0];
    }

    void insert(const T& info, iterator_const _begin, int length = 1) {
        iterator_const arka(array);
        int index = _begin - arka;
        if (num_of_elements + length > _capacity) resize(num_of_elements + length);
        for (int i = num_of_elements - 1; i >= index; --i) {
            array[i + length] = array[i];
        }
        for (int i = 0; i < length; ++i) {
            array[index + i] = info;
        }
        num_of_elements += length;
    }

    int max_size() {
        return std::numeric_limits<T>::max();
    }

    void pop_back() {
        --num_of_elements;
    }

    void push_back(const T& value){
        if(!_capacity){
            _capacity = 1;
            array = new T[_capacity];
        }
        else if (num_of_elements == _capacity){
            _capacity *= 2;
            T* tmp = array;
            array = new T[_capacity];
            for (int i = 0; i < num_of_elements; ++i) array[i] = tmp[i];
            delete[] tmp;
        }
        ++num_of_elements;
        array[num_of_elements - 1] = value;
    }

    iterator_rev rbegin() {
        T* pointer = array + num_of_elements - 1;
        iterator_rev tmp(pointer);
        return tmp;
    }

    iterator_rev rend() {
        T* pointer = array - 1;
        iterator_rev tmp(pointer);
        return tmp;
    }


    void reserve(const int& n){
        _capacity = n;
        T* tmp = array;
        array = new T[_capacity];
        for(int i = 0; i < size(); ++i){
            array[i] = tmp[i];
        }
    }

    void resize(const int& n){
        if(!_capacity){
            _capacity = 1;
            while (_capacity < n) {
                _capacity *= 2;
            }
            array = new T[_capacity];
            for (int i = 0; i < n; ++i) array[i] = {};
            num_of_elements = n;
        }
        else{
            while(_capacity < n){
                _capacity *= 2;
            }
            T* tmp = array;
            array = new T[_capacity];
            for (int i = 0; i < num_of_elements; ++i) array[i] = tmp[i];
            for(int i = num_of_elements; i < n; ++i) array[i] = 0;
            num_of_elements = n;
            delete[] tmp;
        }

    }

    int size() const {
        return num_of_elements;
    }

    void swap(vector& other) {
        vector<T> tmp = other;
        other.reserve(this->size());
        other = *this;
        this->reserve(tmp._capacity);
        *this = tmp;
    }

    vector& operator=(const vector& other) {
        if (this != &other) {
            delete[] array;
            array = new T[other._capacity];
            for(int i = 0; i < other.size(); ++i) array[i] = other.array[i];
            num_of_elements = other.size();
            _capacity = other.size();
        }
        return *this;
    }

//    Vectorr& operator =(const Vectorr& other) {
//        this->resize(other._capacity);
//        this->num_of_elements = other.num_of_elements;
//        for (int i = 0; i < other.num_of_elements; ++i) {
//            this->array[i] = other.array[i];
//        }
//        return *this;
//    }

    T& operator [](int index) {
        return array[index];
    }

    T operator [](int index) const {
        return array[index];
    }


    bool operator<(const vector<T>& tmp) const {
        T* _first = array;
        T* _other = tmp.array;

        for (int i = 0; i < num_of_elements && i < tmp.num_of_elements; ++i) {
            if (_first[i] < _other[i]) {
                return true;
            }
            else if (_first[i] > _other[i]) {
                return false;
            }
        }

        return (num_of_elements < tmp.num_of_elements);
    }

    bool operator>(const vector<T>& tmp) const {
        return tmp < *this;
    }

private:
    T* array;
    int _capacity = 1;
    int num_of_elements = 0;
};

#endif // VECTORR_H
