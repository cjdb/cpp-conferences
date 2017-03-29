#include <algorithm>
#include <iterator>
#include <iostream>
#include <type_traits>
#include <vector>

template <typename InputIterator, std::enable_if_t<
      std::is_same<typename InputIterator::iterator_tag_t,
         typename InputIterator::iterator_tag_t>::value,
      int> = 0>
std::vector<double> make_vector(InputIterator first, InputIterator last)
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
   auto v = make_vector(10, 1);
   copy(v.begin(), v.end(), std::ostream_iterator<decltype(v)::value_type>{std::cout, " "});
   std::cout << '\n';
}
