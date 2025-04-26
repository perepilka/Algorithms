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
                    "1. int\n2. float\n3. char\n ";
            std::cin >> type;
            arraytype_choosing:
            std::cout << "Wybiers typ tablicy do generowania: \n"
                    "1. Elementy ulozone losowo\n"
                    "2. Elementy posortowano rosnaco\n"
                    "3. Elementy posortowano malejaco\n"
                    "4. 33% procenty elemetow posortowano rosnaco\n"
                    "5. 33% procenty elemetow posortowano rosnaco\n";

            std::cin >> x;
            ArrayTypes array_type;
            switch(x){
                    {
                    case 1: {
                        array_type = ArrayTypes::RANDOM;
                        break;
                    }
                    case 2: {
                        array_type = ArrayTypes::SORTED;
                        break;
                    }
                    case 3: {
                        array_type = ArrayTypes::REVERSE_SORTED;
                        break;
                    }
                    case 4: {
                        array_type = ArrayTypes::PARTIALLY_SORTED_33;
                        break;
                    }
                    case 5: {
                        array_type = ArrayTypes::PARTIALLY_SORTED_66;
                        break;
                    }
                    default: {
                        std::cout << "Wybrana zly typ tablicy, wpisz powtornie: "
                        goto arraytype_choosing;
                        break;}
                    }

                    std::cout << "Generacja...";
                    switch (type) {
                        //1. int
                        case 1: {
                            int_vec = DataGenerator::generate<int>(size, array_type);
                        }
                        //2. float
                        case 2: {
                            float_vec = DataGenerator::generate<float>(size, array_type);
                        }
                        //3. char
                        case 3: {
                            char_vec = DataGenerator::generate<char>(size, array_type);
                        }
                        default: {
                            std::cout << "Wybrany zly typ danych, wpisz powtornie: "
                            goto datatype_choosing;
                            break;
                        }
                    }
            }




            //2. Wczytywanie z pliku
        case 2: {

        }
        }
        //1. Generacja nowych dannych
    }
