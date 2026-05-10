#include<iostream>
#include<SFML/Graphics.hpp>
#include"board.h"
#include"piece.h"
#include"pawn.h"
#include"knight.h"
#include"king.h"
#include"bishop.h"
#include"rook.h"
#include"queen.h"
#include"common.h"

using namespace std;
using namespace sf;





void display_winner_window(piece_colour loser_color, Font& font)
{
	RenderWindow winnerWindow(VideoMode({ 300, 400 }), "Game Over");
	string winnerStr = (loser_color == piece_colour::black) ? "White Wins!" : "Black Wins!";
	Texture win_t;
	if (loser_color == piece_colour::black)
	{
		win_t.loadFromFile("whitewin.PNG");
	}
	else
	{
		win_t.loadFromFile("blackwin.PNG");
	}
	Sprite winner(win_t);
	winner.setScale({ 0.35,0.35 });

	while (winnerWindow.isOpen())
	{
		while (const optional event = winnerWindow.pollEvent())
		{
			if (event->is<Event::Closed>())
			{
				winnerWindow.close();
			}
		}
		winnerWindow.clear(Color(40, 40, 40));
		winnerWindow.draw(winner);
		Text text(font);
		text.setString(winnerStr);
		text.setCharacterSize(40);
		text.setFillColor(Color::Yellow);
		FloatRect textBounds = text.getLocalBounds();
		text.setPosition({ 35.0f, 70.0f });



		winnerWindow.draw(text);
		winnerWindow.display();
	}
}



void display_stalemate_window(Font& font)
{
	RenderWindow stalemateWindow(VideoMode({ 300, 400 }), "Stalemate");
	Texture stalemate_t;
	stalemate_t.loadFromFile("stalemate.PNG");
	Sprite stalemateSprite(stalemate_t);
	stalemateSprite.setScale({ 1, 1 });

	while (stalemateWindow.isOpen())
	{
		while (const optional event = stalemateWindow.pollEvent())
		{
			if (event->is<Event::Closed>())
			{
				stalemateWindow.close();
			}
		}
		stalemateWindow.clear(Color(40, 40, 40));
		stalemateWindow.draw(stalemateSprite);
		Text text(font);
		text.setString("Stalemate!");
		text.setCharacterSize(40);
		text.setFillColor(Color::Yellow);
		text.setPosition({ 35.0f, 70.0f });
		stalemateWindow.draw(text);
		Text sub(font);
		sub.setString("It's a Draw!");
		sub.setCharacterSize(28);
		sub.setFillColor(Color::White);
		sub.setPosition({ 55.0f, 130.0f });
		stalemateWindow.draw(sub);
		stalemateWindow.display();
	}
}




void run_credits(Font& font)
{
	RenderWindow creditsWindow(VideoMode({ 800, 800 }), "Credits");
	while (creditsWindow.isOpen())
	{
		while (const optional event = creditsWindow.pollEvent())
		{
			if (event->is<Event::Closed>())
			{
				creditsWindow.close();
			}
		}
		creditsWindow.clear(Color(30, 30, 30));

		Texture credits_t;
		credits_t.loadFromFile("credits.PNG");
		Sprite credit(credits_t);
		credit.setScale({ 1.15,1.15 });
		creditsWindow.draw(credit);
		creditsWindow.display();
	}
}



void run_game(Font& font)
{

	Texture wp_t;
	wp_t.loadFromFile("whitepawn.png");
	Sprite wp(wp_t);
	if (wp_t.getSize().x > 0)
	{
		wp.setScale({ 100.f / wp_t.getSize().x, 100.f / wp_t.getSize().y });
	}
	Texture bp_t;
	bp_t.loadFromFile("blackpawn.png");
	Sprite bp(bp_t);
	if (bp_t.getSize().x > 0)
	{
		bp.setScale({ 100.f / bp_t.getSize().x, 100.f / bp_t.getSize().y });
	}
	Texture wking_t;
	wking_t.loadFromFile("whiteking.png");
	Sprite wking(wking_t);
	if (wking_t.getSize().x > 0)
	{
		wking.setScale({ 100.f / wking_t.getSize().x, 100.f / wking_t.getSize().y });
	}
	Texture bking_t;
	bking_t.loadFromFile("blackking.png");
	Sprite bking(bking_t);
	if (bking_t.getSize().x > 0)
	{
		bking.setScale({ 100.f / bking_t.getSize().x, 100.f / bking_t.getSize().y });
	}
	Texture wr_t;
	wr_t.loadFromFile("whiterook.png");
	Sprite wr(wr_t);
	if (wr_t.getSize().x > 0)
	{
		wr.setScale({ 100.f / wr_t.getSize().x, 100.f / wr_t.getSize().y });
	}
	Texture wn_t;
	wn_t.loadFromFile("whiteknight.png");
	Sprite wn(wn_t);
	if (wn_t.getSize().x > 0)
	{
		wn.setScale({ 100.f / wn_t.getSize().x, 100.f / wn_t.getSize().y });
	}
	Texture wb_t;
	wb_t.loadFromFile("whitebishop.png");
	Sprite wb(wb_t);
	if (wb_t.getSize().x > 0)
	{
		wb.setScale({ 100.f / wb_t.getSize().x, 100.f / wb_t.getSize().y });
	}
	Texture wq_t;
	wq_t.loadFromFile("whitequeen.png");
	Sprite wq(wq_t);
	if (wq_t.getSize().x > 0)
	{
		wq.setScale({ 100.f / wq_t.getSize().x, 100.f / wq_t.getSize().y });
	}
	Texture br_t;
	br_t.loadFromFile("blackrook.png");
	Sprite br(br_t);
	if (br_t.getSize().x > 0)
	{
		br.setScale({ 100.f / br_t.getSize().x, 100.f / br_t.getSize().y });
	}
	Texture bn_t;
	bn_t.loadFromFile("blackknight.png");
	Sprite bn(bn_t);
	if (bn_t.getSize().x > 0)
	{
		bn.setScale({ 100.f / bn_t.getSize().x, 100.f / bn_t.getSize().y });
	}
	Texture bb_t;
	bb_t.loadFromFile("blackbishop.png");
	Sprite bb(bb_t);
	if (bb_t.getSize().x > 0)
	{
		bb.setScale({ 100.f / bb_t.getSize().x, 100.f / bb_t.getSize().y });
	}
	Texture bq_t;
	bq_t.loadFromFile("blackqueen.png");
	Sprite bq(bq_t);
	if (bq_t.getSize().x > 0)
	{
		bq.setScale({ 100.f / bq_t.getSize().x, 100.f / bq_t.getSize().y });
	}
	RenderWindow window(VideoMode({ 800, 800 }), "Chess Board Debugger");
	board_class board;
	int turnno = 0;
	bool game_over = false;
	bool winner_displayed = false;
	bool stalemate_detected = false;
	bool stalemate_displayed = false;
	int box_size = 100;
	int selected_x = -1, selected_y = -1;
	block_address* move_hints = nullptr;
	int move_hint_count = 0;

	while (window.isOpen())
	{
		const bool white_turn = (turnno % 2 == 0);
		piece_colour current_turn = white_turn ? piece_colour::white : piece_colour::black;
		int side = white_turn ? 0 : 1;
		piece_class* king_ptr = all_pieces[side][12];
		int kx = king_ptr->get_x();
		int ky = king_ptr->get_y();
		bool in_check = is_square_attacked(kx, ky, current_turn, board);

		while (const auto event = window.pollEvent())
		{
			if (event->is<Event::Closed>())
			{
				window.close();
			}
			else if (const auto* mouse_pressed = event->getIf<Event::MouseButtonPressed>())
			{
				if (mouse_pressed->button == Mouse::Button::Left)
				{
					int y = mouse_pressed->position.x / box_size;
					int x = mouse_pressed->position.y / box_size;

					if (selected_x == -1 && selected_y == -1)
					{
						block* clicked = board.b[x][y];
						bool can_pick = ((!game_over) && (clicked->piece_ptr != nullptr) && (clicked->p_colour == current_turn));
						if (in_check && clicked->p_type != type::king)
						{
							can_pick = false;
						}

						if (can_pick)
						{
							selected_x = x; selected_y = y;
							move_hints = clicked->piece_ptr->find_all_movements(board, move_hint_count);
						}
					}
					else
					{
						block* from = board.b[selected_x][selected_y];
						block* to = board.b[x][y];
						if (from->piece_ptr && from->piece_ptr->valid_move(x, y, board))
						{
							if (!(from->p_type == type::king && is_square_attacked(x, y, from->p_colour, board)))
							{
								from->piece_ptr->movement(x, y, board);
								to->piece_ptr = from->piece_ptr;
								to->p_type = from->p_type;
								to->p_colour = from->p_colour;
								from->piece_ptr = nullptr;
								from->p_type = type::undefined;
								from->p_colour = piece_colour::undefined;
								turnno++;

								piece_colour next_turn = (turnno % 2 == 0) ? piece_colour::white : piece_colour::black;
								if (is_checkmate(next_turn, board))
								{
									game_over = true;
								}
								else if (stalemate(next_turn, board))
								{
									game_over = true;
									stalemate_detected = true;
								}
							}
						}
						delete[] move_hints; move_hints = nullptr; move_hint_count = 0;
						selected_x = -1; selected_y = -1;
					}
				}
			}
		}

		if (game_over && !winner_displayed && !stalemate_detected)
		{
			winner_displayed = true;
			display_winner_window((turnno % 2 == 0) ? piece_colour::white : piece_colour::black, font);
		}
		if (game_over && stalemate_detected && !stalemate_displayed)
		{
			stalemate_displayed = true;
			display_stalemate_window(font);
		}

		window.clear();
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				RectangleShape rect({ (float)box_size, (float)box_size });
				rect.setPosition({ (float)(j * box_size), (float)(i * box_size) });
				if ((i + j) % 2 == 0)
				{
					rect.setFillColor(Color(61, 105, 58));
				}
				else
				{
					rect.setFillColor(Color(205, 255, 201));
				}

				if (in_check && i == kx && j == ky)
				{
					rect.setFillColor(Color::Red);
				}
				rect.setOutlineThickness(1);
				rect.setOutlineColor(Color(205, 255, 201));
				window.draw(rect);
				if (selected_x >= 0 && move_hints != nullptr)
				{
					for (int h = 0; h < move_hint_count; h++)
					{
						if (move_hints[h].x == i && move_hints[h].y == j)
						{
							piece_class* sel_piece = board.b[selected_x][selected_y]->piece_ptr;
							block* dest = board.b[i][j];
							block* from_sq = board.b[selected_x][selected_y];
							bool is_move_valid = sel_piece != nullptr && sel_piece->valid_move(i, j, board);
							if (is_move_valid && from_sq->p_type == type::king && is_square_attacked(i, j, from_sq->p_colour, board))
							{
								is_move_valid = false;
							}
							if (is_move_valid)
							{
								if (dest->piece_ptr != nullptr && dest->p_colour != piece_colour::undefined && dest->p_colour != from_sq->p_colour)
								{
									rect.setFillColor(Color(220, 60, 60));
								}
								else
								{
									rect.setFillColor(Color(135, 206, 235));
								}
								window.draw(rect);
							}
						}
					}
				}
				if (selected_x == i && selected_y == j)
				{
					RectangleShape sel({ (float)box_size, (float)box_size });
					sel.setPosition({ (float)(j * box_size), (float)(i * box_size) });
					sel.setFillColor(Color::Transparent);
					sel.setOutlineThickness(-5);
					sel.setOutlineColor(Color::Red);
					window.draw(sel);
				}
				if (board.b[i][j]->p_type != type::undefined)
				{
					if (board.b[i][j]->p_colour == piece_colour::white)
					{
						if (board.b[i][j]->p_type == type::pawn)
						{
							wp.setPosition({ (float)j * 100, (float)i * 100 });
							window.draw(wp);
						}
						else if (board.b[i][j]->p_type == type::rook)
						{
							wr.setPosition({ (float)j * 100, (float)i * 100 });
							window.draw(wr);
						}
						else if (board.b[i][j]->p_type == type::knight)
						{
							wn.setPosition({ (float)j * 100, (float)i * 100 });
							window.draw(wn);
						}
						else if (board.b[i][j]->p_type == type::bishop)
						{
							wb.setPosition({ (float)j * 100, (float)i * 100 });
							window.draw(wb);
						}
						else if (board.b[i][j]->p_type == type::queen)
						{
							wq.setPosition({ (float)j * 100, (float)i * 100 });
							window.draw(wq);
						}
						else if (board.b[i][j]->p_type == type::king)
						{
							wking.setPosition({ (float)j * 100, (float)i * 100 });
							window.draw(wking);
						}
					}
					else
					{
						if (board.b[i][j]->p_type == type::pawn)
						{
							bp.setPosition({ (float)j * 100, (float)i * 100 });
							window.draw(bp);
						}
						else if (board.b[i][j]->p_type == type::rook)
						{
							br.setPosition({ (float)j * 100, (float)i * 100 });
							window.draw(br);
						}
						else if (board.b[i][j]->p_type == type::knight)
						{
							bn.setPosition({ (float)j * 100, (float)i * 100 });
							window.draw(bn);
						}
						else if (board.b[i][j]->p_type == type::bishop)
						{
							bb.setPosition({ (float)j * 100, (float)i * 100 });
							window.draw(bb);
						}
						else if (board.b[i][j]->p_type == type::queen)
						{
							bq.setPosition({ (float)j * 100, (float)i * 100 });
							window.draw(bq);
						}
						else if (board.b[i][j]->p_type == type::king)
						{
							bking.setPosition({ (float)j * 100, (float)i * 100 });
							window.draw(bking);
						}
					}
				}
			}
		}
		window.display();
	}
	delete[] move_hints;
}



int main()
{
	Font font;
	font.openFromFile("C:/Windows/Fonts/stencil.ttf");
	Texture background;
	background.loadFromFile("chess3.PNG");
	Sprite back(background);
	back.setScale({ 1,1 });
	while (true)
	{
		RenderWindow menu(VideoMode({ 800, 800 }), "Main Menu");
		RectangleShape b1({ 300, 80 }), b2({ 300, 80 }), b3({ 300, 80 });


		b1.setPosition({ 250, 250 });
		b1.setFillColor(Color(61, 105, 58));


		b2.setPosition({ 250, 380 });
		b2.setFillColor(Color(61, 105, 58));


		b3.setPosition({ 250, 510 });
		b3.setFillColor(Color(220, 60, 60));


		int action = 0;
		while (menu.isOpen())
		{
			while (const optional event = menu.pollEvent())
			{
				if (event->is<Event::Closed>())
				{
					return 0;
				}
				if (const auto* ms = event->getIf<Event::MouseButtonPressed>())
				{
					Vector2f pos = (Vector2f)ms->position;
					if (b1.getGlobalBounds().contains(pos))
					{
						action = 1; menu.close();
					}
					else if (b2.getGlobalBounds().contains(pos))
					{
						action = 2; menu.close();
					}
					else if (b3.getGlobalBounds().contains(pos))
					{
						return 0;
					}
				}
			}



			menu.clear(Color(30, 30, 30));
			menu.draw(back);
			menu.draw(b1);
			menu.draw(b2);
			menu.draw(b3);



			Text t(font); t.setString("Firefly Chess");
			t.setFillColor(Color::Black);
			t.setCharacterSize(80);
			t.setPosition({ 110, 80 });
			menu.draw(t);
			Text t1(font); t1.setString("PLAY");
			t1.setCharacterSize(35);
			t1.setPosition({ 350, 265 });
			menu.draw(t1);
			Text t2(font); t2.setString("CREDITS");
			t2.setCharacterSize(35);
			t2.setPosition({ 325, 395 });
			menu.draw(t2);
			Text t3(font);
			t3.setString("EXIT");
			t3.setCharacterSize(35);
			t3.setPosition({ 355, 525 });
			menu.draw(t3);





			menu.display();
		}
		if (action == 1)
		{
			run_game(font);
		}
		else if (action == 2)
		{
			run_credits(font);
		}
	}
	return 0;
}