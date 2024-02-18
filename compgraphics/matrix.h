#include "number.h"
#include <vector>

class Matrix
{
private:
    int dim = 3;
    std::vector<std::vector<number>> M = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
    std::vector<std::vector<number>> deleteRowAndColumn(std::vector<std::vector<number>> source, int index_1, int index_2);
    number det(std::vector<std::vector<number>> source);

public:

    int getDim();
    number getElem(int i, int j);

    void setDim(int d);
    void setElem(number el, int i, int j);

    std::vector<std::vector<number>> getMatrix();
    number getDet();

    void transpose();

    number getRank();

    void printMatrix();
};
