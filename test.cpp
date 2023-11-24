#include <iostream>
#include "BitArray/BitArray.h"
#include "gtest/gtest.h"

TEST(BitArrayTest, BitArraySize) {
    BitArray a(4, 2);
    int res = a.return_size();
    ASSERT_EQ(4, res);
}

TEST(BitArrayTest, BitArrayToString) {
    BitArray a(10, 15);
    std::string res = a.to_string();
    ASSERT_EQ("0000001111", res);
}

TEST(BitArrayTest, BitArrayCreate) {
    BitArray a(5);
    int size = a.return_size();
    std::string code = a.to_string();
    ASSERT_EQ(5, size);
    ASSERT_EQ("00000", code);
}

TEST(BitArrayTest, BitArrayCopy) {
    BitArray a(3, 2);
    BitArray c = a;
    std::string code_a = a.to_string();
    std::string code_c = c.to_string();
    ASSERT_EQ(code_a, code_c);
}

TEST(BitArrayTest, BitArraySwap) {
    BitArray a(3, 2);
    BitArray b(4, 4);
    a.swap(b);
    int size = a.return_size();
    std::string code = a.to_string();
    ASSERT_EQ(4, size);
    ASSERT_EQ("0100", code);
}

// operator =
TEST(BitArrayTest, BitArrayOp) {
    BitArray a(4, 2);
    BitArray c(2, 1);
    a = c;
    int size = a.return_size();
    std::string code = a.to_string();
    ASSERT_EQ(2, size);
    ASSERT_EQ("01", code);
}

TEST(BitArrayTest, BitArrayResize) {
    BitArray a(5, 5);
    a.resize(10);
    int size = a.return_size();
    std::string code = a.to_string();
    ASSERT_EQ(10, size);
    ASSERT_EQ("0010100000", code);
}

TEST(BitArrayTest, BitArrayClear) {
    BitArray a(3, 6);
    a.clear();
    std::string code = a.to_string();
    ASSERT_EQ("000", code);
}

TEST(BitArrayTest, BitArrayPushBack) {
    BitArray a(3);
    a.push_back(true);
    std::string code = a.to_string();
    ASSERT_EQ("0001", code);
}

// operator &=           test 1
TEST(BitArrayTest, BitArrayOp1) {
    BitArray a(5, 5);
    BitArray b(5, 4);
    a &= b;
    std::string code = a.to_string();
    ASSERT_EQ("00100", code);
}

// operator &=           test 2
TEST(BitArrayTest, BitArrayOp2) {
    BitArray a(5, 5);
    BitArray b(3, 4);
    a &= b;
    std::string code = a.to_string();
    ASSERT_EQ("00101", code);
}

// operator |=           test 1
TEST(BitArrayTest, BitArrayOp3) {
    BitArray a(5, 5);
    BitArray b(5, 4);
    a |= b;
    std::string code = a.to_string();
    ASSERT_EQ("00101", code);
}

// operator |=           test 2
TEST(BitArrayTest, BitArrayOp4) {
    BitArray a(6, 5);
    BitArray b(3, 4);
    a |= b;
    std::string code = a.to_string();
    ASSERT_EQ("000101", code);
}

// operator ^=           test 1
TEST(BitArrayTest, BitArrayOp5) {
    BitArray a(5, 5);
    BitArray b(5, 4);
    a ^= b;
    std::string code = a.to_string();
    ASSERT_EQ("00001", code);
}

// operator ^=           test 2
TEST(BitArrayTest, BitArrayOp6) {
    BitArray a(6, 5);
    BitArray b(3, 4);
    a ^= b;
    std::string code = a.to_string();
    ASSERT_EQ("000101", code);
}

// operator >>=
TEST(BitArrayTest, BitArrayOp7) {
    BitArray a(6, 16);
    a >>= 3;
    std::string code = a.to_string();
    ASSERT_EQ("000010", code);
}

// operator <<=
TEST(BitArrayTest, BitArrayOp8) {
    BitArray a(6, 2);
    a <<= 2;
    std::string code = a.to_string();
    ASSERT_EQ("001000", code);
}

// operator <<
TEST(BitArrayTest, BitArratOp9) {
    BitArray a(6, 8);
    BitArray c = a << 1;
    std::string code = c.to_string();
    ASSERT_EQ("010000", code);
}

// operator >>
TEST(BitArrayTest, BitArratOp10) {
    BitArray a(6, 8);
    BitArray c = a >> 1;
    std::string code = c.to_string();
    ASSERT_EQ("000100", code);
}

TEST(BitArrayTest, BitArraySet) {
    BitArray a(3, 5);
    a.set(1);
    std::string code = a.to_string();
    ASSERT_EQ("111", code);
}

// set that fills all mass with true
TEST(BitArrayTest, BitArraySetTrue) {
    BitArray a(3);
    a.set();
    std::string code = a.to_string();
    ASSERT_EQ("111", code);
}

TEST(BitArrayTest, BitArrayReset) {
    BitArray a(3, 4);
    a.reset(0);
    std::string code = a.to_string();
    ASSERT_EQ("000", code);
}

// reset that fills all mass with false
TEST(BitArrayTest, BitArrayResetFalse) {
    BitArray a(3, 7);
    a.reset();
    std::string code = a.to_string();
    ASSERT_EQ("000", code);
}

TEST(BitArrayTest, BitArrayAny) {
    BitArray a(3, 4);
    bool res = a.any();
    ASSERT_EQ(true, res);
}

TEST(BitArrayTest, BitArrayNone) {
    BitArray a(3, 4);
    bool res = a.none();
    ASSERT_EQ(false, res);
}

TEST(BitArrayTest, BitArrayInverse) {
    BitArray a(3, 5);
    ~a;
    std::string code = a.to_string();
    ASSERT_EQ("010", code);
}

TEST(BitArrayTest, BitArrayCount) {
    BitArray a(5, 7);
    int res = a.count();
    ASSERT_EQ(3, res);
}

// operator []
TEST(BitArrayTest, BitArratOp11) {
    BitArray a(4, 2);
    bool res = a[2];
    ASSERT_EQ(true, res);
}

TEST(BitArrayTest, BitArrayEmpty) {
    BitArray a(4);
    bool res = a.empty();
    ASSERT_EQ(true, res);
}

// operator ==
TEST(BitArrayTest, BitArrayOp12) {
    BitArray a(3, 2);
    BitArray b(4, 2);
    bool res = a == b;
    ASSERT_EQ(false, res);
}

// operator !=
TEST(BitArrayTest, BitArrayOp13) {
    BitArray a(3, 2);
    BitArray b(4, 2);
    bool res = a != b;
    ASSERT_EQ(true, res);
}

// operator & between two arrays
TEST(BitArrayTest, BitArrayOp14) {
    BitArray a(5);
    BitArray b(3, 7);
    BitArray c = a & b;
    std::string code = c.to_string();
    ASSERT_EQ("00000", code);
}

// operator | between two arrays
TEST(BitArrayTest, BitArrayOp15) {
    BitArray a(5);
    BitArray b(3, 7);
    BitArray c = a | b;
    std::string code = c.to_string();
    ASSERT_EQ("00111", code);
}

// operator ^ between two arrays
TEST(BitArrayTest, BitArrayOp16) {
    BitArray a(5, 5);
    BitArray b(3, 7);
    std::cout<<a.to_string() << "\n" << b.to_string();
    /*BitArray c = a ^ b;
    std::string code = c.to_string();
    ASSERT_EQ("00010", code);*/
}