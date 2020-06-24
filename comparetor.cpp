#include "comparetor.hpp"
#include "deck.hpp"

int straight_flush_comparetpor::compare(deck *Deck1, deck *Deck2)
{
    return Deck1->getDeck().at(Deck1->getMatchPoint()).compare(Deck2->getDeck().at(Deck2->getMatchPoint()));
}

int four_of_a_kind_comparetpor::compare(deck *Deck1, deck *Deck2)
{
    int matchPoint[] = {Deck1->getMatchPoint(),Deck2->getMatchPoint()};
    int result = Deck1->getDeck().at(matchPoint[0]).compare(Deck2->getDeck().at(matchPoint[1]));
    if(result == 0)
    {
        for(int i = 0;i<2;i++)
        {
            if(matchPoint[i] == 3)
            {
                matchPoint[i] = 4;
            }
            else
            {
                matchPoint[i] = 0;
            }
        }
        return Deck1->getDeck().at(matchPoint[0]).compare(Deck2->getDeck().at(matchPoint[1]));
    }
    return result;
}

int full_house_comparetpor::compare(deck *Deck1, deck *Deck2)
{
    int matchPoint[] = {Deck1->getMatchPoint(),Deck2->getMatchPoint()};
    int result = Deck1->getDeck().at(matchPoint[0]).compare(Deck2->getDeck().at(matchPoint[1]));
    if(result == 0)
    {
        for(int i = 0;i<2;i++)
        {
            if(matchPoint[i] == 2)
            {
                matchPoint[i] = 4;
            }
            else
            {
                matchPoint[i] = 1;
            }
        }
        return Deck1->getDeck().at(matchPoint[0]).compare(Deck2->getDeck().at(matchPoint[1]));
    }
    return result;
}

int straight_comparetpor::compare(deck *Deck1, deck *Deck2)
{
    return Deck1->getDeck().at(Deck1->getMatchPoint()).compare(Deck2->getDeck().at(Deck2->getMatchPoint()));
}

int three_of_a_kind_comparetpor::compare(deck *Deck1, deck *Deck2)
{
    int matchPoint[] = {Deck1->getMatchPoint(),Deck2->getMatchPoint()};
    int result = Deck1->getDeck().at(matchPoint[0]).compare(Deck2->getDeck().at(matchPoint[1]));
    if(result == 0)
    {
        QVector<card> deck1_tmp = Deck1->getDeck();
        QVector<card> deck2_tmp = Deck2->getDeck();
        deck1_tmp.erase(deck1_tmp.begin()+matchPoint[0]-2,deck1_tmp.begin()+matchPoint[0]);
        deck2_tmp.erase(deck2_tmp.begin()+matchPoint[1]-2,deck2_tmp.begin()+matchPoint[1]);
        while(true)
        {
            result = deck1_tmp.back().compare(deck2_tmp.back());
            deck1_tmp.pop_back();
            deck2_tmp.pop_back();
            if(result !=0 || deck1_tmp.isEmpty())
            {
                return result;
            }
        }
    }
    return result;
}

int flush_comparetpor::compare(deck *Deck1, deck *Deck2)
{
    int result;
    QVector<card> deck1_tmp = Deck1->getDeck();
    QVector<card> deck2_tmp = Deck2->getDeck();
    while(true)
    {
        result = deck1_tmp.back().compare(deck2_tmp.back());
        deck1_tmp.pop_back();
        deck2_tmp.pop_back();
        if(result !=0 || deck1_tmp.isEmpty())
        {
            return result;
        }
    }
}

int high_card_comparetor::compare(deck *Deck1, deck *Deck2)
{
    int result;
    QVector<card> deck1_tmp = Deck1->getDeck();
    QVector<card> deck2_tmp = Deck2->getDeck();
    while(true)
    {
        result = deck1_tmp.back().compare(deck2_tmp.back());
        deck1_tmp.pop_back();
        deck2_tmp.pop_back();
        if(result !=0 || deck1_tmp.isEmpty())
        {
            return result;
        }
    }
}

int one_pair_comparetor::compare(deck *Deck1, deck *Deck2)
{
    int matchPoint[] = {Deck1->getMatchPoint(),Deck2->getMatchPoint()};
    int result = Deck1->getDeck().at(matchPoint[0]).compare(Deck2->getDeck().at(matchPoint[1]));
    if(result == 0)
    {
        QVector<card> deck1_tmp = Deck1->getDeck();
        QVector<card> deck2_tmp = Deck2->getDeck();
        deck1_tmp.erase(deck1_tmp.begin()+matchPoint[0]-1,deck1_tmp.begin()+matchPoint[0]);
        deck2_tmp.erase(deck2_tmp.begin()+matchPoint[1]-1,deck2_tmp.begin()+matchPoint[1]);
        while(true)
        {
            result = deck1_tmp.back().compare(deck2_tmp.back());
            deck1_tmp.pop_back();
            deck2_tmp.pop_back();
            if(result !=0 || deck1_tmp.isEmpty())
            {
                return result;
            }
        }
    }
    return result;
}

int two_pares_comparetpor::compare(deck *Deck1, deck *Deck2)
{
    int matchPoint[] = {Deck1->getMatchPoint(),Deck2->getMatchPoint()};
    QVector<card> deck1_tmp = Deck1->getDeck();
    QVector<card> deck2_tmp = Deck2->getDeck();
    card the_single_card[2] = {deck1_tmp.at(matchPoint[0]),deck1_tmp.at(matchPoint[1])};

    deck1_tmp.erase(deck1_tmp.begin()+matchPoint[0]);
    deck2_tmp.erase(deck2_tmp.begin()+matchPoint[1]);

    int result = deck1_tmp.back().compare(deck2_tmp.back());

    if(result == 0)
    {
        result = deck1_tmp.front().compare(deck2_tmp.front());
        if(result == 0)
        {
            return the_single_card[0].compare(the_single_card[1]);
        }
        return result;
    }
    return result;

}

int royal_flush_comparetpor::compare(deck *Deck1, deck *Deck2)
{
    Q_UNUSED(Deck1);
    Q_UNUSED(Deck2);
    return 0;
}
