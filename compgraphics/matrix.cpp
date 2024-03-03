#pragma once
#include "matrix.h"
#include<iostream>

void Matrix::setElem(number el, int i, int j) {
    M[i][j] = el;
}
number Matrix::getElem(int i, int j) {
    return M[i][j];
}


void Matrix::setDim(int d) {
    dim = d;
    M.resize(d);
    for (int i = 0; i < d; i++) M[i].resize(d);

}
int Matrix::getDim() {
    return dim;
}





std::vector<std::vector<number>> Matrix::getMatrix() {
    return M;
}

std::vector<std::vector<number>> Matrix::deleteRowAndColumn(std::vector<std::vector<number>> matr, int i, int j) {
    std::vector<std::vector<number>> resultMatr;
    resultMatr = matr;

    int n_i = 0;
    for (auto ele = resultMatr.begin(); ele != resultMatr.end(); ele++) {
        if (n_i == i) {
            resultMatr.erase(ele);
            break;
        }
        n_i++;
    }

    n_i = 0;
    for (int n_j = 0; n_j < resultMatr.size(); n_j++) {
        for (auto ele = resultMatr[n_j].begin(); ele != resultMatr[n_j].end(); ele++) {
            if (n_i == j) {
                resultMatr[n_j].erase(ele);
                break;
            }
            n_i++;
        }
    }
    return resultMatr;
}


number Matrix::getDet() {
    return det(M);
}

number Matrix::det(std::vector<std::vector<number>> matr) {
    std::vector<std::vector<number>> minor;
    int i = 0, sign = 1;
    number result;
    if (matr.size() == 1) {
        return matr[0][0];
    }
    if (matr.size() == 2) {
        return matr[0][0] * matr[1][1] - (matr[1][0] * matr[0][1]);
    }
    if (matr.size() > 2) {
        for (i = 0; i < matr.size(); i++) {
            minor = deleteRowAndColumn(matr, i, 0);
            result = result + number(sign) * matr[i][0] * det(minor);
            sign = -sign;
        }
    }
    return result;
}


void Matrix::transpose() {

    std::vector<std::vector<number>> copy = M;

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            M[i][j] = copy[j][i];
        }
    }
}


void Matrix::printMatrix()
{
    for (auto& row : M) {
        for (auto& el : row) {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }
}


int Matrix::getRank() {
    int rank = 0;
    int q = 1;

    while (q <= dim)
    {
        std::vector<number> defaultM(1, 1);
        std::vector<std::vector<number>> B;
        defaultM.resize(q);
        for (int w = 0; w < q; w++) B.push_back(defaultM);

        for (int a = 0; a < (dim - (q - 1)); a++) {
            for (int b = 0; b < (dim - (q - 1)); b++) {
                for (int c = 0; c < q; c++) {
                    for (int d = 0; d < q; d++) {
                        B[c][d] = M[a + c][b + d];
                    }
                }
                if (!(det(B) == 0)) rank = q;
            }
        }
        q++;
    }
    return rank;
}
