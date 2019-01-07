//
//  Created by Joshua Karbi on 2018-08-28.
//

#include "Holding.hpp"

#include <sstream>

namespace trading
{
    // main constructor
    Holding::Holding(const std::string& sym, size_t number, double price, size_t ex)
    {
        symbol = sym;
        exchange = ex;
        num_shares = number;
        purchase_price = price;
    }
    
    // do not take into account price or number of shares
    bool Holding::operator==(const Holding& other) const
    {
        if (symbol == other.getSymbol() && exchange == other.getExchange())
        {
            return true;
        }
        return false;
    }
    
    std::string Holding::getStringExchange() const
    {
        if (exchange == NYSE)
        {
            return "NYSE";
        }
        else if (exchange == NASDAQ)
        {
            return "NASDAQ";
        }
        else
        {
            return "TSX";
        }
    }

    std::string Holding::toString() const
    {
        std::stringstream res;
        res << num_shares << " of " << symbol << " on the " << getStringExchange() << "@ "<< purchase_price;
        return res.str();
    }

}
