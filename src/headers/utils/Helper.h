//
// Created by perepilka on 5/3/25.
//

#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <filesystem>



class Helper{

  public:
    template <typename Type>
    static void print_vec(std::vector<Type> &vec){
      for (auto i : vec){
        std::cout << i << " ";
      }
      std::cout << std::endl;
    }




};




#endif //HELPER_H
