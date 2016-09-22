#include <experimental/ranges/concepts>
#include <iostream>
#include <memory>

namespace ranges = std::experimental::ranges::v1;

template <ranges::Regular T>
std::unique_ptr<T> make_unique(T t)
{
   return std::make_unique<T>(t);
}

int main()
{
   auto p = make_unique(10);
   auto q = make_unique(p);
   std::cout << *q << '\n';
}