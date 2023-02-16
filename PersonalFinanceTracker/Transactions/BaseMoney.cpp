#include "BaseMoney.h"

BaseMoney::BaseMoney(int cents): cents_(cents)
{}

int BaseMoney::get_base_money() const
{ return cents_; }

BaseMoney BaseMoney::operator+(const BaseMoney& other) const
{
	return BaseMoney(cents_ + other.cents_);
}

BaseMoney BaseMoney::operator-(const BaseMoney& other) const
{
	return BaseMoney(cents_ - other.cents_);
}

BaseMoney BaseMoney::operator*(const int factor) const
{
	return BaseMoney(cents_ * factor);
}

BaseMoney BaseMoney::operator/(const int divisor) const
{
	return BaseMoney(cents_ / divisor);
}

std::strong_ordering BaseMoney::operator<=>(int i) const {
	if (cents_ < i) {
		return std::strong_ordering::less;
	}
	else if (cents_ > i) {
		return std::strong_ordering::greater;
	}
	return std::strong_ordering::equal;
}


std::ostream& operator<<(std::ostream& os, const BaseMoney& money)
{
	{
		os << "$" << money.cents_ / 100 << "." << money.cents_ % 100;
		return os;
	}
}
