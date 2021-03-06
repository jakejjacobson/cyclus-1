#ifndef COMMODITYPRODUCER_H
#define COMMODITYPRODUCER_H

#include <map>
#include <set>

#include "Commodity.h"

namespace SupplyDemand
{
  /**
     a container to hold information about a commodity
   */
  struct CommodityInformation
  {
    CommodityInformation();
    CommodityInformation(double a_capacity, double a_cost);
    double cost;
    double capacity;
  };

  /**
     a mixin to provide information about produced commodities
   */
  class CommodityProducer
  {
  public:
    /// constructor
    CommodityProducer();

    /// virtual destructor for inheritence
    virtual ~CommodityProducer();

    /**
       @return the set of commodities produced by this producers
     */
    std::set<Commodity,CommodityCompare> producedCommodities();

    /**
       @return true if the commodity is produced by this entity
       @param commodity the commodity in question
     */
    bool producesCommodity(const Commodity& commodity);

    /**
       @return the production capacity for a commodity
       @param commodity the commodity in question
     */
    double productionCapacity(const Commodity& commodity);

    /**
       @return the cost to produce a commodity at a given capacity
       @param commodity the commodity in question
     */
    double productionCost(const Commodity& commodity);

    // protected: @MJGFlag - should be protected. revise when tests can
    // be found by classes in the Utility folder
    /**
       register a commodity as being produced by this object
       @param commodity the commodity being produced
     */
    void addCommodity(const Commodity& commodity);

    /**
       set the production capacity for a given commodity
       @param commodity the commodity being produced
       @param capacity the production capacity
     */
    void setCapacity(const Commodity& commodity, double capacity);

    /**
       set the production cost for a given commodity
       @param commodity the commodity being produced
       @param cost the production cost
     */
    void setCost(const Commodity& commodity, double cost);

    /**
       register a commodity as being produced by this object and set
       its relevant info
       @param commodity the commodity being produced
       @param info the information describing the commodity
     */
    void addCommodityWithInformation(const Commodity& commodity, 
                                     const CommodityInformation& info);
    /**
       add all commodities produced by a source
       @param source the original commodity producer
     */
    void copyProducedCommoditiesFrom(CommodityProducer* source);
    
    /**
       checks if producesCommodity() is true. if it is false, an 
       error is thrown.
       @param commodity the commodity in question
     */
    void throwErrorIfCommodityNotProduced(const Commodity& commodity);
    
    /// a default production capacity
    double default_capacity_;

    /// a default production cost
    double default_cost_;

  private:
    /// a collection of commodities and their production capacities
    std::map<Commodity,CommodityInformation,CommodityCompare> produced_commodities_;

    //#include "CommodityProducerTests.h"
    //friend class CommodityProducerTests; 
    // @MJGFlag - removed for the same reason as above
  };
}

#endif
