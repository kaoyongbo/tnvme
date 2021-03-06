/*
 * Copyright (c) 2012, Intel Corporation.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef _SECURITYSEND_H_
#define _SECURITYSEND_H_

#include "baseSecurity.h"


class SecuritySend;    // forward definition
typedef boost::shared_ptr<SecuritySend>             SharedSecuritySendPtr;
typedef boost::shared_ptr<const SecuritySend>       ConstSharedSecuritySendPtr;
#define CAST_TO_SECURITYSEND(shared_trackable_ptr)  \
        boost::dynamic_pointer_cast<SecuritySend>(shared_trackable_ptr);


/**
* This class implements the Security Send admin cmd specific to nvm cmd set.
*
* @note This class may throw exceptions.
*/
class SecuritySend : public BaseSecurity
{
public:
    SecuritySend();
    virtual ~SecuritySend();

    /// Used to compare for NULL pointers being returned by allocations
    static SharedSecuritySendPtr NullSecuritySendPtr;
    static const uint8_t Opcode;
};


#endif
