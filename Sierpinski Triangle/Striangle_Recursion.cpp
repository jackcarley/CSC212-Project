
// Sierpinski Triangle with recursion

// Hassan Bhatti
// CSC 212
// Spring 2022

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

const int int_triangle_1 = 1;
const int int_triangle_2 = 2;

// const unsigned char char_triangle_1[2] = {0x25, 0xE2}; //'◢';
// const unsigned char char_triangle_2[2] = {0x25, 0xE3}; //'◣';
// const char char_triangle_1 = '\u25E2'; //'◢';
// const char char_triangle_2 = '\u25E3'; //'◣';

void sierptri(const int N, int row, int col, vector<vector<int>> &grid);
void rec_sierptri(const int N, int row, int col, vector<vector<int>> &grid, int i, int j, int level);
void fill_triangle_1(vector<vector<int>> &grid);
void fill_triangle_N(vector<vector<int>> &grid, int i, int j);

int main()
{

    int row, col, N;
    cout << "Enter the degree number:  ";
    cin >> N;
    row = pow(2, N - 1);
    col = pow(2, N);
    vector<vector<int>> grid(row, vector<int>(col, 0));
    //cout << "row: " << row << endl;
    //cout << "col: " << col << endl;

    sierptri(N, row, col, grid);

    ofstream file;
    file.open("output.txt");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 1)
            {
                file << "\u25E2";
            }
            else if (grid[i][j] == 2)
            { 
                file << "\u25E3";
            }
            else
            {
                file << " ";
            }
        }
        file << endl;
    }
}

void sierptri(const int N, int row, int col, vector<vector<int>> &grid)
{

    if (N == 1)
    {
        fill_triangle_1(grid);
    }
    else
    {
        rec_sierptri(N, row, col, grid, 0, 0, 2);
    }
}

void rec_sierptri(const int N, int row, int col, vector<vector<int>> &grid, int i, int j, int level)
{
    if (N == level)
    {
        fill_triangle_N(grid, i, j);
    }
    else
    {
        rec_sierptri(N, row / 2, col / 2, grid, i, j + col / 4, level + 1);
        rec_sierptri(N, row / 2, col / 2, grid, i + row / 2, j, level + 1);
        rec_sierptri(N, row / 2, col / 2, grid, i + row / 2, j + col / 2, level + 1);
    }
}

void fill_triangle_1(vector<vector<int>> &grid)
{
    grid[0][0] = int_triangle_1;
    grid[0][1] = int_triangle_2;
}

void fill_triangle_N(vector<vector<int>> &grid, int i, int j){

    // grid[i][j] = 0;
    grid[i][j + 1] = int_triangle_1;
    grid[i][j + 2] = int_triangle_2;
    // grid[i][j+3] = 0;
    grid[i + 1][j] = int_triangle_1;
    grid[i + 1][j + 1] = int_triangle_2;
    grid[i + 1][j + 2] = int_triangle_1;
    grid[i + 1][j + 3] = int_triangle_2;
}
