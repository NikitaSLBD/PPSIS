#include "TicTacToe.hpp"

char TicTacToe::get_content(unsigned int index)
{    
        return this->Field[index];
}

bool TicTacToe::get_player()
{
    return this->player;
}

void TicTacToe::decrement_empties()
{
    this->empties--;
}

void TicTacToe::switch_player()
{
    this->player = !this->player;
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

    this->decrement_empties();
}

void TicTacToe::operator [] (unsigned int index)
{

    try
    {
        if (this->Field[index] == '_')
        {
            this->set_content(index);
        }
        else
        {
            this->switch_player();
        }
    }
    catch (...)
    {
        throw "Index out of range";
    }
}

bool TicTacToe::is_horizontal_win(char symbol)
{
    return ((this->Field[0] == symbol && this->Field[1] == symbol && this->Field[2] == symbol) ||
            (this->Field[3] == symbol && this->Field[4] == symbol && this->Field[5] == symbol) ||
            (this->Field[6] == symbol && this->Field[7] == symbol && this->Field[8] == symbol));
}

bool TicTacToe::is_vertical_win(char symbol)
{
    return ((this->Field[0] == symbol && this->Field[3] == symbol && this->Field[6] == symbol) ||
            (this->Field[1] == symbol && this->Field[4] == symbol && this->Field[7] == symbol) ||
            (this->Field[2] == symbol && this->Field[5] == symbol && this->Field[8] == symbol));
}

bool TicTacToe::is_diagonal_win(char symbol)
{
    return ((this->Field[0] == symbol && this->Field[4] == symbol && this->Field[8] == symbol) ||
            (this->Field[2] == symbol && this->Field[4] == symbol && this->Field[6] == symbol));
}


bool TicTacToe::is_win()
{
    return ((this->is_horizontal_win('O') || this->is_horizontal_win('X')) ||
            (this->is_vertical_win('O') || this->is_vertical_win('X')) ||
            (this->is_diagonal_win('O') || this->is_diagonal_win('X')));
}

bool TicTacToe::is_dry()
{
    return !this->empties && !this->is_win();
}

