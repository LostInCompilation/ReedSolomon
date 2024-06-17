//
//  GaloisField.hpp
//  ReedSolomonEC
//
//  Created by Marc Schöndorf on 09.06.24.
//

#ifndef GaloisField_hpp
#define GaloisField_hpp

namespace RS
{
class GaloisField
{
private:
    const uint64_t          m_PrimitivePolynomial;
    
    const uint64_t          m_Characteristic = 2;
    const uint64_t          m_Exponent = 0;
    const uint64_t          m_Cardinality = 0;
    
    std::vector<RSWord>     m_ExponentialTable;
    std::vector<RSWord>     m_LogarithmicTable;
    
    void PrecomputeTables();
    
public:
    GaloisField(const uint64_t exponent);
    
    RSWord Add(const RSWord x, const RSWord y) const noexcept;
    RSWord Subtract(const RSWord x, const RSWord y) const noexcept;
    RSWord Multiply(const RSWord x, const RSWord y) const;
    RSWord Divide(const RSWord x, const RSWord y) const;
    RSWord Pow(const RSWord x, const RSWord power) const;
    RSWord Inverse(const RSWord x) const;
    
    const std::vector<RSWord>& GetExponentialTable() const noexcept { return m_ExponentialTable; }
    const std::vector<RSWord>& GetLogarithmicTable() const noexcept { return m_LogarithmicTable; }
    
    const uint64_t    GetCharacteristic() const { return m_Characteristic; }
    const uint64_t    GetExponent() const { return m_Exponent; }
    const uint64_t    GetCardinality() const { return m_Cardinality; }
};
};

#endif /* GaloisField_hpp */
