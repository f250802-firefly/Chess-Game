#pragma once
#include<iostream>
#include"common.h"
#include"board.h"
using namespace std;



class piece_class
{
protected:

	int turns;
	bool alive;
	block_address pos_of_block;
	piece_colour c;
public:
	piece_class(int a, int b, int color_val) : pos_of_block(a, b), alive(true), turns(0)
	{
		if (color_val == 1)
		{
			c = piece_colour::white;
		}
		else
		{
			c = piece_colour::black;
		}
	}
	virtual ~piece_class() = default;
	virtual void movement(int m, int n, board_class& b_ref) = 0;
	virtual bool valid_move(int m, int n, board_class& b_ref) = 0;
	virtual block_address* find_all_movements(board_class& board, int& out_count) = 0;
	void set_turns(int x)
	{
		turns = x;
	}
	int get_turns()
	{
		return turns;
	}
	int get_x()
	{
		return pos_of_block.x;
	}
	int get_y()
	{
		return pos_of_block.y;
	}
};