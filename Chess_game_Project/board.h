#pragma once
#include <iostream>
#include "common.h"
#include "piece.h"
#include "pawn.h"
#include "knight.h"
#include "king.h"
#include "bishop.h"
#include "rook.h"
#include "queen.h"

using namespace std;

block::block(int i, int j) : block_address(i, j)
{
	piece_ptr = nullptr;
	if (i < 2)
	{
		p_colour = piece_colour::black;
		if (i == 1)
		{
			p_type = type::pawn;
		}
		else if (j == 0 || j == 7)
		{
			p_type = type::rook;
		}
		else if (j == 1 || j == 6)
		{
			p_type = type::knight;
		}
		else if (j == 2 || j == 5)
		{
			p_type = type::bishop;
		}
		else if (j == 3)
		{
			p_type = type::queen;
		}
		else if (j == 4)
		{
			p_type = type::king;
		}
		else
		{
			p_type = type::undefined;
		}
	}
	else if (i >= 6)
	{
		p_colour = piece_colour::white;
		if (i == 6)
		{
			p_type = type::pawn;
		}
		else if (j == 0 || j == 7)
		{
			p_type = type::rook;
		}
		else if (j == 1 || j == 6)
		{
			p_type = type::knight;
		}
		else if (j == 2 || j == 5)
		{
			p_type = type::bishop;
		}
		else if (j == 3)
		{
			p_type = type::queen;
		}
		else if (j == 4)
		{
			p_type = type::king;
		}
		else
		{
			p_type = type::undefined;
		}
	}
	else
	{
		p_colour = piece_colour::undefined;
		p_type = type::undefined;
	}
	int side = (p_colour == piece_colour::white) ? 0 : 1;
	int color_val = (p_colour == piece_colour::white) ? 1 : 0;
	if (p_type != type::undefined)
	{
		if (p_type == type::pawn)
		{
			piece_ptr = new pawn(i, j, color_val);
		}
		else if (p_type == type::rook)
		{
			piece_ptr = new rook(i, j, color_val);
		}
		else if (p_type == type::knight)
		{
			piece_ptr = new knight(i, j, color_val);
		}
		else if (p_type == type::bishop)
		{
			piece_ptr = new bishop(i, j, color_val);
		}
		else if (p_type == type::queen)
		{
			piece_ptr = new queen(i, j, color_val);
		}
		else if (p_type == type::king)
		{
			piece_ptr = new king(i, j, color_val);
		}
		if (i == 1 || i == 6)
		{
			all_pieces[side][j] = piece_ptr;
		}
		else
		{
			all_pieces[side][8 + j] = piece_ptr;
		}
	}
}