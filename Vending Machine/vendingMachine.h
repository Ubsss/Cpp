//
//  vendingMachine.h
//  Vending Machine
//
//  Created by Uchechukwu Uboh on 11/21/18.
//  Copyright © 2018 Uchechukwu Uboh. All rights reserved.
//

#ifndef vendingMachine_h
#define vendingMachine_h

class vendingMachine{
public:
    // increments input_amount variable based on preset amounts
    void enter_cash();
    
    // if dispense_soda is true:
    //      Calculate chage and return
    // else:
    //      calculate amount needed to equal soda cost and return
    double calculate_change(double cash);
    
    // takes incremented amount and compares it to cost of soda
    // return true if requal and return false if not
    
    // soda dispensed message
    void dispense_message();
    
private:
    double soda_cost;
    // increamented amount
    double input_amount;
    double nickel;
    double dime;
    double quarter;
    bool dispense_soda;
};

#endif /* vendingMachine_h */
