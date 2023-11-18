#ifndef PROBLEMSOLVER_H
#define PROBLEMSOLVER_H

class ProblemSolver {
public:
  virtual double solve() = 0;
  virtual double equation(double x) = 0;
  double calculateFirstDerivative(double x);
  double calculateSecondDerivative(double x);
};

#endif
