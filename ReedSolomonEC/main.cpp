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

using namespace ReedSolomon;

int main()
{
    std::cout << "Reed-Solomon error correction" << std::endl << std::endl;
    
    GaloisField gf(8); // GF(2^8)
    //Polynomial p(nullptr, 0);
    
    return 0;
}