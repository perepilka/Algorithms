//
// Created by perepilka on 4/26/25.
//

#ifndef TYPES_H
#define TYPES_H

// Typy generowanych tablic testowych:
enum class ArrayTypes {
    RANDOM,              // Losowe dane
    SORTED,              // Posortowane rosnąco
    REVERSE_SORTED,      // Posortowane malejąco
    PARTIALLY_SORTED_33, // Częściowo posortowane (33%)
    PARTIALLY_SORTED_66, // Częściowo posortowane (66%)

};

// Typy danych obsługiwane przez program
enum class DataType {
    INT,    // Liczby całkowite (np. 1, 2, 3)
    FLOAT,  // Liczby zmiennoprzecinkowe pojedynczej precyzji (np. 3.14f)
    CHAR
};

#endif //TYPES_H
