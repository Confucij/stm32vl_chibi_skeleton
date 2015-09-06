/* 
 * File:   debug_f.h
 * Author: lordgal
 *
 * Created on September 5, 2015, 11:43 PM
 */

#ifndef DEBUG_F_H
#define	DEBUG_F_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>

#include "../app_config.h"
    
#define TRACE_MSG(LEVEL, PRINTF_FORMAT, ...) \
    printf(LEVEL"::%s:%d "PRINTF_FORMAT"\n",__FILE__,__LINE__,##__VA_ARGS__);
    
#define CRITICAL_MSG(PRINTF_FORMAT, ...) \
    TRACE_MSG("CRITICAL",PRINTF_FORMAT,##__VA_ARGS__);

#if DBG_LEVEL < 1
    #define WARNING_MSG(PRINTF_FORMAT, ...) 
#else
    #define WARNING_MSG(PRINTF_FORMAT, ...) \
    TRACE_MSG("WARNING", PRINTF_FORMAT, ##__VA_ARGS__);
#endif

#if DBG_LEVEL < 2
    #define INFO_MSG(PRINTF_ARGS, ...)
#else
    #define INFO_MSG(PRINTF_FORMAT, ...) \
    TRACE_MSG("INFO", PRINTF_FORMAT, ##__VA_ARGS__);
#endif

#if DBG_LEVEL < 3
    #define DEBUG_MSG(PRINTF_ARGS, ...)
#else
    #define DEBUG_MSG(PRINTF_FORMAT, ...) \
    TRACE_MSG("DEBUG", PRINTF_FORMAT, ##__VA_ARGS__);
#endif

//#undef TRACE_MSG



#ifdef	__cplusplus
}
#endif

#endif	/* DEBUG_F_H */

