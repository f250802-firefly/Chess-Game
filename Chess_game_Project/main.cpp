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



int main()
{
	Font font;
	Font font2;
	font.openFromFile("serife.ttf");
	font2.openFromFile("C:/Windows/Fonts/ITCEDSCR.ttf");
	Texture background;
	background.loadFromFile("chess3.PNG");
	Sprite back(background);
	back.setScale({ 1.f,1.4f });
	while (true)
	{
		RenderWindow menu(VideoMode({ 900, 900 }), "Main Menu", (Style::Titlebar | Style::Close));
		RectangleShape b1({ 340, 90 }), b2({ 340, 90 }), b3({ 340, 90 }), b4({ 340, 90 });

		b1.setOutlineColor(Color::Black);
		b1.setOutlineThickness(-6);
		b1.setPosition({ 280, 320 });
		b1.setFillColor(dark_block);

		b2.setOutlineColor(Color::Black);
		b2.setOutlineThickness(-6);
		b2.setPosition({ 280, 455 });
		b2.setFillColor(dark_block);

		b3.setOutlineColor(Color::Black);
		b3.setOutlineThickness(-6);
		b3.setPosition({ 280,570 });
		b3.setFillColor(dark_block);

		b4.setOutlineColor(Color::Black);
		b4.setOutlineThickness(-6);
		b4.setPosition({ 280, 695 });
		b4.setFillColor(Color(220, 60, 60));

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
						action = 1;
					}
					else if (b2.getGlobalBounds().contains(pos))
					{
						action = 2;
						menu.close();
					}
					else if (b3.getGlobalBounds().contains(pos))
					{
						action = 3;
						menu.close();
					}
					else if (b4.getGlobalBounds().contains(pos))
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
			menu.draw(b4);


			Text t(font2);
			t.setString("Firefly Chess");
			t.setFillColor(Color::Black);
			t.setCharacterSize(195);
			t.setPosition({ 65, 30 });
			menu.draw(t);

			Text t1(font);
			t1.setString("PLAY");
			t1.setCharacterSize(50);
			FloatRect txt1 = t1.getLocalBounds();
			t1.setOrigin({txt1.position.x + txt1.size.x / 2.f,txt1.position.y + txt1.size.y / 2.f});
			t1.setPosition({ 450,365 });
			menu.draw(t1);

			Text t2(font);
			t2.setString("CREDITS");
			t2.setCharacterSize(50);
			FloatRect txt2 = t2.getLocalBounds();
			t2.setOrigin({ txt2.position.x + txt2.size.x / 2.f,txt2.position.y + txt2.size.y / 2.f });
			t2.setPosition({ 450,500 });
			menu.draw(t2);

			Text t3(font);
			t3.setString("SETTINGS");
			t3.setCharacterSize(50);
			FloatRect txt3 = t3.getLocalBounds();
			t3.setOrigin({txt3.position.x + txt3.size.x / 2.f,txt3.position.y + txt3.size.y / 2.f});
			t3.setPosition({ 450,615 });
			menu.draw(t3);

			Text t4(font);
			t4.setString("EXIT");
			t4.setCharacterSize(50);
			FloatRect txt4 = t4.getLocalBounds();
			t4.setOrigin({txt4.position.x + txt4.size.x / 2.f,txt4.position.y + txt4.size.y / 2.f});
			t4.setPosition({ 450,740 });
			menu.draw(t4);
			menu.display();

			if (action == 1)
			{
				run_game(font, font2);
				menu.close();
			}
			else if (action == 2)
			{
				run_credits(font);
			}
			else if (action == 3)
			{
				run_theme(font, font2);
			}
		}
	}
	return 0;
}