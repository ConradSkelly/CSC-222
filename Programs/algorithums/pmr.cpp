#include <functional>
#include <iostream>
#include <memory_resource>
#include <ostream>

int main(){
  std::byte buffer[1024];

  std::pmr::monotonic_buffer_resource pool(buffer, sizeof(buffer));

  std::pmr::vector<int> numbers(&pool);

  numbers.push_back(10);
  numbers.push_back(20);
  numbers.push_back(30);

  for (int num : numbers) {
    std::cout << num << std::endl;
  }
}
