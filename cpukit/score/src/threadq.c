/**
 *  @file
 *
 *  @brief Thread Queue Initialize
 *  @ingroup ScoreThreadQ
 */

/*
 *  COPYRIGHT (c) 1989-2014.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.org/license/LICENSE.
 */

#if HAVE_CONFIG_H
#include "config.h"
#endif

#include <rtems/score/threadqimpl.h>
#include <rtems/score/rbtreeimpl.h>
#include <rtems/score/threadimpl.h>

#if HAVE_STRUCT__THREAD_QUEUE_QUEUE

RTEMS_STATIC_ASSERT(
#if defined(RTEMS_SMP)
  offsetof( Thread_queue_Syslock_queue, Queue.Lock.next_ticket )
#else
  offsetof( Thread_queue_Syslock_queue, reserved[ 0 ] )
#endif
    == offsetof( struct _Thread_queue_Queue, _Lock._next_ticket ),
  THREAD_QUEUE_SYSLOCK_QUEUE_NEXT_TICKET
);

RTEMS_STATIC_ASSERT(
#if defined(RTEMS_SMP)
  offsetof( Thread_queue_Syslock_queue, Queue.Lock.now_serving )
#else
  offsetof( Thread_queue_Syslock_queue, reserved[ 1 ] )
#endif
    == offsetof( struct _Thread_queue_Queue, _Lock._now_serving ),
  THREAD_QUEUE_SYSLOCK_QUEUE_NOW_SERVING
);

RTEMS_STATIC_ASSERT(
  offsetof( Thread_queue_Syslock_queue, Queue.heads )
    == offsetof( struct _Thread_queue_Queue, _heads ),
  THREAD_QUEUE_SYSLOCK_QUEUE_HEADS
);

RTEMS_STATIC_ASSERT(
  offsetof( Thread_queue_Syslock_queue, Queue.owner )
    == offsetof( struct _Thread_queue_Queue, _owner ),
  THREAD_QUEUE_SYSLOCK_QUEUE_OWNER
);

RTEMS_STATIC_ASSERT(
  sizeof( Thread_queue_Syslock_queue )
    == sizeof( struct _Thread_queue_Queue ),
  THREAD_QUEUE_SYSLOCK_QUEUE_SIZE
);

#endif /* HAVE_STRUCT__THREAD_QUEUE_QUEUE */

#if defined(RTEMS_SMP)
void _Thread_queue_Do_acquire_critical(
  Thread_queue_Control *the_thread_queue,
  ISR_lock_Context     *lock_context
)
{
  _Thread_queue_Queue_acquire_critical(
    &the_thread_queue->Queue,
    &the_thread_queue->Lock_stats,
    lock_context
  );
#if defined(RTEMS_DEBUG)
  the_thread_queue->owner = _SMP_Get_current_processor();
#endif
}

void _Thread_queue_Acquire(
  Thread_queue_Control *the_thread_queue,
  Thread_queue_Context *queue_context
)
{
  _ISR_lock_ISR_disable( &queue_context->Lock_context.Lock_context );
  _Thread_queue_Queue_acquire_critical(
    &the_thread_queue->Queue,
    &the_thread_queue->Lock_stats,
    &queue_context->Lock_context.Lock_context
  );
#if defined(RTEMS_DEBUG)
  the_thread_queue->owner = _SMP_Get_current_processor();
#endif
}

void _Thread_queue_Do_release_critical(
  Thread_queue_Control *the_thread_queue,
  ISR_lock_Context     *lock_context
)
{
#if defined(RTEMS_DEBUG)
  _Assert( _Thread_queue_Is_lock_owner( the_thread_queue ) );
  the_thread_queue->owner = SMP_LOCK_NO_OWNER;
#endif
  _Thread_queue_Queue_release_critical(
    &the_thread_queue->Queue,
    lock_context
  );
}

void _Thread_queue_Release(
  Thread_queue_Control *the_thread_queue,
  Thread_queue_Context *queue_context
)
{
#if defined(RTEMS_DEBUG)
  _Assert( _Thread_queue_Is_lock_owner( the_thread_queue ) );
  the_thread_queue->owner = SMP_LOCK_NO_OWNER;
#endif
  _Thread_queue_Queue_release_critical(
    &the_thread_queue->Queue,
    &queue_context->Lock_context.Lock_context
  );
  _ISR_lock_ISR_enable( &queue_context->Lock_context.Lock_context );
}
#endif

void _Thread_queue_Initialize( Thread_queue_Control *the_thread_queue )
{
  _Thread_queue_Queue_initialize( &the_thread_queue->Queue );
#if defined(RTEMS_SMP)
  _SMP_lock_Stats_initialize( &the_thread_queue->Lock_stats, "Thread Queue" );
#endif
}

#if defined(RTEMS_MULTIPROCESSING)
void _Thread_queue_MP_callout_do_nothing(
  Thread_Control *the_proxy,
  Objects_Id      mp_id
)
{
  /* Do nothing */
}
#endif
