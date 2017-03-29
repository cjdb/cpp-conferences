#include <experimental/ranges/iterator>
#include <algorithm>
#include <forward_list>
#include <iostream>
#include <vector>

namespace ranges = std::experimental::ranges::v1;

int main()
{
   auto victor = std::vector<int>{1, 2, 3, 4, 5};
   auto frodo = std::forward_list<int>{6, 7, 8, 9, 10};
   ranges::RandomAccessIterator end = std::copy(victor.cbegin(), victor.cend(), frodo.begin());
   std::sort(frodo.begin(), end);
   std::copy(frodo.begin(), end, std::ostream_iterator<decltype(frodo)::value_type>{std::cout, "\n"});
}