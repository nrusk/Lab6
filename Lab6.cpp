#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main() {
	string background = "images1/backgrounds/prague.png";
	string foreground = "images1/characters/yoda.png";
	Texture backgroundTex;

	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}

	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}

	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();
	Image foregroundImage;
	foregroundImage = foregroundTex.copyToImage();
	Vector2u sz = backgroundImage.getSize();

	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {

			// These two loops will run the code inside for each pixel in the background image
			// You can access the current pixel at x,y like so:
			// Color objects store the individual channel values like example.r example.g and example.b

			//I'm not sure why this works. I had (0, 0), but it didn't work, so I tried (1, 1) and saw a small portion working, so I did the image size - 1
			//In the if statement, I had != and it worked but switched the pixels oppositely
			// and when I first tried ==, it didn't without changing the (x, y) for Color Green
			Color green = foregroundImage.getPixel(1023, 767);

			Color bc = backgroundImage.getPixel(x, y);
			Color fc = foregroundImage.getPixel(x, y);
			Color combinedImage(
				bc.r,
				bc.g,
				bc.b);

			if (fc.r == green.r && fc.g == green.g && fc.b == green.b) {
				foregroundImage.setPixel(x, y, combinedImage);
			}

		}
	}

	// By default, just show the foreground image
	RenderWindow window(VideoMode(1024, 768), "Here's the output");
	Sprite sprite1;
	Texture tex1;
	tex1.loadFromImage(foregroundImage);
	sprite1.setTexture(tex1);
	window.clear();
	window.draw(sprite1);
	window.display();

	while (true);
}