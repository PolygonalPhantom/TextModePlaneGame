//TextModePlaneGame v0.2.0

//File: main.cpp
//Author: PolygonalPhantom

//You can do whatever you want with this code

//todo:
    //1. tidy up code []
    //2. optimize code (maybe) []
    //3. add random ascii terrain generation [*]
    //4. add a win condition []
    //5. make window unresizable [*]
    //6. better movement system [*]
    //7. better ascii terrain generation []

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){

    //Variables & Function Declarations

    int c = 0;
    int tabs = 0;
    int temp = 0;

    SHORT currentYpos = 0;
    SHORT currentXpos = 0;

    void GenerateTerrain(void);

    //Start code

    HWND consoleWindow = GetConsoleWindow();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //console handler, used to move the DOS cursor using SetConsoleCursorPosition();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    GenerateTerrain();
    SetConsoleCursorPosition(hConsole, {currentXpos, currentYpos});
    cout << "^-_->|";

    //Update code (constantly executed)

    while(true){
        switch(c=getch()) {
        case 72:
            if(currentYpos > 0){
                // newlines--;
                temp = currentXpos;
                SetConsoleCursorPosition(hConsole, {(SHORT)temp, currentYpos});
                for(int i = 0; i < 6; i++){
                    cout << " ";
                }
                currentYpos--;
                SetConsoleCursorPosition(hConsole, {currentXpos, currentYpos});
                cout << "^-_->|";
            }
            break;
        case 80:
            if(currentYpos < 29){
                // newlines++;
                temp = currentXpos;
                SetConsoleCursorPosition(hConsole, {(SHORT)temp, currentYpos});
                for(int i = 0; i < 6; i++){
                    cout << " ";
                }
                currentYpos++;
                SetConsoleCursorPosition(hConsole, {currentXpos, currentYpos});
                cout << "^-_->|";
            }
            break;
        case 75:
             if(currentXpos > 0){
                currentXpos-=6;
                temp = currentXpos+6;
                SetConsoleCursorPosition(hConsole, {(SHORT)temp, currentYpos});
                for(int i = 0; i < 6; i++){
                    cout << " ";
                }
                SetConsoleCursorPosition(hConsole, {currentXpos, currentYpos});
                cout << "^-_->|";
            }
            break;
        case 77:
            if(currentXpos < 114){
                currentXpos+=6;
                temp = currentXpos-6;
                SetConsoleCursorPosition(hConsole, {(SHORT)temp, currentYpos});
                for(int i = 0; i < 6; i++){
                    cout << " ";
                }
                SetConsoleCursorPosition(hConsole, {currentXpos, currentYpos});
                cout << "^-_->|";
            }
            break;
        default:
             ;
            break;
         }
         if(currentYpos == 24){
                system("cls");
                cout << "CRASH!";
                Sleep(700);
                currentYpos = 0;
                currentXpos = 0;
                SetConsoleCursorPosition(hConsole, {currentXpos, currentYpos});
                system("cls");
                GenerateTerrain();
                
         }
    };
    
}

void GenerateTerrain(void){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, {0, 29});

    SHORT currentYpos = 29;
    SHORT currentXpos = 0;
    int bin = 0;
    
    //Random Generation

    srand(time(0));
    for(int x=0;x<12;x++){
        bin = (rand() % 2);

        SetConsoleCursorPosition(hConsole, {currentXpos, currentYpos});

        if(!bin){
            cout << "----------";
        } else {
            currentYpos-=5;
            SetConsoleCursorPosition(hConsole, {currentXpos, currentYpos});
            cout << "----------";
            currentYpos+=5;
            SetConsoleCursorPosition(hConsole, {currentXpos, currentYpos});
        }
        currentXpos += 10;
    }

    SetConsoleCursorPosition(hConsole, {0, 0});
    return;
}