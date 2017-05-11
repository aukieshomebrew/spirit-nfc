#ifndef MENU_H
#define MENU_H



#include <stdio.h>


struct Item {
    char* item_name;
};

class Menu {
    private:
        int n_item_selected;
        int offset;

        int n_items;
        Item* item;
        void printSelected(int n, char* str);
        void printNormal(int n, char* str);

    public:
        void printMenu();
        void menuUp();
        void menuDown();

        void addItem(char* name);

        int getItemSelected();
    

        Menu(int offset);
        ~Menu();
};

#endif