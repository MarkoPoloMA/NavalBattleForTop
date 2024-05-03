#include <iostream>
#include <ctime>
#include <fstream>
#define SIZE_ALL 10
#define DEBUG

using namespace std;

// �������� ���������� ����
// �������� ����� ���������
struct Ship {
    int X = 0;
    int Y = 0;
    int direction = 0;
    int ShipSize = 0;
};

struct Player {
    char battleField[SIZE_ALL][SIZE_ALL];
    char shootingField[SIZE_ALL][SIZE_ALL];
    Ship ship;
};



void ExitMenu(Player& player, Player& playerTwo);
void MainFunction(Player& player, Player& playerTwo);
void InitializeFieldsOfShipForPlayers(Player& player);

//��������� ������� � ����� �����

void WtiteFile(Player& player, Player &playerTwo)
{
    ofstream infile_battleField_PlayerTwo("File_for_BattlefieldPlayerTwo.txt");
    ofstream infile_shootingField_PlayerTwo("File_for_shootingFieldPlayerTwo.txt");
    ofstream infile_battleField_Player("File_for_BattlefieldPlayer.txt");
    ofstream infile_shootingField_Player("File_for_shootingFieldPlayer.txt");
    if (infile_battleField_PlayerTwo.is_open() && infile_shootingField_PlayerTwo.is_open() && infile_battleField_Player.is_open() && infile_shootingField_Player.is_open()) {

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++)
            {
                infile_battleField_PlayerTwo << playerTwo.battleField[i][j];
                infile_shootingField_PlayerTwo << playerTwo.shootingField[i][j];
                infile_battleField_Player << player.battleField[i][j];
                infile_shootingField_Player << player.shootingField[i][j];

            }
            cout << endl;
        }
        infile_battleField_PlayerTwo.close();
    }
    else
        cout << "����� �� �������. ������." << endl;
}

//� ��� ����������� ������ � ������
void ContinueTheGameForPlayer(Player& player, Player& playerTwo)
{
    ifstream infile_battleField_Player("File_for_BattlefieldPlayer.txt");
    ifstream infile_shootingField_Player("File_for_shootingFieldPlayer.txt");
    ifstream infile_battleField_PlayerTwo("File_for_BattlefieldPlayerTwo.txt");
    ifstream infile_shootingField_PlayerTwo("File_for_shootingFieldPlayerTwo.txt");

    InitializeFieldsOfShipForPlayers(player);
    InitializeFieldsOfShipForPlayers(playerTwo);

    if (infile_battleField_Player.is_open())
    {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++)
            {
                infile_battleField_Player >> player.battleField[i][j];
                infile_battleField_Player >> player.battleField[i][j];
                infile_battleField_PlayerTwo >> playerTwo.battleField[i][j];
                infile_shootingField_PlayerTwo >> playerTwo.shootingField[i][j];
            }
            cout << endl;
        }
        infile_battleField_Player.close();
    }
    else
        cout << "����� ������ ���. ������" << endl;

}

// ������������� �����
void InitializeFieldsOfShipForPlayers(Player& player) {
    for (int i = 0; i < SIZE_ALL; i++) {
        for (int j = 0; j < SIZE_ALL; j++) {
            player.battleField[i][j] = '.';
            player.shootingField[i][j] = '.';
        }
    }
    cout << endl;
}

//����� �����;
void PrintFields(const Player& player) {
    system("cls");
    cout << "  ";
    for (int i = 0; i < SIZE_ALL; i++)
        cout << i << " ";
    cout << "\t  ";
    for (int i = 0; i < SIZE_ALL; i++)
        cout << i << " ";
    cout << endl;

    for (int i = 0; i < SIZE_ALL; i++) {
        cout << i << " ";
        for (int j = 0; j < SIZE_ALL; j++)
            cout << player.battleField[i][j] << " ";
        cout << "\t";
        cout << i << " ";
        for (int j = 0; j < SIZE_ALL; j++)
            cout << player.shootingField[i][j] << " ";
        cout << endl;
    }
}

//������ ����� ��� ���� ���������-���������
void PrintFieldsforGame_Machine_Machine(Player& player, Player& playerTwo)
{
    system("cls");
    cout << "  ";
    for (int i = 0; i < SIZE_ALL; i++)
        cout << i << " ";
    cout << "\t  ";
    for (int i = 0; i < SIZE_ALL; i++)
        cout << i << " ";
    cout << endl;

    for (int i = 0; i < SIZE_ALL; i++) {
        cout << i << " ";
        for (int j = 0; j < SIZE_ALL; j++)
            cout << player.shootingField[i][j] << " ";
        cout << "\t";
        cout << i << " ";
        for (int j = 0; j < SIZE_ALL; j++)
            cout << playerTwo.shootingField[i][j] << " ";
        cout << endl;
    }
}
// ����� ��� ���� ������� - ���������
void PrintFieldsForGame_Machine_Human(Player& player, Player& playerTwo)
{
    system("cls");
    cout << "  ���� ���������" << "\t   " <<
         "���� ����" << endl;
    cout << "  ";
    for (int i = 0; i < SIZE_ALL; i++)
        cout << i << " ";
    cout << "\t  ";

    for (int i = 0; i < SIZE_ALL; i++)
        cout << i << " ";
    cout << endl;

    for (int i = 0; i < SIZE_ALL; i++) {
        cout << i << " ";
        for (int j = 0; j < SIZE_ALL; j++)
            cout << playerTwo.shootingField[i][j] << " ";
        cout << "\t";
        cout << i << " ";
        for (int j = 0; j < SIZE_ALL; j++)
            cout << player.battleField[i][j] << " ";
        cout << endl;
    }
}

void PrintAllBattlefields(Player& player, Player& playerTwo)
{
    system("cls");
    cout << "\t������ \t\t\t ������" << endl;
    cout << "  ";
    for (int i = 0; i < SIZE_ALL; i++)
        cout << i << " ";
    cout << "\t  ";
    for (int i = 0; i < SIZE_ALL; i++)
        cout << i << " ";
    cout << endl;

    for (int i = 0; i < SIZE_ALL; i++) {
        cout << i << " ";
        for (int j = 0; j < SIZE_ALL; j++)
            cout << player.battleField[i][j] << " ";
        cout << "\t";
        cout << i << " ";
        for (int j = 0; j < SIZE_ALL; j++)
            cout << playerTwo.battleField[i][j] << " ";
        cout << endl;
    }
}


//�������� � ����� � �����������
void Random_X_Y_Direction(Player& player)
{
    player.ship.X = rand() % 9;
    player.ship.Y = rand() % 9;
    player.ship.direction = rand() % 2 + 1;
}

//��������� ����� �� ������� 0 <x< 10;
bool CheckBounds(Player& player)
{
    return ((player.ship.X >= 0 && player.ship.X < 10) && (player.ship.Y >= 0 && player.ship.Y < 10));
} 

// ��������� ����������� ������(�� ������ �� ���) ����� false
bool DirectionForRight(Player& player)
{
    int count = 0;
    for (int i = player.ship.Y; i < player.ship.Y + player.ship.ShipSize; i++)
    {
        if (player.battleField[player.ship.X][i] == 'X' || player.battleField[player.ship.X][i] == '#' || player.ship.Y + player.ship.ShipSize > 10 || player.ship.Y + player.ship.ShipSize < 0)
            return false;
    }
    return true;
}
// ���� ������ �� ������,�� �������� ������� 
void PrintRight(Player& player)
{
    for (int i = player.ship.Y; i < player.ship.Y + player.ship.ShipSize; i++)
        player.battleField[player.ship.X][i] = 'X';
}
//����� ��������� ������ ?
void RightDirectionPrint(Player& player)
{
    for (int i = player.ship.X - 1; i <= player.ship.X + 1; i++)

        for (int j = player.ship.Y - 1; j <= player.ship.Y + player.ship.ShipSize; j++)
        {
            if (i >= 0 && i < 10 && j >= 0 && j < 10) {
                if (player.battleField[i][j] == 'X') {
                    continue;
                }
                else
                    player.battleField[i][j] = '#';
            }
}       }

// ��������� ����������� ���� �� ������ �� ���) ����� false
bool DirectionDown(Player& player)
{
    for (int i = player.ship.X; i < player.ship.X + player.ship.ShipSize; i++)
    {
        if (player.battleField[i][player.ship.Y] == 'X' || player.battleField[i][player.ship.Y] == '#'|| player.ship.X + player.ship.ShipSize > 10 || player.ship.X + player.ship.ShipSize < 0)
            return false;
    }
    return true;
}
// ���� ����� �� ������,�� �������� ������� 
void PrintDown(Player& player)
{
    for (int i = player.ship.X; i < player.ship.X + player.ship.ShipSize; i++)
        player.battleField[i][player.ship.Y] = 'X';
}
//����� ��������� ������ ?
void DownDirectionPrint(Player& player)
{
    for (int i = player.ship.X - 1; i <= player.ship.X + player.ship.ShipSize; i++)

        for (int j = player.ship.Y - 1; j <= player.ship.Y + 1; j++)
        {
            if (i >= 0 && i < 10 && j >= 0 && j < 10) {

                if (player.battleField[i][j] == 'X')
                    continue;
                else
                    player.battleField[i][j] = '#';
                
            }
        }
}
// ��������� ����� �� ����������� ������� ��� � �������� ������ ���� '?'
bool SwitchDirection(Player& player)
{
    switch (player.ship.direction)
        {
        case(1): {
            if (DirectionForRight(player))
            {
                PrintRight(player);
                RightDirectionPrint(player);
                return true;
            }
            else return false;
        }
        case(2): {
            if (DirectionDown(player))
            {
                PrintDown(player);
                DownDirectionPrint(player);
                return true;
            }
            else return false;
        }
    }
}
// �������������� ����������� ��������
void HeadMainForMachine(Player& player)
{
    int shipAll = 4;
    for (player.ship.ShipSize = 1, shipAll = 4; player.ship.ShipSize <= 4; shipAll--, player.ship.ShipSize++)
    {
        for (int shipNum = 1; shipNum <= shipAll;)
        {
            if (player.ship.ShipSize == 4 || player.ship.ShipSize == 3) {
                player.ship.X = rand() % 9;
                player.ship.Y = rand() % 9; 
                player.ship.direction = rand() % 2 + 1;
            }
            else
            Random_X_Y_Direction(player); //������ X and Y

            if (CheckBounds(player) && SwitchDirection(player))
            {
                shipNum++;
            }
        }
    }
}
void Random_X_Y_ForMainGameForMachine(Player& player) // �������� ��� �������� 
{
    player.ship.X = rand() % 10;
    player.ship.Y = rand() % 10;
}
bool MainGameForPlayer(Player& player)
{
    cout << "������� ���������� X ��� �������� =>" << endl;
    cin >> player.ship.X;
    cout << "������� ���������� Y ��� �������� =>" << endl;
    cin >> player.ship.Y;
    if ((player.battleField[player.ship.X][player.ship.Y] == 'X' || player.battleField[player.ship.X][player.ship.Y] == '@')
        && player.shootingField[player.ship.X][player.ship.Y] == '.') // ���� �� ������ ...
    {
        player.shootingField[player.ship.X][player.ship.Y] = 'X';
        player.battleField[player.ship.X][player.ship.Y] = '@';
        cout << "�� ������,��������� ��� ���!" << endl;
        system("pause");
        return true;
    }
    if (player.battleField[player.ship.X][player.ship.Y] == '#')
    { // ���� �� �� ������ ... 
        player.shootingField[player.ship.X][player.ship.Y] = '?';
        cout << "�� ������������. ������� ����� ������� ��� �����������" << endl;
        system("pause");
        return false;
    }
    else return false;
}
bool MainGameForMachine(Player& player) // �������� �� �������
{
    Random_X_Y_ForMainGameForMachine(player);

    if ((player.battleField[player.ship.X][player.ship.Y] == 'X' || player.battleField[player.ship.X][player.ship.Y] == '@') 
        && player.shootingField[player.ship.X][player.ship.Y] == '.') // ���� �� ������ ...
    {
        player.shootingField[player.ship.X][player.ship.Y] = 'X';
        player.battleField[player.ship.X][player.ship.Y] = '@';
        return true;
    }
    if (player.battleField[player.ship.X][player.ship.Y] == '#') { // ���� �� �� ������ ... 
        player.shootingField[player.ship.X][player.ship.Y] = '?';
        return false;
    }
    else return false;
}
bool IsStiilAliveShip(Player& player)
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (player.battleField[i][j] == 'X') {
                return true;
            }
        }
    }
    return false;
}
void ShipsForConsole(Player&player, int shipAll,int shipNum)
{
    if (player.ship.ShipSize == 1)
        cout << "�� ������������ ������������ �������" << endl << "�� �������� - " << shipAll - shipNum + 1 << endl;
    else if (player.ship.ShipSize == 2)
        cout << "�� ������������ ������������ �������" << endl << "�� �������� - " << shipAll - shipNum + 1 << endl;
    else if (player.ship.ShipSize == 3)
        cout << "�� ������������ ������������ �������" << endl << "�� �������� - " << shipAll - shipNum + 1 << endl;
    else
        cout << "�� ������������ ��������������� �������" << endl << "�� �������� - " << shipAll - shipNum + 1 << endl;
}
void PlayerFieldsGame(Player& player, Player &playerTwo)
{
    cout << "�� ������� ������ �����������" << endl;
    int shipAll;
    InitializeFieldsOfShipForPlayers(player); // ������������� � ����������� ���� ��������� �������
    for (player.ship.ShipSize = 1, shipAll = 4; player.ship.ShipSize <= 4; shipAll--, player.ship.ShipSize++)
    {
        for (int shipNum = 1; shipNum <= shipAll;)
        {
            ShipsForConsole(player, shipAll, shipNum); // ����� ������� �����������

            cout << "������� => X " << endl;
            cin >> player.ship.X;
            cout << "������� => Y " << endl;
            cin >> player.ship.Y;
            
            cout << "������� ����������� �������" << endl
                << "1 - ������" << endl
                << "2 - ����" << endl;
            cin >> player.ship.direction;
            switch (player.ship.direction)
            {
            case(1):
                if (DirectionForRight(player) && CheckBounds(player)) {
                    PrintRight(player);
                    RightDirectionPrint(player);
                    PrintFields(player);
                    shipNum++;
                    break;
                }
            case(2):
                if (DirectionDown(player) && CheckBounds(player))
                {
                    PrintDown(player);
                    DownDirectionPrint(player);
                    PrintFields(player);
                    shipNum++;
                    system("pause");

                    break;
                }
            
            default:
                cout << "���������� �����!" << endl;
                continue;
            }
        }
    }
    cout <<  endl <<"�� ���������� ��� �������. ������ ����������� ��������� �� ������ ����" << endl;
    system("pause");
}
void ContinueGame_Human_Machine(Player& player, Player& playerTwo)
{

    PrintFieldsForGame_Machine_Human(player, playerTwo);
    int Switchi = 1; //�������� ������ ��������
    do
    {
        if (!IsStiilAliveShip(player)) {
            cout << endl << endl << "������� �������" << endl; // ���� �� ������ ���� ������ ��� �������� => ������� ������

            break;
        }
        else if (!IsStiilAliveShip(playerTwo)) {
            cout << endl << endl << "������� ���������" << endl; // ���� �� ������ ���� ������ ��� �������� => ������� ������

            break;
        }
        else {
            switch (Switchi)
            {
            case(1):
                if (MainGameForPlayer(playerTwo)) {
                    system("cls");
                    PrintFieldsForGame_Machine_Human(player, playerTwo); //���� ��� ���� 4 ��������
                    break;
                }
                else {
                    Switchi = 2;
                    PrintFieldsForGame_Machine_Human(player, playerTwo);
                    break;
                }
            case(2):
                if (MainGameForMachine(player)) {
                    system("cls");
                    PrintFieldsForGame_Machine_Human(player, playerTwo);//���� ��� ���� 4 ��������
                    break;
                }
                else {
                    Switchi = 1;
                    PrintFieldsForGame_Machine_Human(player, playerTwo);
                    cout << "��������� �� �����. ���������!" << endl;
                    system("pause");
                }
            }
        }
    } while (true);
}
void MainGameTwo(Player& OnePlayer, Player &TwoPlayer)
{
    int Choice;
    cin >> Choice;
    switch (Choice)
    {
        case(1): 
        {
            InitializeFieldsOfShipForPlayers(OnePlayer); // ������������� � ����������� ���� ��������� �������
            HeadMainForMachine(OnePlayer);

            InitializeFieldsOfShipForPlayers(TwoPlayer); // ������������� � ����������� ���� ��������� �������
            HeadMainForMachine(TwoPlayer);

            PrintAllBattlefields(OnePlayer, TwoPlayer); // ����� �������� �� ���� ����� 
            system("pause");
            int Switchi = 1;
            bool flagForSwitch;
            do
            {
                if (!IsStiilAliveShip(OnePlayer)) {
                    cout << endl << endl << "������� ������ ���������" << endl; // ���� �� ������ ���� ������ ��� �������� => ������� ������ ���������
                    break;
                }
                else if (!IsStiilAliveShip(TwoPlayer)) {
                    cout << endl << endl << "������� ������ ���������" << endl; // ���� �� ������ ���� ������ ��� �������� => ������� ������ ���������
                    break;
                }
                else {
                    switch (Switchi)
                    {
                    case(1):
                        if (MainGameForMachine(TwoPlayer)) {
                            system("cls");
                            
                            PrintFieldsforGame_Machine_Machine(OnePlayer, TwoPlayer); //���� ��� ���� 4 ��������
                            break;
                        }
                        else {
                            Switchi = 2;
                            break;
                        }
                    case(2):
                        if (MainGameForMachine(OnePlayer)) {
                            system("cls");
                            PrintFieldsforGame_Machine_Machine(TwoPlayer, OnePlayer); //���� ��� ���� 4 ��������
                            break;
                        }
                        else {
                            Switchi = 1;
                            break;
                        }
                    }
                }
            } while (true);
            break;
        }
        case(2): {
            InitializeFieldsOfShipForPlayers(OnePlayer);
            PrintFields(OnePlayer);

            PlayerFieldsGame(OnePlayer, TwoPlayer); //����������� �������� ��� �������� �� ������ ����

            InitializeFieldsOfShipForPlayers(TwoPlayer); // ������������� ���� ��� ���������� �� ������ ���� 

            HeadMainForMachine(TwoPlayer); // ����������� �������� ����������� �� ������ ���� 
            PrintFieldsForGame_Machine_Human(OnePlayer, TwoPlayer);
            int Switchi = 1; //�������� ������ ��������
            do
            {
                if (!IsStiilAliveShip(OnePlayer)) {
                    cout << endl << endl << "������� �������" << endl; // ���� �� ������ ���� ������ ��� �������� => ������� ������
        
                 break;
             }
             else if (!IsStiilAliveShip(TwoPlayer)) {
                 cout << endl << endl << "������� ���������" << endl; // ���� �� ������ ���� ������ ��� �������� => ������� ������
        
                    break;
                }
                else {
                    switch (Switchi)
                    {
                    case(1):
                        if (MainGameForPlayer(TwoPlayer)) {
                            system("cls");
                            PrintFieldsForGame_Machine_Human(OnePlayer, TwoPlayer); //���� ��� ���� 4 ��������
                            break;
                        }
                        else {
                            Switchi = 2;
                            PrintFieldsForGame_Machine_Human(OnePlayer, TwoPlayer);
                            break;
                        }
                    case(2):
                        if (MainGameForMachine(OnePlayer)) {
                            system("cls");
                            PrintFieldsForGame_Machine_Human(OnePlayer, TwoPlayer);//���� ��� ���� 4 ��������
                            break;
                        }
                        else {
                            Switchi = 1;
                            PrintFieldsForGame_Machine_Human(OnePlayer, TwoPlayer);
                            cout << "��������� �� �����. ���������!" << endl;
                            system("pause");
                            break;
                        }
                    }
                }
            } while (true);
            break; }
        default:
            ExitMenu(OnePlayer, TwoPlayer);
            exit(0);
    }
}
void ExitMenu(Player& player, Player& playerTwo)
{
    system("cls"); //������� �� ������� � ��������� � ���� 4 �������
    WtiteFile(player, playerTwo);
    system("cls");
    cout << endl << endl << endl;
    cout << "\t\t\t\t\t�� ����������� � ����� �� ���� ������� ���!" << endl << endl << endl;
    
}
void Rules()
{
    system("cls");
    cout << "\t\t\t\t\t�����������: \n"
        << "1 - ����� - �������� ������ ����\n"
        << "2 - X - �������� ��������� �� ������� \n"
        << "3 - ? - �������� ������ ���� \n"
        << "\t\t\t\t\t������� ���� � ������� ���: \n"
        << "1 - ��������� ��� ������ \n"
        << "2 - ������ ������ �� ���� 10�10 ������ \n"
        << "3 - ������� ��������� ������������� ������� � ������� \n"
        << "4 - ����� ������� ������ �������� ������ ��������������, ��� ����� ������ ������.\n"
        << "5 - ����� ������� �����������, ������ �� ������� ���������� ����������, ������� �������� �� �� �����������.\n"
        << "6 - ���� ������� �������� � ������, �� ������� ��������, �� ������� ����� �����!�, � ���������� ����� ������\n"
        << "�� ����� �������� � ���� ����� �����.����� ���� ��������� � ���������.\n"
        << "7 - ���� ������� �������� � ������, ��� ��������� ������������� �������(�������� ������ ��� 1 ������), �� �������\n"
        << "������(�)!�.���������� ����� ������ �� ����� ���� � ��� ������ �������, � ��� ��������� ������ ������� �� ����� ���� ����� � ��� ������.\n"
        << " ���������� ����� �������� ����� �� ��� ���� �������.\n"
        << "8 - ���� ������� �������� � ������, ��� ��������� ����������� �������, ��� ��������� ����������� ������ �������������� �������, \n"
        << "�� ������� ����� �����(�)!� ��� ��������(�)!�.��� ������ �������� ����������� ������� �� �����.���������� ����� �������� ����� �� ��� ���� �������.\n"
        << "9 - ���� ������� �� ������ ������ ������ �� �������, �� ���� ���� �� ����� ��������� ��� �������.\n";
    system("pause");
    system("cls");
}
void MainFunction(Player& OnePlayer, Player& TwoPlayer)
{
    while (true)
    {
        cout << "\t\t\t\t\t�� ��������� ���� ������� ���!" << endl
            << "1 => ������� � �������� ����:" << endl
            << "2 => ������ ����� ����" << endl
            << "3 => ���������� ����(��������� �� ������)" << endl
            << "4 => �����" << endl;

        int FooBoo;
        cin >> FooBoo;

        switch (FooBoo)
        {
        case(1):
            Rules();
            break;
        case(2):
            system("cls");

            cout << "�������� ���� =>" << endl
                << "1 - ��������� - ���������" << endl
                << "2 - ��������� - �������" << endl;
            MainGameTwo(OnePlayer, TwoPlayer);
            break;
        case(3):
            
             ContinueTheGameForPlayer(OnePlayer, TwoPlayer); // ��������� ��� ����.
             PlayerFieldsGame(OnePlayer, TwoPlayer);
             ContinueGame_Human_Machine(OnePlayer, TwoPlayer);
             break;

        case(4):
            system("cls");
            cout << endl << endl << endl;
            cout << "\t\t\t\t\t�� ����� �� ���� ������� ���!" << endl << endl << endl << endl;
            return;
        default:
            cout << "������ ������ ���. ���������� ��� ���" << endl;
            continue;
        }
    }
}


void Flag(Player& player, Player& playerTwo, bool flagForSwitch,bool flagTwo, int X_1, int Y)
{
    if (player.battleField[X_1][Y] == 'X')
        flagTwo = true;
    else {
        flagTwo = false;
        X_1 = playerTwo.ship.X;
        flagForSwitch = false;
    }
}
void GorizontPaluba(Player& player, Player& playerTwo, bool flagForSwitch,int X_1, int Y) 
{
    if (flagForSwitch && playerTwo.ship.X > 0 && playerTwo.ship.X <= 9)
        X_1 = playerTwo.ship.X - 1;
    else if(playerTwo.ship.X >= 0 && playerTwo.ship.X < 9)
        X_1 = playerTwo.ship.X + 1;

}


void main() {
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    Player OnePlayer;
    Player TwoPlayer;
    MainFunction(OnePlayer, TwoPlayer);
}

