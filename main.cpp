#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	
	srand(time(nullptr));
	const float length = 800;
	const float width = 600;
	const float length_rect = 20;
	const float width_rect = 80;
	const float ballradius = 10;
	const float otstup = 50;
	const float circle_posx = length / 2 - 10;
	const float circle_posy = width / 2 - 10;
	const Color batcolor1(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
	const Color batcolor2(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
	const Vector2f batsize(length_rect, width_rect);
	const float batSpeed = 5.f;
	// Объект, который, собственно, является главным окном приложения

	RenderWindow window(VideoMode(length, width), "SFML Works!");
	window.setFramerateLimit(60);
	Texture textur;
	textur.loadFromFile("futbl.jpg");
	Texture textur1;
	textur1.loadFromFile("setka.png");
	//шарик
	CircleShape circle(ballradius);
	circle.setPosition(circle_posx,circle_posy);
	circle.setFillColor(Color::White);
	circle.setOutlineColor(Color::Black);
	circle.setOutlineThickness(2);
	const float ball_dx = 2;
	const float ball_dy = 2;
	float arr_speed[]{ -5.f,-4.f,-3.f,-2.f,-1.f,1.f,2.f,3.f,4.f,5.f };
	int index = rand() % 10;
	float ball_speedx = arr_speed[index];
	index = rand() % 10;
	float ball_speedy = arr_speed[index];
	//поле футбольное
	RectangleShape pl(Vector2f(800,600));
	pl.setTexture(&textur);
	//рокетки
	RectangleShape leftbat(batsize);
	leftbat.setTexture(&textur1);
	leftbat.setPosition(otstup,width/2-40);
	leftbat.setFillColor(batcolor1);
	RectangleShape rightbat(batsize);
	rightbat.setTexture(&textur1);
	rightbat.setPosition(length-otstup,width/2-40);
	rightbat.setFillColor(batcolor2);
	float leftBаtSpeedY = 0.f;
	float rightBаtSpeedY = 0.f;
	//шарик
	
	
	//index = rand() %
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		//проверка нажатий клавиш
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			leftBаtSpeedY = -batSpeed;
			if (leftbat.getPosition().y <= 0)
			{
				leftbat.setPosition(otstup, 0);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			leftBаtSpeedY = batSpeed;
			if (leftbat.getPosition().y >= (width-80))
			{
				leftbat.setPosition(otstup, width - 80);
			}

		}
		leftbat.move(0, leftBаtSpeedY);
		leftBаtSpeedY = 0.f;
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			rightBаtSpeedY = -batSpeed;
			if (rightbat.getPosition().y <= 0)
			{
				rightbat.setPosition(length - otstup, 0);
			}

		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			rightBаtSpeedY = batSpeed;
			if (rightbat.getPosition().y >= (width - 80))
			{
				rightbat.setPosition(length-otstup, width - 80);
			}
		}
		rightbat.move(0, rightBаtSpeedY);
		rightBаtSpeedY = 0.f;
		
		// движение шарика
		circle.move(ball_speedx, ball_speedy);
		if (circle.getPosition().x<=0 || circle.getPosition().x >= (length -2*ballradius) )
		{
			ball_speedx = -ball_speedx;
		}
		if (circle.getPosition().y <= 0 || circle.getPosition().y >= (width - 2 * ballradius))
		{
			ball_speedy = -ball_speedy;
		}
		
		
		
		
		
		//отрисовка обьектов
		window.clear();
		window.draw(pl);
		window.draw(leftbat);
		window.draw(rightbat);
		window.draw(circle);
		window.display();
	}

	return 0;
}
