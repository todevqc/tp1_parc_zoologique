#ifndef __DIETE_H__
#define __DIETE_H__

#include <iostream>
#include <string>

class Diete{
    
    private:
        double viande;
        double fruits;
        double herbe;
        
    public:
        Diete(double besoinsViande, double besoinsFruits, double besoinsHerbe);
        double getViande();
        double getFruits();
        double getHerbe();
};

#endif