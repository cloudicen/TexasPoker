#include "deck.hpp"

void deck::initDeck()
{
    std::sort(Deck.begin(),Deck.end(),[&](card a,card b){
        return a<b;
    });
}

void deck::analyzeType()
{
    bool flush_flag=true;
    bool straight_flag=true;
    QVector<card> deck_tmp;
    deck_tmp.push_back(Deck.at(0));

    QList<int>lengthCount;
    lengthCount.push_back(1);

    int maxLength = 1;

    for(int i=1;i<5;i++)
    {
        //检测是否是同花
        if(flush_flag == true && !deck_tmp.back().isSameSuit(Deck.at(i)))
        {
           flush_flag = false;
        }

        //检测是否是顺子
        if(straight_flag == true && deck_tmp.back().compare(Deck.at(i)) != -1)
        {
           straight_flag = false;
        }

        //遍历进行逐个匹配
        if(deck_tmp.back() == Deck.at(i))
        {
            deck_tmp.push_back(Deck.at(i));
            lengthCount.push_back(deck_tmp.length());
            if(deck_tmp.length() > maxLength)
            {
                maxLength = deck_tmp.length();
            }
        }
        else
        {
            deck_tmp.clear();
            deck_tmp.push_back(Deck.at(i));
            lengthCount.push_back(deck_tmp.length());
        }
    }

    if(flush_flag == true)
    {
        if(straight_flag == true)
        {
            if(Deck.last().operator==(card("A")))
            {
                Type = royal_flush;
                matchPoit = 4;
            }
            else
            {
                Type = straight_flush;
                matchPoit = 4;
            }
        }
        else
        {
            Type = flush;
            matchPoit = 4;
        }
    }
    else if(straight_flag == true)
    {
        Type = straight;
        matchPoit = 4;
    }
    else
    {
        if(maxLength == 1)
        {
            Type = high_card;
            matchPoit = 4;
        }
        else if(maxLength == 4)
        {
            Type = four_of_a_kind;
            matchPoit = (lengthCount.indexOf(4));
        }
        else if(maxLength == 3)
        {
            matchPoit = lengthCount.indexOf(3);
            if(lengthCount.count(2) == 2)
            {
                Type = full_house;
            }
            else
            {
                Type = three_of_a_kind;
            }
        }
        else if(maxLength == 2)
        {
            if(lengthCount.count(2) == 2)
            {
                Type = two_pairs;
                if(lengthCount.lastIndexOf(2) == 3)
                {
                    matchPoit = 4;
                }
                else if(lengthCount.indexOf(2) == 1)
                {
                    matchPoit = 2;
                }
                else
                {
                    matchPoit = 0;
                }
            }
            else
            {
                Type = one_pair;
                matchPoit = lengthCount.indexOf(2);
            }
        }
    }

}

deck::deck(const QVector<card> &_Deck)
{
    if(_Deck.size() >5)
    {
        return;
    }
    else
    {
        Deck = QVector<card>(_Deck);
    }
}

QString deck::compare(deck &other)
{
    QString result="winner:%1 ; reason:%2.";
    if(this->Type > other.Type)
    {
        result = result.arg("prev").arg("Type");
    }
    else if(this-> Type < other.Type)
    {
        result = result.arg("after").arg("Type");
    }
    else
    {
        QString state;
        auto comparetor = comparetorFactory::getComparetor(this->Type);
        int cmpResult = comparetor->compare(this,&other);
        if(cmpResult > 0)
        {
            result = result.arg("prev").arg("Num");
        }
        else if(cmpResult < 0)
        {
            result = result.arg("after").arg("Num");
        }
        else
        {
            result = result.arg("none").arg("Num");
        }
    }
    return result;
}

const QVector<card> &deck::getDeck() const
{
    return Deck;
}

deckType deck::getType() const
{
    return Type;
}

int deck::getMatchPoint() const
{
    return matchPoit;
}

bool deck::addCard(const card & _card)
{
    if(Deck.size() < 5)
    {
        Deck.push_back(_card);
        return true;
    }
    return false;
}

void deck::clearDeck()
{
    Deck.clear();
    isAnalyzed = false;
}

void deck::analyzeDeck()
{
    initDeck();
    analyzeType();
    isAnalyzed = true;
}

QString deck::toString()
{

    return QString("deck:%1,%2,%3,%4,%5 type:%6")
            .arg(Deck.at(0).toString())
            .arg(Deck.at(1).toString())
            .arg(Deck.at(2).toString())
            .arg(Deck.at(3).toString())
            .arg(Deck.at(4).toString())
            .arg(deckTypeName.value(Type,"haven't analyzed"));
}
