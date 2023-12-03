#include "Menu.h"
#include <iostream>
#include <string>
using namespace std;
char getSelection(string selection);
#pragma region constructors and destructors
Menu::Menu()
{
    
}

Menu::~Menu()
{
}

#pragma endregion

#pragma region Main Menu
void Menu::printMainM()
{
    cout << "Main Menu" << endl;
    cout << "1. Create" << endl;
    cout << "2. Play" << endl;
    cout << "3. Quit" << endl;
    cout << "Enter your selection using the selection's number:" << endl;
}

void Menu::load()
{
    int selection;
    while (true)
    {
        printMainM();
        cin >> selection;

        switch (selection)
        {
        case 1:
            CreateMenu();
            break;
        default:
            break;
        }
        
        if (selection == 3)
        {
            break;
        }
    }
}
#pragma endregion

#pragma region Create Menu Main
void Menu::printCreateMenuMain()
{
    cout << "Create Help Menu" << endl;
    cout << "1. Start a new Map" << endl;
    cout << "2. Load a Map" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your selection using the selection's number:" << endl;
}

void Menu::CreateMenuMain()
{
    int selection;
    while (true)
    {
        printCreateMenuMain();
        cin >> selection;

        switch (selection)
        {
        case 1:
            // Start a new Map
            //TODO: Create a new map obj
            CreateMenu();
            break;
        case 2:
            // Load a Map
            break;
        default:
            break;
        }
        
        if (selection == 3)
        {
            break;
        }
    }
}
#pragma endregion

#pragma region Create Menu
/*
╔═══════════════╦════════════════════════════════════════════════════════╗
║ Command       ║   Function                                             ║
╠═══════════════╬════════════════════════════════════════════════════════╣
║ n or north    ║   move north                                           ║
╠═══════════════╬════════════════════════════════════════════════════════╣
║ s or south    ║   move south                                           ║
╠═══════════════╬════════════════════════════════════════════════════════╣
║ e or east     ║   move east                                            ║
╠═══════════════╬════════════════════════════════════════════════════════╣
║ w or west     ║   move west                                            ║
╠═══════════════╬════════════════════════════════════════════════════════╣
║ l or look     ║   show room description                                ║
╠═══════════════╬════════════════════════════════════════════════════════╣
║ x or exits    ║   list exits from current room                         ║
╠═══════════════╬════════════════════════════════════════════════════════╣
║ c or connect  ║   connect this room to another (already existing) room ║
╠═══════════════╬════════════════════════════════════════════════════════╣
║ r or rename   ║   rename the current room                              ║
╠═══════════════╬════════════════════════════════════════════════════════╣
║ d or desc     ║   change the description of the current room           ║
╠═══════════════╬════════════════════════════════════════════════════════╣
║ a or add      ║   add a new room to the game                           ║
╠═══════════════╬════════════════════════════════════════════════════════╣
║ q or quit     ║   quit the roombuilder tool                            ║
╠═══════════════╬════════════════════════════════════════════════════════╣
║ ?             ║   show a help menu                                     ║
╚═══════════════╩════════════════════════════════════════════════════════╝
*/
void Menu::printCreateM()
{
    cout << "╔════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                    Adventure Game Map Creator v1.01                    ║" << endl;
    cout << "╠═══════════════╦════════════════════════════════════════════════════════╣" << endl;
    cout << "║ Command       ║   Function                                             ║" << endl;
    cout << "╠═══════════════╬════════════════════════════════════════════════════════╣" << endl;
    cout << "║ n or north    ║   move north                                           ║" << endl;
    cout << "╠═══════════════╬════════════════════════════════════════════════════════╣" << endl;
    cout << "║ s or south    ║   move south                                           ║" << endl;
    cout << "╠═══════════════╬════════════════════════════════════════════════════════╣" << endl;
    cout << "║ e or east     ║   move east                                            ║" << endl;
    cout << "╠═══════════════╬════════════════════════════════════════════════════════╣" << endl;
    cout << "║ w or west     ║   move west                                            ║" << endl;
    cout << "╠═══════════════╬════════════════════════════════════════════════════════╣" << endl;
    cout << "║ l or look     ║   show room description                                ║" << endl;
    cout << "╠═══════════════╬════════════════════════════════════════════════════════╣" << endl;
    cout << "║ x or exits    ║   list exits from current room                         ║" << endl;
    cout << "╠═══════════════╬════════════════════════════════════════════════════════╣" << endl;
    cout << "║ c or connect  ║   connect this room to another (already existing) room ║" << endl;
    cout << "╠═══════════════╬════════════════════════════════════════════════════════╣" << endl;
    cout << "║ r or rename   ║   rename the current room                              ║" << endl;
    cout << "╠═══════════════╬════════════════════════════════════════════════════════╣" << endl;
    cout << "║ d or desc     ║   change the description of the current room           ║" << endl;
    cout << "╠═══════════════╬════════════════════════════════════════════════════════╣" << endl;
    cout << "║ a or add      ║   add a new room to the game                           ║" << endl;
    cout << "╠═══════════════╬════════════════════════════════════════════════════════╣" << endl;
    cout << "║ f or find     ║   find a room by name                                  ║" << endl;
    cout << "╠═══════════════╬════════════════════════════════════════════════════════╣" << endl;
    cout << "║ q or quit     ║   save and quit the map creator tool                   ║" << endl;
    cout << "╠═══════════════╬════════════════════════════════════════════════════════╣" << endl;
    cout << "║ ?             ║   show a help menu                                     ║" << endl;
    cout << "╚═══════════════╩════════════════════════════════════════════════════════╝" << endl;
    cout << "Enter your selection using the selection's number:" << endl;
}

void Menu::CreateMenu()
{
    //TODO: Make a Map obj based on if the user wants to load or create a new map
        //TODO: if we load the onject then we need to load the Object
        //TODO: if we create a new map then we need to create a new object
    
    //TODO: 
    string selectionString;
    char selection;
    while (true)
    {
        printCreateM();

        cin.ignore();
        getline(cin, selectionString);

        selection = getSelection(selectionString); // Turns from selection string into a char for the switch statement
        

        switch (selection)
        {
        case 'n':
            // Create Room
            break;
        case 's':
            // Create Item
            break;
        case 'e':
            // Create Creature
            break;
        case 'w':
            // Create Exit
            break;
        case 'l':
            // Go to Room
            break;
        case 'x':
            // Save
            break;
        case 'c':
            // Save
            break;
        case 'r':
            // Save
            break;
        case 'd':
            // Save
            break;
        case 'a':
            // Save
            break;
        case 'f':
            // Save
            break;
        case 'q':
            // Save
            break;
        case '?':
            // Save
            break;
        default:
            break;
        }
    }
}

#pragma endregion

#pragma region Create Help
void Menu::printCreateHelpM()
{
    cout << "Create Help Menu" << endl;
    cout << "1. Create Room" << endl;
    cout << "2. Create Item" << endl;
    cout << "3. Create Creature" << endl;
    cout << "4. Create Exit" << endl;
    cout << "5. Go to Room" << endl;
    cout << "6. Save" << endl;
    cout << "Enter your selection using the selection's number:" << endl;
}
#pragma endregion

#pragma region local functions
char getSelection(string selection)
{
    if (selection == "n" || selection == "north")
    {
        return 'n';
    }
    else if (selection == "s" || selection == "south")
    {
        return 's';
    }
    else if (selection == "e" || selection == "east")
    {
        return 'e';
    }
    else if (selection == "w" || selection == "west")
    {
        return 'w';
    }
    else if (selection == "l" || selection == "look")
    {
        return 'l';
    }
    else if (selection == "x" || selection == "exits")
    {
        return 'x';
    }
    else if (selection == "c" || selection == "connect")
    {
        return 'c';
    }
    else if (selection == "r" || selection == "rename")
    {
        return 'r';
    }
    else if (selection == "d" || selection == "desc")
    {
        return 'd';
    }
    else if (selection == "a" || selection == "add")
    {
        return 'a';
    }
    else if (selection == "f" || selection == "find")
    {
        return 'f';
    }
    else if (selection == "q" || selection == "quit")
    {
        return 'q';
    }
    else if (selection == "?")
    {
        return '?';
    }
    else
    {
        cout << "Invalid selection" << endl;
        return '0';
    }
}
#pragma endregion