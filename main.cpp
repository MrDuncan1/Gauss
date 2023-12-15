#include "solver.cpp"
#include "input.cpp"
#include <vector>
#include <iostream>

int main(){
    int L, N;
    std::cout << "Выберите режим: 1 - ручной ввод, 2 - рандомный" << std::endl;
    std::cin >> L;
    std::vector<double> free;
    std::vector<std::vector<double>> matrix;
    if (L == 1){
        N = inputer(matrix, free);
    }
    else if (L == 2){
        N = randinputer(matrix, free);
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < N; ++i){
        std::cout << free[i] << " ";
    }
    }
    else{
        std::cout << "Дурак - 1 или 2, сказал же" << std::endl;
        return 0; 
    }

    auto result = Solve(matrix, free, N);
    if (result == std::vector<double>()){
        return 0;
    }
    std::cout << "Ответ:" << std::endl;
    for (int i = 0; i < N; ++i){
        std::cout << result[i] << " ";
    } 
    std::cout << std::endl;

    return 0;
}


