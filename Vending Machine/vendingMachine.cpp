//
//  vendingMachine.cpp
//  Vending Machine
//
//  Created by Uchechukwu Uboh on 11/21/18.
//  Copyright © 2018 Uchechukwu Uboh. All rights reserved.
//

#include "vendingMachine.h"
#include <iostream>
#include <cmath>
using namespace std;

class vending_Machine: public vendingMachine{
public:
    
    void enter_cash(){
        
        while (1){
        cout<<"A soda cost 20 cents and you have a balance of $"<<input_amount<<"\nPlease select your input amount: "<<endl<<endl;
        cout<<"Enter 1 to input a nickel or 5 cents."<<endl;
        cout<<"Enter 2 to input a dime or 10 cents."<<endl;
        cout<<"Enter 3 to input a quarter or 25 cents."<<endl;
        cout<<"Enter 4 to finish inputing cash."<<endl;
        cout<<"Enter 5 to exit the program."<<endl;
        cin>>selection;
        
        switch (selection){
            case 1:
                input_amount += nickel;
                break;
            case 2:
                input_amount += dime;
                break;
            case 3:
                input_amount += quarter;
                break;
            case 4:
                calculate_change();
                break;
            case 5:
                cout<<"Thank you!\n";
                exit(0);
                break;
            default:
                cout<<"This is not a valid selection \nPlease try again!"<<endl;
                break;
            }
        }
    }
    
    double calculate_change(){
        if (input_amount == soda_cost){
            cout<<"You had exact change!"<<endl;
            dispense_soda = true;
            dispense_message();
            input_amount = 0;
            return input_amount;
        }
        else if (input_amount < soda_cost){
            cout<<"You need $" << abs(input_amount - soda_cost)<<" more to get a soda!"<<endl;
            dispense_soda = false;
            dispense_message();
            return input_amount;
        }
        else{
            cout<<"Your change is $" <<input_amount - soda_cost<<"!"<<endl;
            dispense_soda = true;
            dispense_message();
            input_amount -= soda_cost;
            return input_amount;
        }
    }
    
    void dispense_message(){
        if(dispense_soda == true)
            cout<<"Congratulation, your soda has been dispensed! :D"<<endl;
        else
            cout<<"Sorry, not enough cash for soda! D:"<<endl;
    }
    
private:
    int selection;
    double soda_cost = 0.20;
    double input_amount;
    double nickel = 0.05;
    double dime = 0.10;
    double quarter = 0.25;
    bool dispense_soda = false;
};
