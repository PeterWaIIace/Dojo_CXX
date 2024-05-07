#include <vector>
#include <cassert>
#include <iostream>


int sumMatrix(int x , int y , int w , int h , std::vector<std::vector<int>>& matrix){

    int sum = 0;
    for(int i = x; i < x+w ; i++){
        for(int j = y; j < y+h ; j++){
            sum += matrix[i][j];
        }
    }
    return sum;
}

int maximalSquare(std::vector<std::vector<int>>& matrix) {
    int sum = 0;
    int width = matrix.size();
    int height = matrix[0].size();
    int side = width < height ? width : height;  

    while(side > 0)
    {
        int x = 0;
        do{
            int y = 0;
            do{
                int tmpSum = sumMatrix(x,y,side,side,matrix);

                if(tmpSum > sum and tmpSum == side * side){
                    sum = tmpSum;
                }
                y++;
            }while( y <= matrix[0].size() - side);
            x++;
        }while( x <= matrix.size() - side);
        side--;
    }
    return sum;
}

void test1(){
    std::vector<std::vector<int>> matrix = {{0,1},{1,0}};
    int output = 1;    
    
    int result = maximalSquare(matrix); 
    std::cout << "result: " << result << std::endl;
    assert(result == output);
}

void test2(){
    std::vector<std::vector<int>> matrix = {{0}};
    int output = 0;    
    
    int result = maximalSquare(matrix); 
    std::cout << "result: " << result << std::endl;
    assert(result == output);
}

void test3(){
    std::vector<std::vector<int>> matrix = {{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    int output = 4;    
    
    int result = maximalSquare(matrix); 
    std::cout << "result: " << result << std::endl;
    assert(result == output);
}

void test4(){
    std::vector<std::vector<int>> matrix = {{1,0,1,0,0},
                                            {1,0,1,1,1},
                                            {1,1,1,1,1},
                                            {1,0,1,1,1}};
    int output = 9;    
    
    int result = maximalSquare(matrix); 
    std::cout << "result: " << result << std::endl;
    assert(result == output);
}


void test5(){
    std::vector<std::vector<int>> matrix = {{1,0,1,0,0},
                                            {1,0,1,1,1},
                                            {1,1,1,1,1},
                                            {1,0,1,1,0}};
    int output = 4;    
    
    int result = maximalSquare(matrix); 
    std::cout << "result: " << result << std::endl;
    assert(result == output);
}

void test6(){
    std::vector<std::vector<int>> matrix = {{1,0,1,0,0},
                                            {1,0,1,1,1},
                                            {1,1,1,0,1},
                                            {1,0,1,1,0}};
    int output = 1;
    
    int result = maximalSquare(matrix); 
    std::cout << "result: " << result << std::endl;
    assert(result == output);
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}