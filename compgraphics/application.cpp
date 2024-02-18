#include "application.h"

int Application::run() {

    Matrix tab;
    int select;
    int dimension = tab.getDim();
    int buff;

    while (1) {
        select = menu();
        switch (select)
        {
        case (1):
            std::cout << "Введите желаемую размерность матрицы: ";
            std::cin >> dimension;
            tab.setDim(dimension);
            for (int i = 0; i < dimension; i++) {
                for (int j = 0; j < dimension; j++) {
                    std::cout << "Введите элемент [" << i << "][" << j << "]: ";
                    std::cin >> buff;
                    tab.setElem(buff, i, j);
                }
            }
            tab.printMatrix();
            std::cout << "######################################################" << std::endl;
            break;
        case (2):
            std::cout << "Определитель матрицы = " << tab.getDet() << std::endl;
            std::cout << "######################################################" << std::endl;
            break;
        case (3):
            tab.transpose();
            tab.printMatrix();
            std::cout << "######################################################" << std::endl;
            break;

        case (4):
            std::cout << "Ранг матрицы = " << tab.getRank() << std::endl;
            std::cout << "######################################################" << std::endl;
            break;
        case (5):
            
            tab.printMatrix();
            std::cout << "######################################################" << std::endl;
            break;
        case (6):
            
            return 0;
        default:
            std::cout << "Некорректное значение" << std::endl;
            std::cout << "######################################################" << std::endl;

        }
    }
    return 0;
}

int Application::menu() {
    int choice;
    std::cout << "Введите 1, чтобы задать матрицу" << std::endl;
    std::cout << "Введите 2, чтобы рассчитать определитель матрицы" << std::endl;
    std::cout << "Введите 3, чтобы вывести транспонированной матрицы" << std::endl;
    std::cout << "Введите 4, чтобы рассчитать ранг матрицы" << std::endl;
    std::cout << "Введите 5, чтобы вывести текущую матрицу" << std::endl;
    std::cout << "Введите 6, чтобы завершить работу" << std::endl << " ";
    std::cin >> choice;
    std::cout << "######################################################" << std::endl;
    return choice;
}
