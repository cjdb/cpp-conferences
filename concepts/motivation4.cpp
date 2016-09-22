#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

std::vector<int> make_crowd(const int children, const int adults, const int seniors)
{
   auto crowd = std::vector<int>{};

   // random number generator in C++... much better than what you're used to!
   namespace chrono = std::chrono;
   auto generator = std::mt19937(chrono::system_clock::now().time_since_epoch().count());
   auto distribute = std::uniform_int_distribution<>{0, 17};

   for (auto i = 0; i < children; ++i)
      crowd.push_back(distribute(generator));

   distribute = std::uniform_int_distribution<>{18, 64};
   for (auto i = 0; i < adults; ++i)
      crowd.push_back(distribute(generator));

   distribute = std::uniform_int_distribution<>{65, 128};
   for (auto i = 0; i < seniors; ++i)
      crowd.push_back(distribute(generator));

   return crowd;
}

int main()
{
   auto a = make_crowd(5, 2, 100);
   std::sort(a.begin(), a.end());

   auto b = make_crowd(100, 2, 5);
   std::sort(b.begin(), b.end());

   // get the container that has the extremes
   auto youngest = a.front() < b.front() ? a.cbegin() : b.cbegin();
   auto oldest = a.back() > b.back() ? a.crbegin().base() : b.crbegin().base(); // tutor note: base converts a reverse_iterator to an iterator
   std::copy(youngest, oldest, std::ostream_iterator<decltype(youngest)::value_type>{std::cout, "\n"});
}