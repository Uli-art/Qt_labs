#ifndef PAIR_H
#define PAIR_H

template <typename T1, typename T2>
class Pair
{
public:
    T1 first;
    T2 second;

    Pair(): first(), second() {}
    Pair(const T1& fir, const T2& sec) : first(fir), second(sec) {}

    template <typename U1, typename U2>
    Pair(Pair<U1, U2>& para) : first(para.first), second(para.second) {}

    template <typename U1, typename U2>
    Pair& operator =(const Pair<U1, U2>& para) {
        first = para.first;
        second =para.second;
        return *this;
    }

    void swap(Pair& other) {
        Pair<T1, T2> tmp(*this);
        *this = other;
        other = tmp;
    }

    bool operator<(const Pair& other){
        if (first == other.first) {
            return (second < other.second);
        }
        return first < other.first;
    }
    bool operator>(const Pair& other){
        if (this->first == other.first) {
            return this->second > other.second;
        }
        return this->first > other.first;
    }
    bool operator<=(const Pair& other){
        return this->first <= other.first;
    }
    bool operator>=(const Pair& other){
        return this->first >= other.first;
    }

};

template<class T1,class T2>
Pair<T1, T2>& make_pair(T1 lhs, T2 rhs){
    return *(new Pair<T1, T2>(lhs, rhs));

}

template<class T1,class T2>
bool operator==(const Pair<T1, T2>& lhs, const Pair<T1, T2>& rhs){
    if(lhs.first == rhs.first && lhs.second == rhs.second){
        return true;
    }
    return false;
};

template<class T1,class T2>
bool operator!=(const Pair<T1, T2>& lhs, const Pair<T1, T2>& rhs){
    if(lhs.first == rhs.first && lhs.second == rhs.second){
        return false;
    }
    return true;
};


#endif // PAIR_H
