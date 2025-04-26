//
// Created by perepilka on 4/26/25.
//

#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include <vector>
#include "Types.h"

class DataGenerator {
  public:
    template<typename Type>
    static std::vector<Type>  generate(size_t size, ArrayTypes array_type);
    template<typename Type>
    static void save(std::vector<Type> & vec);
    template<typename Type>
    static std::vector<Type>  load(std::string fileName);


};

#endif //DATAGENERATOR_H
