//
//  GaloisField.hpp
//  ReedSolomonEC
//
//  Created by Marc Schöndorf on 09.06.24.
//

#ifndef GaloisField_hpp
#define GaloisField_hpp

namespace ReedSolomon
{
class GaloisField
{
private:
    const uint32_t          m_PrimitivePolynomial;
    
    const uint8_t           m_Characteristic = 2;
    uint8_t                 m_Exponent = 0;
    uint32_t                m_Cardinality = 0;
    
    std::vector<RSWord>     m_ExponentialTable;
    std::vector<RSWord>     m_LogarithmicTable;
    
    void PrecomputeTables();
    
public:
    GaloisField(uint8_t exponent);
    
    RSWord Add(const RSWord x, const RSWord y) const;
    RSWord Subtract(const RSWord x, const RSWord y) const;
    //RSWord MultiplyWithoutLookupTable(RSWord x, RSWord y) const;
    RSWord Multiply(const RSWord x, const RSWord y) const;
    RSWord Divide(const RSWord x, const RSWord y) const;
    RSWord Pow(const RSWord x, const RSWord power) const;
    RSWord Inverse(const RSWord x) const;
};
};

#endif /* GaloisField_hpp */
