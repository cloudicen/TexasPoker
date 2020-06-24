/**
  * 这里定义了一些比较器，用于在牌型相同的时候进行比较
  * 抽象基类:comparetor
  * 针对不同牌型的比较器继承于基类
  *
  */
#ifndef COMPARETOR_HPP
#define COMPARETOR_HPP

#include <QVector>
#include "card.hpp"


class deck;//前置声明deck类

class comparetor
{
public:
    virtual int compare(deck*Deck1,deck*Deck2) = 0;
    inline ~comparetor(){};
};

class high_card_comparetor : public comparetor
{
    int compare(deck*Deck1,deck*Deck2) override;
};

class one_pair_comparetor :public comparetor
{
    int compare(deck*Deck1,deck*Deck2) override;
};

class two_pares_comparetpor: public comparetor
{
    int compare(deck*Deck1,deck*Deck2) override;
};

class three_of_a_kind_comparetpor: public comparetor
{
    int compare(deck*Deck1,deck*Deck2) override;
};

class straight_comparetpor: public comparetor
{
    int compare(deck*Deck1,deck*Deck2) override;
};

class flush_comparetpor: public comparetor
{
    int compare(deck*Deck1,deck*Deck2) override;
};

class full_house_comparetpor: public comparetor
{
    int compare(deck*Deck1,deck*Deck2) override;
};

class four_of_a_kind_comparetpor: public comparetor
{
    int compare(deck*Deck1,deck*Deck2) override;
};

class straight_flush_comparetpor: public comparetor
{
    int compare(deck*Deck1,deck*Deck2) override;
};

class royal_flush_comparetpor: public comparetor
{
    int compare(deck*Deck1,deck*Deck2) override;
};
#endif // COMPARETOR_HPP
