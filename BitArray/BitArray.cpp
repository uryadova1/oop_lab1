//
// Created by tyzzko on 19.10.2023.
//

#include "BitArray.h"
#include <iostream>
#include <string.h>
#include <cmath>

BitArray::BitArray() {
    this->array = new bool[0]{};
    this->size = 0;
}

BitArray::~BitArray() {
    delete[] this->array;
}


BitArray::BitArray(int num_bits, unsigned long value) {
    int len = 0;
    unsigned long check_len_value = value;

    while (check_len_value) {
        check_len_value >>= 1;
        len++;
    }
    if (num_bits < len) {
        std::cout << "The length of the array is less than the length of the bit representation of the number";
        std::exit(1);

    }
    this->size = num_bits;
    this->array = new bool[num_bits]{};
    for (int i = 0; i < num_bits; i++) {
        bool k = (value & (1UL << i)) != 0;
        this->array[num_bits - i - 1] = k;
    }
}

BitArray::BitArray(const BitArray &b) {
    this->size = b.size;
    this->array = new bool[b.size];
    for (int i = 0; i < size; i++) {
        this->array[i] = b.array[i];
    }
}

void BitArray::swap(BitArray &b) {
    std::swap(this->size, b.size);
    std::swap(this->array, b.array);
}

void BitArray::resize(int num_bits, bool value) {
    bool *newBits = new bool[size + num_bits];

    if (num_bits > size) {
        for (int i = 0; i < size; i++) {
            newBits[i] = this->array[i];
        }

        for (int i = size; i < size + (num_bits - size); i++) {
            newBits[i] = value;
        }

        delete[] this->array;

        this->array = newBits;
        this->size += (num_bits - size);
    } else {
        for (int i = 0; i < num_bits; i++) {
            newBits[i] = this->array[i];
        }

        delete[] this->array;

        this->array = newBits;
        this->size = num_bits;
    }
    /*bool *t = new bool[num_bits];
    memset(t, 0, sizeof(int) * num_bits);

    std::copy(this->array, this->array + std::min(this->size, num_bits), t);

    this->array = t;
    delete[] t;*/
}

void BitArray::clear() {
    memset(this->array, 0, sizeof(bool) * this->size);
}

void BitArray::push_back(bool bit) {
    this->resize(this->size + 1, bit);
}

BitArray &BitArray::operator=(BitArray &b) {
    delete[] this->array;
    this->array = new bool[b.size];
    this->size = b.size;
    for (int i = 0; i <= b.size; i++) {
        this->array[i] = b.array[i];
    }
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
        this->array[i] ^= b.array[i];
    }
    return *this;
}

BitArray &BitArray::operator<<=(int n) {
    bool *newBits = new bool[size - n];

    if (n <= 0) {
        return *this;
    }

    for (int i = 0; i < size; i++) {
        newBits[i] = false;
    }

    for (int i = n; i < size; i++) {
        newBits[i - n] = this->array[i];
    }
    delete[] this->array;
    this->array = newBits;

    return *this;
}

BitArray &BitArray::operator>>=(int n) {
    bool *newBits = new bool[size + n];

    if (n <= 0) {
        return *this;
    }

    for (int i = 0; i < n; i++) {
        newBits[i] = false;
    }

    for (int i = 0; i < this->size; i++) {
        newBits[i + n] = this->array[i];
    }

    delete[] this->array;
    this->array = newBits;

    return *this;
}

BitArray BitArray::operator<<(int n) const {
    BitArray new_arr = BitArray(this->size);

    for (int i = 0; i < this->size; i++) {
        if (i + n >= this->size) {
            new_arr.array[i] = false;
        } else {
            new_arr.array[i] = this->array[i + n];
        }
    }
    return new_arr;
}

BitArray BitArray::operator>>(int n) const {
    BitArray new_arr = BitArray(this->size);

    for (int i = 0; i < this->size; i++) {
        if (i + n >= this->size) {
            new_arr.array[i] = false;
        } else {
            new_arr.array[i + n] = this->array[i];
        }
    }
    return new_arr;
}

BitArray &BitArray::set(int n) {
    this->array[n] = true;
    return *this;
}

BitArray &BitArray::set() {
    for (int i = 0; i < this->size; i++) {
        this->array[i] = true;
    }
    return *this;
}

BitArray &BitArray::reset(int n) {
    this->array[n] = false;
    return *this;
}

BitArray &BitArray::reset() {
    for (int i = 0; i < this->size; i++) {
        this->array[i] = false;
    }
    return *this;
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
    for (int i = 0; i < this->size; i++) {
        if (this->array[i]) {
            this->array[i] = false;
        } else {
            this->array[i] = true;
        }
    }
    return *this;
}

bool BitArray::empty() const {
    if (this->size == 0) {
        return true;
    }
    for (int i = 0; i < this->size; i++) {
        if (this->array[i]) {
            return false;
        }
    }
    return true;
}

std::string BitArray::to_string() const {
    std::string str;
    for (int i = 0; i < this->size; i++) {
        if (this->array[i]) {
            str += '1';
        } else {
            str += '0';
        }
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
        return true;
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
    int size = std::max(b1.return_size(), b2.return_size());
    int min_size = std::min(b1.return_size(), b2.return_size());

    unsigned long newValue = 0;
    bool *arr = new bool[size];

    for (int i = 0; i < min_size; i++) {
        if (b1.return_size() == b2.return_size()) {
            arr[i] = b1[i];
        } else if (b1.return_size() < b2.return_size()) {
            arr[i + (size - min_size)] = b1[i];
        } else {
            arr[i + (size - min_size)] = b2[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (b1.return_size() == b2.return_size()) {
            arr[i] &= b2[i];
        } else if (b1.return_size() < b2.return_size()) {
            arr[i] &= b2[i];
        } else {
            arr[i] &= b1[i];
        }
    }

    for (int i = 0; i < size; i++) {
        newValue += arr[i] * pow(2, size - i - 1);
    }

    BitArray NewArr(size, newValue);

    return NewArr;
}

BitArray operator|(const BitArray &b1, const BitArray &b2) {
    int size = std::max(b1.return_size(), b2.return_size());
    int min_size = std::min(b1.return_size(), b2.return_size());

    unsigned long newValue = 0;
    bool* mass = new bool[size];

    if (size == min_size){
        for (int i = 0; i < size; i++){
            mass[i] = b1[i] | b2[i];
        }
    }else{
        if (b1.return_size() > b2.return_size()){
            for (int i = 0; i < size; i++){
                mass[i] = b1[i];
            }
            int difference = size-min_size;
            for (int i = min_size; i >= 0; i--){
                mass[i+difference] |= b2[i];
            }
        }else{
            for (int i = 0; i < size; i++){
                mass[i] = b2[i];
            }
            int difference = size-min_size;
            for (int i = min_size; i >= 0; i--){
                mass[i+difference] |= b1[i];
            }
        }
    }
    for (int i = 0; i < size; i++) {
        newValue += mass[i] * pow(2, size - i - 1);
    }

    BitArray NewArr(size, newValue);

    return NewArr;
}

BitArray operator^(const BitArray &b1, const BitArray &b2) {
    int size = std::max(b1.return_size(), b2.return_size());
    int min_size = std::min(b1.return_size(), b2.return_size());

    unsigned long newValue = 0;
    bool *mass = new bool[size];

    for (int i = 0; i < min_size; i++) {
        if (b1.return_size() == b2.return_size()) {
            mass[i] = b1[i];
        } else if (b1.return_size() < b2.return_size()) {
            mass[i + (size - min_size)] = b1[i];
        } else {
            mass[i + (size - min_size)] = b2[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (b1.return_size() == b2.return_size()) {
            mass[i] ^= b2[i];
        } else if (b1.return_size() < b2.return_size()) {
            mass[i] ^= b2[i];
        } else {
            mass[i] ^= b1[i];
        }
    }

    for (int i = 0; i < size; i++) {
        newValue += mass[i] * pow(2, size - i - 1);
    }

    BitArray NewArr(size, newValue);

    return NewArr;
}
