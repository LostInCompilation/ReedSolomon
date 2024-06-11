//
//  main.cpp
//  ReedSolomonEC
//
//  Created by Marc Schöndorf on 09.06.24.
//

#include <iostream>

#include "Utils.hpp"
#include "GaloisField.hpp"
#include "Polynomial.hpp"
#include "ReedSolomon.hpp"

using namespace RS;

int main()
{
    std::cout << "Reed-Solomon error correction" << std::endl << std::endl;
    
    GaloisField gf(8); // GF(2^8)
    
    std::vector<RSWord> coeff{1, 2, 3};
    Polynomial p(coeff, &gf);
    p.Scale(42);
    
    ReedSolomon rs(8);
    
    return 0;
}
