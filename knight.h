#pragma once
#include<iostream>
#include"piece.h"
#include"board.h"
#include"common.h"
using namespace std;

class knight :public piece_class
{
public:
	knight(int a, int b, int colour_var) :piece_class(a, b, colour_var) {}
	void movement(int x, int y, board_class& board)override
	{
		if (valid_move(x, y, board))
		{
			pos_of_block.x = x;
			pos_of_block.y = y;
			turns++;
		}
	}
	bool valid_move(int x, int y, board_class& board)override
	{
		if ((((x == pos_of_block.x + 1 || x == pos_of_block.x - 1) && (y == pos_of_block.y + 2 || y == pos_of_block.y - 2)) || ((x == pos_of_block.x + 2 || x == pos_of_block.x - 2) && (y == pos_of_block.y + 1 || y == pos_of_block.y - 1))) && (board.b[x][y]->p_colour != c))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	block_address* find_all_movements(board_class& board, int& out_count)override
	{
		block_address* bptr = nullptr;
		int size = 0;
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (valid_move(i, j, board))
				{
					size++;
					block_address* ptr = new block_address[size];
					for (int k = 0; k < size - 1; ++k)
					{
						ptr[k] = bptr[k];
					}
					ptr[size - 1].set_address(i, j);
					delete[] bptr;
					bptr = ptr;
				}
			}
		}
		out_count = size;
		return bptr;
	}
};