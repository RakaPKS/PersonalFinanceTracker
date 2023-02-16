#pragma once

#include <ostream>

class BaseMoney {
public:
    // Constructor
    explicit BaseMoney(int cents);

    // Getter function for cents
    [[nodiscard]]int get_base_money() const;

    // Overloaded operators
    BaseMoney operator+(const BaseMoney& other) const;

    BaseMoney operator-(const BaseMoney& other) const;

    BaseMoney operator*(int factor) const;

    BaseMoney operator/(int divisor) const;

    std::strong_ordering operator<=>(int i) const;

	friend std::ostream& operator<<(std::ostream& os, const BaseMoney& money);
    

private:
    int cents_;
};
