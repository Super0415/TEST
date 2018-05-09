;/* ********************************************************* */
;/* Name       ARM Cortex-M0 Port                             */
;/* File       ASMCortex.s                                    */
;/* Version    V1.0                                           */
;/* Mode       Thumb2                                         */
;/* ********************************************************* */

    RSEG CODE:CODE:NOROOT(2)
    THUMB
     
;/* ********************************************************* */
;/*             EXTERN and PUBLIC                             */
;/* ********************************************************* */
    EXTERN  ucOSRunning
    EXTERN  ucOSPrioCur
    EXTERN  ucOSPrioHighRdy
    EXTERN  ucOSIntNesting
    EXTERN  pOSTCBCur
    EXTERN  pOSTCBHighRdy
    PUBLIC  OS_CPU_SR_Save
    PUBLIC  OS_CPU_SR_Restore
    PUBLIC  OSCtxSw
    PUBLIC  OSIntCtxSw
    PUBLIC  OSStartHighRdy
    PUBLIC  PendSV_Handler

;/* ********************************************************* */
;/*             Definitions                                   */
;/* ********************************************************* */
NVIC_INT_CTRL     EQU   0xE000ED04
NVIC_SYSPRI14     EQU   0xE000ED22
NVIC_PENDSV_PRI   EQU         0xFF
NVIC_PENDSVSET    EQU   0x10000000

;/* ********************************************************* */
;/*             OS_CPU_SR_Save()                              */
;/* ********************************************************* */
OS_CPU_SR_Save
    MRS     R0, PRIMASK
    CPSID   I
    BX      LR

;/* ********************************************************* */
;/*             OS_CPU_SR_Restore()                           */
;/* ********************************************************* */
OS_CPU_SR_Restore
    MSR     PRIMASK, R0
    BX      LR

;/* ********************************************************* */
;/*            OSCtxSw()                                      */
;/* ********************************************************* */
OSCtxSw
    LDR     R0, =NVIC_INT_CTRL
    LDR     R1, =NVIC_PENDSVSET
    STR     R1, [R0]
    BX      LR

;/* ********************************************************* */
;/*            OSIntCtxSw()                                   */
;/* ********************************************************* */
OSIntCtxSw
    LDR     R0, =NVIC_INT_CTRL
    LDR     R1, =NVIC_PENDSVSET
    STR     R1, [R0]
    BX      LR

;/* ********************************************************* */
;/*             OSStartHighRdy()                              */
;/* ********************************************************* */
OSStartHighRdy
    LDR     R0, =NVIC_SYSPRI14
    LDR     R1, =NVIC_PENDSV_PRI
    STR     R1, [R0]
    MOVS    R0, #0
    MSR     PSP, R0
    LDR     R0, =ucOSRunning
    MOVS    R1, #1
    STRB    R1, [R0]
    LDR     R0, =NVIC_INT_CTRL
    LDR     R1, =NVIC_PENDSVSET
    STR     R1, [R0]
    CPSIE   I
OSStartHighRdy_Loop
    B       OSStartHighRdy_Loop

;/* ********************************************************* */
;/*            PendSV_Handler()                               */
;/* ********************************************************* */
PendSV_Handler
    CPSID   I                       ;/* 1: Dis Interrupt      */
    MRS     R0, PSP                 ;/* 2: PSP == 0 ?         */
    CBZ     R0, PendSVHandler_nosave
    SUBS    R0, R0, #0x20           ;/* 3: {R4-R11} >> PSP    */
    STM     R0, {R4-R11}
#ifdef __ARMVFP__
    VSTMDB  R0!, {S16-S31}          ;/* 3: {S16-S31} >> PSP   */
#endif
    LDR     R1, =pOSTCBCur          ;/* 4: PSP>>pOSTCBCur->P0 */
    LDR     R1, [R1]
    STR     R0, [R1]
PendSVHandler_nosave
    LDR     R0, =ucOSPrioCur        ;/* 6: Read ucOSPrioCur   */
    LDR     R1, =ucOSPrioHighRdy    ;/* 7: PrioCur = HighRdy  */
    LDRB    R2, [R1]
    STRB    R2, [R0]
    LDR     R0, =pOSTCBCur          ;/* 8: Read pOSTCBCur     */
    LDR     R1, =pOSTCBHighRdy      ;/* 9: pOSTCBCur=pHighRdy */
    LDR     R2, [R1]
    STR     R2, [R0]
    LDR     R0, [R2]                ;/* 10: PSP=pOSTCBCur->P0 */
#ifdef __ARMVFP__
    VLDMIA  R0!, {S16-S31}          ;/* 11: {S16-S31} << PSP  */
#endif
    LDM     R0, {R4-R11}            ;/* 11: {R4-R11} << PSP   */
    ADDS    R0, R0, #0x20
    MSR     PSP, R0
#ifdef __ARMVFP__
    ORR     LR, LR, #0x04           ;/* 12: Use process stack */
#else
    ORR     LR, LR, #0xF4           ;/* 12: Use process stack */
#endif
    CPSIE   I                       ;/* 13: En Interrupt      */
    BX      LR

;/* ********************************************************* */
    END
;/* ********************************************************* */
;/*            The End                                        */
;/* ********************************************************* */
