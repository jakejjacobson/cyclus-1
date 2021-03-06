#ifndef BUILDER_H
#define BUILDER_H

#include <set>

#include "CommodityProducer.h"

namespace ActionBuilding
{
  /**
     a mixin to provide information about commodity producers that can
     be built
   */
  class Builder
  {
  public:
    /// constructor
    Builder();

    /// virtual destructor for inheritence
    virtual ~Builder();

    // protected: @MJGFlag - should be protected. revise when tests can
    // be found by classes in the Utility folder
    /**
       register a commodity producer with the manager
       @param producer the producer
     */
    void registerProducer(SupplyDemand::CommodityProducer* producer);

    /**
       unregister a commodity producer with the manager
       @param producer the producer
     */
    void unRegisterProducer(SupplyDemand::CommodityProducer* producer);

    /**
       @return the number of buildings managed by this builder
     */
    double nBuildingPrototypes();
    
    /**
       @return the beginning iterator of the set of producers
     */
    std::set<SupplyDemand::CommodityProducer*>::iterator beginningProducer();

    /**
       @return the beginning iterator of the set of producers
     */
    std::set<SupplyDemand::CommodityProducer*>::iterator endingProducer();

  private:
    /// the set of managed producers
    std::set<SupplyDemand::CommodityProducer*> producers_;

    //#include "CommodityProducerManagerTests.h"
    //friend class CommodityProducerManagerTests; 
    // @MJGFlag - removed for the same reason as above
  };
}
#endif
