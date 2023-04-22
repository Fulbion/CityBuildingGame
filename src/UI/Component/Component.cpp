#include "UI/Component/Component.hpp"

namespace UI
{
	Component::Component()
	{
		m_position = sf::Vector2f(0, 0);
		m_size = sf::Vector2f(100, 100);
		m_borderRadius = 0;
	}

	Component::~Component()
	{
	}

	void Component::setBackgroundColor(const sf::Color& i_color)
	{
		m_color = i_color;
	}

	void Component::setPosition(const sf::Vector2f& i_position)
	{
		m_position = i_position;
	}

	void Component::setPosition(const uint16_t i_x, const uint16_t i_y)
	{
		m_position = sf::Vector2f(i_x, i_y);
	}

	void Component::setSize(const sf::Vector2f& i_size)
	{
		m_size = i_size;
	}

	void Component::setSize(const uint16_t i_width, const uint16_t i_height)
	{
		m_size = sf::Vector2f(i_width, i_height);
	}

	void Component::setBorderRadius(const uint8_t i_radius)
	{
		m_borderRadius = i_radius;

		m_renderTexture.create(m_size.x, m_size.y);
		m_renderTexture.clear();
		
		uint8_t radius = i_radius * 2;
		sf::RectangleShape widthRectangle, heightRectangle;

		widthRectangle.setPosition(0, 0 + radius / 2);
		heightRectangle.setPosition(0 + radius / 2, 0);

		widthRectangle.setSize(sf::Vector2f(m_size.x, m_size.y - radius));
		heightRectangle.setSize(sf::Vector2f(m_size.x - radius, m_size.y));

		widthRectangle.setFillColor(m_color);
		heightRectangle.setFillColor(m_color);

		sf::CircleShape ltCircle, rtCircle, lbCircle, rbCircle;
		ltCircle.setRadius(i_radius);
		rtCircle.setRadius(i_radius);
		lbCircle.setRadius(i_radius);
		rbCircle.setRadius(i_radius);

		ltCircle.setFillColor(m_color);
		rtCircle.setFillColor(m_color);
		lbCircle.setFillColor(m_color);
		rbCircle.setFillColor(m_color);
		
		ltCircle.setPosition(0, m_size.y - radius);
		rtCircle.setPosition(m_size.x - radius, m_size.y - radius);
		lbCircle.setPosition(0, radius / m_size.y * m_size.y - radius);
		rbCircle.setPosition(m_size.x - radius, radius / m_size.y * m_size.y - radius);

		m_renderTexture.draw(widthRectangle);
		m_renderTexture.draw(heightRectangle);

		m_renderTexture.draw(ltCircle);
		m_renderTexture.draw(rtCircle);
		m_renderTexture.draw(lbCircle);
		m_renderTexture.draw(rbCircle);

		m_sprite.setTexture(m_renderTexture.getTexture());
	}

	void Component::update()
	{
		this->setBorderRadius(m_borderRadius);
		m_sprite.setTexture(m_renderTexture.getTexture());
		m_sprite.setPosition(m_position);
	}

	void Component::render(sf::RenderTarget& i_target)
	{
		i_target.draw(m_sprite);
	}
}