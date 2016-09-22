#ifndef ARITHMETIC_CONCEPT_HPP_INCLUDED
#define ARITHMETIC_CONCEPT_HPP_INCLUDED
#include <experimental/ranges/concepts>
#include <type_traits>

template <std::experimental::ranges::v1::Regular T>
concept bool Arithmetic() {
   return std::experimental::ranges::v1::StrictTotallyOrdered<T>() &&
          requires(T a, T b) {
      {a + b}   -> T;
      {a - b}   -> T;
      {a * b}   -> T;
      {a / b}   -> T;
      {a++}     -> T;
      {a = b}   -> T&;
      {a += b}  -> T&;
      {a -= b}  -> T&;
      {a *= b}  -> T&;
      {a /= b}  -> T&;
      {++a}     -> T&;
      {&a}      -> T*;
   };
}

//#endif // ARITHMETIC_CONCEPT_HPP_INCLUDED













template <Arithmetic T, Arithmetic U>
concept bool Arithmetic() {
   return std::experimental::ranges::Common<T, U>() &&
          std::experimental::ranges::StrictTotallyOrdered<T, U>() &&
          requires(T a, U b) {
      {a + b}  -> std::common_type_t<T, U>;
      {a - b}  -> std::common_type_t<T, U>;
      {a * b}  -> std::common_type_t<T, U>;
      {a / b}  -> std::common_type_t<T, U>;
      {a = b}  -> T&;
      {a += b} -> T&;
      {a -= b} -> T&;
      {a *= b} -> T&;
      {a /= b} -> T&;
      {static_cast<T>(b)}  -> T;
   };
}
#endif // ARITHMETIC_CONCEPT_HPP_INCLUDED
