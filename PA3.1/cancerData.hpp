

#ifndef CancerData_hpp
#define CancerData_hpp
 
#include <iostream>
#include <string>
 
class CancerData
{
private:
    std::string country;
    float rate;
    
public:
    CancerData(std::string, float);
    float get_rate()
    {
        return rate;
    }
    std::string get_country()
    {
        return country;
    }
    
};
 
#endif /* CancerData_hpp */