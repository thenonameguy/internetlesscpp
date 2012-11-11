#include "studentinfo.h"

bool compare(const Student_info& x,const Student_info& y){return x.name<y.name;}

std::istream& read_hw(std::istream& in, std::vector<double>& hw)
{
	if(in)
	{
		hw.clear();
		double x;
		while(in>>x)
		{
			hw.push_back(x);
		}
		in.clear();
	}
	return in;
}
std::istream& read(std::istream& in,Student_info& student)
{
	in>>student.name>>student.midterm>>student.final;
	read_hw(in,student.homework);
	return in;
}
