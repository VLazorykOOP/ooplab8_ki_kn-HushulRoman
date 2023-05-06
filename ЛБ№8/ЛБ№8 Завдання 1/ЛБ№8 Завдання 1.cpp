#include <algorithm> // for std::remove()
#include <cstring>   // for std::strcmp()
#include <iostream>

template <typename T>
void remove_min(T* array, size_t size) {
    // знаходимо мінімальне значення в масиві
    T min_val = *std::min_element(array, array + size);

    // вилучаємо всі мінімальні значення
    T* new_end = std::remove(array, array + size, min_val);

    // виводимо новий масив без мінімальних значень
    std::cout << "New array without minimum values: ";
    for (T* p = array; p != new_end; ++p) {
        std::cout << *p << " ";
    }
    std::cout << std::endl;
}

template <>
void remove_min<char*>(char** array, size_t size) {
    // знаходимо мінімальне значення в масиві за допомогою std::strcmp()
    char* min_val = *std::min_element(array, array + size,
        [](const char* a, const char* b) {
            return std::strcmp(a, b) < 0;
        });

    // вилучаємо всі мінімальні значення
    char** new_end = std::remove(array, array + size, min_val);

    // виводимо новий масив без мінімальних значень
    std::cout << "New array without minimum values: ";
    for (char** p = array; p != new_end; ++p) {
        std::cout << *p << " ";
    }
    std::cout << std::endl;
}

// Точка входу в програму.
int main(int argc, char* argv[])
{
    // приклад виклику для типу int
    int int_array[] = { 5, 3, 1, 2, 1, 4 };
    size_t int_size = sizeof(int_array) / sizeof(int);

    std::cout << "Original int array: ";
    for (size_t i = 0; i < int_size; ++i) {
        std::cout << int_array[i] << " ";
    }
    std::cout << std::endl;

    remove_min(int_array, int_size);


    // приклад виклику для типу char*
    char* char_array[] = { (char*)"apple", (char*)"banana", (char*)"orange", (char*)"grape", (char*)"banana" };
    size_t char_size = sizeof(char_array) / sizeof(char*);

    std::cout << "Original char* array: ";
    for (size_t i = 0; i < char_size; ++i) {
        std::cout << char_array[i] << " ";
    }
    std::cout << std::endl;

    remove_min(char_array, char_size);

    return 0;
}
