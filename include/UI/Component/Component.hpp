#pragma once

#include <SFML/Graphics.hpp>

namespace UI
{
	////////////////////////////////////////////////////////////
	/// \brief UI component object. By the way, it is abstract.
	///
	////////////////////////////////////////////////////////////
	class Component
	{
	public:
		Component();
		virtual ~Component();

		// Modify the component
		////////////////////////////////////////////////////////////
		/// \brief Change the background color of the component
		///
		/// \param i_color   Background color
		///
		////////////////////////////////////////////////////////////
		virtual void setBackgroundColor(const sf::Color& i_color);

		////////////////////////////////////////////////////////////
		/// \brief Change the position of the component
		///
		/// \param i_position   Position of the object
		///
		////////////////////////////////////////////////////////////
		virtual void setPosition(const sf::Vector2f& i_position);

		////////////////////////////////////////////////////////////
		/// \brief Change the position of the component
		///
		/// \param i_x   X Coordinate of the object
		/// \param i_y   Y Coordinate of the object
		///
		////////////////////////////////////////////////////////////
		virtual void setPosition(const uint16_t i_x, const uint16_t i_y);

		////////////////////////////////////////////////////////////
		/// \brief Change the size of the component
		///
		/// \param i_size   Size of the object
		///
		////////////////////////////////////////////////////////////
		virtual void setSize(const sf::Vector2f& i_size);

		////////////////////////////////////////////////////////////
		/// \brief Change the size of the component
		///
		/// \param i_width    Width of the object
		/// \param i_height   Height of the object
		///
		////////////////////////////////////////////////////////////
		virtual void setSize(const uint16_t i_width, const uint16_t i_height);

		////////////////////////////////////////////////////////////
		/// \brief Change the border radius of the component
		///
		/// \param i_radius   Radius of the corner
		///
		////////////////////////////////////////////////////////////
		virtual void setBorderRadius(const uint8_t i_radius);

		sf::Texture getRenderTexture() { return m_renderTexture.getTexture(); }

		// Functions

		////////////////////////////////////////////////////////////
		/// \brief Update the component
		///
		////////////////////////////////////////////////////////////
		virtual void update();

		////////////////////////////////////////////////////////////
		/// \brief Draw the component on the screen
		///
		/// \param i_target   Render target: it can be the screen,
		///                   or a render texture
		///
		////////////////////////////////////////////////////////////
		virtual void render(sf::RenderTarget& i_target);

	protected:
		////////////////////////////////////////////////////////////
		// Member data
		////////////////////////////////////////////////////////////
		sf::Vector2f m_position; /// Component position
		sf::Vector2f m_size;     /// Component size
		sf::Color m_color;       /// Component background color
		uint8_t m_borderRadius;  /// Component border radius

		sf::RenderTexture m_renderTexture; /// Render texture used to draw the component
		sf::Sprite m_sprite;               /// Sprite to draw the render texture
	};
}