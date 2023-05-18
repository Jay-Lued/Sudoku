#include <iostream>
#include <random>

using namespace std;

const int ROWS = 9;
const int COLM = 9;

void Fill_Matrix(int(&grid)[ROWS][COLM]);
void Check_Row(int grid[ROWS][COLM], int x, int y, int num, bool& again);
void Check_Colm(int grid[ROWS][COLM], int x, int colm, int num, bool& again);

int main()
{
    int grid[ROWS][COLM];

    Fill_Matrix(grid);

    for (int x = 0; x < ROWS; x++) {
        for (int y = 0; y < COLM; y++) {
            std::cout << grid[x][y] << " ";
        }
        std::cout << std::endl;
    }
}

void Fill_Matrix(int(&grid)[ROWS][COLM])
{
    int minNum = 1;
    int maxNum = 9;


    for (int a = 0; a < (ROWS * COLM); a++) {
        for (int x = 0; x < ROWS; x++) {
            for (int y = 0; y < COLM; y++) {

                bool again = true;
                while (again)
                {
                    //random number genorator by Mersenne Twister algorithem
                    random_device rd;
                    mt19937 gen(rd());
                    uniform_int_distribution<> dis(minNum, maxNum);

                    //obtain random number and fill matrix
                    int ranNum = dis(gen);
                    grid[x][y] = ranNum;

                    Check_Row(grid, x, y, ranNum, again);
                    Check_Colm(grid, x, y, ranNum, again);
                }
            }
        }
    }
}

void Check_Row(int grid[ROWS][COLM], int row, int y, int num, bool& again)
{
    for (int x = 0; x < ROWS; x++) {
        if (x == row)
        {
            x++;
        }

        if (grid[x][y] == num) { //If number is not unique in row
            again = true;
            return;
        }

    }
    again = false;
}

void Check_Colm(int grid[ROWS][COLM], int x, int colm, int num, bool& again)
{
    for (int y = 0; y < COLM; y++) {
        if (y == colm) {
            y++;
        }

        if (grid[x][y] == num) { // If number is not unique in column
            again = true;
            return;
        }
    }
    again = false;
}