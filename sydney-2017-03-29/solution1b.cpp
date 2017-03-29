#include <experimental/ranges/algorithm>
#include <experimental/ranges/iterator>
#include <iostream>
#include <vector>

namespace ranges = std::experimental::ranges::v1;

template <typename I, typename S>
requires
   ranges::InputIterator<I>() &&
   ranges::Sentinel<I, S>()
std::vector<double> make_vector(I first, S last)
{
   auto v = std::vector<double>{};
   while (first != last)
      v.push_back(*first++);
   return v;
}

std::vector<double> make_vector(std::size_t size, double magnitude)
{
   return std::vector<double>(size, magnitude);
}

int main()
{
   auto v1 = make_vector(10, 1);
   ranges::copy(v1.begin(), v1.end(), ranges::ostream_iterator<decltype(v1)::value_type>{std::cout, " "});
   std::cout << '\n';

   auto v2 = make_vector(v1.cbegin(), v1.cend());
   ranges::copy(v2.cbegin(), v2.cend(), ranges::ostream_iterator<decltype(v2)::value_type>{std::cout, " "});
   std::cout << '\n';
}
