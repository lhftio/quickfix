#ifndef FIX50SP2_BUSTEND_H
#define FIX50SP2_BUSTEND_H

#include "Message.h"

namespace FIX50SP2
{

  class BustEnd : public Message
  {
  public:
    BustEnd() : Message(MsgType()) {}
    BustEnd(const FIX::Message& m) : Message(m) {}
    BustEnd(const Message& m) : Message(m) {}
    BustEnd(const BustEnd& m) : Message(m) {}
    static FIX::MsgType MsgType() { return FIX::MsgType("UI"); }

    FIELD_SET(*this, FIX::BustID);
    FIELD_SET(*this, FIX::ExecID);

    FIELD_SET(*this, FIX::NoPartyIDs);
    class NoPartyIDs: public FIX::Group
    {
    public:
    NoPartyIDs() : FIX::Group(453,448,FIX::message_order(448,447,452,802,0)) {}
      FIELD_SET(*this, FIX::PartyID);
      FIELD_SET(*this, FIX::PartyIDSource);
      FIELD_SET(*this, FIX::PartyRole);
      FIELD_SET(*this, FIX::NoPartySubIDs);
      class NoPartySubIDs: public FIX::Group
      {
      public:
      NoPartySubIDs() : FIX::Group(802,523,FIX::message_order(523,803,0)) {}
        FIELD_SET(*this, FIX::PartySubID);
        FIELD_SET(*this, FIX::PartySubIDType);
      };
    };

    FIELD_SET(*this, FIX::Symbol);
  };
} 
 
#endif
