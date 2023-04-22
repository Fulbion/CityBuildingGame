#include "UI/Component/Panel.hpp"

namespace UI
{
	Panel::Panel(uint16_t i_x, uint16_t i_y, uint16_t i_width, uint16_t i_height) :
		Component()
	{
		m_color = sf::Color(32, 32, 32);
	}

	Panel::~Panel()
	{
	}

	void Panel::setBackgroundColor(const sf::Color& i_color)
	{
		Component::setBackgroundColor(i_color);
	}

	void Panel::setPosition(const sf::Vector2f& i_position)
	{
		Component::setPosition(i_position);
	}

	void Panel::setPosition(const uint16_t i_x, const uint16_t i_y)
	{
		Component::setPosition(i_x, i_y);
	}

	void Panel::setSize(const sf::Vector2f& i_size)
	{
		Component::setSize(i_size);
	}

	void Panel::setSize(const uint16_t i_width, const uint16_t i_height)
	{
		Component::setSize(i_width, i_height);
	}

	void Panel::setBorderRadius(const uint8_t i_radius)
	{
		Component::setBorderRadius(i_radius);
	}

	void Panel::setDock(const sf::Window& i_window, const Dock& i_dockMode)
	{
		switch (i_dockMode)
		{
		case UI::Dock::None:
			break;

		case UI::Dock::Left:
			this->setPosition(0, 0);
			this->setSize(m_size.x, i_window.getSize().y);
			break;

		case UI::Dock::Bottom:
			this->setPosition(0, i_window.getSize().y - m_size.y);
			this->setSize(i_window.getSize().x, m_size.y);
			break;

		case UI::Dock::Top:
			this->setPosition(0, 0);
			this->setSize(i_window.getSize().x, m_size.y);
			break;

		case UI::Dock::Right:
			this->setPosition(i_window.getSize().x - m_size.x, 0);
			this->setSize(m_size.x, i_window.getSize().y);
			break;
		}
	}

	void Panel::setTitle(const std::string i_title)
	{
		m_title = i_title;
		this->setBorderRadius(m_borderRadius);
		sf::Font font;
		font.loadFromFile("resources/fonts/ModeSeven.ttf");
		m_text.getInverseTransform();
		m_text.setFont(font);
		m_text.setCharacterSize(24);
		m_text.setString(i_title);
		m_text.setFillColor(sf::Color::White);
		m_text.setPosition(m_position.x + 30, m_position.y + 30);
		m_renderTexture.draw(m_text);
	}

	void Panel::update()
	{
		this->setBorderRadius(m_borderRadius);
		this->setTitle(m_title);
		m_sprite.setTexture(m_renderTexture.getTexture());
		m_sprite.setPosition(m_position);
	}

	void Panel::render(sf::RenderTarget& i_target)
	{
		i_target.draw(m_sprite);
	}
}