#ifndef DERIVEDSOLVER_H
#define DERIVEDSOLVER_H

#include "ProblemSolver.h"

class DerivedSolver : public ProblemSolver {
public:
  double solve() override;
  double equation(double x) override;
};

#endif
