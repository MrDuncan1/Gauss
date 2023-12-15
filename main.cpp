#include "solver.cpp"
#include "input.cpp"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <cmath>

bool operator!=(std::vector<double> lhs, std::vector<double> rhs)
{
    if (lhs.size() != rhs.size())
        return true;
    for (int i = 0; i < lhs.size(); ++i)
        if (abs(lhs[i] - rhs[i]) > 0.001)
            return true;
    return false;
}

int main(){
    srand(18);
    int L, N;
    std::cout << "Выберите режим:" << std::endl << "1 - ручной ввод," << std::endl <<"2 - рандомный,"<< std::endl <<"3 - quize mode." << std::endl;
    std::cin >> L;
    std::vector<double> free, answer;
    std::vector<std::vector<double>> matrix;
    if (L == 1){
        N = inputer(matrix, free);
        resulter(matrix, free);
    }
    else if (L == 2){
        N = randinputer(matrix, free);
        matrixprinter(matrix);
        std::cout << std::endl;
        for (int i = 0; i < N; ++i){
            std::cout << free[i] << " ";
        }
        resulter(matrix, free);
    }
    else if (L == 3){
        std::cout << "Добро пожаловать в quize mod - потренеруй себя - реши задачку" << std::endl;
        N = randinputer(matrix, free);
        std::cout << "Матрица:"<< std::endl;
        matrixprinter(matrix);
        std::cout << "Свободный столбец:"<< std::endl;
        for (int j = 0; j < N; ++j){
            std::cout << free[j] << std::endl;
        }

        answer.resize(N);
        std::cout << "Ваш ответ:"<< std::endl;
        for (int j = 0; j < N; ++j){
                std::cin >> answer[j];
        }

        if (resulter(matrix, free) != answer){
            std::cout << "Неверно" <<std::endl;
        }
        else{
            std::cout << "Ня"; 
            #include "documentation.txt"
        }
    }
    else{
        std::cout << "1, 2, 3 - сказал же" << std::endl;
    }
    return 0;
}


