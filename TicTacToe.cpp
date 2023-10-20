#include "TicTacToe.hpp"

char TicTacToe::get_content(unsigned int index)
{    
    return this->Field[index]; 
}

bool TicTacToe::get_player()
{
    return this->player;
}

void TicTacToe::set_content(unsigned int index)
{
    if (this->player)
    {
        this->Field[index] = 'X';
    }
    else
    {
        this->Field[index] = 'O';
    }
}

void TicTacToe::operator [] (unsigned int index)
{

    if (this->Field[index] == '_')
    {
        this->set_content(index);  
    }  
    else
    {
        throw 1;
    }
}

void TicTacToe::switch_player()
{
    this->player = !this->player;
}

bool TicTacToe::is_horizontal_win(char symbol)
{
    if ((this->Field[0] == symbol && this->Field[1] == symbol && this->Field[2] == symbol) ||
        (this->Field[3] == symbol && this->Field[4] == symbol && this->Field[5] == symbol) ||
        (this->Field[6] == symbol && this->Field[7] == symbol && this->Field[8] == symbol))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TicTacToe::is_vertical_win(char symbol)
{
    if ((this->Field[0] == symbol && this->Field[3] == symbol && this->Field[6] == symbol) ||
        (this->Field[1] == symbol && this->Field[4] == symbol && this->Field[7] == symbol) ||
        (this->Field[2] == symbol && this->Field[5] == symbol && this->Field[8] == symbol))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TicTacToe::is_diagonal_win(char symbol)
{
    if ((this->Field[0] == symbol && this->Field[4] == symbol && this->Field[8] == symbol) ||
        (this->Field[2] == symbol && this->Field[4] == symbol && this->Field[6] == symbol))
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool TicTacToe::is_win()
{
    if ((this->is_horizontal_win('O') || this->is_horizontal_win('X')) || 
        (this->is_vertical_win('O') || this->is_vertical_win('X')) || 
        (this->is_diagonal_win('O') || this->is_diagonal_win('X')))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TicTacToe::is_tie()
{
    for (int i = 0; i < 9; i++)
    {
        if (this->Field[i] == '_')
        {
            return false;
        }

    }

    return true;
}

