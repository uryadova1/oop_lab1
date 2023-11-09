//
// Created by tyzzko on 19.10.2023.
//

#include "BitArray.h"
#include <iostream>
#include <string.h>

BitArray::BitArray() {
    this->array = new bool[0]{};
    this->size = 0;
}

BitArray::~BitArray() {
    delete[] this->array;
    delete this;
}

BitArray::BitArray(int num_bits, unsigned long value) {
    unsigned long new_value = value;
    this->size = num_bits;
    this->array = new bool[num_bits]{};
    for (int i = num_bits - 1; i >= 0; i--) {
        this->array[i] = (bool) new_value & 1;
        new_value >>= 1;
    }
}

BitArray::BitArray(const BitArray &b) {
    this->size = b.size;
    this->array = new bool[size];
    for (int i = 0; i < size; i++) {
        this->array[i] = b.array[i];
    }
}

void BitArray::swap(BitArray &b) {
    if (this->size != b.size) {
        std::cout << "Arrays must be same size";
        return;
    }
    int len = this->size;
    for (int i = 0; i < len; i++) {
        bool tmp = this->array[i];
        this->array[i] = b.array[i];
        b.array[i] = tmp;
    }
}

void BitArray::resize(int num_bits, bool value) {
    bool *t = new bool[num_bits];
    memset(t, 0, sizeof(int) * num_bits);

    std::copy(this->array, this->array + std::min(this->size, num_bits), t);

    this->array = t;
    delete[] t;
}

void BitArray::clear() {
    memset(this->array, 0, sizeof(bool) * this->size);
}

void BitArray::push_back(bool bit) {
    this->resize(this->size + 1, bit);
}

BitArray &BitArray::operator=(BitArray &&b) {
    delete[] this->array;

    this->size = b.size;
    this->array = b.array;
    delete[] b.array;
    b.size = 0;

    return *this;

}

BitArray &BitArray::operator&=(const BitArray &b) {
    if (this->size != b.size) {
        std::cout << "Arrays must be same size";
        return *this;
    }
    int len = this->size;
    for (int i = 0; i < len; i++) {
        this->array[i] &= b.array[i];
    }
    return *this;
}

BitArray &BitArray::operator|=(const BitArray &b) {
    if (this->size != b.size) {
        std::cout << "Arrays must be same size";
        return *this;
    }
    int len = this->size;
    for (int i = 0; i < len; i++) {
        this->array[i] |= b.array[i];
    }
    return *this;
}

BitArray &BitArray::operator^=(const BitArray &b) {
    if (this->size != b.size) {
        std::cout << "Arrays must be same size";
        return *this;
    }
    int len = this->size;
    for (int i = 0; i < len; i++) {
        this->array[i] = this->array[i] == true && b.array[i] == true ? true : false;
    }
    return *this;
}

BitArray &BitArray::operator<<=(int n) {
    int number = 0;
    int len = this->size;
    for (int i = 0; i < len; i++) {
        number = this->array[i] & 1;
        if (i != number - 1) {
            number <<= 1;
        }
    }
    number <<= n;
    for (int i = number - 1; i >= 0; i--) {
        this->array[i] = number & 1;
        number >>= 1;
    }
    return *this;
}

BitArray &BitArray::operator>>=(int n) {
    int number = 0;
    int len = this->size;
    for (int i = 0; i < len; i++) {
        number = this->array[i] & 1;
        if (i != number - 1) {
            number <<= 1;
        }
    }
    number >>= n;
    for (int i = number - 1; i >= 0; i--) {
        this->array[i] = number & 1;
        number >>= 1;
    }
    return *this;
}

BitArray BitArray::operator<<(int n) const {
    BitArray new_arr = BitArray(this->size);
    new_arr.array = this->array;
    new_arr <<= n;
    return new_arr;
}

BitArray BitArray::operator>>(int n) const {
    BitArray new_arr = BitArray(this->size);
    new_arr.array = this->array;
    new_arr >>= n;
    return new_arr;
}

BitArray &BitArray::set(int n) {
    this->array[n] = true;
}

BitArray &BitArray::set() {
    for (int i = 0; i < this->size; i++) {
        this->array[i] = true;
    }
}

BitArray &BitArray::reset(int n) {
    this->array[n] = false;
}

BitArray &BitArray::reset() {
    for (int i = 0; i < this->size; i++) {
        this->array[i] = false;
    }
}

bool BitArray::any() const {
    for (int i = 0; i < this->size; i++) {
        if (this->array[i] == true) {
            return true;
        }
    }
    return false;
}

bool BitArray::none() const {
    for (int i = 0; i < this->size; i++) {
        if (this->array[i] == true) {
            return false;
        }
    }
    return true;
}

int BitArray::count() const {
    int cnt = 0;
    for (int i = 0; i < this->size; i++) {
        if (this->array[i] == true) {
            cnt++;
        }
    }
    return cnt;
}

bool BitArray::operator[](int i) const {
    return this->array[i];
}

int BitArray::return_size() const {
    return this->size;
}

BitArray BitArray::operator~() const {
    int len = this->size / 2;
    for (int i = 0; i < len; i++) {
        int tmp = this->array[i];
        this->array[i] = this->array[this->size - i - 1];
        this->array[this->size - i - 1] = tmp;
    }
}

bool BitArray::empty() const {
    return (this->size == 0);
}

std::string BitArray::to_string() const {
    std::string str;
    for (int i = 0; i < this->size; i++) {
        this->array[i] == true ? str[i] = '1' : str[i] = '0';
    }
    return str;
}

bool operator==(const BitArray &a, const BitArray &b) {
    if (a.return_size() != b.return_size()) {
        std::cout << "Arrays must be same size";
        return false;
    }
    int len = a.return_size();
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const BitArray &a, const BitArray &b) {
    if (a.return_size() != b.return_size()) {
        std::cout << "Arrays must be same size";
        return false;
    }
    int len = a.return_size();
    for (int i = 0; i < len; i--) {
        if (a[i] == b[i]) {
            return false;
        }
    }
    return true;
}

BitArray operator&(const BitArray &b1, const BitArray &b2) {
    if (b1.return_size() != b2.return_size()) {
        std::cout << "Arrays must be same size";
        return b1;
    }
    BitArray new_arr = BitArray(b1.return_size(), 0);
    new_arr = b1 & b2;
    return new_arr;
}

BitArray operator|(const BitArray &b1, const BitArray &b2){
    if (b1.return_size() != b2.return_size()) {
        std::cout << "Arrays must be same size";
        return b1;
    }
    BitArray new_arr = BitArray(b1.return_size(), 0);
    new_arr = b1 | b2;
    return new_arr;
}

BitArray operator^(const BitArray &b1, const BitArray &b2){
    if (b1.return_size() != b2.return_size()) {
        std::cout << "Arrays must be same size";
        return b1;
    }
    BitArray new_arr = BitArray(b1.return_size(), 0);
    new_arr = b1 ^ b2;
    return new_arr;
}
