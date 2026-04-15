#pragma once
#include "Templates.h"



namespace core_numeric{
    template<Iterable C>
    requires Addable<typename C::value_type> && Divisible<typename C::value_type>
    auto mean(const C& container){
        using T = typename C::value_type;
        T result{};
        
        size_t size = container.size();
        for (const auto& value : container)
        {
            result = result + value;    
        }
        
        return result / size;
    }
    
    template<Iterable C>
    requires Comparable<typename C::value_type>
    auto max(const C& container){
        using T = typename C::value_type;
        T max = *begin(container);
        size_t i = 0;
        for (const auto& value : container){
            if(i){
                if(value > max) max = value;
            }
            i++;
        }
        return max;
    }
    
    template<typename... Ts>
    requires (Addable<Ts> && ...)
    auto sum_variadic(Ts... xs){
        return (xs + ...);
    }
    
    template<typename... Ts>
    requires (Addable<Ts> && ...)
    double mean_variadic(Ts... xs){
        auto suma = (xs + ...);
        return suma / sizeof...(xs);
    }
    
    template<typename T, typename... Ts>
    requires (Comparable<T> && ... && Comparable<Ts>)
    auto max_variadic(T prim, Ts... rest){
        auto max = prim;
        ((rest > max ? max = rest : max), ...);
        return max;
    }
    
}