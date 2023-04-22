#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

#include "UI/Component/Component.hpp"
#include "UI/Component/Panel.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "City Building");
	window.setFramerateLimit(165);

	UI::Panel testComponent(10, 10, 300, 400);
	testComponent.setPosition(10, 10);
	testComponent.setSize(300, 400);
	// testComponent.setDock(window, UI::Dock::Right);
	testComponent.setBorderRadius(10);
	testComponent.setTitle("Panel");

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		testComponent.update();
		testComponent.render(window);

		window.display();
	}
}