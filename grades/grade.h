#ifndef GUARD_grade
#define GUARD_grade
#include <vector>
#include "studentinfo.h"

double grade(double,double,double);
double grade(double,double,const std::vector<double>&);
double grade(const Student_info&);

#endif
