#pragma once
#include<iostream>
#include"piece.h"
#include"board.h"
#include"common.h"
using namespace std;

class king : public piece_class
{
public:
	king(int a, int b, int color_val) : piece_class(a, b, color_val) {}
	void movement(int m, int n, board_class& board) override
	{
		if (valid_move(m, n, board))
		{
			pos_of_block.x = m;
			pos_of_block.y = n;
			turns++;
		}
	}
	bool valid_move(int m, int n, board_class& b_ref) override
	{
		int x = pos_of_block.x;
		int y = pos_of_block.y;
		if ((m == x + 1 && n == y) || (m == x - 1 && n == y) || (m == x && n == y + 1) || (m == x && n == y - 1) || (m == x + 1 && n == y + 1) || (m == x + 1 && n == y - 1) || (m == x - 1 && n == y + 1) || (m == x - 1 && n == y - 1) && (b_ref.b[m][n]->p_colour != c))
		{
			if (b_ref.b[m][n]->p_colour != c)
			{
				return true;
			}
			return false;
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

bool is_square_attacked(int target_x, int target_y, piece_colour defender_color, board_class& board)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			block* sq = board.b[i][j];
			if (sq->piece_ptr != nullptr && sq->p_colour != piece_colour::undefined && sq->p_colour != defender_color)
			{
				if (sq->piece_ptr->valid_move(target_x, target_y, board))
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool is_checkmate(piece_colour turn_color, board_class& board)
{
	int side = (turn_color == piece_colour::white) ? 0 : 1;
	piece_class* king_ptr = all_pieces[side][12];
	int king_x = king_ptr->get_x();
	int king_y = king_ptr->get_y();

	if (!is_square_attacked(king_x, king_y, turn_color, board))
	{
		return false;
	}

	int move_count = 0;
	block_address* escape_moves = king_ptr->find_all_movements(board, move_count);
	bool can_escape = false;
	for (int i = 0; i < move_count; i++)
	{
		if (!is_square_attacked(escape_moves[i].x, escape_moves[i].y, turn_color, board))
		{
			can_escape = true;
			break;
		}
	}
	delete[] escape_moves;
	return !can_escape;
}
bool stalemate(piece_colour turn_color, board_class& board)
{
	int side = (turn_color == piece_colour::white) ? 0 : 1;
	piece_class* king_ptr = all_pieces[side][12];
	int king_x = king_ptr->get_x();
	int king_y = king_ptr->get_y();

	if (is_square_attacked(king_x, king_y, turn_color, board))
	{
		return false;
	}

	for (int p = 0; p < 16; p++)
	{
		piece_class* piece_ptr = all_pieces[side][p];
		if (piece_ptr == nullptr || board.b[piece_ptr->get_x()][piece_ptr->get_y()]->piece_ptr != piece_ptr)
		{
			continue;
		}
		int move_count = 0;
		block_address* moves = piece_ptr->find_all_movements(board, move_count);
		if (moves != nullptr && move_count > 0)
		{
			for (int i = 0; i < move_count; i++)
			{
				if (!(board.b[piece_ptr->get_x()][piece_ptr->get_y()]->p_type == type::king && is_square_attacked(moves[i].x, moves[i].y, turn_color, board)))
				{
					delete[] moves;
					return false;
				}
			}
		}
		delete[] moves;
	}
	return true;
}

