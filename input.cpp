#include <vector>
#include <iostream>


int inputer (std::vector<std::vector<double>>&matrix, std::vector<double>& free){
    std::cout << "Введите размер матрицы" << std::endl;  
    int N;
    std::cin >> N;
    matrix.resize(N);
    free.resize(N);    
    for (int i = 0; i < N; ++i){
        matrix[i].resize(N);
    }
    std::cout << "Введите матрицу"  << std::endl; 
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            std::cin >> matrix[i][j];
        }
    }
    std::cout << "Введите столбец свободных членов"  << std::endl;  
    for (int j = 0; j < N; ++j){
        std::cin >> free[j];
    }
return N;
}

int randinputer (std::vector<std::vector<double>>&matrix, std::vector<double>& free){  
    int N,M;
    std::cout << "Введите размер матрицы" << std::endl;
    std::cin >> N;
    std::cout << "Введите максимально возможное число" << std::endl;
    std::cin >> M;
    matrix.resize(N);
    free.resize(N);    
    for (int i = 0; i < N; ++i){
        matrix[i].resize(N);
    }
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            matrix[i][j] = rand() % (M+1);
        }
    } 
    for (int j = 0; j < N; ++j){
        free[j] = rand() % (M+1);
    }
return N;
}

void matrixprinter (std::vector<std::vector<double>>&matrix){
    int N = matrix.size();
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}