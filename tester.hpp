#ifndef TESTER_HPP
#define TESTER_HPP
#include "deck.hpp"
#include "QDebug"

/**
 * @brief test
 * @note    因为觉得这一整个算一个单元。。所所以只写了一个测试函数
 */

void test()
{

    qDebug() << "测试card类和deck类的基本操作\n";

    deck deck1(QVector<card>{card("10",'D'),card("J",'D'),card("Q",'D'),card("K",'D'),card("A",'D')});
    deck1.analyzeDeck();
    qDebug() << deck1.toString();

    deck deck2(QVector<card>{card("8",'S'),card("7",'S'),card("6",'S'),card("5",'S'),card("4",'S')});
    deck2.analyzeDeck();
    qDebug() << deck2.toString();

    deck deck3(QVector<card>{card("7",'H'),card("7",'H'),card("7",'H'),card("7",'H'),card("5",'C')});
    deck3.analyzeDeck();
    qDebug() << deck3.toString();

    deck deck4(QVector<card>{card("6",'C'),card("6",'H'),card("6",'D'),card("5",'H'),card("5",'C')});
    deck4.analyzeDeck();
    qDebug() << deck4.toString();

    deck deck5(QVector<card>{card("2",'C'),card("7",'C'),card("5",'C'),card("3",'C'),card("A",'C')});
    deck5.analyzeDeck();
    qDebug() << deck5.toString();

    deck deck6(QVector<card>{card("2",'S'),card("3",'C'),card("4",'H'),card("5",'S'),card("6",'D')});
    deck6.analyzeDeck();
    qDebug() << deck6.toString();

    deck deck7(QVector<card>{card("3",'S'),card("3",'C'),card("3",'H'),card("K",'S'),card("9",'D')});
    deck7.analyzeDeck();
    qDebug() << deck7.toString();

    deck deck8(QVector<card>{card("3",'S'),card("3",'C'),card("K",'H'),card("K",'S'),card("9",'D')});
    deck8.analyzeDeck();
    qDebug() << deck7.toString();

    deck deck9(QVector<card>{card("3",'D'),card("3",'C'),card("A",'H'),card("K",'S'),card("9",'D')});
    deck9.analyzeDeck();
    qDebug() << deck8.toString();

    deck deck10(QVector<card>{card("3",'D'),card("Q",'C'),card("A",'H'),card("K",'S'),card("9",'D')});
    deck10.analyzeDeck();
    qDebug() << deck9.toString() << endl;

    qDebug() << "--------------------------------\n";

    qDebug() << "测试分辨牌组的大小\n";

    qDebug() << "--------------------------------\n";

    qDebug() << "测试各种平局\n";

    qDebug() << deck1.compare(deck1);
    qDebug() << deck2.compare(deck2);
    qDebug() << deck3.compare(deck3);
    qDebug() << deck4.compare(deck4);
    qDebug() << deck5.compare(deck5);
    qDebug() << deck6.compare(deck6);
    qDebug() << deck7.compare(deck7);
    qDebug() << deck8.compare(deck8);
    qDebug() << deck9.compare(deck9);
    qDebug() << deck10.compare(deck10);

    qDebug() << "--------------------------------\n";

    qDebug() << "测试牌型大小\n";

    qDebug() << deck4.compare(deck7);
    qDebug() << deck5.compare(deck1);

    qDebug() << "--------------------------------\n";

    qDebug() << "同种牌型比大小\n";
    {
        qDebug() << "--------------------------------";
        qDebug() << "同花顺，前一个大。";
        deck deckWite = deck2;
        deck deckBlack = deck({QVector<card>{card("7",'S'),card("6",'S'),card("5",'S'),card("4",'S'),card("3",'S')}});
        deckBlack.analyzeDeck();
        qDebug() << deckWite.compare(deckBlack);
        qDebug() << deckWite.toString();
        qDebug() << deckBlack.toString();
        qDebug() << "--------------------------------\n";
    }
    {
        qDebug() << "--------------------------------";
        qDebug() << "四条，后一个大。";
        deck deckWite = deck3;
        deck deckBlack(QVector<card>{card("8",'H'),card("8",'H'),card("8",'H'),card("8",'H'),card("7",'C')});
        deckBlack.analyzeDeck();
        qDebug() << deckWite.compare(deckBlack);
        qDebug() << deckWite.toString();
        qDebug() << deckBlack.toString();
        qDebug() << "--------------------------------\n";
    }
    {
        qDebug() << "--------------------------------";
        qDebug() << "满堂红，前一个大。";
        deck deckWite = deck4;
        deck deckBlack(QVector<card>{card("3",'D'),card("3",'H'),card("3",'H'),card("8",'H'),card("8",'C')});
        deckBlack.analyzeDeck();
        qDebug() << deckWite.compare(deckBlack);
        qDebug() << deckWite.toString();
        qDebug() << deckBlack.toString();
        qDebug() << "--------------------------------\n";
    }
    {
        qDebug() << "--------------------------------";
        qDebug() << "同花，前一个大。";
        deck deckWite = deck5;
        deck deckBlack(QVector<card>{card("K",'H'),card("2",'H'),card("3",'H'),card("8",'H'),card("8",'H')});
        deckBlack.analyzeDeck();
        qDebug() << deckWite.compare(deckBlack);
        qDebug() << deckWite.toString();
        qDebug() << deckBlack.toString();
        qDebug() << "--------------------------------\n";
    }
    {
        qDebug() << "--------------------------------";
        qDebug() << "顺子，后一个大。";
        deck deckWite = deck6;
        deck deckBlack(QVector<card>{card("K",'D'),card("Q",'S'),card("J",'H'),card("10",'H'),card("9",'H')});
        deckBlack.analyzeDeck();
        qDebug() << deckWite.compare(deckBlack);
        qDebug() << deckWite.toString();
        qDebug() << deckBlack.toString();
        qDebug() << "--------------------------------\n";
    }
    {
        qDebug() << "--------------------------------";
        qDebug() << "三条，前一个大。";
        deck deckWite = deck7;
        deck deckBlack(QVector<card>{card("2",'D'),card("2",'S'),card("2",'H'),card("3",'H'),card("9",'H')});
        deckBlack.analyzeDeck();
        qDebug() << deckWite.compare(deckBlack);
        qDebug() << deckWite.toString();
        qDebug() << deckBlack.toString();
        qDebug() << "--------------------------------\n";
    }
    {
        qDebug() << "--------------------------------";
        qDebug() << "两对，后一个大。";
        deck deckWite = deck8;
        deck deckBlack(QVector<card>{card("2",'D'),card("2",'S'),card("A",'H'),card("A",'H'),card("9",'H')});
        deckBlack.analyzeDeck();
        qDebug() << deckWite.compare(deckBlack);
        qDebug() << deckWite.toString();
        qDebug() << deckBlack.toString();
        qDebug() << "--------------------------------\n";
    }
    {
        qDebug() << "--------------------------------";
        qDebug() << "一对，前一个大。";
        deck deckWite = deck9;
        deck deckBlack(QVector<card>{card("3",'D'),card("3",'S'),card("A",'H'),card("K",'H'),card("5",'H')});
        deckBlack.analyzeDeck();
        qDebug() << deckWite.compare(deckBlack);
        qDebug() << deckWite.toString();
        qDebug() << deckBlack.toString();
        qDebug() << "--------------------------------\n";
    }
    {
        qDebug() << "--------------------------------";
        qDebug() << "高牌，后一个大。";
        deck deckWite = deck10;
        deck deckBlack(QVector<card>{card("10",'D'),card("2",'S'),card("A",'H'),card("K",'H'),card("Q",'H')});
        deckBlack.analyzeDeck();
        qDebug() << deckWite.compare(deckBlack);
        qDebug() << deckWite.toString();
        qDebug() << deckBlack.toString();
        qDebug() << "--------------------------------\n";
    }

}

#endif // TESTER_HPP
