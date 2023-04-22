#include "UI/Component/Window.hpp"
#include <iostream>
namespace UI
{
	Window::Window(uint16_t i_x, uint16_t i_y, uint16_t i_width, uint16_t i_height)
	{
		m_windowBounds = sf::IntRect(i_x, i_y, i_width, i_height);
	}

	Window::~Window()
	{
	}

	void Window::setBackgroundColor(const sf::Color& i_color)
	{
		m_backgroundColor = i_color;
	}

	void Window::update(const sf::Window& i_window, sf::Event& i_event)
	{
		m_windowTitleBarBounds = sf::IntRect(m_windowBounds.left, m_windowBounds.top, m_windowBounds.width, 30);
		this->dragAndDrop(i_window, i_event);
		m_window.setPosition(m_windowBounds.left, m_windowBounds.top);
		m_window.setSize(sf::Vector2f(m_windowBounds.width, m_windowBounds.height));
		m_window.setFillColor(m_backgroundColor);
		m_window.setOutlineThickness(1);
		m_window.setOutlineColor(sf::Color(255, 255, 255, 64));
		m_windowTitle.setPosition(m_windowBounds.left, m_windowBounds.top);
		m_windowTitle.setSize(sf::Vector2f(m_windowBounds.width, m_windowTitleBarBounds.height));
		m_windowTitle.setFillColor(sf::Color(32, 48, 92));
	}

	void Window::render(sf::RenderTarget& i_target)
	{
		i_target.draw(m_window);
		i_target.draw(m_windowTitle);
	}
	
	void Window::dragAndDrop(const sf::Window& i_window, sf::Event& i_event)
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(i_window);
		sf::Vector2i deltaPosition;

		if (m_windowTitleBarBounds.contains(mousePosition))
		{
			if (i_event.type == sf::Event::MouseButtonPressed)
			{
				if (i_event.mouseButton.button == sf::Mouse::Left)
				{
					m_isMoving = true;
					deltaPosition.x = mousePosition.x - m_windowBounds.left;
					deltaPosition.y = mousePosition.y - m_windowBounds.top;
				}
			}

			if (i_event.type == sf::Event::MouseButtonReleased)
			{
				m_isMoving = false;
			}
		}

		if (m_isMoving)
		{
			m_windowBounds.left = mousePosition.x - deltaPosition.x;
			m_windowBounds.top = mousePosition.y - deltaPosition.y;
		}
	}
}