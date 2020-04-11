#include <iostream>
#include <cmath>
#include "RSDL/src/rsdl.hpp"

using namespace std;

Point mousePosition;

class Ball {
public:
	void update(Window* window) {
		x = mousePosition.x;
		y = mousePosition.y;
	}

	void draw(Window* window) {
		window->fill_circle(Point(x,y), 20);
	}
	
private:
	float x, y;
};

Ball ball;

void update(Window* window) {
	while(window->has_pending_event()) {
		Event e = window->poll_for_event();
		switch(e.get_type()) {
			case Event::EventType::QUIT:
				exit(0);
				break;
			case Event::EventType::MMOTION:
				mousePosition = e.get_mouse_position();
				break;
		}
	}
	ball.update(window);
}

void draw(Window* window) {
	window->clear();
	window->draw_rect(Rectangle(100, 100, 200, 200));
	ball.draw(window);
	window->update_screen();
}

int main()
{
	Window *window = new Window(1000, 1000, "RSDL Demo");
	while(true) {
		update(window);
		draw(window);
		delay(15);
	}
	return 0;
}