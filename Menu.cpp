#include "Menu.h"
#include "Room.h"
#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;
char getSelection(string selection);
void addRoom(map<string, Room*>& rooms);
void jumpToRoom(map<string, Room*>& rooms, Room &currRoom);
void changeDec(Room &currRoom);
void rename(Room &currRoom);
void connectRooms(map<string, Room*>& rooms, Room &currRoom);
void printEmptyExits(Room currRoom);
void printExits(Room currRoom);
Direction getDoorPick(string doorPick);
void pressEnter();
void saveMap(map<string, Room*> rooms);
map<string, Room*> loadMap();
string findOtherExit(string name, Room* room);


// default constructor and destructor
#pragma region constructors and destructors
Menu::Menu()
{
    
}

Menu::~Menu()
{
}

#pragma endregion

#pragma region Main Menu
// Main Menu
void Menu::printMainM()
{
    cout << "Main Menu" << endl;
    cout << "1. Create" << endl;
    cout << "2. Play" << endl;
    cout << "3. Quit" << endl;
    cout << "Enter your selection using the selection's number:" << endl;
}

// Main Menu
void Menu::load()
{
    int selection;
    // while loop to get input from the user
    while (true)
    {
        printMainM();

        cin >> selection;
        cin.ignore();
        switch (selection)
        {
        case 1:
            CreateMenuMain();
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
// Create Menu Main
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
    // while loop to get input from the user
    while (true)
    {
        printCreateMenuMain();

        cin >> selection;
        cin.ignore();

        switch (selection)
        {
        case 1:

            // if the user wants to start a new Map
            CreateMenu(false);
            break;
        case 2:
            // if the user wants to load a map
            CreateMenu(true);
            break;
        case 3:
            return;
            break;
        default:
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
    cout << "║ j or jump     ║   jump to a room by name                               ║" << endl;
    cout << "╠═══════════════╬════════════════════════════════════════════════════════╣" << endl;
    cout << "║ q or quit     ║   save and quit the map creator tool                   ║" << endl;
    cout << "╠═══════════════╬════════════════════════════════════════════════════════╣" << endl;
    cout << "║ ?             ║   reprint the menu                                     ║" << endl;
    cout << "╚═══════════════╩════════════════════════════════════════════════════════╝" << endl;
    
}

void Menu::CreateMenu(bool ifloadgame)
{
    string selectionString;
    char selection;
    Room* currentRoom;
    map <string, Room *> rooms;
    // Will create a new room of the user decides to 
    if (ifloadgame)
    {
        cout << "What is the name of the map you want load?" << endl;
        // Load map from file
        rooms = loadMap();
        currentRoom = rooms.begin()->second;
    } 
    else
    {
        //  Create a new room if we arent making a new map
        currentRoom = new Room("The Void", "You are in the void");
        rooms["The Void"] = currentRoom;
    }
    
    while (true)
    {
        // Print the menu
        printCreateM();
        cout << "Current Room: " << currentRoom->name() << endl;
        cout << "═════════════════════════════" << endl;
        cout << "> ";

        getline(cin, selectionString);
        cout << endl;
        
        // Turns from selection string into a char for the switch statement
        selection = getSelection(selectionString); 
        
        // Switch statement for the menu choices
        switch (selection)
        {
        case 'n':
            // move north
            if (currentRoom->north() == nullptr)
            {
                // if there is no room to the north
                cout << "There is no room to the north." << endl;
                pressEnter();
            }
            else
            {
                // if there is a room to the north
                currentRoom = currentRoom->north();
                cout << "You are now in the " << currentRoom->name() << endl;
                pressEnter();
            }
            break;

        case 's':
            // move south
            if (currentRoom->south() == nullptr)
            {
                // if there is no room to the south
                cout << "There is no room to the south." << endl;
                pressEnter();
            }
            else
            {
                // if there is a room to the south
                currentRoom = currentRoom->south();
                cout << "You are now in the " << currentRoom->name() << endl;
                pressEnter();
            }
            break;

        case 'e':
            // move east
            if (currentRoom->east() == nullptr)
            {
                // if there is no room to the east
                cout << "There is no room to the east." << endl;
                pressEnter();
            }
            else
            {
                // if there is a room to the east
                currentRoom = currentRoom->east();
                cout << "You are now in the " << currentRoom->name() << endl;
                pressEnter();
            }
            break;

        case 'w':
            // move west
            if (currentRoom->west() == nullptr)
            {
                // if there is no room to the west
                cout << "There is no room to the west." << endl;
                pressEnter();
            }
            else
            {
                // if there is a room to the west
                currentRoom = currentRoom->west();
                cout << "You are now in the " << currentRoom->name() << endl;
                pressEnter();
            }
            break;

        case 'l':
            // show room description
            cout << "Room Name: "<< endl << currentRoom->name() << endl << endl;
            cout << "Room Description:" << endl;
            cout << currentRoom->description() << endl;
            pressEnter();
            break;

        case 'x':
            // list exits from current room
            printExits(*currentRoom);
            pressEnter();
            break;

        case 'c':
            // connect this room to another (already existing) room
            connectRooms(rooms, *currentRoom);
            pressEnter();
            break;

        case 'r':
            // rename the current room
            rename(*currentRoom);
            pressEnter();
            break;

        case 'd':
            // change the description of the current room
            changeDec(*currentRoom);
            pressEnter();
            break;

        case 'a':
            // add a new room to the game
            addRoom(rooms);
            pressEnter();
            break;

        case 'j':
            // jump to a room by name
            jumpToRoom(rooms, *currentRoom);
            pressEnter();
            break;

        case 'q':
            // save in the JSON and quit the map creator tool
            
            saveMap(rooms);
            return;
            break;

        case '?':
            // reprints the menu
            printCreateM();
            break;

        default:
            break;
        }
    }
}

#pragma endregion



#pragma region local functions
// Function to turn the selection string into a char for the switch statement
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
    else if (selection == "j" || selection == "jump")
    {
        return 'j';
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
        pressEnter();
        return '0';
    }
}

// Function to add a new room to the map of rooms
void addRoom(map<string, Room*>& rooms)
{
    // Declare variables to hold the room name and description
    string roomName;
    string roomDesc;

    // Create a new Room object on the heap
    Room* newRoom = new Room();

    // Prompt the user to enter the room name
    cout << "Enter the name of the room." << endl;
    getline(cin, roomName);

    // Set the name of the new Room object
    newRoom->set_name(roomName);
    
    // Read the room description from the user
    cout << "Enter the description of the room." << endl;
    getline(cin, roomDesc);

    // Set the description of the new Room object
    newRoom->set_description(roomDesc);

    // Add the new Room object to the map, using the room name as the key
    rooms[roomName] = newRoom;

    // Print a confirmation message
    cout << "Room added." << endl;
}

void jumpToRoom(map<string, Room*>& rooms, Room &currRoom)
{
    string roomName;
    cout << "Enter the name of the room you want to jump to: " << endl;
    
    getline(cin, roomName);
    if (rooms.find(roomName) == rooms.end())
    {
        cout << "Room not found." << endl;
    }
    else
    {
        currRoom = *rooms[roomName];
        cout << "Jumped to room: " << roomName << endl;
    }
}

// Function to change the description of the current room
void changeDec(Room &currRoom)
{
    string newDesc;
    cout << "Enter the new description of the room: " << endl;
    
    getline(cin, newDesc);
    currRoom.set_description(newDesc);
    cout << "Description changed." << endl;
}

// Function to rename the current room
void rename(Room &currRoom)
{
    string newName;
    cout << "Enter the new name of the room: " << endl;
    
    getline(cin, newName);
    currRoom.set_name(newName);
    cout << "Name changed." << endl;
}

// Function to connect the current room to another room
void connectRooms(map<string, Room*>& rooms, Room& currRoom)
{
    // Prompt the user to enter the name of the room to connect to
    string roomName;
    cout << "Enter the name of the room you want to connect to: " << endl;
    getline(cin, roomName);

    // Check if the room exists
    if (rooms.find(roomName) == rooms.end())
    {
        cout << "Room not found." << endl;
    } 
    else if (currRoom.name() == "The Void")
    {
        cout << "You cant connect a room with \"The Void\"." << endl;
    }
    else // if the room exists
    {
        // Prompt the user to enter the direction to connect the rooms
        string doorPick1;
        string doorPick2;
        
        // Prompt the user to enter the direction to connect the rooms
        cout << "In the current room, What door do you want to connect the new room to?" << endl;
        printEmptyExits(currRoom);
        getline(cin, doorPick1);

        // Prompt the user to enter the direction to connect the rooms
        cout << "In the new room, What door do you want to connect the current room to?" << endl;
        printEmptyExits(*rooms[roomName]);
        getline(cin, doorPick2);
        
        // Connect the rooms
        currRoom.connect(getDoorPick(doorPick1), rooms[roomName], getDoorPick(doorPick2));
        cout << "Connected to room: " << roomName << endl;
    }
}

void printEmptyExits(Room currRoom)
{
    // Print the available exits
    cout << "Avalible Exits to Choose: " << endl;
    if (currRoom.north() == nullptr)
    {
        cout << " - north" << endl;
    }
    if (currRoom.south() == nullptr)
    {
        cout << " - south" << endl;
    }
    if (currRoom.east() == nullptr)
    {
        cout << " - east" << endl;
    }
    if (currRoom.west() == nullptr)
    {
        cout << " - west" << endl;
    }
    cout << "════════════════════════════════════════════════════════════════════════" << endl;
}

// Function to print the exits of the current room
void printExits(Room currRoom)
{
    // Print the available exits
    bool found = false;
    cout << "Exits in Room: " << endl;

    // Print the available exits
    if (currRoom.north() != nullptr)
    {
        cout << " - north [" << currRoom.north()->name() << "]" << endl;
        found = true;
    } 
    if (currRoom.south() != nullptr)
    {
        cout << " - south [" << currRoom.south()->name() << "]" << endl;
        found = true;
    } 
    if (currRoom.east() != nullptr)
    {
        cout << " - east [" << currRoom.east()->name() << "]" << endl;
        found = true;
    }
    if (currRoom.west() != nullptr)
    {
        cout << " - west [" << currRoom.west()->name() << "]" << endl;
        found = true;
    }
    if (!found) // if there are no exits
    {
        cout << "No exits found." << endl;
    }
    cout << "══════════════════════════════" << endl;
}

Direction getDoorPick(string doorPick)
{
    // Prompt the user to enter the direction to connect the rooms
    while (doorPick != "n" && doorPick != "north" && doorPick != "s" && doorPick != "south" && doorPick != "e" && doorPick != "east" && doorPick != "w" && doorPick != "west")
    {
        cout << "Please Choose a Valid Selection (\"n\", \"s\", \"e\", \"w\")" << endl << "Try Again:" << endl;
        getline(cin, doorPick);
        cout << "your pick was "<< doorPick << endl;
    }
    
    // Connect the rooms
    if (doorPick == "n" || doorPick == "north")
    {
        return NORTH;
    }
    else if (doorPick == "s" || doorPick == "south")
    {
        return SOUTH;
    }
    else if (doorPick == "e" || doorPick == "east")
    {
        return EAST;
    }
    else if (doorPick == "w" || doorPick == "west")
    {
        return WEST;
    }
    else return NORTH;
}

// Function to pause the program until the user presses enter
void pressEnter()
{
    while(true)
    {
        cout << endl << "Press Enter to Continue..." << endl;
        cin.get();
        break;
    }
}


// Function to save the map to a file
void saveMap(map<string, Room*> rooms)
{   
    // Prompt the user to save the map
    cout << "Would you like to save the map? (y/n)" << endl;
    string save;
    getline(cin, save);
    if (save == "n")
    {
        return;
    }
    
    // Prompt the user for the map name
    cout << "What would you like to name the map?" << endl;
    string mapName;
    getline(cin, mapName);
    string fileName = mapName + ".txt";

    // Open the file for writing
    ofstream file(fileName);
    
    // Write room names and descriptions to the file
    vector<string> roomNames;
    for (pair<string, Room*> pair : rooms) 
    {
        roomNames.push_back(pair.first);
    }
    
    for (int i = 0; i < roomNames.size(); i++)
    {
        file << roomNames[i] << ":" << rooms[roomNames[i]]->description() << endl;
    }

    file << "end" << endl;

    // Write room connections to the file
    for (int i = 0; i < roomNames.size(); i++)
    {
        if (rooms[roomNames[i]]->north() != nullptr)
        {
            file << roomNames[i] << "[north]" << rooms[roomNames[i]]->north()->name() << "[" << findOtherExit(roomNames[i], rooms[roomNames[i]]->north()) << "]" << endl;
        }
        if (rooms[roomNames[i]]->south() != nullptr)
        {
            file << roomNames[i] << "[south]" << rooms[roomNames[i]]->south()->name() << "[" << findOtherExit(roomNames[i], rooms[roomNames[i]]->south()) << "]" << endl;
        }
        if (rooms[roomNames[i]]->east() != nullptr)
        {
            file << roomNames[i] << "[east]" << rooms[roomNames[i]]->east()->name() << "[" << findOtherExit(roomNames[i], rooms[roomNames[i]]->east()) << "]" << endl;
        }
        if (rooms[roomNames[i]]->west() != nullptr)
        {
            file << roomNames[i] << "[west]" << rooms[roomNames[i]]->west()->name() << "[" << findOtherExit(roomNames[i], rooms[roomNames[i]]->west()) << "]" << endl;
        }
        
    }
    file << "end" << endl;

    // Close the file
    file.close();

    // Print a success message
    cout << "Map Saved as " << mapName << endl;
}

// Function to find the direction of the exit from a given room
string findOtherExit(string name, Room* room)
{
    if (room->north() != nullptr && room->north()->name() == name)
    {
        return "north";
    }
    else if (room->south() != nullptr && room->south()->name() == name)
    {
        return "south";
    }
    else if (room->east() != nullptr && room->east()->name() == name)
    {
        return "east";
    }
    else if (room->west() != nullptr && room->west()->name() == name)
    {
        return "west";
    }
    else
    {
        return "error";
    }
}

// Function to load a map from a file
map<string, Room*> loadMap()
{
    // Prompt the user for the map name
    cout << "What map would you like to load?" << endl;
    string mapName;
    getline(cin, mapName);

    // Open the file for reading
    string fileName = mapName + ".txt";
    ifstream file(fileName);
    string line;
    map<string, Room*> rooms;

    // Load Function for the Rooms
    while (getline(file, line))
    {
        // Check if the end of the rooms section has been reached
        if (line == "end")
        {
            break;
        } // If not, load the room
        else
        {
            string roomName = line.substr(0, line.find(":"));
            string roomDesc = line.substr(line.find(":") + 1, line.length());
            Room* newRoom = new Room(roomName, roomDesc);
            rooms[roomName] = newRoom;
        }
    }

    // Load Function for the connections
    while(getline(file, line))
    {
        if (line == "end")
        {
            break;
        }
        else // if not, load the connections
        {
            // Get the room name and door direction of the 1st room
            string roomName = line.substr(0, line.find("["));
            string door = line.substr(line.find("[") + 1, line.find("]") - line.find("[") - 1);

            // Get the room name and door direction of the other room
            string roomName2 = line.substr(line.find("]") + 1, line.find("[", line.find("]") + 1) - line.find("]") - 1);
            string door2 = line.substr(line.find("[", line.find("]") + 1) + 1, line.find("]", line.find("]") + 1) - line.find("[", line.find("]") + 1) - 1);
            
            // Convert the door directions to Direction enums
            Direction doorDire1;
            Direction doorDire2;
            if (door == "north")
            {
                doorDire1 = NORTH;
            }
            else if (door == "south")
            {
                doorDire1 = SOUTH;
            }
            else if (door == "east")
            {
                doorDire1 = EAST;
            }
            else if (door == "west")
            {
                doorDire1 = WEST;
            }
            else
            {
                cout << "Error in loading map" << endl;
            }

            // Convert the door directions to Direction enums
            if (door2 == "north")
            {
                doorDire2 = NORTH;
            }
            else if (door2 == "south")
            {
                doorDire2 = SOUTH;
            }
            else if (door2 == "east")
            {
                doorDire2 = EAST;
            }
            else if (door2 == "west")
            {
                doorDire2 = WEST;
            }
            else
            {
                cout << "Error in loading " << roomName << endl;
            }
            
            // Connect the rooms
            rooms[roomName]->connect(doorDire1, rooms[roomName2], doorDire2);
        }
    }
    
    file.close();
    return rooms;
}

#pragma endregion