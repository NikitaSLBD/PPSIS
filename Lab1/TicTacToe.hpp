#pragma once 

using namespace std;

class TicTacToe
{
    private:
        char Field[10];
        bool player;
        unsigned int empties;

        void set_content(unsigned int);
        bool is_horizontal_win(char symbol);
        bool is_vertical_win(char symbol);
        bool is_diagonal_win(char symbol);
        void decrement_empties();

    public:
        TicTacToe(): Field("_________"), player(true), empties(9) {};
        char get_content(unsigned int);
        bool get_player();
        void switch_player();
        void operator [] (unsigned int);
        bool is_win();
        bool is_dry(); 
};