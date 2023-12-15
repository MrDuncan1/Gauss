#include "solver.cpp"
#include <vector>
#include <iostream>


int main(){
    std::vector<std::vector<double>> test {{0,2,4},{0,1,1},{0,0,1}};
    std::vector<double> freetest {1,1,1};
    auto result = Solve(test, freetest, 3);
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            std::cout << test[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    if (result == std::vector<double>()){
        return 0;
    }
    
    for (int i = 0; i < 3; ++i){
        std::cout << result[i] << " ";
    } 
    std::cout << std::endl;

    return 0;
}


