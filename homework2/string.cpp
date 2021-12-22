#include "../include/string.hpp"
#include "cstring"

BMSTU::string::string() {
    _str_ptr = nullptr;
    _size_str = 0;
}

BMSTU::string::string(size_t size)
        : _size_str(size) {
    _str_ptr = new char[_size_str];
}

BMSTU::string::string(const char *size) {
    _size_str = _strlen(size);
    _str_ptr = new char[_size_str];
    memcpy(_str_ptr, size, _size_str);
}

BMSTU::string::string(const BMSTU::string &other_string)
        : string(other_string._size_str) {
    memcpy(_str_ptr, other_string._str_ptr, _size_str);
}

BMSTU::string BMSTU::string::operator+(const BMSTU::string &other_string) {
    string str(_size_str + other_string._size_str);

    memcpy(str._str_ptr, _str_ptr, _size_str);
    memcpy(str._str_ptr + _size_str, other_string._str_ptr, other_string._size_str);

    return str;
}

BMSTU::string &BMSTU::string::operator=(const BMSTU::string &other_string) {
    if (this == &other_string) return *this;

    delete[] _str_ptr;
    _size_str = other_string._size_str;
    _str_ptr = new char[other_string._size_str];

    memcpy(_str_ptr, other_string._str_ptr, _size_str);
    return *this;
}

BMSTU::string &BMSTU::string::operator=(const char *other_c_str) {
    _size_str = _strlen(other_c_str);
    delete[] _str_ptr;

    if (_size_str == 0) {
        _str_ptr = nullptr;
        return *this;
    }
    _str_ptr = new char[_size_str];

    memcpy(_str_ptr, other_c_str, _size_str);
    return *this;
}

std::ostream &BMSTU::operator<<(std::ostream &out, const BMSTU::string &item) {
    out.write(item._str_ptr, item._size_str);

    return out;
}

BMSTU::string::~string() {
    delete[] _str_ptr;
}

const char *BMSTU::string::c_str() const {
    return _str_ptr;
}

char *BMSTU::string::data() {
    return _str_ptr;
}

const size_t BMSTU::string::size() const {
    return _size_str;
}

void BMSTU::swap(BMSTU::string &first, BMSTU::string &second) {
    auto tmp_str_ptr = first._str_ptr;
    auto tmp_size_str = first._size_str;

    first._size_str = second._size_str;
    first._str_ptr = second._str_ptr;
    second._size_str = tmp_size_str;
    second._str_ptr = tmp_str_ptr;
}

void BMSTU::string::_fill(char *str, size_t size, char value) {
    memset(str, value, size);
}

size_t BMSTU::string::_strlen(const char *str) {
    if (str == nullptr) return 0;

    size_t pos = 0;
    while(str[pos]) ++pos;

    return pos;
}