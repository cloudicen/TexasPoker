#include "card.hpp"

QMap<char,QString> card::cardSuitType = {
    {'D',"方片"},
    {'S',"黑桃"},
    {'H',"红桃"},
    {'C',"梅花"}};

QList<QString> card::cardNoList = {"0","2","3","4","5","6","7","8","9","10","J","Q","K","A"};

card::card(QString _cardNo, char _cardSuit)
{
    if(!cardNoList.contains(_cardNo))
    {
        valid = false;
        return;
    }
    if(!cardSuitType.contains(_cardSuit))
    {
        valid = false;
        return;
    }
    cardNo=_cardNo;
    cardSuit=_cardSuit;
    valid = true;
}

QString card::toString() const
{
    return QString("%1 %2").arg(cardSuitType.value(cardSuit)).arg(cardNo);
}

bool card::isValid() const
{
    return valid;
}

int card::compare(const card &other) const
{
    return cardNoList.indexOf(cardNo) - cardNoList.indexOf(other.cardNo);
}

bool card::sameAs(const card &other) const
{
    if(*this == other && this->cardSuit == other.cardSuit)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool card::isSameSuit(const card &other) const
{
    if(this->cardSuit == other.cardSuit)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool card::operator>(const card &other) const
{
    return cardNoList.indexOf(cardNo) > cardNoList.indexOf(other.cardNo);
}

bool card::operator<(const card &other) const
{
    return cardNoList.indexOf(cardNo) < cardNoList.indexOf(other.cardNo);
}

bool card::operator==(const card &other) const
{
    return cardNoList.indexOf(cardNo) == cardNoList.indexOf(other.cardNo);
}
