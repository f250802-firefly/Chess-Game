#pragma once
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
#include"functions.h"


using namespace sf;


Color dark_block(0, 106, 183);
Color light_block(255, 247, 210);
Color enemy_colour(220, 60, 60);
Color step_colour(248, 220, 96);
Color current_step_color(106, 214, 44);
Color Dark_teal(0, 33, 43);


void run_theme(Font& font3, Font& font2)
{
	Font font("C:/Windows/Fonts/times.ttf");
	Texture theme_t;
	theme_t.loadFromFile("theme.png");
	Sprite theme(theme_t);
	theme.setScale({ 1.05,1.1 });
	RenderWindow theme_window(VideoMode({ 900, 900 }), "Themes Window", (Style::Titlebar | Style::Close));
	while (theme_window.isOpen())
	{
		while (const optional event = theme_window.pollEvent())
		{
			if (event->is<Event::Closed>())
			{
				theme_window.close();
			}
			theme_window.clear(Color(0, 44, 57));
			theme_window.draw(theme);
			Text t1(font2);
			t1.setString("Choose Theme");
			t1.setCharacterSize(150);
			t1.setFillColor(Color::Black);
			FloatRect title = t1.getLocalBounds();
			t1.setOrigin({title.position.x + title.size.x / 2.f,title.position.y + title.size.y / 2.f});
			t1.setPosition({ 450,110 });
			theme_window.draw(t1);


			RectangleShape rec1({ 320,90 });
			rec1.setFillColor(Dark_teal);
			rec1.setPosition({ 290,230 });
			theme_window.draw(rec1);
			RectangleShape rec2({ 320,90 });
			rec2.setFillColor(Dark_teal);
			rec2.setPosition({ 290,355 });
			theme_window.draw(rec2);
			RectangleShape rec3({ 320,90 });
			rec3.setFillColor(Dark_teal);
			rec3.setPosition({ 290,480 });
			theme_window.draw(rec3);
			RectangleShape rec4({ 320,90 });
			rec4.setFillColor(Dark_teal);
			rec4.setPosition({ 290,605 });
			theme_window.draw(rec4);
			RectangleShape rec5({ 320,90 });
			rec5.setFillColor(Dark_teal);
			rec5.setPosition({ 290,730 });
			theme_window.draw(rec5);



			t1.setFont(font);
			t1.setCharacterSize(65);
			t1.setFillColor(Color::White);
			t1.setString("Green");
			FloatRect txt = t1.getLocalBounds();
			t1.setOrigin({txt.position.x + txt.size.x / 2.f,txt.position.y + txt.size.y / 2.f});
			t1.setPosition({ 450,275 });
			theme_window.draw(t1);
			t1.setString("Blue");
			txt = t1.getLocalBounds();
			t1.setOrigin({txt.position.x + txt.size.x / 2.f,txt.position.y + txt.size.y / 2.f});
			t1.setPosition({ 450,400 });
			theme_window.draw(t1);
			t1.setString("Red");
			txt = t1.getLocalBounds();
			t1.setOrigin({txt.position.x + txt.size.x / 2.f,txt.position.y + txt.size.y / 2.f});
			t1.setPosition({ 450,525 });
			theme_window.draw(t1);
			t1.setString("Pink");
			txt = t1.getLocalBounds();
			t1.setOrigin({	txt.position.x + txt.size.x / 2.f,txt.position.y + txt.size.y / 2.f});
			t1.setPosition({ 450,650 });
			theme_window.draw(t1);
			t1.setString("Dark");
			txt = t1.getLocalBounds();
			t1.setOrigin({txt.position.x + txt.size.x / 2.f,txt.position.y + txt.size.y / 2.f});
			t1.setPosition({ 450,775 });
			theme_window.draw(t1);
			theme_window.display();



			if (const auto* ms = event->getIf<Event::MouseButtonPressed>())
			{
				Vector2f pos = (Vector2f)ms->position;
				if (rec1.getGlobalBounds().contains(pos))
				{
					dark_block = Color(61, 105, 58);
					light_block = Color(205, 255, 201);
					enemy_colour = Color(220, 60, 60);
					step_colour = Color(135, 206, 235);
					current_step_color = Color(96, 95, 161);
					theme_window.close();
					return;
				}
				else if (rec2.getGlobalBounds().contains(pos))
				{
					dark_block = Color(0, 106, 183);
					light_block = Color(255, 247, 210);
					enemy_colour = Color(220, 60, 60);
					step_colour = Color(248, 220, 96);
					current_step_color = Color(106, 214, 44);
					theme_window.close();
					return;
				}
				else if (rec3.getGlobalBounds().contains(pos))
				{
					dark_block = Color(150, 59, 36);
					light_block = Color(237, 165, 147);
					enemy_colour = Color(131, 80, 242);
					step_colour = Color(245, 234, 120);
					current_step_color = Color(149, 237, 147);
					theme_window.close();
					return;
				}
				else if (rec4.getGlobalBounds().contains(pos))
				{
					dark_block = Color(146, 15, 107);
					light_block = Color(226, 190, 215);
					enemy_colour = Color(131, 80, 242);
					step_colour = Color(245, 234, 120);
					current_step_color = Color(149, 237, 147);
					theme_window.close();
					return;
				}
				else if (rec5.getGlobalBounds().contains(pos))
				{
					dark_block = Color(59, 53, 47);
					light_block = Color(186, 163, 140);
					enemy_colour = Color(131, 80, 242);
					step_colour = Color(245, 234, 120);
					current_step_color = Color(149, 237, 147);
					theme_window.close();
					return;
				}
			}

		}
	}
}



void display_winner_window(piece_colour loser_color, Font& font)
{
	RenderWindow winnerWindow(VideoMode({ 400, 500 }), "Game Over",Style::Close);
	string winnerStr = (loser_color == piece_colour::black) ? "White Won!!" : "Black Won!!";
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
	winner.setScale({ 0.45,0.45 });

	while (winnerWindow.isOpen())
	{
		while (const optional event = winnerWindow.pollEvent())
		{
			if (event->is<Event::Closed>())
			{
				winnerWindow.close();
			}
		}
		winnerWindow.clear(Color::White);
		winnerWindow.draw(winner);

		Text text(font);
		text.setString(winnerStr);
		text.setCharacterSize(55);
		text.setFillColor(Color::White);
		FloatRect textBounds = text.getLocalBounds();
		text.setPosition({ 55, 70 });



		winnerWindow.draw(text);
		winnerWindow.display();
	}
}



void display_stalemate_window(Font& font)
{
	RenderWindow stalemate_window(VideoMode({ 400, 500 }), "Stalemate",Style::Close);
	Texture stalemate_t;
	stalemate_t.loadFromFile("stalemate.PNG");
	Sprite stalemate_s(stalemate_t);
	if (stalemate_t.getSize().x > 0 && stalemate_t.getSize().y > 0)
	{
		stalemate_s.setScale({ 400.f / stalemate_t.getSize().x, 500.f / stalemate_t.getSize().y });
	}

	while (stalemate_window.isOpen())
	{
		while (const optional event = stalemate_window.pollEvent())
		{
			if (event->is<Event::Closed>())
			{
				stalemate_window.close();
			}
		}
		stalemate_window.clear(Dark_teal);
		stalemate_window.draw(stalemate_s);

		Text text(font);
		text.setString("Stalemate!");
		text.setCharacterSize(55);
		text.setFillColor(Color::Yellow);
		text.setOutlineColor(Color::Black);
		text.setOutlineThickness(3);
		text.setPosition({ 75.0f, 60.0f });
		stalemate_window.draw(text);

		Text sub(font);
		sub.setString("It's a Draw!");
		sub.setCharacterSize(40);
		sub.setFillColor(Color::White);
		sub.setOutlineColor(Color::Black);
		sub.setOutlineThickness(3);
		sub.setPosition({ 95.0f, 130.0f });
		stalemate_window.draw(sub);

		stalemate_window.display();
	}
}



type display_promotion_window(piece_colour pawn_color, Font& font)
{
	RenderWindow prom_win(VideoMode({ 500, 180 }), "Pawn Promotion",Style::None);

	Color grey_box(200, 200, 200);

	RectangleShape b_queen({ 100, 100 }), b_rook({ 100, 100 }), b_bishop({ 100, 100 }), b_knight({ 100, 100 });
	b_queen.setPosition({ 20, 50 });
	b_rook.setPosition({ 140, 50 });
	b_bishop.setPosition({ 260, 50 });
	b_knight.setPosition({ 380, 50 });

	b_queen.setFillColor(grey_box);
	b_rook.setFillColor(grey_box);
	b_bishop.setFillColor(grey_box);
	b_knight.setFillColor(grey_box);

	Texture t_queen, t_rook, t_bishop, t_knight;
	if (pawn_color == piece_colour::white)
	{
		t_queen.loadFromFile("whitequeen.png");
		t_rook.loadFromFile("whiterook.png");
		t_bishop.loadFromFile("whitebishop.png");
		t_knight.loadFromFile("whiteknight.png");
	}
	else
	{
		t_queen.loadFromFile("blackqueen.png");
		t_rook.loadFromFile("blackrook.png");
		t_bishop.loadFromFile("blackbishop.png");
		t_knight.loadFromFile("blackknight.png");
	}

	Sprite s_queen(t_queen), s_rook(t_rook), s_bishop(t_bishop), s_knight(t_knight);

	if (t_queen.getSize().x > 0) s_queen.setScale({ 100.f / t_queen.getSize().x, 100.f / t_queen.getSize().y });
	if (t_rook.getSize().x > 0) s_rook.setScale({ 100.f / t_rook.getSize().x, 100.f / t_rook.getSize().y });
	if (t_bishop.getSize().x > 0) s_bishop.setScale({ 100.f / t_bishop.getSize().x, 100.f / t_bishop.getSize().y });
	if (t_knight.getSize().x > 0) s_knight.setScale({ 100.f / t_knight.getSize().x, 100.f / t_knight.getSize().y });

	s_queen.setPosition({ 20, 50 });
	s_rook.setPosition({ 140, 50 });
	s_bishop.setPosition({ 260, 50 });
	s_knight.setPosition({ 380, 50 });

	type selected_type = type::queen;
	while (prom_win.isOpen())
	{
		while (const optional event = prom_win.pollEvent())
		{
			if (event->is<Event::Closed>())
			{
				prom_win.close();
			}
			else if (const auto* mouse_pressed = event->getIf<Event::MouseButtonPressed>())
			{
				if (mouse_pressed->button == Mouse::Button::Left)
				{
					Vector2f pos = (Vector2f)mouse_pressed->position;
					if (b_queen.getGlobalBounds().contains(pos))
					{
						selected_type = type::queen;
						prom_win.close();
					}
					else if (b_rook.getGlobalBounds().contains(pos))
					{
						selected_type = type::rook;
						prom_win.close();
					}
					else if (b_bishop.getGlobalBounds().contains(pos))
					{
						selected_type = type::bishop;
						prom_win.close();
					}
					else if (b_knight.getGlobalBounds().contains(pos))
					{
						selected_type = type::knight;
						prom_win.close();
					}
				}
			}
		}

		prom_win.clear(Dark_teal);
		Text t(font);
		t.setString("Choose Promotion:");
		t.setCharacterSize(22);
		t.setFillColor(Color::White);
		t.setPosition({ 20, 15 });
		prom_win.draw(t);
		prom_win.draw(b_queen);
		prom_win.draw(b_rook);
		prom_win.draw(b_bishop);
		prom_win.draw(b_knight);
		prom_win.draw(s_queen);
		prom_win.draw(s_rook);
		prom_win.draw(s_bishop);
		prom_win.draw(s_knight);

		prom_win.display();
	}
	return selected_type;
}



void run_credits(Font& font)
{
	RenderWindow creditsWindow(VideoMode({ 900, 900 }), "Credits", (Style::Titlebar | Style::Close));
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
		credit.setScale({ 1.35,1.25 });
		creditsWindow.draw(credit);
		creditsWindow.display();
	}
}



void run_game(Font& font,Font& font2)
{
	Clock clock;
	float t = 3;
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

	RenderWindow window(VideoMode({ 900, 900 }), "Chess Board", (Style::Titlebar | Style::Close));
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
		
	    bool white_turn = (turnno % 2 == 0);
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
					if (mouse_pressed->position.x < 50 || mouse_pressed->position.y < 50 || mouse_pressed->position.x > 850 || mouse_pressed->position.y > 850)
					{
						continue;
					}
					int y = (mouse_pressed->position.x - 50) / box_size;
					int x = (mouse_pressed->position.y - 50) / box_size;

					if (selected_x == -1 && selected_y == -1)
					{
						block* clicked = board.b[x][y];
						bool can_pick = ((!game_over) && (clicked->piece_ptr != nullptr) && (clicked->p_colour == current_turn));

						if (can_pick)
						{
							selected_x = x;
							selected_y = y;
							move_hints = clicked->piece_ptr->find_all_movements(board, move_hint_count);
						}
					}
					else
					{
						block* from = board.b[selected_x][selected_y];
						block* to = board.b[x][y];
						if (is_move_legal(selected_x, selected_y, x, y, board))
						{
							from->piece_ptr->movement(x, y, board);
							to->piece_ptr = from->piece_ptr;
							to->p_type = from->p_type;
							to->p_colour = from->p_colour;
							from->piece_ptr = nullptr;
							from->p_type = type::undefined;
							from->p_colour = piece_colour::undefined;

							if (to->p_type == type::pawn)
							{
								if ((to->p_colour == piece_colour::white && x == 0) || (to->p_colour == piece_colour::black && x == 7))
								{
									type promoted_to = display_promotion_window(to->p_colour, font);
									int color_val = (to->p_colour == piece_colour::white) ? 1 : 0;
									int cside = (to->p_colour == piece_colour::white) ? 0 : 1;

									piece_class* new_piece = nullptr;
									if (promoted_to == type::queen)
									{
										new_piece = new queen(x, y, color_val);
									}
									else if (promoted_to == type::rook)
									{
										new_piece = new rook(x, y, color_val);
									}
									else if (promoted_to == type::bishop)
									{
										new_piece = new bishop(x, y, color_val);
									}
									else if (promoted_to == type::knight)
									{
										new_piece = new knight(x, y, color_val);
									}
									if (new_piece)
									{
										for (int i = 0; i < 16; ++i)
										{
											if (all_pieces[cside][i] == to->piece_ptr)
											{
												all_pieces[cside][i] = new_piece;
												break;
											}
										}
										delete to->piece_ptr;
										to->piece_ptr = new_piece;
										to->p_type = promoted_to;
									}
								}
							}

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
						delete[] move_hints; move_hints = nullptr; move_hint_count = 0;
						selected_x = -1; selected_y = -1;
					}
				}
			}
		}


		window.clear(Color(0, 33, 43));
		{
			char ch = 'a';
			for (int i = 0; i < 8; ++i)
			{
				{
					Text t(font);
					t.setString(ch);
					t.setCharacterSize(35);
					t.setFillColor(Color::White);
					t.setPosition({ (float)(100 * i + 90), (float)1 });
					window.draw(t);
					t.setPosition({ (float)(100 * i + 90), (float)852 });
					window.draw(t);
					ch++;
				}
			}
			ch = '1';
			for (int i = 0; i < 8; ++i)
			{
				{
					Text t(font);
					t.setString(ch);
					t.setCharacterSize(35);
					t.setFillColor(Color::White);
					t.setPosition({ (float)15, (float)(100 * i + 90) });
					window.draw(t);
					t.setPosition({ (float)865, (float)(100 * i + 90) });
					window.draw(t);
					ch++;
				}
			}
		}
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				RectangleShape rect({ (float)box_size, (float)box_size });
				rect.setPosition({ (float)(j * box_size + 50), (float)(i * box_size + 50) });
				if ((i + j) % 2 == 0)
				{
					rect.setFillColor(dark_block);
				}
				else
				{
					rect.setFillColor(light_block);
				}

				if (in_check && i == kx && j == ky)
				{
					rect.setFillColor(Color::Red);
				}
				rect.setOutlineThickness(1);
				rect.setOutlineColor(light_block);
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
							bool is_move_valid = is_move_legal(selected_x, selected_y, i, j, board);
							if (is_move_valid)
							{
								if (dest->piece_ptr != nullptr && dest->p_colour != piece_colour::undefined && dest->p_colour != from_sq->p_colour)
								{
									rect.setFillColor(enemy_colour);
								}
								else
								{
									rect.setFillColor(step_colour);
								}
								window.draw(rect);
							}
						}
					}
				}
				if (selected_x == i && selected_y == j)
				{
					RectangleShape sel({ (float)box_size, (float)box_size });
					sel.setPosition({ (float)(j * box_size) + 50, (float)(i * box_size) + 50 });
					sel.setFillColor(Color::Transparent);
					sel.setOutlineThickness(-50);
					sel.setOutlineColor(current_step_color);
					window.draw(sel);
				}
				if (board.b[i][j]->p_type != type::undefined)
				{
					if (board.b[i][j]->p_colour == piece_colour::white)
					{
						if (board.b[i][j]->p_type == type::pawn)
						{
							wp.setPosition({ (float)j * 100 + 50, (float)i * 100 + 50 });
							window.draw(wp);
						}
						else if (board.b[i][j]->p_type == type::rook)
						{
							wr.setPosition({ (float)j * 100 + 50, (float)i * 100 + 50 });
							window.draw(wr);
						}
						else if (board.b[i][j]->p_type == type::knight)
						{
							wn.setPosition({ (float)j * 100 + 50, (float)i * 100 + 50 });
							window.draw(wn);
						}
						else if (board.b[i][j]->p_type == type::bishop)
						{
							wb.setPosition({ (float)j * 100 + 50, (float)i * 100 + 50 });
							window.draw(wb);
						}
						else if (board.b[i][j]->p_type == type::queen)
						{
							wq.setPosition({ (float)j * 100 + 50, (float)i * 100 + 50 });
							window.draw(wq);
						}
						else if (board.b[i][j]->p_type == type::king)
						{
							wking.setPosition({ (float)j * 100 + 50, (float)i * 100 + 50 });
							window.draw(wking);
						}
					}
					else
					{
						if (board.b[i][j]->p_type == type::pawn)
						{
							bp.setPosition({ (float)j * 100 + 50, (float)i * 100 + 50 });
							window.draw(bp);
						}
						else if (board.b[i][j]->p_type == type::rook)
						{
							br.setPosition({ (float)j * 100 + 50, (float)i * 100 + 50 });
							window.draw(br);
						}
						else if (board.b[i][j]->p_type == type::knight)
						{
							bn.setPosition({ (float)j * 100 + 50, (float)i * 100 + 50 });
							window.draw(bn);
						}
						else if (board.b[i][j]->p_type == type::bishop)
						{
							bb.setPosition({ (float)j * 100 + 50 ,(float)i * 100 + 50 });
							window.draw(bb);
						}
						else if (board.b[i][j]->p_type == type::queen)
						{
							bq.setPosition({ (float)j * 100 + 50, (float)i * 100 + 50 });
							window.draw(bq);
						}
						else if (board.b[i][j]->p_type == type::king)
						{
							bking.setPosition({ (float)j * 100 + 50, (float)i * 100 + 50 });
							window.draw(bking);
						}
					}
				}
			}
		}
		if (game_over)
		{
			RectangleShape r;
			r.setSize({ 900, 900 });
			r.setFillColor(Color(255, 255, 255, 100));
			r.setPosition({ 0,0 });
			window.draw(r);
			Text t(font);
			t.setString("Game Over");
			t.setFillColor(Dark_teal);
			t.setCharacterSize(160);
			t.setPosition({ 70,335 });
			window.draw(t);
		}
		

		window.display();
		Time elapsed = clock.getElapsedTime();
		if (game_over && (winner_displayed || stalemate_displayed) && (elapsed.asSeconds() >= t))
		{
			window.close();
			return;
		}
		piece_colour loser = (turnno % 2 == 0) ? piece_colour::white : piece_colour::black;
		if (game_over && !winner_displayed && !stalemate_detected)
		{
			winner_displayed = true;
			display_winner_window(loser, font);
			clock.restart();
		}
		if (game_over && stalemate_detected && !stalemate_displayed)
		{
			stalemate_displayed = true;
			display_stalemate_window(font);
			clock.restart();
		}
	}
	delete[] move_hints;
	
}