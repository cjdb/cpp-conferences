#include <algorithm>
#include <iterator>
#include <iostream>
#include <forward_list>
#include "make_crowd.hpp"
#include <vector>

int main()
{
   using Container = std::forward_list<int>;
   auto c = make_crowd<Container>(5, 5, 5);

   auto first = find_if(c.begin(), c.end(), [](const auto& i) { return i >= young_adult; });
   auto last = find_if(first, c.end(), [](const auto& i) { return i > almost_senior; });

   print_crowd(first, last);
   reverse(first, last);
   print_crowd(first, last);
}
