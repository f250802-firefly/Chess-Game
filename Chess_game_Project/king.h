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

bool is_move_legal(int start_x, int start_y, int end_x, int end_y, board_class& board)
{
	block* from_sq = board.b[start_x][start_y];
	block* to_sq = board.b[end_x][end_y];
	piece_class* piece_ptr = from_sq->piece_ptr;

	if (piece_ptr == nullptr || !piece_ptr->valid_move(end_x, end_y, board))
	{
		return false;
	}

	piece_colour turn_color = from_sq->p_colour;
	int side = (turn_color == piece_colour::white) ? 0 : 1;
	piece_class* king_ptr = all_pieces[side][12];

	piece_class* captured_piece = to_sq->piece_ptr;
	type captured_type = to_sq->p_type;
	piece_colour captured_colour = to_sq->p_colour;

	to_sq->piece_ptr = piece_ptr;
	to_sq->p_type = from_sq->p_type;
	to_sq->p_colour = from_sq->p_colour;
	piece_ptr->set_x(end_x);
	piece_ptr->set_y(end_y);
	from_sq->piece_ptr = nullptr;
	from_sq->p_type = type::undefined;
	from_sq->p_colour = piece_colour::undefined;

	int cur_king_x = king_ptr->get_x();
	int cur_king_y = king_ptr->get_y();
	bool still_in_check = is_square_attacked(cur_king_x, cur_king_y, turn_color, board);

	from_sq->piece_ptr = piece_ptr;
	from_sq->p_type = to_sq->p_type;
	from_sq->p_colour = to_sq->p_colour;
	piece_ptr->set_x(start_x);
	piece_ptr->set_y(start_y);
	to_sq->piece_ptr = captured_piece;
	to_sq->p_type = captured_type;
	to_sq->p_colour = captured_colour;

	return !still_in_check;
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
				if (is_move_legal(piece_ptr->get_x(), piece_ptr->get_y(), moves[i].x, moves[i].y, board))
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
				if (is_move_legal(piece_ptr->get_x(), piece_ptr->get_y(), moves[i].x, moves[i].y, board))
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

