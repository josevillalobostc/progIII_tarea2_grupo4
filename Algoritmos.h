#pragma once
#include "Templates.h"



namespace core_numeric{
    template<Iterable C>
    requires Addable<typename C::value_type>
    double mean(const C& container){
        using T = typename C::value_type;
        T result{};
        
        size_t i = 0;
        for (const auto& value : container)
        {
            result = result + value;
            i++;
        }
        
        return result / i;
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
    requires requires(Ts... xs) { (... + xs);}
    auto sum_variadic(Ts... xs){
        return (xs + ...);
    }
    
    template<typename... Ts>
    requires requires(Ts... xs) { (... + xs);}
    double mean_variadic(Ts... xs){
        auto suma = (xs + ...);
        return suma / sizeof...(xs);
    }
    
    
}