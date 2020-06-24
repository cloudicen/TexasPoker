#ifndef COMPARETORFACTORY_HPP
#define COMPARETORFACTORY_HPP
#include "comparetor.hpp"
#include "QPointer"

/**
 * @brief The deckType enum，定义了各种牌型的枚举
 */
enum deckType{undefined,high_card,one_pair,two_pairs,three_of_a_kind,straight,flush,full_house,four_of_a_kind,straight_flush,royal_flush};

/**
 * @brief The comparetorFactory class，比较器的工厂类，返回需要的比较器
 */
class comparetorFactory
{
public:
    static QSharedPointer<comparetor> getComparetor(const deckType type);
};

#endif // COMPARETORFACTORY_HPP
