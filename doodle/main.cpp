#include "SFML/Graphics.hpp"
#include "time.h"

struct point {
	int x, y;
};

using namespace sf;
int main() {
	RenderWindow app(VideoMode(532, 850), "Doodle jump");
	app.setFramerateLimit(60);
	Texture t1, t2, t3;
	t1.loadFromFile("Images/background_doodle.png");
	t2.loadFromFile("Images/platform.png");
	t3.loadFromFile("Images/doodle.jpg");
	Sprite sBackground(t1), sPers(t3), sPlat(t2);
	point plat[20];
	for (int i = 0; i < 10; i++) {
		plat[i].x = rand() % 532;
		plat[i].y = rand() % 850;
	}
	while (app.isOpen()) {

		//handle close window event
		Event event; // create event
		while (app.pollEvent(event)) {
			if (event.type == Event::Closed)
				app.close();
		}
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