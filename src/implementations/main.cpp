#include <iostream>
#include <vector>
#include <string>
#include <../headers/data_generation/DataGenerator.h>
#include <../headers/utils/Helper.h>
// #include <../headers/sorters/Sorter.h>

std::vector<int> int_vec;
std::vector<float> float_vec;
std::vector<char> char_vec;




int main() {
    int x;
start:

    std::cout << "Wybierz opcje: \n"
            "1. Generacja nowych dannych \n"
            "2. Wczytywanie z pliku \n"
            "3. Zakonczenie programu\n";


    std::cin >> x;

    switch (x) {
        choosing:
        case 1: {
            size_t size;
            std::cout << "Wybierz ilosc elementow do generacji: ";
            std::cin >> size;


            std::cout << "Wybierz typ dannych do generacji: \n"
                    "1. int\n2. float\n3. char\n";
            std::cin >> x;
            DataType data_type;
            switch (x) {
                case 1:
                    data_type = DataType::INT;
                    break;
                case 2:
                    data_type = DataType::FLOAT;
                    break;
                case 3:
                    data_type = DataType::CHAR;
                    break;
                default:
                    std::cout << "Wybrano zly typ danych.\n";
                    goto choosing;
            }

            int array_choice;
            std::cout << "Wybierz typ tablicy do generowania: \n"
                    "1. Elementy ulozone losowo\n"
                    "2. Elementy posortowano rosnaco\n"
                    "3. Elementy posortowano malejaco\n"
                    "4. 33% elementow posortowano rosnaco\n"
                    "5. 66% elementow posortowano rosnaco\n";

            std::cin >> array_choice;
            ArrayTypes array_type;

            switch (array_choice) {
                case 1:
                    array_type = ArrayTypes::RANDOM;
                    break;
                case 2:
                    array_type = ArrayTypes::SORTED;
                    break;
                case 3:
                    array_type = ArrayTypes::REVERSE_SORTED;
                    break;
                case 4:
                    array_type = ArrayTypes::PARTIALLY_SORTED_33;
                    break;
                case 5:
                    array_type = ArrayTypes::PARTIALLY_SORTED_66;
                    break;
                default:
                    std::cout << "Wybrano zly typ tablicy\n";
                    goto choosing;
            }

            std::cout << "Generacja...\n";

            switch (data_type) {
                case DataType::INT:
                    int_vec = DataGenerator::generate<int>(size, array_type);
                    Helper::print_vec<int>(int_vec);
                    break;
                case DataType::FLOAT:
                    float_vec = DataGenerator::generate<float>(size, array_type);
                    Helper::print_vec<float>(float_vec);
                    break;
                case DataType::CHAR:
                    char_vec = DataGenerator::generate<char>(size, array_type);
                    Helper::print_vec<char>(char_vec);
                    break;
                default:
                    std::cout << "Wybrano zly typ danych.\n";
                    goto choosing;
            }
            std::cout << "\nCzy chcesz zapisac do pliku?\n"
                    "1. Tak\n"
                    "2. Nie\n";
            std::cin >> x;

            if (x == 1) {
                std::cout << "Napisz nazwe pliku: ";
                std::string path;
                std::cin >> path;
                switch (data_type) {
                    case DataType::INT:
                        DataGenerator::save(int_vec, "../data/input/int/" + path);
                        break;
                    case DataType::FLOAT:
                        DataGenerator::save(float_vec, "../data/input/float/" + path);
                        break;
                    case DataType::CHAR:
                        DataGenerator::save(char_vec, "../data/input/char/" + path);
                        break;
                }
            }
            // Sorter<char>::sort(char_vec, SortType::QuickSort);
            // Helper::print_vec<char>(char_vec);

            std::cout << "Posortowac:\n"
                    "1. Insertion sort\n"
                    "2. Binary insertion sort\n"
                    "3. Heap sort\n"
                    "4. Quick sort\n"
                    "5. Nie sortowac\n";
            std::cin >> x;
            SortType sort_type;
            switch (x) {
                case 1:
                    sort_type = SortType::InsertionSort;
                break;
                case 2:
                    sort_type = SortType::BinaryInsertionSort;
                break;
                case 3:
                    sort_type = SortType::HeapSort;
                break;
                case 4:
                    sort_type = SortType::QuickSort;
                break;
                case 5:
                    goto skip;
                default:
                    std::cout << "Niepoprawna opcja sortowania.\n";
                goto skip;
            }

            Helper::sort(int_vec, float_vec, char_vec, sort_type, data_type);
            Helper::print_vec<int>(int_vec);

        skip:
            goto start;
            break;
        }

        case 2: {
            // Tutaj możesz dodać kod do wczytywania z pliku
            std::cout << "Funkcja wczytywania z pliku nie jest jeszcze zaimplementowana.\n";
            goto start;
            break;
        }
        case 3: {
            break;
        }

        default: {
            std::cout << "Niepoprawna opcja.\n";
            goto start;
            break;
        }
    }

    return 0;
}
