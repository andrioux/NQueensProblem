#include <iostream>
#include <cmath>
using namespace std;

const int boardSize = 8;
int loc[boardSize] = {0,0,0,0,0,0,0,0};

bool canPutQueen(int row, int col)
{
    for(int r = 0; r < row; r++)
    {
        if(loc[r] == col || abs(r-row) == abs(loc[r] - col))
            return false;
    }
    return true;
}

void print()
{
    for(int i = 0; i < boardSize; i++)
    {
        for( int j = 0; j < boardSize; j++)
        {
            if( j == loc[i])
                cout << "X ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    cout << endl << endl << endl;
}

void nqueen(int row)
{
    for(int col = 0; col < boardSize; col++)
    {
        if(canPutQueen(row,col))
        {
            loc[row] = col;
            if(row == boardSize - 1)
                print();
            else
                nqueen(row + 1);
        }
    }
}

int main()
{
    nqueen(0);
    return 0;
}
