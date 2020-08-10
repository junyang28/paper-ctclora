/**
 * @file LDDUsart.h
 * <!------------------------------------------------------------------------>
 * @brief @ref REF ""
 *
 * @par Project:
 * <!------------------------------------------------------------------------>
 * <!--
 * @par Description:
 *
 *  [Description]
 * -->
 * <!--
 *  @ref [extdocname] "more..."
 *  -->
 * <!------------------------------------------------------------------------>
 * <!--
 * @remarks
 * - [...]
 * - [...]
 * -->
 * <!------------------------------------------------------------------------
 * Copyright (c) 2011
 * IMST GmbH
 * Carl-Friedrich Gauss Str. 2
 * 47475 Kamp-Lintfort
 * -------------------------------------------------------------------------->
 * @author Frank Brey (FB), IMST
 * <!------------------------------------------------------------------------
 * Target OS:    none
 * Target CPU:   EFM32
 * Compiler:     IAR C/C++ Compiler
 * -------------------------------------------------------------------------->
 * @internal
 * @par Revision History:
 * <PRE>
 * ---------------------------------------------------------------------------
 * Version | Date       | Author | Comment
 * ---------------------------------------------------------------------------
 * 0.1     | 21.08.2012 | FB     | Created
 * </PRE>

 Copyright (c) 2011 IMST GmbH.
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are NOT permitted without prior written permission
 of the IMST GmbH.

 THIS SOFTWARE IS PROVIDED BY THE IMST GMBH AND CONTRIBUTORS ``AS IS'' AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 ARE DISCLAIMED. IN NO EVENT SHALL THE IMST GMBH OR CONTRIBUTORS BE
 LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 THIS SOFTWARE IS CLASSIFIED AS: CONFIDENTIAL

 *******************************************************************************/


#ifndef LDDUSART_H_
#define LDDUSART_H_

//------------------------------------------------------------------------------
// public needed include files
//------------------------------------------------------------------------------

#include "bsp.h"
#include "PDDUsart.h"


//------------------------------------------------------------------------------
// public available Data Types
//------------------------------------------------------------------------------


typedef struct LddUsartControlBlock 
{
    TPddUsartControlBlock*       PddUsartControlBlock;
    TUsartCbTxByteIndication     TxByteIndication;
    TUsartCbRxByteIndication     RxByteIndication;
    TUsartCbTxFinishedIndication TxFinishedIndication;

    USART_Buffer_t               RingBuffer;

} TLddUsartControlBlock;



//------------------------------------------------------------------------------
// public available Variables
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// public available Function Prototypes
//------------------------------------------------------------------------------

void 
LDDUsart_Init(void);

void 
LDDUsart_RegisterClient(TUsartCbRxByteIndication cbRxByteIndication);

void 
LDDUsart_SendByte(uint8_t txByte);





#endif /* LDDUSART_H_ */
