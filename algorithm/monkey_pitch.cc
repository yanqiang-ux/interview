#include <iostream>
#include <vector>

//recursive 
uint64_t pick_methods(uint32_t num) {
  if (num == 0) {
    return 0;
  }
  if (num == 1) {
    return 1;
  }
  return pick_methods(num-1) + pick_methods(num-2);
}

//dp
uint64_t dp_pick_methods(uint32_t num) {
  std::vector<uint64_t> recorder;
  recorder.resize(num);
  recorder[0] = 0;
  recorder[1] = 1;
  for (uint32_t i = 2; i <= num; i++) {
    recorder[i] = recorder[i-1] + recorder[i-2];
  }
  return recorder[num];
}

int main() {
  int n = 20;
  std::cout << pick_methods(n) << std::endl;
  std::cout << dp_pick_methods(n) << std::endl;
}
