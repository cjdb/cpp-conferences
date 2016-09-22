#include <experimental/ranges/concepts>
#include <iostream>
#include <memory>
#include <mutex>
#include <sstream>
#include <random>

namespace ranges = std::experimental::ranges::v1;

template <ranges::DefaultConstructible T>
concept bool Unique = ranges::Movable<T>() && not ranges::Copyable<T>();

std::mutex factory() { return {}; }

int main()
{
   Unique foo = std::make_unique<int>(5); // expects: compiles
   Unique bar{std::ostringstream{}};      // expects: compiles
   bar << *foo; // to shut up -Wall
   std::cout << bar.str() << '\n';

   // compile the lines below with
   //    g++ -Wall -Wextra -pedantic -Werror -fconcepts -std=c++1z -o unique unique.cpp 2>&1 | grep 'Unique' 
   //Unique fizz = std::random_device{};    // expects: doesn't compile
   //Unique buzz{std::mutex{}};             // expects: doesn't compile
}