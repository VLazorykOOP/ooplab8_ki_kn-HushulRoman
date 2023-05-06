#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
std::vector<T> mergeArrays(const T* arr1, const size_t size1, const T* arr2, const size_t size2) {
    std::vector<T> mergedArr(size1 + size2);

    std::copy(arr1, arr1 + size1, mergedArr.begin());
    std::copy(arr2, arr2 + size2, mergedArr.begin() + size1);

    std::sort(mergedArr.begin(), mergedArr.end());
    auto it = std::unique(mergedArr.begin(), mergedArr.end());
    mergedArr.resize(std::distance(mergedArr.begin(), it));

    return mergedArr;
}

// Спеціалізація для типу char*
template<>
std::vector<const char*> mergeArrays<const char*>(const char* const* arr1, const size_t size1, const char* const* arr2, const size_t size2) {
    std::vector<const char*> mergedArr(size1 + size2);

    std::copy(arr1, arr1 + size1, mergedArr.begin());
    std::copy(arr2, arr2 + size2, mergedArr.begin() + size1);

    std::sort(mergedArr.begin(), mergedArr.end());
    auto it = std::unique(mergedArr.begin(), mergedArr.end());
    mergedArr.resize(std::distance(mergedArr.begin(), it));

    return mergedArr;
}

// Точка входу в програму.
int main(int argc, char* argv[])
{
    int arr1[] = { 1, 2, 3, 4, 5 };
    int arr2[] = { 4, 5, 6, 7, 8 };
    auto mergedIntArr = mergeArrays(arr1, 5, arr2, 5);
    for (const auto& elem : mergedIntArr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    const char* strArr1[] = { "Hello", "world" };
    const char* strArr2[] = { "world", "from", "Ukraine" };
    auto mergedStrArr = mergeArrays(strArr1, 2, strArr2, 3);
    for (const auto& elem : mergedStrArr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
