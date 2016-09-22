#include <algorithm>
#include <cstdint>
#include <iostream>
#include <experimental/ranges/iterator>
#include <vector>

namespace ranges = std::experimental::ranges::v1;

template <typename T>
   requires ranges::ForwardIterator<T>()
std::vector<double> make_vector(T first, const T last)
{
   auto v = std::vector<double>{};
   while (first != last)
      v.push_back(*first++);
   return v;
}

std::vector<double> make_vector(const std::size_t size, const double magnitude)
{
   return std::vector<double>(size, magnitude);
}

int main()
{
   auto v = make_vector(10, 20);
   std::copy(v.cbegin(), v.cend(), std::ostream_iterator<decltype(v)::value_type>{std::cout, " "});
   std::cout << '\n';
}