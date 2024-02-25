// Lab6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
int main() {
	Image background;
	if (!background.loadFromFile("images1/backgrounds/prague.png")) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Image foreground;
	if (!foreground.loadFromFile("images1/characters/Rey_green_screen.png")) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	unsigned int width = background.getSize().x;
	unsigned int height = background.getSize().y;
	for (unsigned int x = 0; x < width; x++) {
		for (unsigned int y = 0; y < height; y++) {
				Color c = foreground.getPixel(x, y);
				Color green = foreground.getPixel(0, 0);
				if (c == green) {
					foreground.createMaskFromColor(green);
					Color backgroundPixel = background.getPixel(x, y);
					foreground.setPixel(x, y, backgroundPixel);
				}
		}
	}

	Texture foregroundTex;
	foregroundTex.loadFromImage(foreground);
	Sprite foregroundSprite(foregroundTex);

	Texture backgroundTex;
	backgroundTex.loadFromImage(background);
	Sprite backgroundSprite(backgroundTex);
	
	// By default, just show the foreground image
	RenderWindow window(VideoMode(width, height), "Here's the output");
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		window.clear();
		window.draw(backgroundSprite);
		window.draw(foregroundSprite);
		window.display();
	}
	while (true);
}