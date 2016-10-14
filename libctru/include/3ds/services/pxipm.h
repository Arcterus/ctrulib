#pragma once

#include <3ds/types.h>
#include <3ds/exheader.h>


/// Initialize PxiPM. Note that you must be able to access this, and few modules can.
Result pxipmInit(void);

/// Deinitialize PxiPM.
void   pxipmExit(void);

/**
 * @brief Register a program (or reregister) a program with PxiPM.
 * @param prog_handle The program's handle
 * @param title The program's current info
 * @param update Information to update if re-registering
 */
Result PXIPM_RegisterProgram(u64 *prog_handle, FS_ProgramInfo *title, FS_ProgramInfo *update);

/**
 * @brief Get a program's information from PxiPM
 * @param exheader Exheader to place infomation retrieved in
 * @param prog_handle Handle to retrieve for
 */
Result PXIPM_GetProgramInfo(EXHEADER_header *exheader, u64 prog_handle);

/**
 * @brief Unregister a program from PxiPM.
 * @param prog_handle Program handle to unregister for.
 */
Result PXIPM_UnregisterProgram(u64 prog_handle);
