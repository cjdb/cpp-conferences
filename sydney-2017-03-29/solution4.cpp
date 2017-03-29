#include <experimental/ranges/algorithm>
#include <experimental/ranges/iterator>
#include <chrono>
#include <iostream>
#include "make_crowd.hpp"
#include <random>
#include <vector>

int main()
{
   using Container = std::vector<int>;

   auto a = make_crowd<Container>(100, 2, 5);
   ranges::sort(a);

   auto b = make_crowd<Container>(5, 2, 100);
   ranges::sort(b);

   // get the container that has the extremes
   auto youngest = a.front() < b.front();
   auto oldest = a.back() > b.back();

   if (youngest && oldest)
      ranges::copy(a, ranges::ostream_iterator<decltype(a)::value_type>{std::cout, "\n"});
   else if (not (youngest || oldest))
      ranges::copy(b, ranges::ostream_iterator<decltype(b)::value_type>{std::cout, "\n"});
   else
      std::cout << "ranges overlap\n";
}
