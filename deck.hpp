#ifndef DECK_HPP
#define DECK_HPP

#include <QList>
#include "card.hpp"
#include "comparetorfactory.hpp"

class comparetor;

class deck
{
private:
    /**
      提供牌型枚举到字符串的映射
      */
    QMap<deckType,QString> deckTypeName = {
        {deckType::high_card,"高牌"},
        {deckType::one_pair,"一对"},
        {deckType::two_pairs,"两对"},
        {deckType::three_of_a_kind,"三条"},
        {deckType::straight,"顺子"},
        {deckType::flush,"同花"},
        {deckType::full_house,"满堂红"},
        {deckType::four_of_a_kind,"四条"},
        {deckType::straight_flush,"同花顺"},
        {deckType::royal_flush,"同花大顺"}
    };

    /**
     * @brief Deck，存放牌组
     */
    QVector<card> Deck;

    /**
     * @brief Type，标识牌型
     */
    deckType Type = undefined;

    /**
     * @brief matchPoit 标识牌型的特征点
     * @note 默认标注的特征点是牌组中位置最靠后的，例外的是在“两对”牌型中，标注的是那一张单牌的位置
     */
    int matchPoit = -1;

    /**
     * @brief isAnalyzed，标注该牌组是否已经被分析过了
     */
    bool isAnalyzed = false;

    /**
     * @brief initDeck，初始化牌组，对其排序
     */
    void initDeck();

    /**
     * @brief analyzeType，分析牌型，需要在牌组初始化后进行
     */
    void analyzeType();

public:
    /**
     * @brief deck
     * @param _Deck，五张牌组成的vector
     */
    deck(const QVector<card> & _Deck);

    /**
     * @brief compare，比较两个牌组
     * @param other
     * @return
     */
    QString compare(deck &other);

    /**
     * @brief getDeck，获取牌组vector的引用
     * @return
     */
    const QVector<card> &getDeck() const;

    /**
     * @brief getType，获取牌型
     * @return
     */
    deckType getType() const;

    /**
     * @brief getMatchPoint，获取特征点
     * @return
     */
    int getMatchPoint() const;

    /**
     * @brief addCard 向牌组添加卡牌
     * @param _card
     * @return 若牌组已满，返回false
     */
    bool addCard(const card & _card);

    /**
     * @brief clearDeck 清空牌组
     */
    void clearDeck();

    /**
     * @brief analyzeDeck 分析牌组，进行比较之前必须先调用
     */
    void analyzeDeck();

    /**
     * @brief toString 转换成可阅读的字符串
     * @return
     */
    QString toString();
};

#endif // DECK_HPP
