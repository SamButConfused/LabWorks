#include "ProblemSolver.h"

double ProblemSolver::calculateFirstDerivative(double x) {
  const double h = 1e-6;
  double f_x_plus_h = equation(x + h);
  double f_x_minus_h = equation(x - h);
  return (f_x_plus_h - f_x_minus_h) / (2 * h);
}

double ProblemSolver::calculateSecondDerivative(double x) {
  const double h = 1e-6;
  double f_x_plus_h = equation(x + h);
  double f_x = equation(x);
  double f_x_minus_h = equation(x - h);
  return (f_x_plus_h - 2 * f_x + f_x_minus_h) / (h * h);
}
