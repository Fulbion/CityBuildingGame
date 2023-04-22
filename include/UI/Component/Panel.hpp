#pragma once

#include "UI/Component/Component.hpp"

namespace UI
{
	enum class Dock
	{
		None,
		Left,
		Bottom,
		Top,
		Right
	};

	class Panel : Component
	{
	public:
		// Constructor & Destructor
		Panel(uint16_t i_x, uint16_t i_y, uint16_t i_width, uint16_t i_height);
		~Panel();

		// Modify the window
		////////////////////////////////////////////////////////////
		/// \brief Change the background color of the panel
		///
		/// \param i_color   Background color
		///
		////////////////////////////////////////////////////////////
		virtual void setBackgroundColor(const sf::Color& i_color) override;

		////////////////////////////////////////////////////////////
		/// \brief Change the position of the panel
		///
		/// \param i_position   Position of the object
		///
		////////////////////////////////////////////////////////////
		virtual void setPosition(const sf::Vector2f& i_position) override;

		////////////////////////////////////////////////////////////
		/// \brief Change the position of the panel
		///
		/// \param i_x   X Coordinate of the object
		/// \param i_y   Y Coordinate of the object
		///
		////////////////////////////////////////////////////////////
		virtual void setPosition(const uint16_t i_x, const uint16_t i_y) override;

		////////////////////////////////////////////////////////////
		/// \brief Change the size of the panel
		///
		/// \param i_size   Size of the object
		///
		////////////////////////////////////////////////////////////
		virtual void setSize(const sf::Vector2f& i_position) override;

		////////////////////////////////////////////////////////////
		/// \brief Change the size of the panel
		///
		/// \param i_width    Width of the object
		/// \param i_height   Height of the object
		///
		////////////////////////////////////////////////////////////
		virtual void setSize(const uint16_t i_x, const uint16_t i_y) override;

		////////////////////////////////////////////////////////////
		/// \brief Change the border radius of the panel
		///
		/// \param i_radius   Radius of the corner
		///
		////////////////////////////////////////////////////////////
		virtual void setBorderRadius(const uint8_t i_radius) override;

		////////////////////////////////////////////////////////////
		/// \brief Change the dock mode of the panel
		///
		/// \param i_window     Reference window
		/// \param i_dockMode   Dock mode of the panel (can be left, right, etc.)
		///
		////////////////////////////////////////////////////////////
		void setDock(const sf::Window& i_window, const Dock& i_dockMode);

		////////////////////////////////////////////////////////////
		/// \brief Change the title of the panel
		///
		/// \param i_title   Title of the panel
		///
		////////////////////////////////////////////////////////////
		void setTitle(const std::string i_title);

		// Events
		virtual void update() override;
		virtual void render(sf::RenderTarget& i_target) override;
		
	private:
		std::string m_title;
		sf::Text m_text;
	};
}