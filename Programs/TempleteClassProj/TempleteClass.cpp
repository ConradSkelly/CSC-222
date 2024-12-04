#include <string>
#include <vector>
#include "TempleteClass.h"



template class TempleteClass<int>;
template class TempleteClass<double>;
template class TempleteClass<std::string>;
template class TempleteClass<std::vector<int>>;
template class TempleteClass<std::vector<std::string>>;

