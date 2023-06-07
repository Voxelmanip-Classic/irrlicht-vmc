// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_GUI_SKIN_H_INCLUDED__
#define __I_GUI_SKIN_H_INCLUDED__

#include "IReferenceCounted.h"
#include "EGUIAlignment.h"
#include "SColor.h"
#include "rect.h"

namespace irr
{
namespace gui
{
	class IGUIFont;
	class IGUISpriteBank;
	class IGUIElement;

	//! Enumeration of available default skins.
	/** To set one of the skins, use the following code, for example to set
	the Windows classic skin:
	\code
	gui::IGUISkin* newskin = environment->createSkin(gui::EGST_WINDOWS_CLASSIC);
	environment->setSkin(newskin);
	newskin->drop();
	\endcode
	*/
	enum EGUI_SKIN_TYPE
	{
		//! Default windows look and feel
		EGST_WINDOWS_CLASSIC=0,

		//! Like EGST_WINDOWS_CLASSIC, but with metallic shaded windows and buttons
		EGST_WINDOWS_METALLIC,

		//! An unknown skin, not serializable at present
		EGST_UNKNOWN,

		//! this value is not used, it only specifies the number of skin types
		EGST_COUNT
	};

	//! Enumeration for skin colors
	enum EGUI_DEFAULT_COLOR
	{
		//! Dark shadow for three-dimensional display elements.
		EGDC_3D_DARK_SHADOW = 0,
		//! Shadow color for three-dimensional display elements (for edges facing away from the light source).
		EGDC_3D_SHADOW,
		//! Face color for three-dimensional display elements and for dialog box backgrounds.
		EGDC_3D_FACE,
		//! Highlight color for three-dimensional display elements (for edges facing the light source.)
		EGDC_3D_HIGH_LIGHT,
		//! Light color for three-dimensional display elements (for edges facing the light source.)
		EGDC_3D_LIGHT,
		//! Text on a button
		EGDC_BUTTON_TEXT,
		//! Grayed (disabled) text.
		EGDC_GRAY_TEXT,
		//! Item(s) selected in a control.
		EGDC_HIGH_LIGHT,
		//! Text of item(s) selected in a control.
		EGDC_HIGH_LIGHT_TEXT,
		//! Tool tip text color
		EGDC_TOOLTIP,
		//! Tool tip background color
		EGDC_TOOLTIP_BACKGROUND,
		//! Scrollbar gray area
		EGDC_SCROLLBAR,
		//! Window background
		EGDC_WINDOW,
		//! Window symbols like on close buttons, scroll bars and check boxes
		EGDC_WINDOW_SYMBOL,
		//! Icons in a list or tree
		EGDC_ICON,
		//! Selected icons in a list or tree
		EGDC_ICON_HIGH_LIGHT,
		//! Grayed (disabled) window symbols like on close buttons, scroll bars and check boxes
		EGDC_GRAY_WINDOW_SYMBOL,
		//! Window background for editable field (editbox, checkbox-field)
		EGDC_EDITABLE,
		//! Grayed (disabled) window background for editable field (editbox, checkbox-field)
		EGDC_GRAY_EDITABLE,
		//! Show focus of window background for editable field (editbox or when checkbox-field is pressed)
		EGDC_FOCUSED_EDITABLE,

		//! this value is not used, it only specifies the amount of default colors
		//! available.
		EGDC_COUNT
	};

	//! Enumeration for default sizes.
	enum EGUI_DEFAULT_SIZE
	{
		//! default with / height of scrollbar. Also width of drop-down button in comboboxes.
		EGDS_SCROLLBAR_SIZE = 0,
		//! width and height of a window titlebar button (like minimize/maximize/close buttons). The titlebar height is also calculated from that.
		EGDS_WINDOW_BUTTON_WIDTH,
		//! width of a checkbox check
		EGDS_CHECK_BOX_WIDTH,
		//! width of a default button
		EGDS_BUTTON_WIDTH,
		//! height of a default button (OK and cancel buttons)
		EGDS_BUTTON_HEIGHT,
		//! distance for text from background
		EGDS_TEXT_DISTANCE_X,
		//! distance for text from background
		EGDS_TEXT_DISTANCE_Y,
		//! pixels to move an unscaled button image to the right when a button is pressed and the unpressed image looks identical
		EGDS_BUTTON_PRESSED_IMAGE_OFFSET_X,
		//! pixels to move an unscaled button image down when a button is pressed  and the unpressed image looks identical
		EGDS_BUTTON_PRESSED_IMAGE_OFFSET_Y,
		//! pixels to move the button text to the right when a button is pressed
		EGDS_BUTTON_PRESSED_TEXT_OFFSET_X,
		//! pixels to move the button text down when a button is pressed
		EGDS_BUTTON_PRESSED_TEXT_OFFSET_Y,
		//! pixels to move an unscaled button sprite to the right when a button is pressed
		EGDS_BUTTON_PRESSED_SPRITE_OFFSET_X,
		//! pixels to move an unscaled button sprite down when a button is pressed
		EGDS_BUTTON_PRESSED_SPRITE_OFFSET_Y,

		//! this value is not used, it only specifies the amount of default sizes
		//! available.
		EGDS_COUNT
	};

	//! Customizable symbols for GUI
	enum EGUI_DEFAULT_ICON
	{
		//! scroll bar up button
		EGDI_CURSOR_UP = 0,
		//! scroll bar down button
		EGDI_CURSOR_DOWN,
		//! scroll bar left button
		EGDI_CURSOR_LEFT,
		//! scroll bar right button
		EGDI_CURSOR_RIGHT,
		//! tick for checkbox
		EGDI_CHECK_BOX_CHECKED,

		//! value not used, it only specifies the number of icons
		EGDI_COUNT
	};

	// Customizable fonts
	enum EGUI_DEFAULT_FONT
	{
		//! For static text, edit boxes, lists and most other places
		EGDF_DEFAULT=0,
		//! Font for buttons
		EGDF_BUTTON,
		//! Font for tooltips
		EGDF_TOOLTIP,
		//! this value is not used, it only specifies the amount of default fonts
		//! available.
		EGDF_COUNT
	};

	//! A skin modifies the look of the GUI elements.
	class IGUISkin : virtual public IReferenceCounted
	{
	public:

		//! returns default color
		virtual video::SColor getColor(EGUI_DEFAULT_COLOR color) const = 0;

		//! sets a default color
		virtual void setColor(EGUI_DEFAULT_COLOR which, video::SColor newColor) = 0;

		//! returns size for the given size type
		virtual s32 getSize(EGUI_DEFAULT_SIZE size) const = 0;

		//! sets a default size
		virtual void setSize(EGUI_DEFAULT_SIZE which, s32 size) = 0;

		//! returns the default font
		virtual IGUIFont* getFont(EGUI_DEFAULT_FONT which=EGDF_DEFAULT) const = 0;

		//! sets a default font
		virtual void setFont(IGUIFont* font, EGUI_DEFAULT_FONT which=EGDF_DEFAULT) = 0;

		//! returns the sprite bank
		virtual IGUISpriteBank* getSpriteBank() const = 0;

		//! sets the sprite bank
		virtual void setSpriteBank(IGUISpriteBank* bank) = 0;

		//! Returns a default icon
		/** Returns the sprite index within the sprite bank */
		virtual u32 getIcon(EGUI_DEFAULT_ICON icon) const = 0;

		//! Sets a default icon
		/** Sets the sprite index used for drawing icons like arrows,
		close buttons and ticks in checkboxes
		\param icon: Enum specifying which icon to change
		\param index: The sprite index used to draw this icon */
		virtual void setIcon(EGUI_DEFAULT_ICON icon, u32 index) = 0;

		//! draws a standard 3d button pane
		/** Used for drawing for example buttons in normal state.
		It uses the colors EGDC_3D_DARK_SHADOW, EGDC_3D_HIGH_LIGHT, EGDC_3D_SHADOW and
		EGDC_3D_FACE for this. See EGUI_DEFAULT_COLOR for details.
		\param element: Pointer to the element which wishes to draw this. This parameter
		is usually not used by IGUISkin, but can be used for example by more complex
		implementations to find out how to draw the part exactly.
		\param rect: Defining area where to draw.
		\param clip: Clip area. */
		virtual void draw3DButtonPaneStandard(IGUIElement* element,
			const core::rect<s32>& rect,
			const core::rect<s32>* clip=0) = 0;

		//! draws a pressed 3d button pane
		/** Used for drawing for example buttons in pressed state.
		It uses the colors EGDC_3D_DARK_SHADOW, EGDC_3D_HIGH_LIGHT, EGDC_3D_SHADOW and
		EGDC_3D_FACE for this. See EGUI_DEFAULT_COLOR for details.
		\param element: Pointer to the element which wishes to draw this. This parameter
		is usually not used by IGUISkin, but can be used for example by more complex
		implementations to find out how to draw the part exactly.
		\param rect: Defining area where to draw.
		\param clip: Clip area. */
		virtual void draw3DButtonPanePressed(IGUIElement* element,
			const core::rect<s32>& rect,
			const core::rect<s32>* clip=0) = 0;

		//! draws a sunken 3d pane
		/** Used for drawing the background of edit, combo or check boxes.
		\param element: Pointer to the element which wishes to draw this. This parameter
		is usually not used by IGUISkin, but can be used for example by more complex
		implementations to find out how to draw the part exactly.
		\param bgcolor: Background color.
		\param flat: Specifies if the sunken pane should be flat or displayed as sunken
		deep into the ground.
		\param fillBackGround: Specifies if the background should be filled with the background
		color or not be drawn at all.
		\param rect: Defining area where to draw.
		\param clip: Clip area. */
		virtual void draw3DSunkenPane(IGUIElement* element,
			video::SColor bgcolor, bool flat, bool fillBackGround,
			const core::rect<s32>& rect,
			const core::rect<s32>* clip=0) = 0;

		//! draws a tab button
		/** Used for drawing for tab buttons on top of tabs.
		\param element: Pointer to the element which wishes to draw this. This parameter
		is usually not used by IGUISkin, but can be used for example by more complex
		implementations to find out how to draw the part exactly.
		\param active: Specifies if the tab is currently active.
		\param rect: Defining area where to draw.
		\param clip: Clip area.
		\param alignment Alignment of GUI element. */
		virtual void draw3DTabButton(IGUIElement* element, bool active,
			const core::rect<s32>& rect, const core::rect<s32>* clip=0, gui::EGUI_ALIGNMENT alignment=EGUIA_UPPERLEFT) = 0;

		//! draws a tab control body
		/** \param element: Pointer to the element which wishes to draw this. This parameter
		is usually not used by IGUISkin, but can be used for example by more complex
		implementations to find out how to draw the part exactly.
		\param border: Specifies if the border should be drawn.
		\param background: Specifies if the background should be drawn.
		\param rect: Defining area where to draw.
		\param clip: Clip area.
		\param tabHeight Height of tab.
		\param alignment Alignment of GUI element. */
		virtual void draw3DTabBody(IGUIElement* element, bool border, bool background,
			const core::rect<s32>& rect, const core::rect<s32>* clip=0, s32 tabHeight=-1, gui::EGUI_ALIGNMENT alignment=EGUIA_UPPERLEFT ) = 0;

		//! draws an icon, usually from the skin's sprite bank
		/** \param element: Pointer to the element which wishes to draw this icon.
		This parameter is usually not used by IGUISkin, but can be used for example
		by more complex implementations to find out how to draw the part exactly.
		\param icon: Specifies the icon to be drawn.
		\param position: The position to draw the icon
		\param starttime: The time at the start of the animation
		\param currenttime: The present time, used to calculate the frame number
		\param loop: Whether the animation should loop or not
		\param clip: Clip area. */
		virtual void drawIcon(IGUIElement* element, EGUI_DEFAULT_ICON icon,
			const core::position2di position, u32 starttime=0, u32 currenttime=0,
			bool loop=false, const core::rect<s32>* clip=0) = 0;

		//! draws a 2d rectangle.
		/** \param element: Pointer to the element which wishes to draw this icon.
		This parameter is usually not used by IGUISkin, but can be used for example
		by more complex implementations to find out how to draw the part exactly.
		\param color: Color of the rectangle to draw. The alpha component specifies how
		transparent the rectangle will be.
		\param pos: Position of the rectangle.
		\param clip: Pointer to rectangle against which the rectangle will be clipped.
		If the pointer is null, no clipping will be performed. */
		virtual void draw2DRectangle(IGUIElement* element, const video::SColor &color,
			const core::rect<s32>& pos, const core::rect<s32>* clip = 0) = 0;

		//! get the type of this skin
		virtual EGUI_SKIN_TYPE getType() const { return EGST_UNKNOWN; }
	};


} // end namespace gui
} // end namespace irr

#endif

