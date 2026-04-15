#pragma once
#include <concepts>
#include <iterator>

template <typename T>
concept Addable = requires(T a, T b) {
    //{a + b} -> std::same_as<T>;
    {a + b};
};

template <typename T>
concept Divisible = requires(T a, size_t b) {
    //{a / b} -> std::same_as<T>;
    {a / b};
};

template <typename T>
concept Iterable = requires(T a){
    std::begin(a);
    std::end(a);
};

template <typename T>
concept Comparable = requires(T a, T b){
    {a > b} -> std::same_as<T>;  
};