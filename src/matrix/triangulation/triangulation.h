//
// Created by ruskaof on 19/02/23.
//

#ifndef LAB1_TRIANGULATION_H

#include <vector>
#include "../Matrix.h"

/**
 * Triangulates a given matrix using elementary matrix row transformations
 * @param matrix - matrix that will be triangulated
 * @return a number of times rows were swapped during triangulation.
 */
size_t make_triangulated(Matrix &matrix);

#define LAB1_TRIANGULATION_H

#endif //LAB1_TRIANGULATION_H
