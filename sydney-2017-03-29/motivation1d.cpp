#include <algorithm>
#include <iterator>
#include <iostream>
#include <type_traits>
#include <vector>

template <typename InputIterator, std::enable_if_t<
      std::is_base_of<std::input_iterator_tag,
         typename std::iterator_traits<InputIterator>::iterator_category>::value,
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
   auto v1 = make_vector(10, 1);
   copy(v1.begin(), v1.end(), std::ostream_iterator<decltype(v1)::value_type>{std::cout, " "});
   std::cout << '\n';

   auto v2 = make_vector(v1.cbegin(), v1.cend());
   copy(v2.cbegin(), v2.cend(), std::ostream_iterator<decltype(v2)::value_type>{std::cout, " "});
   std::cout << '\n';
}
