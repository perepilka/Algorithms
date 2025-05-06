#include <iostream>
#include <vector>
#include <string>
#include <../headers/data_generation/DataGenerator.h>
#include <../headers/utils/Helper.h>





int main() {
    std::vector<int> vec;
    int times = 100;
    ArrayTypes array_type = ArrayTypes::RANDOM;
    DataType data_type = DataType::INT;
    int number_of_elements = 1000;
    SortType sort_type = SortType::InsertionSort;

    for (int i = 0; i < times; i++) {
        vec = DataGenerator::generate<int>(number_of_elements, array_type);





    }

    return 0;
}
