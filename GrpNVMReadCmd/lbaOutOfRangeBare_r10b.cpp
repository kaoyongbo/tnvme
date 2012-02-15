/*
 * Copyright (c) 2011, Intel Corporation.
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

#include "lbaOutOfRangeBare_r10b.h"
#include "globals.h"
#include "grpDefs.h"
#include "../Queues/acq.h"
#include "../Queues/asq.h"
#include "../Utils/kernelAPI.h"
#include "../Utils/queues.h"
#include "../Cmds/read.h"

#define RD_NUM_BLKS                 2


LBAOutOfRangeBare_r10b::LBAOutOfRangeBare_r10b(int fd, string grpName, string testName,
    ErrorRegs errRegs) :
    Test(fd, grpName, testName, SPECREV_10b, errRegs)
{
    // 66 chars allowed:     xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    mTestDesc.SetCompliance("revision 1.0b, section 4,6");
    mTestDesc.SetShort(     "Issue read and cause SC=LBA Out of Range on bare namspcs");
    // No string size limit for the long description
    mTestDesc.SetLong(
        "For all bare namspcs from Identify.NN, determine Identify.NSZE; For "
        "each namspc cause many scenarios by issuing a single read cmd "
        "requesting 2 data blocks. 1) Issue cmd where 1st block starts at LBA "
        "(Identify.NSZE - 1), expect failure 2) Issue cmd where 1st block "
        "starts at LBA Identify.NSZE, expect failure. 3) Issue cmd where 1st "
        "block starts at 2nd to last max LBA value, expect failure. 4) Issue "
        "cmd where 1st block starts at last max LBA value, expect failure.");
}


LBAOutOfRangeBare_r10b::~LBAOutOfRangeBare_r10b()
{
    ///////////////////////////////////////////////////////////////////////////
    // Allocations taken from the heap and not under the control of the
    // RsrcMngr need to be freed/deleted here.
    ///////////////////////////////////////////////////////////////////////////
}


LBAOutOfRangeBare_r10b::
LBAOutOfRangeBare_r10b(const LBAOutOfRangeBare_r10b &other) : Test(other)
{
    ///////////////////////////////////////////////////////////////////////////
    // All pointers in this object must be NULL, never allow shallow or deep
    // copies, see Test::Clone() header comment.
    ///////////////////////////////////////////////////////////////////////////
}


LBAOutOfRangeBare_r10b &
LBAOutOfRangeBare_r10b::operator=(const LBAOutOfRangeBare_r10b &other)
{
    ///////////////////////////////////////////////////////////////////////////
    // All pointers in this object must be NULL, never allow shallow or deep
    // copies, see Test::Clone() header comment.
    ///////////////////////////////////////////////////////////////////////////
    Test::operator=(other);
    return *this;
}


bool
LBAOutOfRangeBare_r10b::RunCoreTest()
{
    /** \verbatim
     * Assumptions:
     * 1) Test CreateResources_r10b has been called previously
     * \endverbatim
     */

    return true;
}
