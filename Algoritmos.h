#pragma once
#include "Templates.h"
#include <cmath>


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
    requires Addable<typename C::value_type> && Divisible<typename C::value_type>
    double variance(const C& container){
        using T=typename C::value_type;
        T result{};
        size_t _=0;
        for(const auto& value:container){
            result=result+pow(value-core_numeric::mean(value:container),2);_++;
        }
        result=result/container.size()-1;
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
    
    template<Iterable C,typename Func>
    requires Addable<std::invoke_result_t<Func, typename C::value_type>>
    auto transform_reduce(const C& container, Func transformer) {
        using ResultType = std::invoke_result_t<Func, typename C::value_type>;
        ResultType result{};
        for (const auto& item:container){result=result+transformer(item);}
        return result;
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

    template<typename... Ts>
    requires (Addable<Ts>&&...) && (Divisible<Ts>&&...)
    double variance_variadic(Ts...xs){
    double mean=mean_variadic(xs...);
    double suma=(pow(static_cast<double>(xs)-m,2)+...);
    size_t n=sizeof...(xs);
    if(n<=1){return 0.0};
    return sum_sq_diff/(n - 1);
    }

    template<typename T, typename... Ts>
    requires (Comparable<T> && ... && Comparable<Ts>)
    auto max_variadic(T prim, Ts... rest){
        auto max = prim;
        ((rest > max ? max = rest : max), ...);
        return max;
    }
    
}