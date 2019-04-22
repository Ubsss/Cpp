////
////  main.cpp
////  Homework_1
////
////  Created by Uchechukwu Uboh on 1/29/19.
////  Copyright © 2019 Uchechukwu Uboh. All rights reserved.
////
//#include "Vector.h"
//#include <iostream>
//
//using namespace std;
//
//
//int main() {
//    Vector<char> char_vector;
//
//    char_vector.append('c');
//    char_vector.append('c');
//    char_vector.append('c');
//    char_vector.append('d');
//
//    char_vector.remove('d');
//
//    char_vector.operator[](2);
//
//    char_vector.print_vector();
//
//    return 0;
//}


#include <iostream>
#include <string>
using namespace std;

void display_menu();
int menu();

int main() {
    int main_menu = menu();
    if (main_menu == 1)
        display_menu();
    else
        cout << "End Game\n";
    
    system("pause");
    return 0;
}

int menu() {
    int start_game;
    cout << "press 1 to start game\n";
    cin >> start_game;
    return start_game;
}

void display_menu() {
    int points_earned = 0;
    char word;
    cout << "Welcome to the Great Palidrom game for every word you get right you will get 1 point for the ones\n"
    << "you get wrong you will get 0 points \n" << "A.)ewe\n" << "B.)ewe$\n" << "C.)glide\n" << "D.)Eve\n" << "E.)*Eve*\n" << "F.)globe\n"
    << "G.)eme\n" << "H.)*eme\n" << "I.)grace\n" << "please enter The letter Choice that you desire\n";
//    cin >> word;
    
    while (points_earned < 6) {
        cout<<"Please chose an option"<<endl;
        cin>>word;
        switch (word)
        {
            case  'A': case 'B': case 'D': case 'E': case 'H': case 'G': cout << "you are correct you have 1 point\n";
                points_earned++;
                break;
            case 'C': case 'F': case 'I': cout << " You are incorrect sorry try Again\n";
                break;
            default: cout << "that is an invaild input\n";
                break;
        }
    }
}
