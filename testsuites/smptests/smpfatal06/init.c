/*
 * Copyright (c) 2016 embedded brains GmbH.  All rights reserved.
 *
 *  embedded brains GmbH
 *  Dornierstr. 4
 *  82178 Puchheim
 *  Germany
 *  <rtems@embedded-brains.de>
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rtems.org/license/LICENSE.
 */

#ifdef HAVE_CONFIG_H
  #include "config.h"
#endif

#define TESTS_USE_PRINTK
#include "tmacros.h"

#include <rtems.h>

const char rtems_test_name[] = "SMPFATAL 6";

static void Init(rtems_task_argument arg)
{
  rtems_interrupt_level level;

  TEST_BEGIN();

  rtems_interrupt_local_disable(level);
  (void) level;
  rtems_task_wake_after(1);
}

static void fatal_extension(
  rtems_fatal_source source,
  bool is_internal,
  rtems_fatal_code code
)
{
  if (
    source == INTERNAL_ERROR_CORE
      && !is_internal
      && code == INTERNAL_ERROR_BAD_THREAD_DISPATCH_ENVIRONMENT
  ) {
    TEST_END();
  }
}

#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER

#define CONFIGURE_INITIAL_EXTENSIONS \
  { .fatal = fatal_extension }, \
  RTEMS_TEST_INITIAL_EXTENSION

#define CONFIGURE_SMP_APPLICATION

#define CONFIGURE_SMP_MAXIMUM_PROCESSORS 1

#define CONFIGURE_MAXIMUM_TASKS 1

#define CONFIGURE_RTEMS_INIT_TASKS_TABLE

#define CONFIGURE_INIT

#include <rtems/confdefs.h>
