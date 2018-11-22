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
    
    // Keeps track of customer balance
    void enter_cash();
    
    // Calculate change by comparing input_amount and soda_cost
    double calculate_change();

    // Soda dispense message based on dispense_soda bool
    void dispense_message();
    
private:
    int selection;
    double soda_cost;
    double input_amount;
    double nickel;
    double dime;
    double quarter;
    bool dispense_soda;
};
#endif /* vendingMachine_h */
