#pragma once
#include<iostream>
#include"piece.h"
#include"board.h"
#include"common.h"
using namespace std;

class queen : public piece_class
{
public:
	queen(int a, int b, int color_val) : piece_class(a, b, color_val) {}
	void movement(int m, int n, board_class& b_ref) override
	{
		if (valid_move(m, n, b_ref))
		{
			pos_of_block.x = m;
			pos_of_block.y = n;
			turns++;
		}
	}
	bool valid_move(int m, int n, board_class& b_ref) override
	{
		if (m == pos_of_block.x && n < pos_of_block.y)
		{
			int temp_y = pos_of_block.y - 1;
			while (temp_y > n)
			{
				if (b_ref.b[m][temp_y]->p_type != type::undefined)
				{
					return false;
				}
				temp_y--;
			}
		}
		else if (m == pos_of_block.x && n > pos_of_block.y)
		{
			int temp_y = pos_of_block.y + 1;
			while (temp_y < n)
			{
				if (b_ref.b[m][temp_y]->p_type != type::undefined)
				{
					return false;
				}
				temp_y++;
			}
		}
		else if (m < pos_of_block.x && n == pos_of_block.y)
		{
			int temp_x = pos_of_block.x - 1;
			while (temp_x > m)
			{
				if (b_ref.b[temp_x][n]->p_type != type::undefined)
				{
					return false;
				}
				temp_x--;
			}
		}
		else if (m > pos_of_block.x && n == pos_of_block.y)
		{
			int temp_x = pos_of_block.x + 1;
			while (temp_x < m)
			{
				if (b_ref.b[temp_x][n]->p_type != type::undefined)
				{
					return false;
				}
				temp_x++;
			}
		}
		else if (m < pos_of_block.x && n > pos_of_block.y)
		{
			int temp_x = pos_of_block.x - 1;
			int temp_y = pos_of_block.y + 1;
			while (temp_x > m && temp_y < n)
			{
				if (b_ref.b[temp_x][temp_y]->p_type != type::undefined)
				{
					return false;
				}
				temp_x--;
				temp_y++;
			}
			if (temp_x != m || temp_y != n)
			{
				return false;
			}
		}
		else if (m > pos_of_block.x && n > pos_of_block.y)
		{
			int temp_x = pos_of_block.x + 1;
			int temp_y = pos_of_block.y + 1;
			while (temp_x < m && temp_y < n)
			{
				if (b_ref.b[temp_x][temp_y]->p_type != type::undefined)
				{
					return false;
				}
				temp_x++;
				temp_y++;
			}
			if (temp_x != m || temp_y != n)
			{
				return false;
			}
		}
		else if (m < pos_of_block.x && n < pos_of_block.y)
		{
			int temp_x = pos_of_block.x - 1;
			int temp_y = pos_of_block.y - 1;
			while (temp_x > m && temp_y > n)
			{
				if (b_ref.b[temp_x][temp_y]->p_type != type::undefined)
				{
					return false;
				}
				temp_x--;
				temp_y--;
			}
			if (temp_x != m || temp_y != n)
			{
				return false;
			}
		}
		else if (m > pos_of_block.x && n < pos_of_block.y)
		{
			int temp_x = pos_of_block.x + 1;
			int temp_y = pos_of_block.y - 1;
			while (temp_x < m && temp_y > n)
			{
				if (b_ref.b[temp_x][temp_y]->p_type != type::undefined)
				{
					return false;
				}
				temp_x++;
				temp_y--;
			}
			if (temp_x != m || temp_y != n)
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		if (b_ref.b[m][n]->p_colour == c)
		{
			return false;
		}
		return true;
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