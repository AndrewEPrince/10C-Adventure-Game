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
        cin.ignore();

        switch (selection)
        {
        case 1:
            // Start a new Map
            //TODO: Create a new map obj
            CreateMenu(false);
            break;
        case 2:
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
    cout << "║ ?             ║   show a help menu                                     ║" << endl;
    cout << "╚═══════════════╩════════════════════════════════════════════════════════╝" << endl;
    
}

void Menu::CreateMenu(bool ifloadgame)
{
    //TODO: Make a Map obj based on if the user wants to load or create a new map
        //TODO: if we load the onject then we need to load the Object
        //TODO: if we create a new map then we need to create a new object
    
    //TODO: 
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
        currentRoom = new Room("The Void", "You are in the void");
        rooms["The Void"] = currentRoom;
    }
    
    while (true)
    {

        printCreateM();
        cout << "Current Room: " << currentRoom->name() << endl;
        cout << "═════════════════════════════" << endl;
        cout << "> ";

        getline(cin, selectionString);
        cout << endl;
        
        selection = getSelection(selectionString); // Turns from selection string into a char for the switch statement
        

        switch (selection)
        {
        case 'n':
            // move north
            if (currentRoom->north() == nullptr)
            {
                cout << "There is no room to the north." << endl;
                pressEnter();
            }
            else
            {
                currentRoom = currentRoom->north();
                cout << "You are now in the " << currentRoom->name() << endl;
                pressEnter();
            }
            break;

        case 's':
            // move south
            if (currentRoom->south() == nullptr)
            {
                cout << "There is no room to the south." << endl;
                pressEnter();
            }
            else
            {
                currentRoom = currentRoom->south();
                cout << "You are now in the " << currentRoom->name() << endl;
                pressEnter();
            }
            break;

        case 'e':
            // move east
            if (currentRoom->east() == nullptr)
            {
                cout << "There is no room to the east." << endl;
                pressEnter();
            }
            else
            {
                currentRoom = currentRoom->east();
                cout << "You are now in the " << currentRoom->name() << endl;
                pressEnter();
            }
            break;

        case 'w':
            // move west
            if (currentRoom->west() == nullptr)
            {
                cout << "There is no room to the west." << endl;
                pressEnter();
            }
            else
            {
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
            // show a help menu
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

void addRoom(map<string, Room*>& rooms)
{
    string roomName;
    string roomDesc;
    Room* newRoom = new Room();
    cout << "Enter the name of the room." << endl;
    
    getline(cin, roomName);
    newRoom->set_name(roomName);
    cout << "Enter the description of the room." << endl;
    
    getline(cin, roomDesc);
    newRoom->set_description(roomDesc);
    rooms[roomName] = newRoom;

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

void changeDec(Room &currRoom)
{
    string newDesc;
    cout << "Enter the new description of the room: " << endl;
    
    getline(cin, newDesc);
    currRoom.set_description(newDesc);
    cout << "Description changed." << endl;
}

void rename(Room &currRoom)
{
    string newName;
    cout << "Enter the new name of the room: " << endl;
    
    getline(cin, newName);
    currRoom.set_name(newName);
    cout << "Name changed." << endl;
}

void connectRooms(map<string, Room*>& rooms, Room& currRoom)
{
    string roomName;
    cout << "Enter the name of the room you want to connect to: " << endl;
    
    getline(cin, roomName);
    if (rooms.find(roomName) == rooms.end())
    {
        cout << "Room not found." << endl;
    }
    else if (currRoom.name() == "The Void")
    {
        cout << "You cant connect a room with \"The Void\"." << endl;
    }
    else
    {
        string doorPick1;
        string doorPick2;
        
        cout << "In the current room, What door do you want to connect the new room to?" << endl;
        printEmptyExits(currRoom);
        getline(cin, doorPick1);

        cout << "In the new room, What door do you want to connect the current room to?" << endl;
        printEmptyExits(*rooms[roomName]);
        getline(cin, doorPick2);
        
        currRoom.connect(getDoorPick(doorPick1), rooms[roomName], getDoorPick(doorPick2));
        cout << "Connected to room: " << roomName << endl;
    }
}

void printEmptyExits(Room currRoom)
{
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

void printExits(Room currRoom)
{
    bool found = false;
    cout << "Exits in Room: " << endl;
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
    if (!found)
    {
        cout << "No exits found." << endl;
    }
    cout << "══════════════════════════════" << endl;
}

Direction getDoorPick(string doorPick)
{
    
    while (doorPick != "n" && doorPick != "north" && doorPick != "s" && doorPick != "south" && doorPick != "e" && doorPick != "east" && doorPick != "w" && doorPick != "west")
    {
        cout << "Please Choose a Valid Selection (\"n\", \"s\", \"e\", \"w\")" << endl << "Try Again:" << endl;
        getline(cin, doorPick);
        cout << "your pick was "<< doorPick << endl;
    }
    
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
}

void pressEnter()
{
    while(true)
    {
        cout << endl << "Press Enter to Continue..." << endl;
        cin.get();
        break;
    }
}

void saveMap(map<string, Room*> rooms)
{
    cout << "what would you like to name the map?" << endl;
    string mapName;
    getline(cin, mapName);
    string fileName = mapName + ".txt";

    ofstream file(fileName);
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

    file.close();

    cout << "Map Saved as " << mapName << endl;
}

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

map<string, Room*> loadMap()
{
    cout << "What map would you like to load?" << endl;
    string mapName;
    getline(cin, mapName);
    string fileName = mapName + ".txt";
    ifstream file(fileName);
    string line;
    map<string, Room*> rooms;

    // Load Function for the Rooms
    while (getline(file, line))
    {
        if (line == "end")
        {
            break;
        }
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
        else
        {
            string roomName = line.substr(0, line.find("["));
            string door = line.substr(line.find("[") + 1, line.find("]") - line.find("[") - 1);
            string roomName2 = line.substr(line.find("]") + 1, line.find("[", line.find("]") + 1) - line.find("]") - 1);
            string door2 = line.substr(line.find("[", line.find("]") + 1) + 1, line.find("]", line.find("]") + 1) - line.find("[", line.find("]") + 1) - 1);
            
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
            
            rooms[roomName]->connect(doorDire1, rooms[roomName2], doorDire2);
        }
    }
    
    file.close();
    return rooms;
}

#pragma endregion