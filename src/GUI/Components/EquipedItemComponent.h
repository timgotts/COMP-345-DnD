#pragma once
#include "Pane.h"
#include "../../Item.h"
#include "Button.h"
/**
 * Component used to display items from an array
 */
class EquipedItemComponent:public Pane, public Observer
{
public:
	/**
	 * Constructor given an array of item pointers, x, y , width, height
	 */
	EquipedItemComponent(Item** items,int x, int y, int width, int height);
	/**
	 * Override Pane render method
	 */
	void render() override;
	/**
	 * Override Pane click method
	 */
	void click(int x, int y) override;
	/**
	 * Add callback for when an item is clicked
	 */
	void addOnItemClick_callback(std::function<void(Item*, int)>);
	/**
	 * Set the item array
	 */
	void setItems(Item** itms);
	/**
	 * Called when subject is changed
	 */
	void Update() override;

	~EquipedItemComponent();
private:
	Item** items;
	std::vector<Button*> itemButtons;

	std::vector<std::function<void(Item*,int)>> onItemClickCallback;
};
