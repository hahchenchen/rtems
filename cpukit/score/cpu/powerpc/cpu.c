/**
 *  @file
 *
 *  @brief PowerPC Dependent Source
 */

/*
 * Copyright (C) 2009, 2016 embedded brains GmbH.
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rtems.org/license/LICENSE.
 */

/*
 * For now, this file is just a stub to work around
 * structural deficiencies of the powerpc port.
 */

#ifdef HAVE_CONFIG_H
  #include "config.h"
#endif

#include <rtems/score/cpuimpl.h>

#define PPC_ASSERT_OFFSET(field, off) \
  RTEMS_STATIC_ASSERT( \
    offsetof(ppc_context, field) + PPC_DEFAULT_CACHE_LINE_SIZE \
      == PPC_CONTEXT_OFFSET_ ## off, \
    ppc_context_offset_ ## field \
  )

PPC_ASSERT_OFFSET(gpr1, GPR1);
PPC_ASSERT_OFFSET(msr, MSR);
PPC_ASSERT_OFFSET(lr, LR);
PPC_ASSERT_OFFSET(cr, CR);
PPC_ASSERT_OFFSET(gpr14, GPR14);
PPC_ASSERT_OFFSET(gpr15, GPR15);
PPC_ASSERT_OFFSET(gpr16, GPR16);
PPC_ASSERT_OFFSET(gpr17, GPR17);
PPC_ASSERT_OFFSET(gpr18, GPR18);
PPC_ASSERT_OFFSET(gpr19, GPR19);
PPC_ASSERT_OFFSET(gpr20, GPR20);
PPC_ASSERT_OFFSET(gpr21, GPR21);
PPC_ASSERT_OFFSET(gpr22, GPR22);
PPC_ASSERT_OFFSET(gpr23, GPR23);
PPC_ASSERT_OFFSET(gpr24, GPR24);
PPC_ASSERT_OFFSET(gpr25, GPR25);
PPC_ASSERT_OFFSET(gpr26, GPR26);
PPC_ASSERT_OFFSET(gpr27, GPR27);
PPC_ASSERT_OFFSET(gpr28, GPR28);
PPC_ASSERT_OFFSET(gpr29, GPR29);
PPC_ASSERT_OFFSET(gpr30, GPR30);
PPC_ASSERT_OFFSET(gpr31, GPR31);
PPC_ASSERT_OFFSET(gpr2, GPR2);
PPC_ASSERT_OFFSET(isr_dispatch_disable, ISR_DISPATCH_DISABLE);

#ifdef RTEMS_SMP
  PPC_ASSERT_OFFSET(is_executing, IS_EXECUTING);
#endif

#ifdef PPC_MULTILIB_ALTIVEC
  RTEMS_STATIC_ASSERT(
    PPC_CONTEXT_OFFSET_V20 % 16 == 0,
    ppc_context_altivec
  );
  PPC_ASSERT_OFFSET(v20, V20);
  PPC_ASSERT_OFFSET(v21, V21);
  PPC_ASSERT_OFFSET(v22, V22);
  PPC_ASSERT_OFFSET(v23, V23);
  PPC_ASSERT_OFFSET(v24, V24);
  PPC_ASSERT_OFFSET(v25, V25);
  PPC_ASSERT_OFFSET(v26, V26);
  PPC_ASSERT_OFFSET(v27, V27);
  PPC_ASSERT_OFFSET(v28, V28);
  PPC_ASSERT_OFFSET(v29, V29);
  PPC_ASSERT_OFFSET(v30, V30);
  PPC_ASSERT_OFFSET(v31, V31);
  PPC_ASSERT_OFFSET(vrsave, VRSAVE);
#endif

#ifdef PPC_MULTILIB_FPU
  PPC_ASSERT_OFFSET(f14, F14);
  PPC_ASSERT_OFFSET(f15, F15);
  PPC_ASSERT_OFFSET(f16, F16);
  PPC_ASSERT_OFFSET(f17, F17);
  PPC_ASSERT_OFFSET(f18, F18);
  PPC_ASSERT_OFFSET(f19, F19);
  PPC_ASSERT_OFFSET(f20, F20);
  PPC_ASSERT_OFFSET(f21, F21);
  PPC_ASSERT_OFFSET(f22, F22);
  PPC_ASSERT_OFFSET(f23, F23);
  PPC_ASSERT_OFFSET(f24, F24);
  PPC_ASSERT_OFFSET(f25, F25);
  PPC_ASSERT_OFFSET(f26, F26);
  PPC_ASSERT_OFFSET(f27, F27);
  PPC_ASSERT_OFFSET(f28, F28);
  PPC_ASSERT_OFFSET(f29, F29);
  PPC_ASSERT_OFFSET(f30, F30);
  PPC_ASSERT_OFFSET(f31, F31);
#endif

RTEMS_STATIC_ASSERT(
  sizeof(Context_Control) % PPC_DEFAULT_CACHE_LINE_SIZE == 0,
  ppc_context_size
);

#define PPC_EXC_ASSERT_OFFSET(field, off) \
  RTEMS_STATIC_ASSERT( \
    offsetof(CPU_Exception_frame, field) + FRAME_LINK_SPACE == off, \
    CPU_Exception_frame_offset_ ## field \
  )

#define PPC_EXC_ASSERT_CANONIC_OFFSET(field) \
  PPC_EXC_ASSERT_OFFSET(field, field ## _OFFSET)

#define PPC_EXC_MIN_ASSERT_OFFSET(field, off) \
  RTEMS_STATIC_ASSERT( \
    offsetof(CPU_Interrupt_frame, field) == off, \
    CPU_Interrupt_frame_offset_ ## field \
  )

#define PPC_EXC_MIN_ASSERT_CANONIC_OFFSET(field) \
  PPC_EXC_MIN_ASSERT_OFFSET(field, field ## _OFFSET)

PPC_EXC_ASSERT_OFFSET(EXC_SRR0, SRR0_FRAME_OFFSET);
PPC_EXC_ASSERT_OFFSET(EXC_SRR1, SRR1_FRAME_OFFSET);
PPC_EXC_ASSERT_OFFSET(_EXC_number, EXCEPTION_NUMBER_OFFSET);
PPC_EXC_ASSERT_CANONIC_OFFSET(EXC_CR);
PPC_EXC_ASSERT_CANONIC_OFFSET(EXC_CTR);
PPC_EXC_ASSERT_CANONIC_OFFSET(EXC_XER);
PPC_EXC_ASSERT_CANONIC_OFFSET(EXC_LR);
#ifdef __SPE__
  PPC_EXC_ASSERT_OFFSET(EXC_SPEFSCR, PPC_EXC_SPEFSCR_OFFSET);
  PPC_EXC_ASSERT_OFFSET(EXC_ACC, PPC_EXC_ACC_OFFSET);
#endif
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR0);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR1);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR2);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR3);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR4);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR5);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR6);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR7);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR8);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR9);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR10);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR11);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR12);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR13);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR14);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR15);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR16);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR17);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR18);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR19);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR20);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR21);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR22);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR23);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR24);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR25);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR26);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR27);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR28);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR29);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR30);
PPC_EXC_ASSERT_CANONIC_OFFSET(GPR31);

PPC_EXC_MIN_ASSERT_OFFSET(EXC_SRR0, SRR0_FRAME_OFFSET);
PPC_EXC_MIN_ASSERT_OFFSET(EXC_SRR1, SRR1_FRAME_OFFSET);
PPC_EXC_MIN_ASSERT_CANONIC_OFFSET(EXC_CR);
PPC_EXC_MIN_ASSERT_CANONIC_OFFSET(EXC_CTR);
PPC_EXC_MIN_ASSERT_CANONIC_OFFSET(EXC_XER);
PPC_EXC_MIN_ASSERT_CANONIC_OFFSET(EXC_LR);
#ifdef __SPE__
  PPC_EXC_MIN_ASSERT_OFFSET(EXC_SPEFSCR, PPC_EXC_SPEFSCR_OFFSET);
  PPC_EXC_MIN_ASSERT_OFFSET(EXC_ACC, PPC_EXC_ACC_OFFSET);
#endif
PPC_EXC_MIN_ASSERT_CANONIC_OFFSET(GPR0);
PPC_EXC_MIN_ASSERT_CANONIC_OFFSET(GPR1);
PPC_EXC_MIN_ASSERT_CANONIC_OFFSET(GPR2);
PPC_EXC_MIN_ASSERT_CANONIC_OFFSET(GPR3);
PPC_EXC_MIN_ASSERT_CANONIC_OFFSET(GPR4);
PPC_EXC_MIN_ASSERT_CANONIC_OFFSET(GPR5);
PPC_EXC_MIN_ASSERT_CANONIC_OFFSET(GPR6);
PPC_EXC_MIN_ASSERT_CANONIC_OFFSET(GPR7);
PPC_EXC_MIN_ASSERT_CANONIC_OFFSET(GPR8);
PPC_EXC_MIN_ASSERT_CANONIC_OFFSET(GPR9);
PPC_EXC_MIN_ASSERT_CANONIC_OFFSET(GPR10);
PPC_EXC_MIN_ASSERT_CANONIC_OFFSET(GPR11);
PPC_EXC_MIN_ASSERT_CANONIC_OFFSET(GPR12);

#ifdef PPC_MULTILIB_ALTIVEC
PPC_EXC_ASSERT_OFFSET(VSCR, PPC_EXC_VSCR_OFFSET);
PPC_EXC_ASSERT_OFFSET(VRSAVE, PPC_EXC_VRSAVE_OFFSET);
RTEMS_STATIC_ASSERT(PPC_EXC_VR_OFFSET(0) % 16 == 0, PPC_EXC_VR_OFFSET);
PPC_EXC_ASSERT_OFFSET(V0, PPC_EXC_VR_OFFSET(0));
PPC_EXC_ASSERT_OFFSET(V1, PPC_EXC_VR_OFFSET(1));
PPC_EXC_ASSERT_OFFSET(V2, PPC_EXC_VR_OFFSET(2));
PPC_EXC_ASSERT_OFFSET(V3, PPC_EXC_VR_OFFSET(3));
PPC_EXC_ASSERT_OFFSET(V4, PPC_EXC_VR_OFFSET(4));
PPC_EXC_ASSERT_OFFSET(V5, PPC_EXC_VR_OFFSET(5));
PPC_EXC_ASSERT_OFFSET(V6, PPC_EXC_VR_OFFSET(6));
PPC_EXC_ASSERT_OFFSET(V7, PPC_EXC_VR_OFFSET(7));
PPC_EXC_ASSERT_OFFSET(V8, PPC_EXC_VR_OFFSET(8));
PPC_EXC_ASSERT_OFFSET(V9, PPC_EXC_VR_OFFSET(9));
PPC_EXC_ASSERT_OFFSET(V10, PPC_EXC_VR_OFFSET(10));
PPC_EXC_ASSERT_OFFSET(V11, PPC_EXC_VR_OFFSET(11));
PPC_EXC_ASSERT_OFFSET(V12, PPC_EXC_VR_OFFSET(12));
PPC_EXC_ASSERT_OFFSET(V13, PPC_EXC_VR_OFFSET(13));
PPC_EXC_ASSERT_OFFSET(V14, PPC_EXC_VR_OFFSET(14));
PPC_EXC_ASSERT_OFFSET(V15, PPC_EXC_VR_OFFSET(15));
PPC_EXC_ASSERT_OFFSET(V16, PPC_EXC_VR_OFFSET(16));
PPC_EXC_ASSERT_OFFSET(V17, PPC_EXC_VR_OFFSET(17));
PPC_EXC_ASSERT_OFFSET(V18, PPC_EXC_VR_OFFSET(18));
PPC_EXC_ASSERT_OFFSET(V19, PPC_EXC_VR_OFFSET(19));
PPC_EXC_ASSERT_OFFSET(V20, PPC_EXC_VR_OFFSET(20));
PPC_EXC_ASSERT_OFFSET(V21, PPC_EXC_VR_OFFSET(21));
PPC_EXC_ASSERT_OFFSET(V22, PPC_EXC_VR_OFFSET(22));
PPC_EXC_ASSERT_OFFSET(V23, PPC_EXC_VR_OFFSET(23));
PPC_EXC_ASSERT_OFFSET(V24, PPC_EXC_VR_OFFSET(24));
PPC_EXC_ASSERT_OFFSET(V25, PPC_EXC_VR_OFFSET(25));
PPC_EXC_ASSERT_OFFSET(V26, PPC_EXC_VR_OFFSET(26));
PPC_EXC_ASSERT_OFFSET(V27, PPC_EXC_VR_OFFSET(27));
PPC_EXC_ASSERT_OFFSET(V28, PPC_EXC_VR_OFFSET(28));
PPC_EXC_ASSERT_OFFSET(V29, PPC_EXC_VR_OFFSET(29));
PPC_EXC_ASSERT_OFFSET(V30, PPC_EXC_VR_OFFSET(30));
PPC_EXC_ASSERT_OFFSET(V31, PPC_EXC_VR_OFFSET(31));

PPC_EXC_MIN_ASSERT_OFFSET(VSCR, PPC_EXC_MIN_VSCR_OFFSET);
RTEMS_STATIC_ASSERT(PPC_EXC_MIN_VR_OFFSET(0) % 16 == 0, PPC_EXC_MIN_VR_OFFSET);
PPC_EXC_MIN_ASSERT_OFFSET(V0, PPC_EXC_MIN_VR_OFFSET(0));
PPC_EXC_MIN_ASSERT_OFFSET(V1, PPC_EXC_MIN_VR_OFFSET(1));
PPC_EXC_MIN_ASSERT_OFFSET(V2, PPC_EXC_MIN_VR_OFFSET(2));
PPC_EXC_MIN_ASSERT_OFFSET(V3, PPC_EXC_MIN_VR_OFFSET(3));
PPC_EXC_MIN_ASSERT_OFFSET(V4, PPC_EXC_MIN_VR_OFFSET(4));
PPC_EXC_MIN_ASSERT_OFFSET(V5, PPC_EXC_MIN_VR_OFFSET(5));
PPC_EXC_MIN_ASSERT_OFFSET(V6, PPC_EXC_MIN_VR_OFFSET(6));
PPC_EXC_MIN_ASSERT_OFFSET(V7, PPC_EXC_MIN_VR_OFFSET(7));
PPC_EXC_MIN_ASSERT_OFFSET(V8, PPC_EXC_MIN_VR_OFFSET(8));
PPC_EXC_MIN_ASSERT_OFFSET(V9, PPC_EXC_MIN_VR_OFFSET(9));
PPC_EXC_MIN_ASSERT_OFFSET(V10, PPC_EXC_MIN_VR_OFFSET(10));
PPC_EXC_MIN_ASSERT_OFFSET(V11, PPC_EXC_MIN_VR_OFFSET(11));
PPC_EXC_MIN_ASSERT_OFFSET(V12, PPC_EXC_MIN_VR_OFFSET(12));
PPC_EXC_MIN_ASSERT_OFFSET(V13, PPC_EXC_MIN_VR_OFFSET(13));
PPC_EXC_MIN_ASSERT_OFFSET(V14, PPC_EXC_MIN_VR_OFFSET(14));
PPC_EXC_MIN_ASSERT_OFFSET(V15, PPC_EXC_MIN_VR_OFFSET(15));
PPC_EXC_MIN_ASSERT_OFFSET(V16, PPC_EXC_MIN_VR_OFFSET(16));
PPC_EXC_MIN_ASSERT_OFFSET(V17, PPC_EXC_MIN_VR_OFFSET(17));
PPC_EXC_MIN_ASSERT_OFFSET(V18, PPC_EXC_MIN_VR_OFFSET(18));
PPC_EXC_MIN_ASSERT_OFFSET(V19, PPC_EXC_MIN_VR_OFFSET(19));
#endif

#ifdef PPC_MULTILIB_FPU
RTEMS_STATIC_ASSERT(PPC_EXC_FR_OFFSET(0) % 8 == 0, PPC_EXC_FR_OFFSET);
PPC_EXC_ASSERT_OFFSET(F0, PPC_EXC_FR_OFFSET(0));
PPC_EXC_ASSERT_OFFSET(F1, PPC_EXC_FR_OFFSET(1));
PPC_EXC_ASSERT_OFFSET(F2, PPC_EXC_FR_OFFSET(2));
PPC_EXC_ASSERT_OFFSET(F3, PPC_EXC_FR_OFFSET(3));
PPC_EXC_ASSERT_OFFSET(F4, PPC_EXC_FR_OFFSET(4));
PPC_EXC_ASSERT_OFFSET(F5, PPC_EXC_FR_OFFSET(5));
PPC_EXC_ASSERT_OFFSET(F6, PPC_EXC_FR_OFFSET(6));
PPC_EXC_ASSERT_OFFSET(F7, PPC_EXC_FR_OFFSET(7));
PPC_EXC_ASSERT_OFFSET(F8, PPC_EXC_FR_OFFSET(8));
PPC_EXC_ASSERT_OFFSET(F9, PPC_EXC_FR_OFFSET(9));
PPC_EXC_ASSERT_OFFSET(F10, PPC_EXC_FR_OFFSET(10));
PPC_EXC_ASSERT_OFFSET(F11, PPC_EXC_FR_OFFSET(11));
PPC_EXC_ASSERT_OFFSET(F12, PPC_EXC_FR_OFFSET(12));
PPC_EXC_ASSERT_OFFSET(F13, PPC_EXC_FR_OFFSET(13));
PPC_EXC_ASSERT_OFFSET(F14, PPC_EXC_FR_OFFSET(14));
PPC_EXC_ASSERT_OFFSET(F15, PPC_EXC_FR_OFFSET(15));
PPC_EXC_ASSERT_OFFSET(F16, PPC_EXC_FR_OFFSET(16));
PPC_EXC_ASSERT_OFFSET(F17, PPC_EXC_FR_OFFSET(17));
PPC_EXC_ASSERT_OFFSET(F18, PPC_EXC_FR_OFFSET(18));
PPC_EXC_ASSERT_OFFSET(F19, PPC_EXC_FR_OFFSET(19));
PPC_EXC_ASSERT_OFFSET(F20, PPC_EXC_FR_OFFSET(20));
PPC_EXC_ASSERT_OFFSET(F21, PPC_EXC_FR_OFFSET(21));
PPC_EXC_ASSERT_OFFSET(F22, PPC_EXC_FR_OFFSET(22));
PPC_EXC_ASSERT_OFFSET(F23, PPC_EXC_FR_OFFSET(23));
PPC_EXC_ASSERT_OFFSET(F24, PPC_EXC_FR_OFFSET(24));
PPC_EXC_ASSERT_OFFSET(F25, PPC_EXC_FR_OFFSET(25));
PPC_EXC_ASSERT_OFFSET(F26, PPC_EXC_FR_OFFSET(26));
PPC_EXC_ASSERT_OFFSET(F27, PPC_EXC_FR_OFFSET(27));
PPC_EXC_ASSERT_OFFSET(F28, PPC_EXC_FR_OFFSET(28));
PPC_EXC_ASSERT_OFFSET(F29, PPC_EXC_FR_OFFSET(29));
PPC_EXC_ASSERT_OFFSET(F30, PPC_EXC_FR_OFFSET(30));
PPC_EXC_ASSERT_OFFSET(F31, PPC_EXC_FR_OFFSET(31));
PPC_EXC_ASSERT_OFFSET(FPSCR, PPC_EXC_FPSCR_OFFSET);

RTEMS_STATIC_ASSERT(PPC_EXC_MIN_FR_OFFSET(0) % 8 == 0, PPC_EXC_MIN_FR_OFFSET);
PPC_EXC_MIN_ASSERT_OFFSET(F0, PPC_EXC_MIN_FR_OFFSET(0));
PPC_EXC_MIN_ASSERT_OFFSET(F1, PPC_EXC_MIN_FR_OFFSET(1));
PPC_EXC_MIN_ASSERT_OFFSET(F2, PPC_EXC_MIN_FR_OFFSET(2));
PPC_EXC_MIN_ASSERT_OFFSET(F3, PPC_EXC_MIN_FR_OFFSET(3));
PPC_EXC_MIN_ASSERT_OFFSET(F4, PPC_EXC_MIN_FR_OFFSET(4));
PPC_EXC_MIN_ASSERT_OFFSET(F5, PPC_EXC_MIN_FR_OFFSET(5));
PPC_EXC_MIN_ASSERT_OFFSET(F6, PPC_EXC_MIN_FR_OFFSET(6));
PPC_EXC_MIN_ASSERT_OFFSET(F7, PPC_EXC_MIN_FR_OFFSET(7));
PPC_EXC_MIN_ASSERT_OFFSET(F8, PPC_EXC_MIN_FR_OFFSET(8));
PPC_EXC_MIN_ASSERT_OFFSET(F9, PPC_EXC_MIN_FR_OFFSET(9));
PPC_EXC_MIN_ASSERT_OFFSET(F10, PPC_EXC_MIN_FR_OFFSET(10));
PPC_EXC_MIN_ASSERT_OFFSET(F11, PPC_EXC_MIN_FR_OFFSET(11));
PPC_EXC_MIN_ASSERT_OFFSET(F12, PPC_EXC_MIN_FR_OFFSET(12));
PPC_EXC_MIN_ASSERT_OFFSET(F13, PPC_EXC_MIN_FR_OFFSET(13));
PPC_EXC_MIN_ASSERT_OFFSET(FPSCR, PPC_EXC_MIN_FPSCR_OFFSET);
#endif

RTEMS_STATIC_ASSERT(
  CPU_INTERRUPT_FRAME_SIZE % CPU_STACK_ALIGNMENT == 0,
  CPU_INTERRUPT_FRAME_SIZE
);

RTEMS_STATIC_ASSERT(
  PPC_EXC_FRAME_SIZE % CPU_STACK_ALIGNMENT == 0,
  PPC_EXC_FRAME_SIZE
);

RTEMS_STATIC_ASSERT(
  sizeof(CPU_Exception_frame) + FRAME_LINK_SPACE <= PPC_EXC_FRAME_SIZE,
  CPU_Exception_frame
);