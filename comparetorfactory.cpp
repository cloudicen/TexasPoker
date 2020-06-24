#include "comparetorfactory.hpp"


QSharedPointer<comparetor> comparetorFactory::getComparetor(const deckType type)
{
    switch(type)
    {
    case high_card:
        return QSharedPointer<comparetor>(new high_card_comparetor);
    case one_pair:
        return QSharedPointer<comparetor>(new one_pair_comparetor);
    case two_pairs:
        return QSharedPointer<comparetor>(new two_pares_comparetpor);
    case three_of_a_kind:
        return QSharedPointer<comparetor>(new three_of_a_kind_comparetpor);
    case straight:
        return QSharedPointer<comparetor>(new straight_comparetpor);
    case flush:
        return QSharedPointer<comparetor>(new flush_comparetpor);
    case full_house:
        return QSharedPointer<comparetor>(new full_house_comparetpor);
    case four_of_a_kind:
        return QSharedPointer<comparetor>(new four_of_a_kind_comparetpor);
    case straight_flush:
        return QSharedPointer<comparetor>(new straight_flush_comparetpor);
    case royal_flush:
        return QSharedPointer<comparetor>(new royal_flush_comparetpor);
    case undefined:
        return QSharedPointer<comparetor>(nullptr);
    }
    return QSharedPointer<comparetor>(nullptr);
}
