//
//  ReedSolomon.hpp
//  ReedSolomonEC
//
//  Created by Marc Schöndorf on 11.06.24.
//

#ifndef ReedSolomon_hpp
#define ReedSolomon_hpp

namespace RS
{
class ReedSolomon
{
private:
    const uint32_t          m_NumOfErrorCorrectingSymbols = 0;
    
    const GaloisField*      m_GaloisField = nullptr;
    Polynomial*             m_GeneratorPolynomial = nullptr;
    
    // Methods
    void        CreateGeneratorPolynomial(const uint32_t numOfECSymbols);
    Polynomial  CalculateSyndromes(const Polynomial& message) const;
    bool        CheckSyndromes(const Polynomial& syndromes) const;
    
public:
    ReedSolomon(const uint32_t exponent, const uint32_t numOfErrorCorrectingSymbols);
    ~ReedSolomon();
    
    std::vector<RSWord> Encode(const std::vector<RSWord>& message) const;
    
    bool IsMessageCorrupted(const std::vector<RSWord>& message);
};
};

#endif /* ReedSolomon_hpp */
