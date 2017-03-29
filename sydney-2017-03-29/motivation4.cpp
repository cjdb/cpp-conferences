#include <algorithm>
#include "make_crowd.hpp"
#include <iostream>
#include <iterator>

int main()
{
   using Container = std::vector<int>;

   auto a = make_crowd<Container>(5, 2, 100);
   sort(a.begin(), a.end());

   auto b = make_crowd<Container>(100, 2, 5);
   sort(b.begin(), b.end());

   // get the container that has the extremes
   auto youngest = a.front() < b.front() ? a.cbegin() : b.cbegin();
   auto oldest = a.back() > b.back() ? a.crbegin().base() : b.crbegin().base();

   copy(youngest, oldest,
      std::ostream_iterator<decltype(youngest)::value_type>{std::cout, "\n"});
}