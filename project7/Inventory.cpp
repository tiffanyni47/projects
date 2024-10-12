#include "Inventory.hpp"
/*
Author: Tiffany Ni
Course: CSCI-235
Email: tiffany.ni47@myhunter.cuny.edu
Instructor: Tiziana Ligorio
Assignment: Project 7
*/

/**
 * @param : A Pointer to the Item object to be added to the inventory.
 * @post  : The Item is added to the inventory, preserving the BST structure. The BST property is based on (ascending) alphabetical order of the item's name.
 *          If the item is type UNKNOWN, WEAPON, or ARMOR and is already in the inventory, it is not added.
      However, if another instance of an Item of type CONSUMABLE is being added (an item with the same name), its quantity is updated to the sum of the quantities of the two objects, and the time_picked_up_ variable is updated to that of the latest instance of the item being added.
 * @return true if the item was added to the inventory or updated, false otherwise.
 */
bool Inventory::addItem(Item *item)
{
    if(contains(item)){
        if(item->getType() == "CONSUMABLE"){
            auto current_existing_item = getPointerTo(item);
            current_existing_item->getItem()->setQuantity(item->getQuantity() + current_existing_item->getItem()->getQuantity());
            current_existing_item->getItem()->setTimePickedUp(item->getTimePickedUp());
            return true;
        }
        else{
            return false;
        }
    }
    else{
        add(item);
        return true;
    }
}

/**
 * @param   : A reference to string name of the item to be found.
 * @return  : An Item pointer to the found item, or nullptr if the item is not in the inventory.
 */
Item* Inventory::findItem(const std::string &item_name) const
{
    Item* item = new Item();
    item->setName(item_name);
    if(contains(item)){
        std::shared_ptr<BinaryNode<Item*>> tree_item = getPointerTo(item);
        return tree_item->getItem();
    }
    else{
        return nullptr;
    }
}

/**
 * @param   : A reference to string name of the item to be removed from the inventory.
 * @return  : True if the item was found and removed or updated successfully, false otherwise.
 * @post    : If the item is found in the inventory, it is removed while preserving the BST structure.
              If a CONSUMABLE is removed, its quantity is decremented by one, but its time_picked_up_ remains the same. However, if it is the last item (it's quantity is 1 and is being removed), the item should be removed. Non-CONSUMABLE items should always be removed when they are found.
 */
bool Inventory::removeItem(const std::string &item_name)
{
    if(findItem(item_name) != nullptr){
        if(findItem(item_name)->getType() == "CONSUMABLE"){
            if(findItem(item_name)->getQuantity() - 1 == 0){
                remove(findItem(item_name));
                return true;
            }
            else{
                findItem(item_name)->setQuantity(findItem(item_name)->getQuantity() - 1);
                return false;
            }
        }
        else{
            remove(findItem(item_name));
            return true;
        }
    }
    else{
        return false;
    }
}

/**
 * @return    : The total sum of gold values of all items in the inventory.
                Note: consumable items may have quantity >1 and gold value must be
                      added for each item
 */
int Inventory::getTotalGoldValue() const
{
    int totalGoldValue = 0;
    std::vector<Item*> allItems = getAllItem();
    for(int i = 0; i < allItems.size(); i++){
        totalGoldValue += allItems[i]->getQuantity() * allItems[i]->getGoldValue();
    }
    return totalGoldValue;
}

/**
 * @post    : The names of all items in the Inventory are printed in ascending order.
 *            This function performs an in-order traversal of the binary search tree and prints the details of each item in the following format. 
        NOTE: QUANTITY ONLY NEEDS TO BE DISPLAYED FOR CONSUMABLE ITEMS.

 *            [NAME] ([TYPE])
              Level: [LEVEL]
              Value: [VALUE]
              Quantity: [QUANTITY]
   
              Example:
              TIRED GAUNTLETS (ARMOR)
              Level: 3
              Value: 25
        
              SMALL HEALTH POTION (CONSUMABLE)
              Level: 1
              Value: 10
              Quantity: 2
**/
void Inventory::printInventoryInOrder()
{
    std::vector<Item*> items = getAllItem();
    for(int i = 0; i < items.size(); i++){
        std::cout << items[i]->getName() << " (" <<  items[i]->getType() << ")\n"
        << "Level: " << items[i]->getLevel() << "\n"
        << "Value: " << items[i]->getGoldValue() << "\n";
        if(items[i]->getType() == "CONSUMABLE"){
            std::cout << "Quantity: " << items[i]->getQuantity() << "\n\n";
        }
        else{
            std::cout << "\n";
        }
    }
}

/**
 * @param   : a reference to bool if the items are to be printed in ascending order. 
 * @param   : a reference to string attribute which defines the order by which the items are to be printed. You may assume that the given parameter will be in one of the following forms: ["NAME"/"TYPE"/"LEVEL"/"VALUE"/"TIME"]
 * @post    : All items in the Inventory are printed in the order specified by the parameter.
 *          Example usage: inventory.printInventory(false, "LEVEL");
            NOTE: QUANTITY ONLY NEEDS TO BE DISPLAYED FOR CONSUMABLE ITEMS:

            FEATHER DUSTER (WEAPON)
            Level: 5
            Value: 100

            TIRED GAUNTLETS (ARMOR)
            Level: 3
            Value: 50

            SMALL HEALTH POTION (CONSUMABLE)
            Level: 1
            Value: 10
            Quantity: 2

            NOODLES (CONSUMABLE)
            Level: 0
            Value: 120
            Quantity: 5
 */
void Inventory::printInventory(bool inOrder, const std::string& attribute)
{
    std::vector<Item*> items = getAllItem();
    if(attribute == "NAME"){
        if(inOrder == false){
        std::reverse(items.begin(), items.end());
        }
    }
    else if(attribute == "TYPE"){
        std::sort(items.begin(), items.end(), [this](Item* lhs, Item* rhs){
            return lhs->getType() < rhs->getType();
        });
        if(inOrder == false){
        std::reverse(items.begin(), items.end());
        }
    }
    else if(attribute == "LEVEL"){
        if(inOrder == true){
            std::sort(items.begin(), items.end(), [this](Item* lhs, Item* rhs){
                return lhs->getLevel() < rhs->getLevel();
            });
        }
        else{
            std::sort(items.begin(), items.end(), [this](Item* lhs, Item* rhs){
                return lhs->getLevel() > rhs->getLevel();
            });
        }
    }
    else if(attribute == "VALUE"){
        if(inOrder == true){
            std::sort(items.begin(), items.end(), [this](Item* lhs, Item* rhs){
                return lhs->getGoldValue() < rhs->getGoldValue();
            });
        }
        else{
            std::sort(items.begin(), items.end(), [this](Item* lhs, Item* rhs){
                return lhs->getGoldValue() > rhs->getGoldValue();
            });
        }
    }
    else if(attribute == "TIME"){
        std::sort(items.begin(), items.end(), [this](Item* lhs, Item* rhs){
            return lhs->getTimePickedUp() < rhs->getTimePickedUp();
        });
        if(inOrder == false){
        std::reverse(items.begin(), items.end());
        }
    }
    for(int i = 0; i < items.size(); i++){
        std::cout << items[i]->getName() << " (" <<  items[i]->getType() << ")\n"
        << "Level: " << items[i]->getLevel() << "\n"
        << "Value: " << items[i]->getGoldValue() << "\n";
        if(items[i]->getType() == "CONSUMABLE"){
            std::cout << "Quantity: " << items[i]->getQuantity() << "\n\n";
        }
        else{
            std::cout << "\n";
        }
    }
}

void Inventory::setAllItems(std::vector<Item*>& allItem, std::shared_ptr<BinaryNode<Item *>> tree_ptr) const
{
    if(tree_ptr != nullptr){
        setAllItems(allItem, tree_ptr->getLeftChildPtr());
        Item* current_item = tree_ptr->getItem();
        allItem.push_back(current_item);
        setAllItems(allItem, tree_ptr->getRightChildPtr());
    }
}

std::vector<Item *> Inventory::getAllItem() const
{
    std::vector<Item*> allItems;
    setAllItems(allItems, getRoot());
    return allItems;
}
