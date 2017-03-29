#ifndef ARITHMETIC_CONCEPT_HPP_INCLUDED
#define ARITHMETIC_CONCEPT_HPP_INCLUDED
#include <experimental/ranges/concepts>

namespace extended_concepts {
template <ranges::Regular T>
   // axiom(T a, T b, T c, T d) {
   //    a + b == b + a;
   //    a - a == 0;
   //    a + a == 2 * a;
   //    a - b == -(b - a);
   //    a * (b + c) == b * (a + c); 
   //    a * c == b * d && a / b == c / d;
   //    (a * c == b * d) => (a / b == c / d);
   //    (a == b)         => !(a != b);
   //    (a < b)          => (b > a) && !(a > b);
   //    (a <= b)         => (a < b || a == b);
   //    (a >= b)         => (a > b || a == b);
   //    (a = a + b) == (a += b);
   //    (a = a - b) == (a -= b);
   //    (a = a * b) == (a *= b);
   //    (a = a / b) == (a /= b);
   //    (a += 1) == ++a;        // hopefully not undefined behaviour
   //    (a -= 1) == --a;        // hopefully not undefined behaviour
   //    a == a++;               // hopefully not undefined behaviour
   //    a == a--;               // hopefully not undefined behaviour
   // }
concept bool Arithmetic() {
   return ranges::StrictTotallyOrdered<T>() &&
          ranges::Incrementable<T>() &&
          ranges::Assignable<T, T>() &&
          requires(T t) {
      {t + t}   -> T;
      {t - t}   -> T;
      {t * t}   -> T;
      {t / t}   -> T;
      {t += t}  -> ranges::Same<T&>;
      {t -= t}  -> ranges::Same<T&>;
      {t *= t}  -> ranges::Same<T&>;
      {t /= t}  -> ranges::Same<T&>;
      {&t}      -> ranges::Same<T*>;
   };
}

template <Arithmetic T, Arithmetic U>
   // axiom(T a, U b, T c, U d) {
   //    a + b == b + a;
   //    a - b == -(b - a);
   //    a * (b + c) == b * (a + c);
   //    a * (b + d) == b * (a + d);
   //    (a * c == b * d) => (a / b == c / d);
   //    (a == b)         => !(a != b);
   //    (a < b)          => (b > a) && !(a > b);
   //    (a <= b)         => (a < b || a == b);
   //    (a >= b)         => (a > b || a == b);
   //    (a = a + b) == (a += b);
   //    (a = a - b) == (a -= b);
   //    (a = a * b) == (a *= b);
   //    (a = a / b) == (a /= b);
   // }
concept bool Arithmetic() {
   return ranges::Common<T, U>() &&
          ranges::StrictTotallyOrdered<T, U>() &&
          ranges::Assignable<T, U>() &&
          requires(T t, U u) {
      {t + u}  -> std::common_type_t<T, U>;
      {t - u}  -> std::common_type_t<T, U>;
      {t * u}  -> std::common_type_t<T, U>;
      {t / u}  -> std::common_type_t<T, U>;
      {t += u} -> ranges::Same<T&>;
      {t -= u} -> ranges::Same<T&>;
      {t *= u} -> ranges::Same<T&>;
      {t /= u} -> ranges::Same<T&>;
      {static_cast<T>(u)}  -> T;
      {static_cast<T&>(u)} -> Same<T&>;
   };
}
} // namespace extended_concepts
#endif // ARITHMETIC_CONCEPT_HPP_INCLUDED