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
 * Written by: Vincenzo Santopietro <vincenzo.santopietro@uniparthenope.it>,
 *             Department of Science and Technologies
 */

#include <iostream>
#include <cstdio>
#include <string>
#include "CublasFrontend.h"

using namespace std;

extern "C" CUBLASAPI cublasStatus_t CUBLASWINAPI cublasSgemm_v2 (cublasHandle_t handle, 
                                                      cublasOperation_t transa,
                                                      cublasOperation_t transb, 
                                                      int m,
                                                      int n,
                                                      int k,
                                                      const float *alpha, /* host or device pointer */  
                                                      const float *A, 
                                                      int lda,
                                                      const float *B,
                                                      int ldb, 
                                                      const float *beta, /* host or device pointer */  
                                                      float *C,
                                                      int ldc){
    CublasFrontend::Prepare();
    CublasFrontend::AddVariableForArguments<long long int>((long long int)handle);
    CublasFrontend::AddVariableForArguments<cublasOperation_t>(transa);
    CublasFrontend::AddVariableForArguments<cublasOperation_t>(transb);
    CublasFrontend::AddVariableForArguments<int>(m);
    CublasFrontend::AddVariableForArguments<int>(n);
    CublasFrontend::AddVariableForArguments<int>(k);
    float * _alpha = const_cast<float *>(alpha);
    CublasFrontend::AddHostPointerForArguments(_alpha);
    
    CublasFrontend::AddDevicePointerForArguments(A);
    CublasFrontend::AddVariableForArguments<int>(lda);
    CublasFrontend::AddDevicePointerForArguments(B);
    CublasFrontend::AddVariableForArguments<int>(ldb);
    float * _beta = const_cast<float *>(beta);
    CublasFrontend::AddHostPointerForArguments(_beta);
    
    CublasFrontend::AddDevicePointerForArguments(C);
    CublasFrontend::AddVariableForArguments<int>(ldc);
    
    CublasFrontend::Execute("cublasSgemm_v2");
    if (CublasFrontend::Success())
        C = (float *)CublasFrontend::GetOutputDevicePointer();
    return CublasFrontend::GetExitCode();
}

extern "C" CUBLASAPI cublasStatus_t CUBLASWINAPI cublasDgemm_v2 (cublasHandle_t handle, 
                                                      cublasOperation_t transa,
                                                      cublasOperation_t transb, 
                                                      int m,
                                                      int n,
                                                      int k,
                                                      const double *alpha, /* host or device pointer */  
                                                      const double *A, 
                                                      int lda,
                                                      const double *B,
                                                      int ldb, 
                                                      const double *beta, /* host or device pointer */  
                                                      double *C,
                                                      int ldc){
    CublasFrontend::Prepare();
    CublasFrontend::AddVariableForArguments<long long int>((long long int)handle);
    CublasFrontend::AddVariableForArguments<cublasOperation_t>(transa);
    CublasFrontend::AddVariableForArguments<cublasOperation_t>(transb);
    CublasFrontend::AddVariableForArguments<int>(m);
    CublasFrontend::AddVariableForArguments<int>(n);
    CublasFrontend::AddVariableForArguments<int>(k);
    double * _alpha = const_cast<double *>(alpha);
    CublasFrontend::AddHostPointerForArguments(_alpha);
    
    CublasFrontend::AddDevicePointerForArguments(A);
    CublasFrontend::AddVariableForArguments<int>(lda);
    CublasFrontend::AddDevicePointerForArguments(B);
    CublasFrontend::AddVariableForArguments<int>(ldb);
    double * _beta = const_cast<double *>(beta);
    CublasFrontend::AddHostPointerForArguments(_beta);
    
    CublasFrontend::AddDevicePointerForArguments(C);
    CublasFrontend::AddVariableForArguments<int>(ldc);
    
    CublasFrontend::Execute("cublasDgemm_v2");
    if (CublasFrontend::Success())
        C = (double *)CublasFrontend::GetOutputDevicePointer();
    return CublasFrontend::GetExitCode();
}

extern "C" CUBLASAPI cublasStatus_t CUBLASWINAPI cublasCgemm_v2 (cublasHandle_t handle, 
                                                      cublasOperation_t transa,
                                                      cublasOperation_t transb, 
                                                      int m,
                                                      int n,
                                                      int k,
                                                      const cuComplex *alpha, /* host or device pointer */  
                                                      const cuComplex *A, 
                                                      int lda,
                                                      const cuComplex *B,
                                                      int ldb, 
                                                      const cuComplex *beta, /* host or device pointer */  
                                                      cuComplex *C,
                                                      int ldc){
    CublasFrontend::Prepare();
    CublasFrontend::AddVariableForArguments<long long int>((long long int)handle);
    CublasFrontend::AddVariableForArguments<cublasOperation_t>(transa);
    CublasFrontend::AddVariableForArguments<cublasOperation_t>(transb);
    CublasFrontend::AddVariableForArguments<int>(m);
    CublasFrontend::AddVariableForArguments<int>(n);
    CublasFrontend::AddVariableForArguments<int>(k);
    cuComplex * _alpha = const_cast<cuComplex *>(alpha);
    CublasFrontend::AddHostPointerForArguments(_alpha);
    
    CublasFrontend::AddDevicePointerForArguments(A);
    CublasFrontend::AddVariableForArguments<int>(lda);
    CublasFrontend::AddDevicePointerForArguments(B);
    CublasFrontend::AddVariableForArguments<int>(ldb);
    cuComplex * _beta = const_cast<cuComplex *>(beta);
    CublasFrontend::AddHostPointerForArguments(_beta);
    
    CublasFrontend::AddDevicePointerForArguments(C);
    CublasFrontend::AddVariableForArguments<int>(ldc);
    
    CublasFrontend::Execute("cublasCgemm_v2");
    if (CublasFrontend::Success())
        C = (cuComplex *)CublasFrontend::GetOutputDevicePointer();
    return CublasFrontend::GetExitCode();
}

extern "C" CUBLASAPI cublasStatus_t CUBLASWINAPI cublasZgemm_v2 (cublasHandle_t handle, 
                                                      cublasOperation_t transa,
                                                      cublasOperation_t transb, 
                                                      int m,
                                                      int n,
                                                      int k,
                                                      const cuDoubleComplex *alpha, /* host or device pointer */  
                                                      const cuDoubleComplex *A, 
                                                      int lda,
                                                      const cuDoubleComplex *B,
                                                      int ldb, 
                                                      const cuDoubleComplex *beta, /* host or device pointer */  
                                                      cuDoubleComplex *C,
                                                      int ldc){
    CublasFrontend::Prepare();
    CublasFrontend::AddVariableForArguments<long long int>((long long int)handle);
    CublasFrontend::AddVariableForArguments<cublasOperation_t>(transa);
    CublasFrontend::AddVariableForArguments<cublasOperation_t>(transb);
    CublasFrontend::AddVariableForArguments<int>(m);
    CublasFrontend::AddVariableForArguments<int>(n);
    CublasFrontend::AddVariableForArguments<int>(k);
    cuDoubleComplex * _alpha = const_cast<cuDoubleComplex *>(alpha);
    CublasFrontend::AddHostPointerForArguments(_alpha);
    
    CublasFrontend::AddDevicePointerForArguments(A);
    CublasFrontend::AddVariableForArguments<int>(lda);
    CublasFrontend::AddDevicePointerForArguments(B);
    CublasFrontend::AddVariableForArguments<int>(ldb);
    cuDoubleComplex * _beta = const_cast<cuDoubleComplex *>(beta);
    CublasFrontend::AddHostPointerForArguments(_beta);
    
    CublasFrontend::AddDevicePointerForArguments(C);
    CublasFrontend::AddVariableForArguments<int>(ldc);
    
    CublasFrontend::Execute("cublasZgemm_v2");
    if (CublasFrontend::Success())
        C = (cuDoubleComplex *)CublasFrontend::GetOutputDevicePointer();
    return CublasFrontend::GetExitCode();
}

extern "C" CUBLASAPI cublasStatus_t CUBLASWINAPI cublasSnrm2_v2 (cublasHandle_t handle,int n, const float *x, int incx, float *result){
    CublasFrontend::Prepare();
    
    CublasFrontend::AddVariableForArguments<long long int>((long long int)handle);
    CublasFrontend::AddVariableForArguments<int>(n);
    CublasFrontend::AddDevicePointerForArguments(x);
    CublasFrontend::AddVariableForArguments<int>(incx);
    
    CublasFrontend::Execute("cublasSnrm2_v2");
    if(CublasFrontend::Success())
        *result = CublasFrontend::GetOutputVariable<float>();
    return CublasFrontend::GetExitCode();
}

extern "C" CUBLASAPI cublasStatus_t CUBLASWINAPI cublasDnrm2_v2 (cublasHandle_t handle,int n, const double *x, int incx, double *result){
    CublasFrontend::Prepare();
    
    CublasFrontend::AddVariableForArguments<long long int>((long long int)handle);
    CublasFrontend::AddVariableForArguments<int>(n);
    CublasFrontend::AddDevicePointerForArguments(x);
    CublasFrontend::AddVariableForArguments<int>(incx);
    
    CublasFrontend::Execute("cublasDnrm2_v2");
    if(CublasFrontend::Success())
        *result = CublasFrontend::GetOutputVariable<double>();
    return CublasFrontend::GetExitCode();
}

extern "C" CUBLASAPI cublasStatus_t CUBLASWINAPI cublasScnrm2_v2 (cublasHandle_t handle,int n, const cuComplex *x, int incx, float *result){
    CublasFrontend::Prepare();
    
    CublasFrontend::AddVariableForArguments<long long int>((long long int)handle);
    CublasFrontend::AddVariableForArguments<int>(n);
    CublasFrontend::AddDevicePointerForArguments(x);
    CublasFrontend::AddVariableForArguments<int>(incx);
    
    CublasFrontend::Execute("cublasScnrm2_v2");
    if(CublasFrontend::Success())
        *result = CublasFrontend::GetOutputVariable<float>();
    return CublasFrontend::GetExitCode();
}

extern "C" CUBLASAPI cublasStatus_t CUBLASWINAPI cublasDznrm2_v2 (cublasHandle_t handle,int n, const cuDoubleComplex *x, int incx, double *result){
    CublasFrontend::Prepare();
    
    CublasFrontend::AddVariableForArguments<long long int>((long long int)handle);
    CublasFrontend::AddVariableForArguments<int>(n);
    CublasFrontend::AddDevicePointerForArguments(x);
    CublasFrontend::AddVariableForArguments<int>(incx);
    
    CublasFrontend::Execute("cublasDznrm2_v2");
    if(CublasFrontend::Success())
        *result = CublasFrontend::GetOutputVariable<double>();
    return CublasFrontend::GetExitCode();
}

extern "C" CUBLASAPI cublasStatus_t CUBLASWINAPI cublasSsyrk_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, const float *alpha, const float *A, int lda, const float *beta, float *C, int ldc){
    CublasFrontend::Prepare();
    
    CublasFrontend::AddVariableForArguments<long long int>((long long int)handle);
    CublasFrontend::AddVariableForArguments<cublasFillMode_t>(uplo);
    CublasFrontend::AddVariableForArguments<cublasOperation_t>(trans);
    CublasFrontend::AddVariableForArguments<int>(n);
    CublasFrontend::AddVariableForArguments<int>(k);
    float * _alpha = const_cast<float *>(alpha);
    CublasFrontend::AddHostPointerForArguments(_alpha);
    CublasFrontend::AddDevicePointerForArguments(A);
    CublasFrontend::AddVariableForArguments<int>(lda);
    float * _beta = const_cast<float *>(beta);
    CublasFrontend::AddHostPointerForArguments(_beta);
    CublasFrontend::AddDevicePointerForArguments(C);
    CublasFrontend::AddVariableForArguments<int>(ldc);
    
    CublasFrontend::Execute("cublasSsyrk_v2");
    return CublasFrontend::GetExitCode();
}

extern "C" CUBLASAPI cublasStatus_t CUBLASWINAPI cublasDsyrk_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, const double *alpha, const double *A, int lda, const double *beta, double *C, int ldc){
    CublasFrontend::Prepare();
    
    CublasFrontend::AddVariableForArguments<long long int>((long long int)handle);
    CublasFrontend::AddVariableForArguments<cublasFillMode_t>(uplo);
    CublasFrontend::AddVariableForArguments<cublasOperation_t>(trans);
    CublasFrontend::AddVariableForArguments<int>(n);
    CublasFrontend::AddVariableForArguments<int>(k);
    double * _alpha = const_cast<double *>(alpha);
    CublasFrontend::AddHostPointerForArguments(_alpha);
    CublasFrontend::AddDevicePointerForArguments(A);
    CublasFrontend::AddVariableForArguments<int>(lda);
    double * _beta = const_cast<double *>(beta);
    CublasFrontend::AddHostPointerForArguments(_beta);
    CublasFrontend::AddDevicePointerForArguments(C);
    CublasFrontend::AddVariableForArguments<int>(ldc);
    
    CublasFrontend::Execute("cublasDsyrk_v2");
    return CublasFrontend::GetExitCode();
}

extern "C" CUBLASAPI cublasStatus_t CUBLASWINAPI cublasCsyrk_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, const cuComplex *alpha, const cuComplex *A, int lda, const cuComplex *beta, cuComplex *C, int ldc){
    CublasFrontend::Prepare();
    
    CublasFrontend::AddVariableForArguments<long long int>((long long int)handle);
    CublasFrontend::AddVariableForArguments<cublasFillMode_t>(uplo);
    CublasFrontend::AddVariableForArguments<cublasOperation_t>(trans);
    CublasFrontend::AddVariableForArguments<int>(n);
    CublasFrontend::AddVariableForArguments<int>(k);
    cuComplex * _alpha = const_cast<cuComplex *>(alpha);
    CublasFrontend::AddHostPointerForArguments(_alpha);
    CublasFrontend::AddDevicePointerForArguments(A);
    CublasFrontend::AddVariableForArguments<int>(lda);
    cuComplex * _beta = const_cast<cuComplex *>(beta);
    CublasFrontend::AddHostPointerForArguments(_beta);
    CublasFrontend::AddDevicePointerForArguments(C);
    CublasFrontend::AddVariableForArguments<int>(ldc);
    
    CublasFrontend::Execute("cublasCsyrk_v2");
    return CublasFrontend::GetExitCode();
}

extern "C" CUBLASAPI cublasStatus_t CUBLASWINAPI cublasZsyrk_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, const cuDoubleComplex *alpha, const cuDoubleComplex *A, int lda, const cuDoubleComplex *beta, cuDoubleComplex *C, int ldc){
    CublasFrontend::Prepare();
    
    CublasFrontend::AddVariableForArguments<long long int>((long long int)handle);
    CublasFrontend::AddVariableForArguments<cublasFillMode_t>(uplo);
    CublasFrontend::AddVariableForArguments<cublasOperation_t>(trans);
    CublasFrontend::AddVariableForArguments<int>(n);
    CublasFrontend::AddVariableForArguments<int>(k);
    cuDoubleComplex * _alpha = const_cast<cuDoubleComplex *>(alpha);
    CublasFrontend::AddHostPointerForArguments(_alpha);
    CublasFrontend::AddDevicePointerForArguments(A);
    CublasFrontend::AddVariableForArguments<int>(lda);
    cuDoubleComplex * _beta = const_cast<cuDoubleComplex *>(beta);
    CublasFrontend::AddHostPointerForArguments(_beta);
    CublasFrontend::AddDevicePointerForArguments(C);
    CublasFrontend::AddVariableForArguments<int>(ldc);
    
    CublasFrontend::Execute("cublasZsyrk_v2");
    return CublasFrontend::GetExitCode();
}

extern "C" CUBLASAPI cublasStatus_t CUBLASWINAPI cublasCherk_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, const float *alpha, const cuComplex *A, int lda, const float *beta, cuComplex *C, int ldc){
    CublasFrontend::Prepare();
    
    CublasFrontend::AddVariableForArguments<long long int>((long long int)handle);
    CublasFrontend::AddVariableForArguments<cublasFillMode_t>(uplo);
    CublasFrontend::AddVariableForArguments<cublasOperation_t>(trans);
    CublasFrontend::AddVariableForArguments<int>(n);
    CublasFrontend::AddVariableForArguments<int>(k);
    float * _alpha = const_cast<float *>(alpha);
    CublasFrontend::AddHostPointerForArguments(_alpha);
    CublasFrontend::AddDevicePointerForArguments(A);
    CublasFrontend::AddVariableForArguments<int>(lda);
    float * _beta = const_cast<float *>(beta);
    CublasFrontend::AddHostPointerForArguments(_beta);
    CublasFrontend::AddDevicePointerForArguments(C);
    CublasFrontend::AddVariableForArguments<int>(ldc);
    
    CublasFrontend::Execute("cublasCherk_v2");
    return CublasFrontend::GetExitCode();
}

extern "C" CUBLASAPI cublasStatus_t CUBLASWINAPI cublasZherk_v2(cublasHandle_t handle, cublasFillMode_t uplo, cublasOperation_t trans, int n, int k, const double *alpha, const cuDoubleComplex *A, int lda, const double *beta, cuDoubleComplex *C, int ldc){
    CublasFrontend::Prepare();
    
    CublasFrontend::AddVariableForArguments<long long int>((long long int)handle);
    CublasFrontend::AddVariableForArguments<cublasFillMode_t>(uplo);
    CublasFrontend::AddVariableForArguments<cublasOperation_t>(trans);
    CublasFrontend::AddVariableForArguments<int>(n);
    CublasFrontend::AddVariableForArguments<int>(k);
    double * _alpha = const_cast<double *>(alpha);
    CublasFrontend::AddHostPointerForArguments(_alpha);
    CublasFrontend::AddDevicePointerForArguments(A);
    CublasFrontend::AddVariableForArguments<int>(lda);
    double * _beta = const_cast<double *>(beta);
    CublasFrontend::AddHostPointerForArguments(_beta);
    CublasFrontend::AddDevicePointerForArguments(C);
    CublasFrontend::AddVariableForArguments<int>(ldc);
    
    CublasFrontend::Execute("cublasZherk_v2");
    return CublasFrontend::GetExitCode();
}