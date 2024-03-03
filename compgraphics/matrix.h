#include "number.h"
#include <vector>

class Matrix
{
private:
    int dim = 3;
    std::vector<std::vector<number>> M = { {number(1,2), number(2,2), number(3,3)},{number(4,4), number(5,5), number(6,6)},{number(7,7), number(8,8),number(9,9)}};
public:

    int getDim();
    number getElem(int i, int j);

    void setDim(int d);
    void setElem(number el, int i, int j);

    std::vector<std::vector<number>> getMatrix();
    number getDet();

    void transpose();

    int getRank();

    void printMatrix();

    std::vector<std::vector<number>> deleteRowAndColumn(std::vector<std::vector<number>> source, int index_1, int index_2);
    number det(std::vector<std::vector<number>> source);
};
