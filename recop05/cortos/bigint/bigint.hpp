#pragma once

#include <iostream>

class bigint
{
private:
    std::string _big;
public:
    bigint(unsigned int nbr = 0) : _big(std::to_string(nbr)) {};
    bigint(const bigint &other) : _big(other._big) {};

    std::string getbig() const {return (_big); };

    bigint &operator+=(const bigint &other);
    bigint operator+(const bigint &other) const;

    bigint &operator++();
    bigint operator++(int);

    bigint &operator<<=(unsigned int amount);
    bigint operator<<(unsigned int amount) const;
    bigint &operator>>=(const bigint &other);

    bool operator<(const bigint &other) const;
    bool operator>(const bigint &other) const;
    bool operator<=(const bigint &other) const;
    bool operator>=(const bigint &other) const;
    bool operator==(const bigint &other) const;
    bool operator!=(const bigint &other) const;

    ~bigint() {};
};


std::ostream &operator<<(std::ostream &out, const bigint &other);
