#include <iostream>
#include <vector>

int main() {
  std::vector<float> appel {1,2,3};
  std::vector<float> peer {5,6,7};
  std::vector<std::vector<float>> kaas {appel,peer};
  std::cout << kaas[1][2];

  kaas[1] = {9, 8, 12};
  std::cout << kaas[1][2];
}
