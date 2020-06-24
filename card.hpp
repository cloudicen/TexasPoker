#ifndef CARD_HPP
#define CARD_HPP

#include<QMap>
/**
 * @brief The card class，用于表示卡牌的类
 */
class card
{
private:
    /**
     * @brief cardSuitType 提供花色代号到名字的映射
     */
    static QMap<char,QString> cardSuitType;

    /**
     * @brief cardNoList    以字符形式按顺序存储合法的卡牌数字
     */
    static QList<QString> cardNoList;

    /**
     * @brief valid     表示当前的card对象是否有效
     */
    bool valid = false;

    /**
     * @brief cardNo    卡牌数字
     */
    QString cardNo = "0";

    /**
     * @brief cardSuit  卡牌花色
     */
    char cardSuit = '0';

public:
    /**
     * @brief card 禁用默认构造函数
     */
    card() = delete;

    /**
     * @brief card  构造一个card对象
     * @param _cardNo   牌的数字
     * @param _cardSuit 牌的花色
     */
    card(QString _cardNo,char _cardSuit = 'D');

    /**
     * @brief toString  把卡片的数字和花色组合成字符串
     * @return          返回 "<花色> <数字>"形式的字符串
     */
    QString toString()const;

    /**
     * @brief isValid   返回卡片对象的有效性
     * @return
     */
    bool isValid() const;

    /**
     * @brief compare   比较两张牌的大小
     * @param other     card对象
     * @return          相等返回0，其余情况返回差值（大于返回正数，小于返回负数）
     */
    int compare(const card & other) const;

    /**
     * @brief sameAs    用于判断两张牌是否完全相同
     * @param other     card对象
     * @return
     */
    bool sameAs(const card & other) const;

    bool isSameSuit(const card & other) const;

    bool operator>(const card & other) const;
    bool operator<(const card & other) const;
    bool operator==(const card & other) const;
};

#endif // CARD_HPP
