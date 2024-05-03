#include <iostream>
#include <ctime>
#include <fstream>
#define SIZE_ALL 10
#define DEBUG

using namespace std;

// добавить продолжить игру
// добавить умный компьютер
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

//Сохраняем массивы в текст файлы

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
        cout << "Файлы не открыты. Ошибка." << endl;
}

//И для продолжения читаем с файлов
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
        cout << "Таких файлов нет. Ошибка" << endl;

}

// инициализация полей
void InitializeFieldsOfShipForPlayers(Player& player) {
    for (int i = 0; i < SIZE_ALL; i++) {
        for (int j = 0; j < SIZE_ALL; j++) {
            player.battleField[i][j] = '.';
            player.shootingField[i][j] = '.';
        }
    }
    cout << endl;
}

//принт полей;
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

//второй принт для игры компьютер-компьютер
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
// принт для игры человек - компьютер
void PrintFieldsForGame_Machine_Human(Player& player, Player& playerTwo)
{
    system("cls");
    cout << "  Поле соперника" << "\t   " <<
         "Твое поле" << endl;
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
    cout << "\tПервый \t\t\t Второй" << endl;
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


//рандомит Х Игрек и Направление
void Random_X_Y_Direction(Player& player)
{
    player.ship.X = rand() % 9;
    player.ship.Y = rand() % 9;
    player.ship.direction = rand() % 2 + 1;
}

//Проверяет выход за границы 0 <x< 10;
bool CheckBounds(Player& player)
{
    return ((player.ship.X >= 0 && player.ship.X < 10) && (player.ship.Y >= 0 && player.ship.Y < 10));
} 

// проверяет направление вправо(не занято ли там) иначе false
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
// если справо не занято,то печатаем корабль 
void PrintRight(Player& player)
{
    for (int i = player.ship.Y; i < player.ship.Y + player.ship.ShipSize; i++)
        player.battleField[player.ship.X][i] = 'X';
}
//тогда заполняет вокруг ?
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

// проверяет направление вниз не занято ли там) иначе false
bool DirectionDown(Player& player)
{
    for (int i = player.ship.X; i < player.ship.X + player.ship.ShipSize; i++)
    {
        if (player.battleField[i][player.ship.Y] == 'X' || player.battleField[i][player.ship.Y] == '#'|| player.ship.X + player.ship.ShipSize > 10 || player.ship.X + player.ship.ShipSize < 0)
            return false;
    }
    return true;
}
// если снизу не занято,то печатаем корабль 
void PrintDown(Player& player)
{
    for (int i = player.ship.X; i < player.ship.X + player.ship.ShipSize; i++)
        player.battleField[i][player.ship.Y] = 'X';
}
//тогда заполняет вокруг ?
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
// проверяет можно ли расположить корабль так и печатает вокруг него '?'
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
// Автоматическая расстановка кораблей
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
            Random_X_Y_Direction(player); //рандом X and Y

            if (CheckBounds(player) && SwitchDirection(player))
            {
                shipNum++;
            }
        }
    }
}
void Random_X_Y_ForMainGameForMachine(Player& player) // рандомим для стрельбы 
{
    player.ship.X = rand() % 10;
    player.ship.Y = rand() % 10;
}
bool MainGameForPlayer(Player& player)
{
    cout << "Введите координаты X для стрельбы =>" << endl;
    cin >> player.ship.X;
    cout << "Введите координаты Y для стрельбы =>" << endl;
    cin >> player.ship.Y;
    if ((player.battleField[player.ship.X][player.ship.Y] == 'X' || player.battleField[player.ship.X][player.ship.Y] == '@')
        && player.shootingField[player.ship.X][player.ship.Y] == '.') // если вы попали ...
    {
        player.shootingField[player.ship.X][player.ship.Y] = 'X';
        player.battleField[player.ship.X][player.ship.Y] = '@';
        cout << "Вы попали,стреляете еще раз!" << endl;
        system("pause");
        return true;
    }
    if (player.battleField[player.ship.X][player.ship.Y] == '#')
    { // если вы не попали ... 
        player.shootingField[player.ship.X][player.ship.Y] = '?';
        cout << "Вы промахнулись. Нажмите любую клавишу для продолжения" << endl;
        system("pause");
        return false;
    }
    else return false;
}
bool MainGameForMachine(Player& player) // стреляем по очереди
{
    Random_X_Y_ForMainGameForMachine(player);

    if ((player.battleField[player.ship.X][player.ship.Y] == 'X' || player.battleField[player.ship.X][player.ship.Y] == '@') 
        && player.shootingField[player.ship.X][player.ship.Y] == '.') // если вы попали ...
    {
        player.shootingField[player.ship.X][player.ship.Y] = 'X';
        player.battleField[player.ship.X][player.ship.Y] = '@';
        return true;
    }
    if (player.battleField[player.ship.X][player.ship.Y] == '#') { // если вы не попали ... 
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
        cout << "Вы расставляете однопалубные корабли" << endl << "Их осталось - " << shipAll - shipNum + 1 << endl;
    else if (player.ship.ShipSize == 2)
        cout << "Вы расставляете двухпалубные корабли" << endl << "Их осталось - " << shipAll - shipNum + 1 << endl;
    else if (player.ship.ShipSize == 3)
        cout << "Вы расставляете трехпалубные корабли" << endl << "Их осталось - " << shipAll - shipNum + 1 << endl;
    else
        cout << "Вы расставляете четырехпалубный корабль" << endl << "Их осталось - " << shipAll - shipNum + 1 << endl;
}
void PlayerFieldsGame(Player& player, Player &playerTwo)
{
    cout << "Вы выбрали ручную расстановку" << endl;
    int shipAll;
    InitializeFieldsOfShipForPlayers(player); // инициализация и расстановка двух квадратов первого
    for (player.ship.ShipSize = 1, shipAll = 4; player.ship.ShipSize <= 4; shipAll--, player.ship.ShipSize++)
    {
        for (int shipNum = 1; shipNum <= shipAll;)
        {
            ShipsForConsole(player, shipAll, shipNum); // какие корабли расставляет

            cout << "Введите => X " << endl;
            cin >> player.ship.X;
            cout << "Введите => Y " << endl;
            cin >> player.ship.Y;
            
            cout << "Введите направление корабля" << endl
                << "1 - Вправо" << endl
                << "2 - Вниз" << endl;
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
                cout << "Попробуйте снова!" << endl;
                continue;
            }
        }
    }
    cout <<  endl <<"Вы расставили все корабли. Теперь расставляет компьютер на втором поле" << endl;
    system("pause");
}
void ContinueGame_Human_Machine(Player& player, Player& playerTwo)
{

    PrintFieldsForGame_Machine_Human(player, playerTwo);
    int Switchi = 1; //начинает первый стрелять
    do
    {
        if (!IsStiilAliveShip(player)) {
            cout << endl << endl << "Победил человек" << endl; // если на перыом поле больше нет кораблей => победил первый

            break;
        }
        else if (!IsStiilAliveShip(playerTwo)) {
            cout << endl << endl << "Победил компьютер" << endl; // если на втором поле больше нет кораблей => победил второй

            break;
        }
        else {
            switch (Switchi)
            {
            case(1):
                if (MainGameForPlayer(playerTwo)) {
                    system("cls");
                    PrintFieldsForGame_Machine_Human(player, playerTwo); //поле для игры 4 квадрата
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
                    PrintFieldsForGame_Machine_Human(player, playerTwo);//поле для игры 4 квадрата
                    break;
                }
                else {
                    Switchi = 1;
                    PrintFieldsForGame_Machine_Human(player, playerTwo);
                    cout << "Компьютер не попал. Стреляйте!" << endl;
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
            InitializeFieldsOfShipForPlayers(OnePlayer); // инициализация и расстановка двух квадратов первого
            HeadMainForMachine(OnePlayer);

            InitializeFieldsOfShipForPlayers(TwoPlayer); // инициализация и расстановка двух квадратов второго
            HeadMainForMachine(TwoPlayer);

            PrintAllBattlefields(OnePlayer, TwoPlayer); // принт кораблей на двух полях 
            system("pause");
            int Switchi = 1;
            bool flagForSwitch;
            do
            {
                if (!IsStiilAliveShip(OnePlayer)) {
                    cout << endl << endl << "Победил первый компьютер" << endl; // если на перыом поле больше нет кораблей => победил первый компьютер
                    break;
                }
                else if (!IsStiilAliveShip(TwoPlayer)) {
                    cout << endl << endl << "Победил второй компьютер" << endl; // если на втором поле больше нет кораблей => победил втором компьютер
                    break;
                }
                else {
                    switch (Switchi)
                    {
                    case(1):
                        if (MainGameForMachine(TwoPlayer)) {
                            system("cls");
                            
                            PrintFieldsforGame_Machine_Machine(OnePlayer, TwoPlayer); //поле для игры 4 квадрата
                            break;
                        }
                        else {
                            Switchi = 2;
                            break;
                        }
                    case(2):
                        if (MainGameForMachine(OnePlayer)) {
                            system("cls");
                            PrintFieldsforGame_Machine_Machine(TwoPlayer, OnePlayer); //поле для игры 4 квадрата
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

            PlayerFieldsGame(OnePlayer, TwoPlayer); //расстановка кораблей для человека на первом поле

            InitializeFieldsOfShipForPlayers(TwoPlayer); // инициализация поля для компьютера на втором поле 

            HeadMainForMachine(TwoPlayer); // расстановка кораблей компьютером на втором поле 
            PrintFieldsForGame_Machine_Human(OnePlayer, TwoPlayer);
            int Switchi = 1; //начинает первый стрелять
            do
            {
                if (!IsStiilAliveShip(OnePlayer)) {
                    cout << endl << endl << "Победил человек" << endl; // если на перыом поле больше нет кораблей => победил первый
        
                 break;
             }
             else if (!IsStiilAliveShip(TwoPlayer)) {
                 cout << endl << endl << "Победил компьютер" << endl; // если на втором поле больше нет кораблей => победил второй
        
                    break;
                }
                else {
                    switch (Switchi)
                    {
                    case(1):
                        if (MainGameForPlayer(TwoPlayer)) {
                            system("cls");
                            PrintFieldsForGame_Machine_Human(OnePlayer, TwoPlayer); //поле для игры 4 квадрата
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
                            PrintFieldsForGame_Machine_Human(OnePlayer, TwoPlayer);//поле для игры 4 квадрата
                            break;
                        }
                        else {
                            Switchi = 1;
                            PrintFieldsForGame_Machine_Human(OnePlayer, TwoPlayer);
                            cout << "Компьютер не попал. Стреляйте!" << endl;
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
    system("cls"); //выходим из системы и загружаем в файл 4 массива
    WtiteFile(player, playerTwo);
    system("cls");
    cout << endl << endl << endl;
    cout << "\t\t\t\t\tВы сохранились и вышли из игры морской бой!" << endl << endl << endl;
    
}
void Rules()
{
    system("cls");
    cout << "\t\t\t\t\tОбозначения: \n"
        << "1 - Точка - означает пустое поле\n"
        << "2 - X - означает попадание по кораблю \n"
        << "3 - ? - означает пустое поле \n"
        << "\t\t\t\t\tПравила игры в морской бой: \n"
        << "1 - Участвуют два игрока \n"
        << "2 - Каждый играет на поле 10х10 клеток \n"
        << "3 - Стороны квадратов подписываются буквами и цифрами \n"
        << "4 - Перед началом боевых действий игроки договариваются, кто будет ходить первым.\n"
        << "5 - Когда корабли расставлены, игроки по очереди производят «выстрелы», называя квадраты по их координатам.\n"
        << "6 - Если выстрел пришелся в клетку, не занятую кораблем, то следует ответ «Мимо!», и стрелявший игрок ставит\n"
        << "на чужом квадрате в этом месте точку.Право хода переходит к сопернику.\n"
        << "7 - Если выстрел пришёлся в клетку, где находится многопалубный корабль(размером больше чем 1 клетка), то следует\n"
        << "«Попал(а)!».Стрелявший игрок ставит на чужом поле в эту клетку крестик, а его противник ставит крестик на своем поле также в эту клетку.\n"
        << " Стрелявший игрок получает право на еще один выстрел.\n"
        << "8 - Если выстрел пришёлся в клетку, где находится однотрубный корабль, или последнюю непоражённую клетку многопалубного корабля, \n"
        << "то следует ответ «Убил(а)!» или «Потопил(а)!».Оба игрока отмечают потопленный корабль на листе.Стрелявший игрок получает право на еще один выстрел.\n"
        << "9 - Игра ведется до полной победы одного из игроков, то есть пока не будут потоплены все корабли.\n";
    system("pause");
    system("cls");
}
void MainFunction(Player& OnePlayer, Player& TwoPlayer)
{
    while (true)
    {
        cout << "\t\t\t\t\tВы начинаете игру морской бой!" << endl
            << "1 => Перейти к правилам игры:" << endl
            << "2 => Начать новую игру" << endl
            << "3 => Продолжить игру(нормально не сделал)" << endl
            << "4 => Выход" << endl;

        int FooBoo;
        cin >> FooBoo;

        switch (FooBoo)
        {
        case(1):
            Rules();
            break;
        case(2):
            system("cls");

            cout << "Выберете игру =>" << endl
                << "1 - Компьютер - Компьютер" << endl
                << "2 - Компьютер - Человек" << endl;
            MainGameTwo(OnePlayer, TwoPlayer);
            break;
        case(3):
            
             ContinueTheGameForPlayer(OnePlayer, TwoPlayer); // выгрузить все поля.
             PlayerFieldsGame(OnePlayer, TwoPlayer);
             ContinueGame_Human_Machine(OnePlayer, TwoPlayer);
             break;

        case(4):
            system("cls");
            cout << endl << endl << endl;
            cout << "\t\t\t\t\tВы вышли из игры морской бой!" << endl << endl << endl << endl;
            return;
        default:
            cout << "Такого пункта нет. Попробуйте еще раз" << endl;
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

