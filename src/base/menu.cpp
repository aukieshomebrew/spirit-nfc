#include "menu.h"

Menu::Menu(int offset)
{
    this->n_item_selected = 0;
    this->n_items = 0;
    this->item = new Item[16];
    this->offset = offset;

    
   

}

void Menu::addItem(char* name)
{
    if(this->n_items > 16)
    {
        return;
    }
    this->item[this->n_items].item_name = name;
    this->n_items++;
}

void Menu::menuUp()
{
    this->n_item_selected--;
    if(this->n_item_selected < 0)
    {
        this->n_item_selected = 0;
    }
}

void Menu::menuDown()
{
    this->n_item_selected++;
    if(this->n_item_selected >= this->n_items)
    {
        this->n_item_selected = this->n_items - 1;
    }
}

void Menu::printNormal(int n, char* str)
{
    printf("\x1b[%d;0H%s", n + this->offset, str);
}

void Menu::printSelected(int n, char* str)
{
    printf("\x1b[%d;0H\x1b[47;30m%s\x1b[0m", n + this->offset, str);
}

void Menu::printMenu()
{

    printf("\x1b[0;0H%s", "Spirit NFC");
    printf("\x1b[2;0H%s", "By Homebrew Technics");

    for(int i = 0; i < this->n_items; i++)
    {
        if(i == this->n_item_selected)
        {
            this->printSelected(i, this->item[i].item_name);
        }
        else
        {
            this->printNormal(i, this->item[i].item_name);
        }
    }
}

int Menu::getItemSelected()
{
    return this->n_item_selected;
}