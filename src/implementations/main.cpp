#include <iostream>
#include <vector>
#include <string>
#include <../headers/data_generation/DataGenerator.h>
#include <../headers/utils/Helper.h>


std::vector<int> int_vec;
std::vector<float> float_vec;
std::vector<char> char_vec;


int main() {
    int x;
start:
    std::string run_information = "_________Inforamcja symulacji___________\n";

    std::cout << "Wybierz opcje: \n"
            "1. Generacja nowych dannych \n"
            "2. Wczytywanie z pliku \n"
            "3. Zakonczenie programu\n";


    std::cin >> x;

    switch (x) {
        choosing:
        case 1: {
            run_information += "Generacja nowych dannych \n";
            size_t size;
            std::cout << "Wybierz ilosc elementow do generacji: ";
            std::cin >> size;

            run_information += "Liczba elementow: " + std::to_string(size) + "\n";


            std::cout << "Wybierz typ dannych do generacji: \n"
                    "1. int\n2. float\n3. char\n";
            std::cin >> x;
            DataType data_type;
            switch (x) {
                case 1:
                    data_type = DataType::INT;
                    run_information += "Wybrany typ danych: int\n";
                    break;
                case 2:
                    data_type = DataType::FLOAT;
                    run_information += "Wybrany typ danych: float\n";
                    break;
                case 3:
                    data_type = DataType::CHAR;
                    run_information += "Wybrany typ danych: char\n";
                    break;
                default:
                    std::cout << "Wybrano zly typ danych.\n";;
                    goto start;
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
                    run_information += "Wybrany typ tablicy: random\n";
                    break;
                case 2:
                    array_type = ArrayTypes::SORTED;
                    run_information += "Wybrany typ tablicy: sorted\n";
                    break;
                case 3:
                    array_type = ArrayTypes::REVERSE_SORTED;
                    run_information += "Wybrany typ tablicy: reverse sort\n";
                    break;
                case 4:
                    array_type = ArrayTypes::PARTIALLY_SORTED_33;
                    run_information += "Wybrany typ tablicy: partially sorted 33%\n";
                    break;
                case 5:
                    array_type = ArrayTypes::PARTIALLY_SORTED_66;
                    run_information += "Wybrany typ tablicy: partially sorted 66%\n";
                    break;
                default:
                    std::cout << "Wybrano zly typ tablicy\n";
                    goto start;
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
                    goto start;
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
                        path = "../data/input/int/" + path;
                        DataGenerator::save(int_vec, path);
                        break;
                    case DataType::FLOAT:
                        path = "../data/input/float/" + path;
                        DataGenerator::save(float_vec, path);
                        break;
                    case DataType::CHAR:
                        path = "../data/input/char/" + path;
                        DataGenerator::save(char_vec, path);
                        break;
                }
                run_information += "Dane wejsciowe zapisane do pliku o nazwie: " + path + "\n";
            } else run_information += "Dane wejsciowe nie zapisane\n";
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
                    run_information += "Insertion sort\n";
                    sort_type = SortType::InsertionSort;
                    break;
                case 2:
                    run_information += "Binary insertion sort\n";
                    sort_type = SortType::BinaryInsertionSort;
                    break;
                case 3:
                    run_information += "Heap sort\n";
                    sort_type = SortType::HeapSort;
                    break;
                case 4:
                    run_information += "Quick sort\n";
                    sort_type = SortType::QuickSort;
                    break;
                case 5:
                    goto skip;
                default:
                    std::cout << "Niepoprawna opcja sortowania.\n";
                    goto skip;
            }
            std::cout << run_information;
            Helper::sort(int_vec, float_vec, char_vec, sort_type, data_type);
            std::cout << "____________________________\n";
            std::cout << "Wypisac posortowana tablice?\n"
                    "1. Tak\n"
                    "2. Nie\n";
            std::cin >> x;
            if (x == 1) {
                Helper::print_vec<int>(int_vec);
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
                        path = "../data/output/int/" + path;
                        DataGenerator::save(int_vec, path);
                        break;
                    case DataType::FLOAT:
                        path = "../data/output/float/" + path;
                        DataGenerator::save(float_vec, path);
                        break;
                    case DataType::CHAR:
                        path = "../data/output/char/" + path;
                        DataGenerator::save(char_vec, path);
                        break;
                }
            }


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
