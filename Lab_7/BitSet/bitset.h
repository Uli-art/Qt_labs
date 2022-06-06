#ifndef BITSET_H
#define BITSET_H

#include <memory>
#include <limits>
#include <string>

template <size_t N>
class BitSet
{
public:
    typedef unsigned long long WordType;

    class BitRef {
    public:
        BitRef& operator=(bool value) {
            _bitSet.set(_bitPos, value);
            return *this;
        }

    private:
        BitRef(BitSet<N>& bitSet, size_t bitPos) :
            _bitSet(bitSet),
            _bitPos(bitPos) {
        }

        BitSet<N>& _bitSet;
        size_t _bitPos;

        friend class BitSet;
    };

    BitSet();
    BitSet(unsigned long long value);
    BitSet(const std::string& value);
    BitSet(const BitSet& other);

    BitSet& operator=(const BitSet& other);

    bool operator[](size_t pos) const;
    BitRef operator[](size_t pos);

    BitSet<N>& operator&=(const BitSet<N>& other);
    BitSet<N>& operator|=(const BitSet<N>& other);
    BitSet<N>& operator^=(const BitSet<N>& other);
    BitSet<N> operator~() const;

    BitSet<N>& operator<<=(size_t count);
    BitSet<N> operator<<(size_t count) const;
    BitSet<N> operator>>(size_t count) const;
    BitSet<N>& operator>>=(size_t count);

    size_t size() const;
    size_t count() const;
    bool test(size_t pos) const;
    bool all() const;
    bool any() const;
    bool none() const;
    BitSet<N>& flip();
    BitSet<N>& flip(size_t pos);
    BitSet<N>& reset();
    BitSet<N>& reset(size_t pos);
    BitSet<N>& set();
    BitSet<N>& set(size_t pos, bool value);

    std::string toString() const;
    unsigned long long toUllong() const;
    unsigned long toUlong() const;

    static size_t getWordSize();
    static size_t getWordCountInArray();

private:
    void setWord(size_t pos, WordType value);
    std::string wordToString(WordType value) const;
    int getWordIndex(size_t pos) const;
    int getBitIndex(size_t pos) const;

private:
    static const int BitsInWord = std::numeric_limits<WordType>::digits;
    static const int WordsInArray = N / BitsInWord + ((N % BitsInWord) > 0 ? 1 : 0);
    static const WordType AllBitsMask = ~WordType(0);

    WordType _bitArray[WordsInArray];
};

template <size_t N>
BitSet<N>::BitSet() :
    _bitArray() {

}

template <size_t N>
BitSet<N>::BitSet(unsigned long long value) :
    _bitArray() {
    setWord(0, value);
}

template <size_t N>
BitSet<N>::BitSet(const std::string& value) {
    size_t pos = 0;
    for (std::string::const_reverse_iterator charIt = value.rbegin(); charIt != value.rend(); ++charIt) {
        set(pos++, *charIt == '0' ? false : true);
    }
}

template <size_t N>
BitSet<N>::BitSet(const BitSet& other) {
    std::copy(other._bitArray, other._bitArray + WordsInArray, _bitArray);
}

template <size_t N>
BitSet<N>& BitSet<N>::operator=(const BitSet<N>& other) {
    std::copy(other._bitArray, other._bitArray + WordsInArray, _bitArray);
    return *this;
}

template <size_t N>
bool BitSet<N>::operator[](size_t pos) const {
    return test(pos);
}

template <size_t N>
typename BitSet<N>::BitRef BitSet<N>::operator[](size_t pos) {
    return BitRef(*this, pos);
}

template <size_t N>
BitSet<N>& BitSet<N>::operator&=(const BitSet<N>& other) {
    for (int pos = 0; pos < WordsInArray; ++pos) {
        _bitArray[pos] &= other._bitArray[pos];
    }
    return *this;
}

template <size_t N>
BitSet<N>& BitSet<N>::operator|=(const BitSet<N>& other) {
    for (int pos = 0; pos < WordsInArray; ++pos) {
        _bitArray[pos] |= other._bitArray[pos];
    }
    return *this;
}

template <size_t N>
BitSet<N>& BitSet<N>::operator^=(const BitSet<N>& other) {
    for (int pos = 0; pos < WordsInArray; ++pos) {
        _bitArray[pos] ^= other._bitArray[pos];
    }
    return *this;
}

template <size_t N>
BitSet<N> BitSet<N>::operator~() const {
    BitSet copy(*this);
    return copy.flip();
}

template <size_t N>
BitSet<N>& BitSet<N>::operator<<=(size_t count) {
    if (count <= 0) {
        return *this;
    }

    const size_t wordIndex = getWordIndex(count);
    const size_t offset = getBitIndex(count);

    if (offset == 0) {
        for (size_t i = WordsInArray - 1; i >= wordIndex; --i) {
            _bitArray[i] = _bitArray[i - wordIndex];
        }
    }
    else {
        const size_t bitToRightCount = BitsInWord - offset;
        for (size_t i = WordsInArray - 1; i > wordIndex; --i) {
            _bitArray[i] = ((_bitArray[i - wordIndex] << offset) | (_bitArray[i - wordIndex - 1] >> bitToRightCount));
        }

        _bitArray[wordIndex] = _bitArray[0] << offset;
    }

    std::fill(_bitArray, _bitArray + wordIndex, WordType(0));
    return *this;
}

template <size_t N>
BitSet<N> BitSet<N>::operator<<(size_t count) const {
    return BitSet<N>(*this) <<= count;
}

template <size_t N>
BitSet<N> BitSet<N>::operator>>(size_t count) const {
    return BitSet<N>(*this) >>= count;
}

template <size_t N>
BitSet<N>& BitSet<N>::operator>>=(size_t count) {
    if (count <= 0) {
        return *this;
    }

    const size_t wordIndex = getWordIndex(count);
    const size_t offset = getBitIndex(count);
    const size_t wordToLeftCount = WordsInArray - wordIndex - 1;

    if (offset == 0) {
        for (size_t i = 0; i <= wordToLeftCount; ++i) {
            _bitArray[i] = _bitArray[i + wordIndex];
        }
    }
    else {
        const size_t bitToLeftCount = BitsInWord - offset;
        for (size_t i = 0; i < wordToLeftCount; ++i) {
            _bitArray[i] = ((_bitArray[i + wordIndex] >> offset) | (_bitArray[i + wordIndex + 1] << bitToLeftCount));
        }

        _bitArray[wordToLeftCount] = _bitArray[WordsInArray - 1] >> offset;
    }

    std::fill(_bitArray + wordToLeftCount + 1, _bitArray + WordsInArray, WordType(0));
    return *this;
}

template <size_t N>
size_t BitSet<N>::size() const {
    return N;
}

template <size_t N>
size_t BitSet<N>::count() const {
    size_t bitCount = 0;
    for (int pos = 0; pos < WordsInArray; ++pos) {
        WordType word = _bitArray[pos];
        for (int bit = 0; bit < BitsInWord; ++bit) {
            if (word & WordType(1) << bit) {
                ++bitCount;
            }
        }
    }

    return bitCount;
}

template <size_t N>
bool BitSet<N>::test(size_t pos) const {
    return _bitArray[getWordIndex(pos)] & (WordType(1) << getBitIndex(pos));
}


template <size_t N>
bool BitSet<N>::all() const {
    for (int i = 0; i < WordsInArray; ++i) {
        if (_bitArray[i] != AllBitsMask) {
            return false;
        }
    }

    return true;
}

template <size_t N>
bool BitSet<N>::any() const {
    for (int i = 0; i < WordsInArray; ++i) {
        if (_bitArray[i] != WordType(0)) {
            return true;
        }
    }

    return false;
}

template <size_t N>
bool BitSet<N>::none() const {
    return !any();
}

template <size_t N>
BitSet<N>& BitSet<N>::flip() {
    for (int i = 0; i < WordsInArray; ++i) {
        _bitArray[i] ^= AllBitsMask;
    }

    return *this;
}

template <size_t N>
BitSet<N>& BitSet<N>::flip(size_t pos) {
    _bitArray[getWordIndex(pos)] ^= (WordType(1) << getBitIndex(pos));
    return *this;
}

template <size_t N>
BitSet<N>& BitSet<N>::reset() {
    for (int i = 0; i < WordsInArray; ++i) {
        _bitArray[i] = WordType(0);
    }

    return *this;
}

template <size_t N>
BitSet<N>& BitSet<N>::reset(size_t pos) {
    _bitArray[getWordIndex(pos)] &= ~(WordType(1) << getBitIndex(pos));
    return *this;
}

template <size_t N>
BitSet<N>& BitSet<N>::set() {
    for (int i = 0; i < WordsInArray; ++i) {
        _bitArray[i] |= AllBitsMask;
    }

    return *this;
}

template <size_t N>
BitSet<N>& BitSet<N>::set(size_t pos, bool value) {
    if (value) {
        _bitArray[getWordIndex(pos)] |= WordType(1) << getBitIndex(pos);
    }
    else {
        reset(pos);
    }

    return *this;
}

template <size_t N>
std::string BitSet<N>::toString() const {
    std::string result;
    for (int pos = WordsInArray - 1; pos >= 0; --pos) {
        result += wordToString(_bitArray[pos]);
    }

    return result;
}

template <size_t N>
unsigned long long BitSet<N>::toUllong() const {
    return _bitArray[0];
}

template <size_t N>
unsigned long BitSet<N>::toUlong( ) const {
    return _bitArray[0];
}

template <size_t N>
size_t BitSet<N>::getWordSize() {
    return BitsInWord;
}

template <size_t N>
size_t BitSet<N>::getWordCountInArray() {
    return WordsInArray;
}

template <size_t N>
void BitSet<N>::setWord(size_t pos, WordType value) {
    _bitArray[pos] = value;
}

template <size_t N>
std::string BitSet<N>::wordToString(WordType value) const {
    std::string result;
    for (int pos = BitsInWord - 1; pos >= 0; --pos) {
        result += (value & (WordType(1) << pos)) ? std::string("1") : std::string("0");
    }

    return result;
}

template <size_t N>
int BitSet<N>::getWordIndex(size_t pos) const {
    return pos / BitsInWord;
}

template <size_t N>
int BitSet<N>::getBitIndex(size_t pos) const {
    return (pos < BitsInWord) ? pos : pos % BitsInWord - 1;
}

template <size_t N>
BitSet<N> operator&(const BitSet<N>& left, const BitSet<N>& right) {
    return BitSet<N>(left) &= right;
}

template <size_t N>
BitSet<N> operator|(const BitSet<N>& left, const BitSet<N>& right) {
    return BitSet<N>(left) |= right;
}

template <size_t N>
BitSet<N> operator^(const BitSet<N>& left, const BitSet<N>& right) {
    return BitSet<N>(left) ^= right;
}


#endif // BITSET_H
