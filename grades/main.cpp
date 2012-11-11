#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "grade.h"
#include "studentinfo.h"

using std::cin; using std::setprecision;
using std::cout; using std::string;
using std::endl; using std::streamsize;
using std::vector;


int main(int argc, const char *argv[])
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen=0;
	while (read(cin,record)) {
		maxlen=std::max(maxlen,record.name.size());
		students.push_back(record);
	}
	sort(students.begin(),students.end(),compare);

	for (vector<Student_info>::size_type i=0; i<students.size();++i) {
		cout<<students[i].name<<string(maxlen+2-students[i].name.size(),' ');
		try{
			double finalgrade=grade(students[i]);
			streamsize prec=cout.precision();
			cout<<setprecision(3)<<finalgrade<<setprecision(prec);
		}
		catch(std::domain_error e)
		{
			cout<<"Error: "<<e.what();
		}
		cout<<endl;
	}
	return 0;
}

