#pragma once
#include<iostream>
#include"piece.h"
#include"board.h"
#include"common.h"
using namespace std;

class pawn : public piece_class
{
public:
	pawn(int a, int b, int color_val) : piece_class(a, b, color_val) {}
	bool square_empty(board_class& board, int i, int j)
	{
		return board.b[i][j]->piece_ptr == nullptr;
	}
	bool square_has_enemy_piece(board_class& board, int i, int j, piece_colour my_colour)
	{
		block* sq = board.b[i][j];
		if (sq->piece_ptr == nullptr)
		{
			return false;
		}
		return sq->p_colour != my_colour && sq->p_colour != piece_colour::undefined;
	}
	void movement(int m, int n, board_class& board) override
	{
		if (valid_move(m, n, board))
		{
			pos_of_block.x = m;
			pos_of_block.y = n;
			turns++;
		}
	}
	bool valid_move(int m, int n, board_class& board) override
	{
		const int x = pos_of_block.x;
		const int y = pos_of_block.y;
		if (m < 0 || m > 7 || n < 0 || n > 7)
		{
			return false;
		}
		if (c == piece_colour::white)
		{
			if (n == y && m == x - 1 && square_empty(board, m, n))
			{
				return true;
			}
			if (turns == 0 && n == y && m == x - 2 && square_empty(board, x - 1, y) && square_empty(board, m, n))
			{
				return true;
			}
			if (m == x - 1 && (n == y - 1 || n == y + 1) && square_has_enemy_piece(board, m, n, c))
			{
				return true;
			}
			return false;
		}
		if (c == piece_colour::black)
		{
			if (n == y && m == x + 1 && square_empty(board, m, n))
			{
				return true;
			}
			if (turns == 0 && n == y && m == x + 2 && square_empty(board, x + 1, y) && square_empty(board, m, n))
			{
				return true;
			}
			if (m == x + 1 && (n == y - 1 || n == y + 1) && square_has_enemy_piece(board, m, n, c))
			{
				return true;
			}
			return false;
		}
		return false;
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