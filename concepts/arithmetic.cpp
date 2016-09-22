#include "arithmetic_concept.hpp"
#include <cstdint>
#include <iostream>
#include <type_traits>

class Big_int {
public:
   explicit Big_int(std::uint64_t low = 0U, std::int64_t high = 0U) noexcept;

   Big_int& operator+=(const Big_int&) noexcept;
   Big_int& operator-=(const Big_int&) noexcept;
   Big_int& operator*=(const Big_int&) noexcept;
   Big_int& operator/=(const Big_int&) noexcept;
   Big_int& operator%=(const Big_int&) noexcept;

   Big_int operator+(Big_int) const noexcept;
   Big_int operator-(Big_int) const noexcept;
   Big_int operator*(Big_int) const noexcept;
   Big_int operator/(Big_int) const noexcept;

   bool operator<(const Big_int&) const noexcept;
   bool operator<=(const Big_int&) const noexcept;
   bool operator==(const Big_int&) const noexcept;
   bool operator!=(const Big_int&) const noexcept;
   bool operator>=(const Big_int&) const noexcept;
   bool operator>(const Big_int&) const noexcept;

   Big_int& operator++() noexcept;
   Big_int operator++(int) noexcept;
   Big_int& operator--() noexcept;
   Big_int operator--(int) noexcept;

   friend std::ostream& operator<<(std::ostream&, const Big_int&);
private:
   std::int64_t high_;
   std::uint64_t low_;
};

std::ostream& operator<<(std::ostream&, const Big_int&);

template <Arithmetic T, Arithmetic U>
   requires Arithmetic<U, T>()
Arithmetic compute(T a, U b)
{
   return a + b;
}

int main()
{
   std::cout << compute(Big_int{1}, 1.0) << '\n';
}