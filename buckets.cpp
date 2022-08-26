#include "buckets.hpp"
std::map<std::string, int>OutputMap;
void print_Output(){
   std::cout<<"Range, Readings"<<std::endl;
   for(auto x: OutputMap){
      std::cout << x.first << "   " << x.second <<std::endl;
   }
}
int detect_ranges(std::vector<int> samples){
	std::sort(samples.begin(), samples.end());
	int count = 1;
    std::string str;
    for (int i = 0; i < samples.size(); i++){
        if(samples[i]+1 >= (samples[i+1])){
            if(count == 1){
             str =std::to_string(samples[i]);   
            }
          count++;
        }
        else{
           str +="-" + std::to_string(samples[i]);
           OutputMap[str] =  count;
           count=1;
        }
	}
	print_Output();	
	return 1;
}
