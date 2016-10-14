/**
 * @file fsreg.h
 * @brief Program Registry Service
 */
#pragma once

#include <3ds/types.h>
#include <3ds/services/fs.h>
#include <3ds/exheader.h>

/// Initialize the fs:REG service. Bear in mind a limited number of handles exist for this.
Result fsregInit(void);

/// Close and deinitialize fs:REG
void   fsregExit(void);

/**
 * @brief Checks if a program handle is valid?
 * @param prog_handle Program handle to check validity of
 */
Result FSREG_CheckHostLoadId(u64 prog_handle);

/**
 * @brief Registers a loading program.
 * @param prog_handle Program handle
 * @param title Program information
 */
Result FSREG_LoadProgram(u64 *prog_handle, FS_ProgramInfo *title);

/**
 * @brief Retrieves the SystemControlInfo and AccessControlInfo for a program.
 * @param exheader Exheader struct to place output in
 * @param entry_count How many entries to get info for (?)
 * @param prog_handle Program handle to get info for
 */
Result FSREG_GetProgramInfo(EXHEADER_header *exheader, u32 entry_count, u64 prog_handle);

/**
 * @brief Unregisters a currently registered program.
 * @param prog_handle Handle of program to unregister.
 */
Result FSREG_UnloadProgram(u64 prog_handle);

/**
 * @brief Unregister a program previously registered.
 * @param pid Process ID to unregister.
 */
Result FSREG_Unregister(u32 pid);

/**
 * @brief Register a program.
 * @param pid Process ID to register.
 * @param prog_handle Handle of program to register
 * @param info Program info
 * @param storageinfo Storage access flags
 */
Result FSREG_Register(u32 pid, u64 prog_handle, FS_ProgramInfo *info, void *storageinfo);
