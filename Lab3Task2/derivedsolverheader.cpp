#include <iostream>
#include "DerivedSolver.h"

int main() {
  DerivedSolver solver;
  double result = solver.solve();
  std::cout << "Result: " << result << std::endl;
  return 0;
}
