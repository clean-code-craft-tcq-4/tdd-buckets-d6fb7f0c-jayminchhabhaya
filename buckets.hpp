#include <iostream>
#include <string>
#include <vector>  
#include <map>
#include <algorithm>
#include <iterator>
int detect_ranges(std::vector<int> samples);
void print_Output();
std::vector<std::string> GetRanges(std::vector<int> samples);

class MatadataRange
{
	public:
		std::vector<std::string> m_strrange;
};