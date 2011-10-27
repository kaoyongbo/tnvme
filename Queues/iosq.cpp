#include "iosq.h"
#include "globals.h"


IOSQ::IOSQ() :
    SQ(0, Trackable::OBJTYPE_FENCE, Trackable::LIFETIME_FENCE, false)
{
    // This constructor will throw
}


IOSQ::IOSQ(int fd, Trackable::Lifetime life, bool ownByRsrcMngr) :
    SQ(fd, Trackable::OBJ_IOSQ, life, ownByRsrcMngr)
{
	mPriority = 0;
}


IOSQ::~IOSQ()
{
}


void
IOSQ::Init(uint16_t qId, uint16_t numEntries, uint16_t cqId,
    uint8_t priority)
{
    uint8_t entrySize;

    switch (priority) {
	case 0x00:
	case 0x01:
	case 0x10:
	case 0x11:
		mPriority = priority;
		break;
	default:
		LOG_DBG("Illegal priority value, can't fit within 2 bits");
		throw exception();
		break;
	}

    if (gCtrlrConfig->GetIOSQES(entrySize) == false) {
        LOG_ERR("Unable to learn IOSQ entry size");
        throw exception();
    }
    SQ::Init(qId, entrySize, numEntries, cqId);
}


void
IOSQ::Init(uint16_t qId, uint16_t numEntries, MemBuffer &memBuffer,
    uint16_t cqId, uint8_t priority)
{
    uint8_t entrySize;

    switch (priority) {
    	case 0x00:
    	case 0x01:
    	case 0x10:
    	case 0x11:
    		mPriority = priority;
    		break;
    	default:
    		LOG_DBG("Illegal priority value, can't fit within 2 bits");
    		throw exception();
    		break;
    	}

    if (gCtrlrConfig->GetIOSQES(entrySize) == false) {
        LOG_ERR("Unable to learn IOSQ entry size");
        throw exception();
    }
    SQ::Init(qId, entrySize, numEntries, memBuffer, cqId);
}
