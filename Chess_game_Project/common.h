#pragma once



class board_class;
class piece_class;
enum class type { pawn = 1, king = 2, queen = 3, bishop = 4, knight = 5, rook = 6, undefined = 7 };
enum class piece_colour { white = 1, black = 2, undefined = 3 };
piece_class* all_pieces[2][16];



struct block_address
{
	int x;
	int y;
	block_address()
	{
		x = 0, y = 0;
	}
	block_address(int a, int b)
	{
		x = a;
		y = b;
	}
	void set_address(int a, int b)
	{
		x = a;
		y = b;
	}
	block_address& operator=(block_address& address)
	{
		this->x = address.x;
		this->y = address.y;
		return *this;
	}
};


struct block : public block_address
{
	type p_type;
	piece_colour p_colour;
	piece_class* piece_ptr;
	block(int i, int j);
};


class board_class
{
public:
	block* b[8][8];
	board_class()
	{
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				b[i][j] = new block(i, j);
			}
		}
	}
	~board_class()
	{
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				delete b[i][j];
			}
		}
	}
};




