#include <iostream>
#include <memory>

template <typename T>
std::unique_ptr<T> make_unique(T&& t)
{
   return std::make_unique<T>(std::forward<T>(t));
}

int main()
{
   auto p = make_unique(10);
   auto q = make_unique(p);
   //std::cout << *q << '\n';
}