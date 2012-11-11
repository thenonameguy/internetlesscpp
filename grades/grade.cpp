#include "grade.h"
#include <stdexcept>
#include "median.h"
#include "studentinfo.h"


double grade(double final, double midterm, double homework)
{
	return 0.4*final+0.2*midterm+0.4*homework;
}

double grade(double final, double midterm, const std::vector<double>& hw)
{
	if(hw.size()==0)
		throw std::domain_error("no homeworks given");
	return grade(final,midterm,median(hw));
}


double grade(const Student_info& s)
{
	return grade(s.final,s.midterm,s.homework);
}
