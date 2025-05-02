#include <iostream>
#include <../headers/data_generation/DataGenerator.h>

DataGenerator generator;
std::vector<int> int_vec;
std::vector<float> float_vec;
std::vector<char> char_vec;

int main() {
    int x;

    std::cout << "Wybierz opcje: \n"
                 "1. Generacja nowych dannych \n"
                 "2. Wczytywanie z pliku \n";

    std::cin >> x;

    switch (x) {
        case 1: {
            size_t size;
            std::cout << "Wybierz ilosc elementow do sortowania: ";
            std::cin >> size;

            int type;
        datatype_choosing:
            std::cout << "Wybierz typ dannych do generacji: \n"
                         "1. int\n2. float\n3. char\n";
            std::cin >> type;

            int array_choice;
        arraytype_choosing:
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
                    std::cout << "Wybrano zly typ tablicy, wpisz powtornie.\n";
                    goto arraytype_choosing;
            }

            std::cout << "Generacja...\n";

            switch (type) {
                case 1:
                    int_vec = DataGenerator::generate<int>(size, array_type);
                    break;
                case 2:
                    float_vec = DataGenerator::generate<float>(size, array_type);
                    break;
                case 3:
                    char_vec = DataGenerator::generate<char>(size, array_type);
                    break;
                default:
                    std::cout << "Wybrano zly typ danych, wpisz powtornie.\n";
                    goto datatype_choosing;
            }

            break;
        }

        case 2: {
            // Tutaj możesz dodać kod do wczytywania z pliku
            std::cout << "Funkcja wczytywania z pliku nie jest jeszcze zaimplementowana.\n";
            break;
        }

        default: {
            std::cout << "Niepoprawna opcja. Zakonczono program.\n";
            break;
        }
    }

    return 0;
}
