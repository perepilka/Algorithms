//
// Created by perepilka on 4/26/25.
//

#include "../headers/data_generation/DataGenerator.h"
#include <random>
#include <algorithm>

template<typename Type>
std::vector<Type>  DataGenerator::generate(size_t size, ArrayTypes array_type){
  std::vector<Type> vec;
  vec.reserve(size);

  std::random_device rd;
  std::mt19937 gen(rd());


    // type = FLOAT
    if constexpr (std::is_floating_point_v<Type>) {
      std::uniform_real_distribution<Type> dist(0.0f, 10000.0f);
      for(size_t i = 0; i < size; ++i){
        vec.push_back(dist(gen));
      }
    }
    // type = INT
    if constexpr (std::is_integral_v<Type> && !std::is_same_v<DataType, bool>){
      std::uniform_int_distribution<Type> dist(0, 10000);
      for(size_t i = 0; i < size; ++i){
        vec.push_back(dist(gen));
      }
    }
     //type = CHAR
     if constexpr (std::is_same_v<DataType, char>) {
       std::uniform_int_distribution<int> dist('a', 'z');
       for(size_t i = 0; i < size; ++i){
         vec.push_back(static_cast<char>(dist(gen)));
       }
     }

     switch(array_type){
       case ArrayTypes::RANDOM:{
         break;
       }
       case ArrayTypes::SORTED:{
         std::sort(vec.begin(), vec.end());
         break;
       }
       case ArrayTypes::REVERSE_SORTED:{
         std::sort(vec.rbegin(), vec.rend());
         break;
       }
       case ArrayTypes::PARTIALLY_SORTED_33:{
         if (size >= 3) {
           std::sort(vec.begin(), vec.begin() + size/3);
         }
         break;
       }
       case ArrayTypes::PARTIALLY_SORTED_66:{
         if (size >= 3) {
           std::sort(vec.begin(), vec.begin() + 2*size/3);
         }
         break;
       }
     }

     return vec;
  }








std::vector<DataType> & DataGenerator::load(std::vector<DataType> & vec, DataType type) {

}


