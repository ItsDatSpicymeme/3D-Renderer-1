#include "main.h"


int main() {
	// Window
	ContextSettings window_settings;
	window_settings.antialiasingLevel = 0;
		// Main Window
	RenderWindow window(VideoMode(s_l, s_h), "Concept", Style::Default, window_settings);
///	window.setFramerateLimit(FPS);


	// Vertex Point Array
	S_Point vert_p[P] = {};
/*	point[0] = VP(0, 0, 0);
	point[1] = VP(69, 69, 69);
	point[2] = VP(-120, -30, -60);
	point[3] = VP(-33, -96, 30);
*/

		// Visual Points
	CircleShape circle;
		circle.setPosition(0, 0);
		circle.setRadius(30);


	// Sphere
	S_Point sphere(-6, -6, 21);

	// Camera
	S_Point cam(0, 0, 0);
	
	// Light
	S_Point light(9, 12, -6);

	Image image;
	image.create(s_l, s_h, Colour::Black);
	Texture texture;
	texture.create(s_l, s_h);
	Sprite pic;

	if (true) {
		// Optimize variables?
		const double l_l = abs(p_dist(sphere, cam));
		const double op1 = -255.0 / (l_l + 15.0);
		const double s_l_2 = s_l / 2, s_h_2 = s_h / 2;

		for (double i = 0.0; i <= 2.0; i += 1.0 / (s_l)) {
			for (double j = 0.0; j <= 2.0; j += 1.0 / (s_h)) {
				for (double l = 0.0; l <= l_l; l += .1) {
					// Current Point of ray
					S_Point line_p((i - 1.0) * l, -(j - 1.0) * l, l);
					if (p_dist(line_p, sphere) <= 9.0) {
///						double c = (-255.0 / abs(sphere.z - cam.z) * l) + 255.0;
						const double c = (op1 * p_dist(line_p, light)) + 255.0;
						const double ox = 1 / (light.x - line_p.x);
						const S_Point vector((light.x - line_p.x) * ox, (light.y - line_p.y) * ox, (light.z - line_p.z) * ox);
						for (double k = .1; k < l_l; k += .1) {
							const S_Point vect_p(line_p.x + (k * vector.x), line_p.y + (k * vector.y), line_p.z + (k * vector.z));
							if (p_dist(vect_p, sphere) < 8.9) {
								break;
							}
							else if (p_dist(vect_p, light) <= 0.2) {
								if (c > 255 || c < 0) break;
								else image.setPixel(i * s_l_2, j * s_h_2, Colour(c, c, c, 255));
							}
						}
						break;
					}
				}
///				printf("%d / %d\n", (int)(j * s_h / 2), s_h);
			}
///			printf("\t%d / %d\n", (int)(i * s_l / 2), s_l);
		}
	}

	printf("Done!\n");
///	if (!image.saveToFile("result.png")) printf("FUCK >:(\n");
	texture.update(image);
	pic.setTexture(texture);
	
	// Main Window Loop
	for (;true;) {

		// Events-

		Event event;  // array of all events
			// See if window has closed
		for (; window.pollEvent(event);) {
			if (event.type == Event::Closed) {
				window.close();
				return 0;
			}
		}


		// Events

///		printf("%f\t%f %f %f\n", p_dist(cam, sphere), cam.x, cam.y, cam.z);
		


		// Events+

			// Renderer
		window.clear();
		
			// Objects to draw to screen
		window.draw(pic);
				// Reference Circles
///		for (unsigned short i = 0; i < P; i++) {
///			window.draw(circle);
///		}
		
			// Display
		window.display();

	}

	return 0;
}