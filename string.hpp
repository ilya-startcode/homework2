#ifndef EXAMPLE_STRING_HPP
#define EXAMPLE_STRING_HPP

#include "stdlib.h"
#include "iostream"

namespace BMSTU {
    class string {
    public:
// Конструктор по умолчанию
        string();
// Конструктор создающий строку длинной n символов
        string(size_t size);
// Конструктор принимающий C-style строку
        string(const char *c_str);
// Конструктор копирования
        string(const BMSTU::string &other_string);
// Оператор строковой конкатенации
        string operator+(const BMSTU::string &other_string);
// Оператор присваивания
        string &operator=(const BMSTU::string &other_string);
// Оператор присваивания
        string &operator=(const char *other_c_str);
// Оператор вывода в поток
        friend std::ostream &operator<<(std::ostream &out, const string &item);
// Деструктор
        ~string();
        const char *c_str() const;
        char *data();
        const size_t size() const;
        friend void swap(BMSTU::string &first, BMSTU::string &second);
    private:
        char *_str_ptr;
        size_t _size_str;
        void _fill(char *str, size_t size, char value);
        static size_t _strlen(const char *str);
    };
}

#endif //EXAMPLE_STRING_HPP
