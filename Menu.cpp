#include "Menu.h";
#include <iostream>;
using namespace std;

Menu::Menu()
{
    
}

Menu::~Menu()
{
}

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


void Menu::printCreateM()
{
    cout << "Create Menu" << endl;
    cout << "1. Create Room" << endl;
    cout << "2. Create Exit" << endl;
    cout << "3. Go to Room" << endl;
    cout << "4. Save/Exit" << endl;
    cout << "5. Help" << endl;
    cout << "Enter your selection using the selection's number:" << endl;
}
void Menu::CreateMenu()
{
    int selection;
    while (true)
    {
        printCreateM();
        cin >> selection;

        switch (selection)
        {
        case 1:
            // Create Room
            break;
        case 2:
            // 2. Create Exit
            break;
        case 3:
            // Go to Room
            break;
        case 5:
            // Help
            CreateHelp();
            break;
        default:
            break;
        }
        
        if (selection == 4)
        {
            //TODO need to save before exiting
            break;
        }
    }
}


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
