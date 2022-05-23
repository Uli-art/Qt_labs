#ifndef PAIR_H
#define PAIR_H

template<class T1, class T2>
struct Pair
{
    Pair();
    Pair(const T1& first, const T2& second);
    Pair(const Pair& newPair);

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
    Pair& operator =(const Pair& otherPair);

    template<class P1, class P2>
    Pair& operator =(const Pair<P1, P2>& otherPair)
    {
        first = otherPair.first;
        second = otherPair.second;

        return *this;
    }

    T1 first;
    T2 second;

    friend Pair<T1,T2>& make_Pair( T1& first, T2& second);
};

template<class T1, class T2>
Pair<T1,T2>::Pair() :
    first(),
    second()
{
};

template<class T1, class T2>
Pair<T1,T2>::Pair(const T1& p1,const T2& p2) :
    first(p1),
    second(p2)
{
};

template<class T1, class T2>
Pair<T1,T2>::Pair(const Pair& newPair) :
    first(newPair.first),
    second(newPair.second)
{
};

template<class T1, class T2>
Pair<T1,T2>& Pair<T1,T2>::operator =(const Pair& otherPair) {
    first = otherPair.first;
    second = otherPair.second;
    return *this;
}

template<class T1, class T2>
Pair<T1,T2>& make_Pair( T1& first, T2& second){
        return *(new Pair<T1,T2>(first, second));
    }
#endif // PAIR_H
