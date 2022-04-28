//TextModePlaneGame v0.1.0

//File: main.cpp
//Author: PolygonalPhantom

//You can do whatever you want with this code

//todo:
    //1. tidy up code
    //2. optimize code (maybe)
    //3. add random ascii terrain generation
    //4. add a win condition

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

int main(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "^-_->|";
    int c = 0;
    int newlines = 0;
    int tabs = 0;
    while(true){

        ///SetConsoleCursorPosition example

        //COORD pos = {3, 6};
        //SetConsoleCursorPosition(hConsole, pos);

        ///

        switch(c=getch()) {
        case 72:
            if(newlines > 0){
                newlines--;
                system("cls");
                for(int i = 0; i < newlines; i++){
                    cout << endl;
                }
                for(int i = 0; i < tabs; i++){
                    cout << "\t";
                }
                cout << "^-_->|";
            }
            break;
        case 80:
            if(newlines < 29){
                newlines++;
                system("cls");
                for(int i = 0; i < newlines; i++){
                    cout << endl;
                }
                for(int i = 0; i < tabs; i++){
                    cout << "\t";
                }
                cout << "^-_->|";
            }
            break;
        case 75:
             if(tabs > 0){
                tabs--;
                system("cls");
                for(int i = 0; i < newlines; i++){
                    cout << endl;
                }
                for(int i = 0; i < tabs; i++){
                    cout << "\t";
                }
                
                cout << "^-_->|";
            }
            break;
        case 77:
            if(tabs < 14){
                tabs++;
                system("cls");
                for(int i = 0; i < newlines; i++){
                    cout << endl;
                }
                for(int i = 0; i < tabs; i++){
                    cout << "\t";
                }
                cout << "^-_->|";
            }
            break;
        default:
             ;
            break;
         }
         if(newlines == 29){
             system("cls");
             cout << "CRASH!";
             Sleep(700);
             newlines = 0;
             tabs = 0;
             system("cls");
                for(int i = 0; i < newlines; i++){
                    cout << endl;
                }
                for(int i = 0; i < tabs; i++){
                    cout << "\t";
                }
                cout << "^-_->|";
         }
    };
    
}