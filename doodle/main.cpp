#include "SFML/Graphics.hpp"
#include "time.h"

struct point {
	int x, y;
};

using namespace sf;
int main() {
	RenderWindow app(VideoMode(532, 550), "Doodle jump");
	app.setFramerateLimit(60);
	Texture t1, t2, t3;
	t1.loadFromFile("Images/background_doodle.png");
	t2.loadFromFile("Images/platform.png");
	t3.loadFromFile("Images/doodle.jpg");
	Sprite sBackground(t1), sPers(t3), sPlat(t2);
	point plat[20];
	for (int i = 0; i < 10; i++) {
		plat[i].x = rand() % 532;
		plat[i].y = rand() % 550;
	}
	
	int x = 100, y = 100, h = 200;
	float dx = 0, dy = 0;
	
	while (app.isOpen()) {

		//handle close window event
		Event event; // create event
		while (app.pollEvent(event)) {
			if (event.type == Event::Closed)
				app.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) 
			x += 3.5;
		if (Keyboard::isKeyPressed(Keyboard::Left))
			x -= 3.5;
		dy += 0.2; // gravity
		y += dy; // falling (changing player y-position)
		if (y > 400)
			dy = -10; // jump
		if (y < h)
			for (int i = 0; i < 10; i++) {
				y = h;
				plat[i].y = plat[i].y - dy;
				if (plat[i].y > 550) {
					plat[i].y = 0;
					plat[i].x = rand() % 532;
				}
			}


		for (int i = 0; i < 10; i++) 
			if ((x > plat[i].x - 50) && (x < plat[i].x + 50) // platform interval from x
				&& (y > plat[i].y) && (y < plat[i].y + 10) && dy > 0) // platform interval from y
				dy = -10;
		sPers.setPosition(x, y);
		app.draw(sBackground);
		app.draw(sPers);
		for (int i = 0; i < 10; i++) {
			sPlat.setPosition(plat[i].x, plat[i].y);
			app.draw(sPlat);
		}
		app.display();
	}
	return 0;
}