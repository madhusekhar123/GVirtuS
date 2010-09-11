/*
 * gVirtuS -- A GPGPU transparent virtualization component.
 *
 * Copyright (C) 2009-2010  The University of Napoli Parthenope at Naples.
 *
 * This file is part of gVirtuS.
 *
 * gVirtuS is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * gVirtuS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with gVirtuS; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Written by: Giuseppe Coviello <giuseppe.coviello@uniparthenope.it>,
 *             Department of Applied Science
 */

/**
 * @file   AfUnixCommunicator.h
 * @author Giuseppe Coviello <giuseppe.coviello@uniparthenope.it>
 * @date   Wed Sep 30 12:01:12 2009
 * 
 * @brief  
 * 
 * 
 */

#ifndef _AFUNIXCOMMUNICATOR_H
#define	_AFUNIXCOMMUNICATOR_H

#include <ext/stdio_filebuf.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "Communicator.h"

/**
 * AfUnixCommunicator implements a Communicator for the AF_UNIX socket.
 */
class AfUnixCommunicator : public Communicator {
public:
    /** 
     * Creates a new AfUnixCommunicator for binding or connecting it to the
     * AF_UNIX socket specified from path.
     * 
     * @param path the path the AF_UNIX socket.
     * @param mode
     * @param use_shm	
     */
    AfUnixCommunicator(std::string &path, mode_t mode = 00660,
            bool use_shm = false);

    /** 
     * Creates a new AfUnixCommunicator for binding or connecting it to the
     * AF_UNIX socket specified from path.
     * 
     * @param path the path the AF_UNIX socket.
     * @param mode
     * @param use_shm	
     */
    AfUnixCommunicator(const char * path, mode_t mode = 00660,
            bool use_shm = false);
    /** 
     * Creates a new AfUnixCommunicator for binding or connecting it to the
     * AF_UNIX socket specified from path.
     * 
     * @param path the path the AF_UNIX socket.
     */
    AfUnixCommunicator(int fd);

    virtual ~AfUnixCommunicator();
    void Serve();
    const Communicator * const Accept() const;
    void Connect();
    std::istream & GetInputStream() const;
    std::ostream & GetOutputStream() const;
    void Close();

    bool HasSharedMemory() {
        return mHasSharedMemory;
    }

    void * GetSharedMemory() {
        return mpSharedMemory;
    }

    const char * GetSharedMemoryName() {
        return mpSharedMemoryName;
    }

    size_t GetSharedMemorySize() {
        return mSharedMemorySize;
    }

    void SetSharedMemory(const char *name, size_t size) {
        mpSharedMemoryName = strdup(name);
        mSharedMemorySize = size;
        if ((mSharedMemoryFd = shm_open(name, O_RDWR, S_IRWXU)) < 0) {
            std::cout << "Failed to shm_open" << std::endl;
            mpSharedMemory = NULL;
            mHasSharedMemory = false;
        }

        if ((mpSharedMemory = mmap(NULL, size, PROT_READ | PROT_WRITE,
                MAP_SHARED, mSharedMemoryFd, 0)) == MAP_FAILED) {
            std::cout << "Failed to mmap" << std::endl;
            mpSharedMemory = NULL;
            mHasSharedMemory = false;
        }
    }

private:
    /** 
     * Initializes the input and output streams.
     */
    void InitializeStream();
    std::istream *mpInput; /**< the input stream for sending */
    std::ostream *mpOutput;	/**< the output stream for receiving data */
    std::string mPath;		/**< the path of the AF_UNIX socket */
    int mSocketFd;		/**< the file descriptor of the connected socket */
    __gnu_cxx::stdio_filebuf<char> *mpInputBuf;
    __gnu_cxx::stdio_filebuf<char> *mpOutputBuf;
    mode_t mMode;
    bool mHasSharedMemory;
    int mSharedMemoryFd;
    size_t mSharedMemorySize;
    void *mpSharedMemory;
    char *mpSharedMemoryName;
};

#endif	/* _AFUNIXCOMMUNICATOR_H */

