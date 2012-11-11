#include <algorithm>
#include <stdexcept>
#include <vector>
#include "median.h"

double median(std::vector<double> vec)
{

	typedef std::vector<double>::size_type vec_size;
	vec_size size=vec.size();
	
	if (size==0) {
		throw std::domain_error("median of empty vector");
	}

	std::sort(vec.begin(),vec.end());
	vec_size mid=size/2;
	return  size%2==0?(vec[mid]-vec[mid-1])/2:vec[mid];
}

