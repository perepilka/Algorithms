#include <iostream>
#include <vector>
#include <string>
#include <../headers/data_generation/DataGenerator.h>
#include <../headers/utils/Helper.h>

template <typename Type>
void makeTest(int times, std::vector<double>& mss, std::vector<Type>& vec, SortType sort_type, int number_of_elements, std::string path, ArrayTypes array_type) {
    mss.clear();

    Helper::checkPath(path);

    for (int i = 0; i < times; i++) {
        vec = DataGenerator::generate<int>(number_of_elements, array_type);
        mss.push_back(Sorter<int>::sort(vec, sort_type));
    }
    Helper::saveRes(path, Helper::calculateAverageResult(mss));

}


int main() {
    std::vector<int> vec;
    int times = 100;
    std::vector<double> mss;
    ArrayTypes array_type = ArrayTypes::RANDOM;
    DataType data_type = DataType::INT;
    int number_of_elements = 1000;
    SortType sort_type = SortType::InsertionSort;

    std::string path = "../data/1_etap";
    makeTest(times, mss, vec, sort_type, 1000, path + "1etap_i_s_1000_int_100timesAVG.txt", array_type);
    makeTest(times, mss, vec, sort_type, 5000, path + "1etap_i_s_5000_int_100timesAVG.txt", array_type);
    makeTest(times, mss, vec, sort_type, 10000, path + "1etap_s_10000_int_100timesAVG.txt", array_type);
    makeTest(times, mss, vec, sort_type, 50000, path + "1etap_i_s_50000_int_100timesAVG.txt", array_type);
    makeTest(times, mss, vec, sort_type, 100000, path + "1etap_i_s_100000_int_100timesAVG.txt", array_type);
    makeTest(times, mss, vec, sort_type, 150000, path + "1etap_i_s_150000_int_100timesAVG.txt", array_type);
    makeTest(times, mss, vec, sort_type, 200000, path + "1etap_i_s_200000_int_100timesAVG.txt", array_type);

    sort_type = SortType::BinaryInsertionSort;
    makeTest(times, mss, vec, sort_type, 1000, path + "1etap_b_i_s_1000_int_100timesAVG_random.txt", array_type);
    makeTest(times, mss, vec, sort_type, 5000, path + "1etap_b_i_s_5000_int_100timesAVG_random.txt", array_type);
    makeTest(times, mss, vec, sort_type, 10000, path + "1etap_b_i_s_10000_int_100timesAVG_random.txt", array_type);
    makeTest(times, mss, vec, sort_type, 50000, path + "1etap_b_i_s_50000_int_100timesAVG_random.txt", array_type);
    makeTest(times, mss, vec, sort_type, 100000, path + "1etap_b_i_s_100000_int_100timesAVG_random.txt", array_type);
    makeTest(times, mss, vec, sort_type, 150000, path + "1etap_b_i_s_150000_int_100timesAVG_random.txt", array_type);
    makeTest(times, mss, vec, sort_type, 200000, path + "1etap_b_i_s_200000_int_100timesAVG_random.txt", array_type);

    sort_type = SortType::HeapSort;
    makeTest(times, mss, vec, sort_type, 1000, path + "1etap_h_s_1000_int_100timesAVG_random.txt", array_type);
    makeTest(times, mss, vec, sort_type, 5000, path + "1etap_h_s_5000_int_100timesAVG_random.txt", array_type);
    makeTest(times, mss, vec, sort_type, 10000, path + "1etap_h_s_10000_int_100timesAVG_random.txt", array_type);
    makeTest(times, mss, vec, sort_type, 50000, path + "1etap_h_s_50000_int_100timesAVG_random.txt", array_type);
    makeTest(times, mss, vec, sort_type, 100000, path + "1etap_h_s_100000_int_100timesAVG_random.txt", array_type);
    makeTest(times, mss, vec, sort_type, 150000, path + "1etap_h_s_150000_int_100timesAVG_random.txt", array_type);
    makeTest(times, mss, vec, sort_type, 200000, path + "1etap_h_s_200000_int_100timesAVG_random.txt", array_type);

    sort_type = SortType::QuickSort;
    makeTest(times, mss, vec, sort_type, 1000, path + "1etap_q_s_1000_int_100timesAVG_random.txt", array_type);
    makeTest(times, mss, vec, sort_type, 5000, path + "1etap_q_s_5000_int_100timesAVG_random.txt", array_type);
    makeTest(times, mss, vec, sort_type, 10000, path + "1etap_q_s_10000_int_100timesAVG_random.txt", array_type);
    makeTest(times, mss, vec, sort_type, 50000, path + "1etap_q_s_50000_int_100timesAVG_random.txt", array_type);
    makeTest(times, mss, vec, sort_type, 100000, path + "1etap_q_s_100000_int_100timesAVG_random.txt", array_type);
    makeTest(times, mss, vec, sort_type, 150000, path + "1etap_q_s_150000_int_100timesAVG_random.txt", array_type);
    makeTest(times, mss, vec, sort_type, 200000, path + "1etap_q_s_200000_int_100timesAVG_random.txt", array_type);

    path = "../data/2_etap/";
//etap 2
    number_of_elements = 100000;
    sort_type = SortType::InsertionSort;
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "i_s_100000_int_100timesAVG_random.txt", ArrayTypes::RANDOM);
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "i_s_100000_int_100timesAVG_sorted.txt", ArrayTypes::SORTED);
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "i_s_100000_int_100timesAVG_reverse_sorted.txt", ArrayTypes::REVERSE_SORTED);
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "i_s_100000_int_100timesAVG_33.txt", ArrayTypes::PARTIALLY_SORTED_33);
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "i_s_100000_int_100timesAVG_66.txt", ArrayTypes::PARTIALLY_SORTED_66);

    sort_type = SortType::BinaryInsertionSort;
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "b_i_s_100000_int_100timesAVG_random.txt", ArrayTypes::RANDOM);
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "b_i_s_100000_int_100timesAVG_sorted.txt", ArrayTypes::SORTED);
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "b_i_s_100000_int_100timesAVG_reverse_sorted.txt", ArrayTypes::REVERSE_SORTED);
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "b_i_s_100000_int_100timesAVG_33.txt", ArrayTypes::PARTIALLY_SORTED_33);
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "b_i_s_100000_int_100timesAVG_66.txt", ArrayTypes::PARTIALLY_SORTED_66);

    sort_type = SortType::QuickSort;
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "q_s_100000_int_100timesAVG_random.txt", ArrayTypes::RANDOM);
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "q_s_100000_int_100timesAVG_sorted.txt", ArrayTypes::SORTED);
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "q_s_100000_int_100timesAVG_reverse_sorted.txt", ArrayTypes::REVERSE_SORTED);
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "q_s_100000_int_100timesAVG_33.txt", ArrayTypes::PARTIALLY_SORTED_33);
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "q_s_100000_int_100timesAVG_66.txt", ArrayTypes::PARTIALLY_SORTED_66);

    sort_type = SortType::HeapSort;
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "h_s_100000_int_100timesAVG_random.txt", ArrayTypes::RANDOM);
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "h_s_100000_int_100timesAVG_sorted.txt", ArrayTypes::SORTED);
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "h_s_100000_int_100timesAVG_reverse_sorted.txt", ArrayTypes::REVERSE_SORTED);
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "h_s_100000_int_100timesAVG_33.txt", ArrayTypes::PARTIALLY_SORTED_33);
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "h_s_100000_int_100timesAVG_66.txt", ArrayTypes::PARTIALLY_SORTED_66);

    //etap 3
    std::vector<float> float_vec;
    std::vector<char> char_vec;
    path = "../data/3_etap/";

    number_of_elements = 1000000;
    sort_type = SortType::QuickSort;
    array_type = ArrayTypes::RANDOM;

    //int
    makeTest(times, mss, vec, sort_type, number_of_elements, path + "q_s_1000000_int_100timesAVG_random.txt", array_type);
    //float
    makeTest(times, mss, float_vec, sort_type, number_of_elements, path + "q_s_1000000_float_100timesAVG_random.txt", array_type);
    // char
    makeTest(times, mss, char_vec, sort_type, number_of_elements, path + "q_s_1000000_char_100timesAVG_random.txt", array_type);




    return 0;
}
