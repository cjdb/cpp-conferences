#include <algorithm>
#include <forward_list>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
   auto victor = std::vector<int>{1, 2, 3, 4, 5};
   auto frodo = std::forward_list<int>{6, 7, 8, 9, 10};
   auto end = std::copy(victor.cbegin(), victor.cend(), frodo.begin()); // end is RandomAccessIterator
   std::sort(frodo.begin(), end);
   std::copy(frodo.begin(), end, std::ostream_iterator<decltype(frodo)::value_type>{std::cout, "\n"});
}