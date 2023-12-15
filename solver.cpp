#include <vector>
#include <iostream>

std::vector<double> Solve(std::vector<std::vector<double>> matrix, std::vector <double> free, unsigned N){
    for (int i = 0; i < N - 1; ++i){
        if (matrix[i][i] == 0){
                for (int j = i+1; j < N; ++j){
                    if (matrix[j][i] != 0){
                        std::swap(matrix[i],matrix[j]);
                        break;
                    } 
                    std::cout << "А все, приехали, это не код кривой, а матрица говно" << std::endl;
                    return {};
                }
            }
        for (int j = i+1; j < N; ++j){
            double koef = matrix[j][i]/matrix[i][i];
            for (int k = i; k < N; ++k){
                matrix[j][k]-=koef*matrix[i][k];
            }
            free[j]-=koef*free[i];
        }
    }
for (int i = N-1; i >=0; --i){
        for (int j = i-1; j >=0; --j){
            double koef = matrix[j][i]/matrix[i][i];
            for (int k = i; k >=0; --k){
                matrix[j][k]-=koef*matrix[i][k];
            }
            free[j]-=koef*free[i];
        }
    }

for (int i = 0; i < N; ++i){
    free[i] = free[i]/matrix[i][i];
}
return free;
}

std::vector<double> resulter(std::vector<std::vector<double>>& matrix, std::vector <double> free){
    int N = matrix.size();
    auto result = Solve(matrix, free, N);
    if (result == std::vector<double>()){
        return {} ;
    }
    std::cout << "Ответ:" << std::endl;
    for (int i = 0; i < N; ++i){
        std::cout << result[i] << " ";
    } 
    std::cout << std::endl;
    return result;
}