/*
Copyright (c) 2015 - present Advanced Micro Devices, Inc. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "CUDA2HIP.h"

// Maps the names of CUDA RUNTIME API types to the corresponding HIP types
const std::map<llvm::StringRef, hipCounter> CUDA_RUNTIME_TYPE_NAME_MAP {

  // 1. Structs

  // no analogue
  {"cudaChannelFormatDesc",                                            {"hipChannelFormatDesc",                                     "", CONV_TYPE, API_RUNTIME, 36}},
  // no analogue
  {"cudaDeviceProp",                                                   {"hipDeviceProp_t",                                          "", CONV_TYPE, API_RUNTIME, 36}},

  // no analogue
  {"cudaEglFrame",                                                     {"hipEglFrame",                                              "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  {"cudaEglFrame_st",                                                  {"hipEglFrame",                                              "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // no analogue
  {"cudaEglPlaneDesc",                                                 {"hipEglPlaneDesc",                                          "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  {"cudaEglPlaneDesc_st",                                              {"hipEglPlaneDesc",                                          "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // no analogue
  {"cudaExtent",                                                       {"hipExtent",                                                "", CONV_TYPE, API_RUNTIME, 36}},

  // CUDA_EXTERNAL_MEMORY_BUFFER_DESC
  {"cudaExternalMemoryBufferDesc",                                     {"HIP_EXTERNAL_MEMORY_BUFFER_DESC",                          "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUDA_EXTERNAL_MEMORY_HANDLE_DESC
  {"cudaExternalMemoryHandleDesc",                                     {"HIP_EXTERNAL_MEMORY_HANDLE_DESC",                          "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC
  {"cudaExternalMemoryMipmappedArrayDesc",                             {"HIP_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC",                 "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC
  {"cudaExternalSemaphoreHandleDesc",                                  {"HIP_EXTERNAL_SEMAPHORE_HANDLE_DESC",                       "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS
  {"cudaExternalSemaphoreSignalParams",                                {"HIP_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS",                     "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  {"cudaExternalSemaphoreSignalParams_v1",                             {"HIP_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS_v1",                  "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS
  {"cudaExternalSemaphoreWaitParams",                                  {"HIP_EXTERNAL_SEMAPHORE_WAIT_PARAMS",                       "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  {"cudaExternalSemaphoreWaitParams_v1",                               {"HIP_EXTERNAL_SEMAPHORE_WAIT_PARAMS_v1",                    "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // no analogue
  {"cudaFuncAttributes",                                               {"hipFuncAttributes",                                        "", CONV_TYPE, API_RUNTIME, 36}},

  // CUDA_HOST_NODE_PARAMS
  {"cudaHostNodeParams",                                               {"HIP_HOST_NODE_PARAMS",                                     "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUipcEventHandle
  {"cudaIpcEventHandle_t",                                             {"hipIpcEventHandle_t",                                      "", CONV_TYPE, API_RUNTIME, 36}},
  // CUipcEventHandle_st
  {"cudaIpcEventHandle_st",                                            {"hipIpcEventHandle_st",                                     "", CONV_TYPE, API_RUNTIME, 36}},

  // CUipcMemHandle
  {"cudaIpcMemHandle_t",                                               {"hipIpcMemHandle_t",                                        "", CONV_TYPE, API_RUNTIME, 36}},
  // CUipcMemHandle_st
  {"cudaIpcMemHandle_st",                                              {"hipIpcMemHandle_st",                                       "", CONV_TYPE, API_RUNTIME, 36}},

  // CUDA_KERNEL_NODE_PARAMS
  {"cudaKernelNodeParams",                                             {"hipKernelNodeParams",                                      "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // no analogue
  // CUDA_LAUNCH_PARAMS struct differs
  {"cudaLaunchParams",                                                 {"hipLaunchParams",                                          "", CONV_TYPE, API_RUNTIME, 36}},

  // no analogue
  // NOTE: HIP struct is bigger and contains cudaMemcpy3DParms only in the beginning
  {"cudaMemcpy3DParms",                                                {"hipMemcpy3DParms",                                         "", CONV_TYPE, API_RUNTIME, 36}},

  // no analogue
  {"cudaMemcpy3DPeerParms",                                            {"hipMemcpy3DPeerParms",                                     "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUDA_MEMSET_NODE_PARAMS
  {"cudaMemsetParams",                                                 {"hipMemsetParams",                                          "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // no analogue
  {"cudaPitchedPtr",                                                   {"hipPitchedPtr",                                            "", CONV_TYPE, API_RUNTIME, 36}},

  // no analogue
  {"cudaPointerAttributes",                                            {"hipPointerAttribute_t",                                    "", CONV_TYPE, API_RUNTIME, 36}},

  // no analogue
  {"cudaPos",                                                          {"hipPos",                                                   "", CONV_TYPE, API_RUNTIME, 36}},

  // no analogue
  // NOTE: CUDA_RESOURCE_DESC struct differs
  {"cudaResourceDesc",                                                 {"hipResourceDesc",                                          "", CONV_TYPE, API_RUNTIME, 36}},

  // NOTE: CUDA_RESOURCE_VIEW_DESC has reserved bytes in the end
  {"cudaResourceViewDesc",                                             {"hipResourceViewDesc",                                      "", CONV_TYPE, API_RUNTIME, 36}},

  // no analogue
  // NOTE: CUDA_TEXTURE_DESC differs
  {"cudaTextureDesc",                                                  {"hipTextureDesc",                                           "", CONV_TYPE, API_RUNTIME, 36}},

  // NOTE: the same struct and its name
  {"CUuuid_st",                                                        {"hipUUID",                                                  "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // NOTE: possibly CUsurfref is analogue
  {"surfaceReference",                                                 {"surfaceReference",                                         "", CONV_TYPE, API_RUNTIME, 36}},

  // the same - CUevent_st
  {"CUevent_st",                                                       {"ihipEvent_t",                                              "", CONV_TYPE, API_RUNTIME, 36}},
  // CUevent
  {"cudaEvent_t",                                                      {"hipEvent_t",                                               "", CONV_TYPE, API_RUNTIME, 36}},

  // CUextMemory_st
  {"CUexternalMemory_st",                                              {"hipExtMemory_st",                                          "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // CUexternalMemory
  {"cudaExternalMemory_t",                                             {"hipExternalMemory",                                        "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUextSemaphore_st
  {"CUexternalSemaphore_st",                                           {"hipExtSemaphore_st",                                       "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // CUexternalSemaphore
  {"cudaExternalSemaphore_t",                                          {"hipExternalSemaphore",                                     "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // the same - CUgraph_st
  {"CUgraph_st",                                                       {"hipGraph_st",                                              "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // CUgraph
  {"cudaGraph_t",                                                      {"hipGraph",                                                 "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // the same -CUgraphExec_st
  {"CUgraphExec_st",                                                   {"hipGraphExec_st",                                          "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // CUgraphExec
  {"cudaGraphExec_t",                                                  {"hipGraphExec",                                             "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUgraphicsResource_st
  {"cudaGraphicsResource",                                             {"hipGraphicsResource_st",                                   "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // CUgraphicsResource
  {"cudaGraphicsResource_t",                                           {"hipGraphicsResource_t",                                    "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // the same - CUgraphNode_st
  {"CUgraphNode_st",                                                   {"hipGraphNode_st",                                          "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // CUgraphNode
  {"cudaGraphNode_t",                                                  {"hipGraphNode",                                             "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUeglStreamConnection_st
  {"CUeglStreamConnection_st",                                         {"hipEglStreamConnection",                                   "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // CUeglStreamConnection
  {"cudaEglStreamConnection",                                          {"hipEglStreamConnection",                                   "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUarray_st
  {"cudaArray",                                                        {"hipArray",                                                 "", CONV_TYPE, API_RUNTIME, 36}},
  // CUarray
  {"cudaArray_t",                                                      {"hipArray_t",                                               "", CONV_TYPE, API_RUNTIME, 36}},
  // no analogue
  {"cudaArray_const_t",                                                {"hipArray_const_t",                                         "", CONV_TYPE, API_RUNTIME, 36}},

  // CUmipmappedArray_st
  {"cudaMipmappedArray",                                               {"hipMipmappedArray",                                        "", CONV_TYPE, API_RUNTIME, 36}},
  // CUmipmappedArray
  {"cudaMipmappedArray_t",                                             {"hipMipmappedArray_t",                                      "", CONV_TYPE, API_RUNTIME, 36}},
  // no analogue
  {"cudaMipmappedArray_const_t",                                       {"hipMipmappedArray_const_t",                                "", CONV_TYPE, API_RUNTIME, 36}},

  // the same - CUstream_st
  {"CUstream_st",                                                      {"ihipStream_t",                                             "", CONV_TYPE, API_RUNTIME, 36}},
  // CUstream
  {"cudaStream_t",                                                     {"hipStream_t",                                              "", CONV_TYPE, API_RUNTIME, 36}},

  // CUfunction
  {"cudaFunction_t",                                                   {"hipFunction_t",                                            "", CONV_TYPE, API_DRIVER}},

  // CUaccessPolicyWindow_st
  {"cudaAccessPolicyWindow",                                           {"hipAccessPolicyWindow",                                    "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUDA_ARRAY_SPARSE_PROPERTIES_st
  {"cudaArraySparseProperties",                                        {"hipArraySparseProperties",                                 "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUmemLocation_st
  {"cudaMemLocation",                                                  {"hipMemoryLocation",                                        "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUmemAccessDesc_st
  {"cudaMemAccessDesc",                                                {"hipMemoryAccessDescription",                               "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUmemPoolProps_st
  {"cudaMemPoolProps",                                                 {"hipMemPoolProps",                                          "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUmemPoolPtrExportData_st
  {"cudaMemPoolPtrExportData",                                         {"hipMemPoolPtrExportData",                                  "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUDA_EXT_SEM_SIGNAL_NODE_PARAMS_st
  {"cudaExternalSemaphoreSignalNodeParams",                            {"hipExternalSemaphoreSignalNodeParams",                     "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUDA_EXT_SEM_WAIT_NODE_PARAMS_st
  {"cudaExternalSemaphoreWaitNodeParams",                              {"hipExternalSemaphoreWaitNodeParams",                       "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // 2. Unions

  //
  {"cudaStreamAttrValue",                                              {"hipStreamAttrValue",                                       "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  //
  {"cudaKernelNodeAttrValue",                                          {"hipKernelNodeAttrValue",                                   "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // 3. Enums

  // no analogue
  {"cudaCGScope",                                                      {"hipCGScope",                                               "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaCGScope enum values
  {"cudaCGScopeInvalid",                                               {"hipCGScopeInvalid",                                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0
  {"cudaCGScopeGrid",                                                  {"hipCGScopeGrid",                                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  {"cudaCGScopeMultiGrid",                                             {"hipCGScopeMultiGrid",                                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2

  // no analogue
  {"cudaChannelFormatKind",                                            {"hipChannelFormatKind",                                     "", CONV_TYPE, API_RUNTIME, 36}},
  // cudaChannelFormatKind enum values
  {"cudaChannelFormatKindSigned",                                      {"hipChannelFormatKindSigned",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0
  {"cudaChannelFormatKindUnsigned",                                    {"hipChannelFormatKindUnsigned",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 1
  {"cudaChannelFormatKindFloat",                                       {"hipChannelFormatKindFloat",                                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 2
  {"cudaChannelFormatKindNone",                                        {"hipChannelFormatKindNone",                                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 3
  {"cudaChannelFormatKindNV12",                                        {"hipChannelFormatKindNV12",                                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 4

  // CUcomputemode
  {"cudaComputeMode",                                                  {"hipComputeMode",                                           "", CONV_TYPE, API_RUNTIME, 36}},
  // cudaComputeMode enum values
  // CU_COMPUTEMODE_DEFAULT
  {"cudaComputeModeDefault",                                           {"hipComputeModeDefault",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0
  // CU_COMPUTEMODE_EXCLUSIVE
  {"cudaComputeModeExclusive",                                         {"hipComputeModeExclusive",                                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 1
  // CU_COMPUTEMODE_PROHIBITED
  {"cudaComputeModeProhibited",                                        {"hipComputeModeProhibited",                                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 2
  // CU_COMPUTEMODE_EXCLUSIVE_PROCESS
  {"cudaComputeModeExclusiveProcess",                                  {"hipComputeModeExclusiveProcess",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 3

  // CUdevice_attribute
  {"cudaDeviceAttr",                                                   {"hipDeviceAttribute_t",                                     "", CONV_TYPE, API_RUNTIME, 36}},
  // cudaDeviceAttr enum values
  // CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK
  {"cudaDevAttrMaxThreadsPerBlock",                                    {"hipDeviceAttributeMaxThreadsPerBlock",                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, //  1
  // CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X
  {"cudaDevAttrMaxBlockDimX",                                          {"hipDeviceAttributeMaxBlockDimX",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, //  2
  // CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y
  {"cudaDevAttrMaxBlockDimY",                                          {"hipDeviceAttributeMaxBlockDimY",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, //  3
  // CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z
  {"cudaDevAttrMaxBlockDimZ",                                          {"hipDeviceAttributeMaxBlockDimZ",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, //  4
  // CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X
  {"cudaDevAttrMaxGridDimX",                                           {"hipDeviceAttributeMaxGridDimX",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, //  5
  // CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y
  {"cudaDevAttrMaxGridDimY",                                           {"hipDeviceAttributeMaxGridDimY",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, //  6
  // CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z
  {"cudaDevAttrMaxGridDimZ",                                           {"hipDeviceAttributeMaxGridDimZ",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, //  7
  // CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK
  {"cudaDevAttrMaxSharedMemoryPerBlock",                               {"hipDeviceAttributeMaxSharedMemoryPerBlock",                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, //  8
  // CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY
  {"cudaDevAttrTotalConstantMemory",                                   {"hipDeviceAttributeTotalConstantMemory",                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, //  9
  // CU_DEVICE_ATTRIBUTE_WARP_SIZE
  {"cudaDevAttrWarpSize",                                              {"hipDeviceAttributeWarpSize",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 10
  // CU_DEVICE_ATTRIBUTE_MAX_PITCH
  {"cudaDevAttrMaxPitch",                                              {"hipDeviceAttributeMaxPitch",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 11
  // CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK
  {"cudaDevAttrMaxRegistersPerBlock",                                  {"hipDeviceAttributeMaxRegistersPerBlock",                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 12
  // CU_DEVICE_ATTRIBUTE_CLOCK_RATE
  {"cudaDevAttrClockRate",                                             {"hipDeviceAttributeClockRate",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 13
  // CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT
  {"cudaDevAttrTextureAlignment",                                      {"hipDeviceAttributeTextureAlignment",                       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 14
  // CU_DEVICE_ATTRIBUTE_GPU_OVERLAP
  // NOTE: Is not deprecated as CUDA Driver's API analogue CU_DEVICE_ATTRIBUTE_GPU_OVERLAP
  {"cudaDevAttrGpuOverlap",                                            {"hipDeviceAttributeGpuOverlap",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 15
  // CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT
  {"cudaDevAttrMultiProcessorCount",                                   {"hipDeviceAttributeMultiprocessorCount",                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 16
  // CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT
  {"cudaDevAttrKernelExecTimeout",                                     {"hipDeviceAttributeKernelExecTimeout",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 17
  // CU_DEVICE_ATTRIBUTE_INTEGRATED
  {"cudaDevAttrIntegrated",                                            {"hipDeviceAttributeIntegrated",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 18
  // CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY
  {"cudaDevAttrCanMapHostMemory",                                      {"hipDeviceAttributeCanMapHostMemory",                       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 19
  // CU_DEVICE_ATTRIBUTE_COMPUTE_MODE
  {"cudaDevAttrComputeMode",                                           {"hipDeviceAttributeComputeMode",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 20
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH
  {"cudaDevAttrMaxTexture1DWidth",                                     {"hipDeviceAttributeMaxTexture1DWidth",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 21
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH
  {"cudaDevAttrMaxTexture2DWidth",                                     {"hipDeviceAttributeMaxTexture2DWidth",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 22
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT
  {"cudaDevAttrMaxTexture2DHeight",                                    {"hipDeviceAttributeMaxTexture2DHeight",                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 23
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH
  {"cudaDevAttrMaxTexture3DWidth",                                     {"hipDeviceAttributeMaxTexture3DWidth",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 24
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT
  {"cudaDevAttrMaxTexture3DHeight",                                     {"hipDeviceAttributeMaxTexture3DHeight",                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 25
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH
  {"cudaDevAttrMaxTexture3DDepth",                                     {"hipDeviceAttributeMaxTexture3DDepth",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 26
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_WIDTH
  {"cudaDevAttrMaxTexture2DLayeredWidth",                              {"hipDeviceAttributeMaxTexture2DLayeredWidth",               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 27
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_HEIGHT
  {"cudaDevAttrMaxTexture2DLayeredHeight",                             {"hipDeviceAttributeMaxTexture2DLayeredHeight",              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 28
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_LAYERS
  {"cudaDevAttrMaxTexture2DLayeredLayers",                             {"hipDeviceAttributeMaxTexture2DLayeredLayers",              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 29
  // CU_DEVICE_ATTRIBUTE_SURFACE_ALIGNMENT
  {"cudaDevAttrSurfaceAlignment",                                      {"hipDeviceAttributeSurfaceAlignment",                       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 30
  // CU_DEVICE_ATTRIBUTE_CONCURRENT_KERNELS
  {"cudaDevAttrConcurrentKernels",                                     {"hipDeviceAttributeConcurrentKernels",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 31
  // CU_DEVICE_ATTRIBUTE_ECC_ENABLED
  {"cudaDevAttrEccEnabled",                                            {"hipDeviceAttributeEccEnabled",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 32
  // CU_DEVICE_ATTRIBUTE_PCI_BUS_ID
  {"cudaDevAttrPciBusId",                                              {"hipDeviceAttributePciBusId",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 33
  // CU_DEVICE_ATTRIBUTE_PCI_DEVICE_ID
  {"cudaDevAttrPciDeviceId",                                           {"hipDeviceAttributePciDeviceId",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 34
  // CU_DEVICE_ATTRIBUTE_TCC_DRIVER
  {"cudaDevAttrTccDriver",                                             {"hipDeviceAttributeTccDriver",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 35
  // CU_DEVICE_ATTRIBUTE_MEMORY_CLOCK_RATE
  {"cudaDevAttrMemoryClockRate",                                       {"hipDeviceAttributeMemoryClockRate",                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 36
  // CU_DEVICE_ATTRIBUTE_GLOBAL_MEMORY_BUS_WIDTH
  {"cudaDevAttrGlobalMemoryBusWidth",                                  {"hipDeviceAttributeMemoryBusWidth",                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 37
  // CU_DEVICE_ATTRIBUTE_L2_CACHE_SIZE
  {"cudaDevAttrL2CacheSize",                                           {"hipDeviceAttributeL2CacheSize",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 38
  // CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_MULTIPROCESSOR
  {"cudaDevAttrMaxThreadsPerMultiProcessor",                           {"hipDeviceAttributeMaxThreadsPerMultiProcessor",            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 39
  // CU_DEVICE_ATTRIBUTE_ASYNC_ENGINE_COUNT
  {"cudaDevAttrAsyncEngineCount",                                      {"hipDeviceAttributeAsyncEngineCount",                       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 40
  // CU_DEVICE_ATTRIBUTE_UNIFIED_ADDRESSING
  {"cudaDevAttrUnifiedAddressing",                                     {"hipDeviceAttributeUnifiedAddressing",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 41
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_WIDTH
  {"cudaDevAttrMaxTexture1DLayeredWidth",                              {"hipDeviceAttributeMaxTexture1DLayeredWidth",               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 42
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_LAYERS
  {"cudaDevAttrMaxTexture1DLayeredLayers",                             {"hipDeviceAttributeMaxTexture1DLayeredLayers",              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 43
  // 44 - no
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_GATHER_WIDTH
  {"cudaDevAttrMaxTexture2DGatherWidth",                               {"hipDeviceAttributeMaxTexture2DGatherWidth",                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 45
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_GATHER_HEIGHT
  {"cudaDevAttrMaxTexture2DGatherHeight",                              {"hipDeviceAttributeMaxTexture2DGatherHeight",               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 46
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH_ALTERNATE
  {"cudaDevAttrMaxTexture3DWidthAlt",                                  {"hipDeviceAttributeMaxTexture3DWidthAlternate",             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 47
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT_ALTERNATE
  {"cudaDevAttrMaxTexture3DHeightAlt",                                 {"hipDeviceAttributeMaxTexture3DHeightAlternate",            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 48
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH_ALTERNATE
  {"cudaDevAttrMaxTexture3DDepthAlt",                                  {"hipDeviceAttributeMaxTexture3DDepthAlternate",             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 49
  // CU_DEVICE_ATTRIBUTE_PCI_DOMAIN_ID
  {"cudaDevAttrPciDomainId",                                           {"hipDeviceAttributePciDomainId",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 50
  // CU_DEVICE_ATTRIBUTE_TEXTURE_PITCH_ALIGNMENT
  {"cudaDevAttrTexturePitchAlignment",                                 {"hipDeviceAttributeTexturePitchAlignment",                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 51
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_WIDTH
  {"cudaDevAttrMaxTextureCubemapWidth",                                {"hipDeviceAttributeMaxTextureCubemapWidth",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 52
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_LAYERED_WIDTH
  {"cudaDevAttrMaxTextureCubemapLayeredWidth",                         {"hipDeviceAttributeMaxTextureCubemapLayeredWidth",          "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 53
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_LAYERED_LAYERS
  {"cudaDevAttrMaxTextureCubemapLayeredLayers",                        {"hipDeviceAttributeMaxTextureCubemapLayeredLayers",         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 54
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_WIDTH
  {"cudaDevAttrMaxSurface1DWidth",                                     {"hipDeviceAttributeMaxSurface1DWidth",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 55
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_WIDTH
  {"cudaDevAttrMaxSurface2DWidth",                                     {"hipDeviceAttributeMaxSurface2DWidth",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 56
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_HEIGHT
  {"cudaDevAttrMaxSurface2DHeight",                                    {"hipDeviceAttributeMaxSurface2DHeight",                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 57
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_WIDTH
  {"cudaDevAttrMaxSurface3DWidth",                                     {"hipDeviceAttributeMaxSurface3DWidth",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 58
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_HEIGHT
  {"cudaDevAttrMaxSurface3DHeight",                                    {"hipDeviceAttributeMaxSurface3DHeight",                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 59
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_DEPTH
  {"cudaDevAttrMaxSurface3DDepth",                                     {"hipDeviceAttributeMaxSurface3DDepth",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 60
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_LAYERED_WIDTH
  {"cudaDevAttrMaxSurface1DLayeredWidth",                              {"hipDeviceAttributeMaxSurface1DLayeredWidth",               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 61
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_LAYERED_LAYERS
  {"cudaDevAttrMaxSurface1DLayeredLayers",                             {"hipDeviceAttributeMaxSurface1DLayeredLayers",              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 62
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_WIDTH
  {"cudaDevAttrMaxSurface2DLayeredWidth",                              {"hipDeviceAttributeMaxSurface2DLayeredWidth",               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 63
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_HEIGHT
  {"cudaDevAttrMaxSurface2DLayeredHeight",                             {"hipDeviceAttributeMaxSurface2DLayeredHeight",              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 64
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_LA  YERS
  {"cudaDevAttrMaxSurface2DLayeredLayers",                             {"hipDeviceAttributeMaxSurface2DLayeredLayers",              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 65
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_WIDTH
  {"cudaDevAttrMaxSurfaceCubemapWidth",                                {"hipDeviceAttributeMaxSurfaceCubemapWidth",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 66
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_LAYERED_WIDTH
  {"cudaDevAttrMaxSurfaceCubemapLayeredWidth",                         {"hipDeviceAttributeMaxSurfaceCubemapLayeredWidth",          "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 67
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_LAYERED_LAYERS
  {"cudaDevAttrMaxSurfaceCubemapLayeredLayers",                        {"hipDeviceAttributeMaxSurfaceCubemapLayeredLayers",         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 68
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LINEAR_WIDTH
  {"cudaDevAttrMaxTexture1DLinearWidth",                               {"hipDeviceAttributeMaxTexture1DLinearWidth",                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 69
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_WIDTH
  {"cudaDevAttrMaxTexture2DLinearWidth",                               {"hipDeviceAttributeMaxTexture2DLinearWidth",                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 70
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_HEIGHT
  {"cudaDevAttrMaxTexture2DLinearHeight",                              {"hipDeviceAttributeMaxTexture2DLinearHeight",               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 71
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_PITCH
  {"cudaDevAttrMaxTexture2DLinearPitch",                               {"hipDeviceAttributeMaxTexture2DLinearPitch",                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 72
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_MIPMAPPED_WIDTH
  {"cudaDevAttrMaxTexture2DMipmappedWidth",                            {"hipDeviceAttributeMaxTexture2DMipmappedWidth",             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 73
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_MIPMAPPED_HEIGHT
  {"cudaDevAttrMaxTexture2DMipmappedHeight",                           {"hipDeviceAttributeMaxTexture2DMipmappedHeight",            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 74
  // CU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MAJOR
  {"cudaDevAttrComputeCapabilityMajor",                                {"hipDeviceAttributeComputeCapabilityMajor",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 75
  // CU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MINOR
  {"cudaDevAttrComputeCapabilityMinor",                                {"hipDeviceAttributeComputeCapabilityMinor",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 76
  // CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_MIPMAPPED_WIDTH
  {"cudaDevAttrMaxTexture1DMipmappedWidth",                            {"hipDeviceAttributeMaxTexture1DMipmappedWidth",             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 77
  // CU_DEVICE_ATTRIBUTE_STREAM_PRIORITIES_SUPPORTED
  {"cudaDevAttrStreamPrioritiesSupported",                             {"hipDeviceAttributeStreamPrioritiesSupported",              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 78
  // CU_DEVICE_ATTRIBUTE_GLOBAL_L1_CACHE_SUPPORTED
  {"cudaDevAttrGlobalL1CacheSupported",                                {"hipDeviceAttributeGlobalL1CacheSupported",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 79
  // CU_DEVICE_ATTRIBUTE_LOCAL_L1_CACHE_SUPPORTED
  {"cudaDevAttrLocalL1CacheSupported",                                 {"hipDeviceAttributeLocalL1CacheSupported",                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 80
  // CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_MULTIPROCESSOR
  {"cudaDevAttrMaxSharedMemoryPerMultiprocessor",                      {"hipDeviceAttributeMaxSharedMemoryPerMultiprocessor",       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 81
  // CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_MULTIPROCESSOR
  {"cudaDevAttrMaxRegistersPerMultiprocessor",                         {"hipDeviceAttributeMaxRegistersPerMultiprocessor",          "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 82
  // CU_DEVICE_ATTRIBUTE_MANAGED_MEMORY
  {"cudaDevAttrManagedMemory",                                         {"hipDeviceAttributeManagedMemory",                          "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 83
  // CU_DEVICE_ATTRIBUTE_MULTI_GPU_BOARD
  {"cudaDevAttrIsMultiGpuBoard",                                       {"hipDeviceAttributeIsMultiGpuBoard",                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 84
  // CU_DEVICE_ATTRIBUTE_MULTI_GPU_BOARD_GROUP_ID
  {"cudaDevAttrMultiGpuBoardGroupID",                                  {"hipDeviceAttributeMultiGpuBoardGroupID",                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 85
  // CU_DEVICE_ATTRIBUTE_HOST_NATIVE_ATOMIC_SUPPORTED
  {"cudaDevAttrHostNativeAtomicSupported",                             {"hipDeviceAttributeHostNativeAtomicSupported",              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 86
  // CU_DEVICE_ATTRIBUTE_SINGLE_TO_DOUBLE_PRECISION_PERF_RATIO
  {"cudaDevAttrSingleToDoublePrecisionPerfRatio",                      {"hipDeviceAttributeSingleToDoublePrecisionPerfRatio",       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 87
  // CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS
  {"cudaDevAttrPageableMemoryAccess",                                  {"hipDeviceAttributePageableMemoryAccess",                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 88
  // CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS
  {"cudaDevAttrConcurrentManagedAccess",                               {"hipDeviceAttributeConcurrentManagedAccess",                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 89
  // CU_DEVICE_ATTRIBUTE_COMPUTE_PREEMPTION_SUPPORTED
  {"cudaDevAttrComputePreemptionSupported",                            {"hipDeviceAttributeComputePreemptionSupported",             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 90
  // CU_DEVICE_ATTRIBUTE_CAN_USE_HOST_POINTER_FOR_REGISTERED_MEM
  {"cudaDevAttrCanUseHostPointerForRegisteredMem",                     {"hipDeviceAttributeCanUseHostPointerForRegisteredMem",      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 91
  // CU_DEVICE_ATTRIBUTE_CAN_USE_STREAM_MEM_OPS
  {"cudaDevAttrReserved92",                                            {"hipDeviceAttributeCanUseStreamMemOps",                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 92
  // CU_DEVICE_ATTRIBUTE_CAN_USE_64_BIT_STREAM_MEM_OPS
  {"cudaDevAttrReserved93",                                            {"hipDeviceAttributeCanUse64BitStreamMemOps",                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 93
  // CU_DEVICE_ATTRIBUTE_CAN_USE_STREAM_WAIT_VALUE_NOR
  {"cudaDevAttrReserved94",                                            {"hipDeviceAttributeCanUseStreamWaitValueNor",               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 94
  // CU_DEVICE_ATTRIBUTE_COOPERATIVE_LAUNCH
  {"cudaDevAttrCooperativeLaunch",                                     {"hipDeviceAttributeCooperativeLaunch",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 95
  // CU_DEVICE_ATTRIBUTE_COOPERATIVE_MULTI_DEVICE_LAUNCH
  {"cudaDevAttrCooperativeMultiDeviceLaunch",                          {"hipDeviceAttributeCooperativeMultiDeviceLaunch",           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 96
  // CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK_OPTIN
  {"cudaDevAttrMaxSharedMemoryPerBlockOptin",                          {"hipDeviceAttributeMaxSharedMemoryPerBlockOptin",           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 97
  // CU_DEVICE_ATTRIBUTE_CAN_FLUSH_REMOTE_WRITES
  {"cudaDevAttrCanFlushRemoteWrites",                                  {"hipDeviceAttributeCanFlushRemoteWrites",                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 98
  // CU_DEVICE_ATTRIBUTE_HOST_REGISTER_SUPPORTED
  {"cudaDevAttrHostRegisterSupported",                                 {"hipDeviceAttributeHostRegisterSupported",                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 99
  // CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS_USES_HOST_PAGE_TABLES
  {"cudaDevAttrPageableMemoryAccessUsesHostPageTables",                {"hipDeviceAttributePageableMemoryAccessUsesHostPageTables", "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 100
  // CU_DEVICE_ATTRIBUTE_DIRECT_MANAGED_MEM_ACCESS_FROM_HOST
  {"cudaDevAttrDirectManagedMemAccessFromHost",                        {"hipDeviceAttributeDirectManagedMemAccessFromHost",         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 101
  // CU_DEVICE_ATTRIBUTE_MAX_BLOCKS_PER_MULTIPROCESSOR
  {"cudaDevAttrMaxBlocksPerMultiprocessor",                            {"hipDeviceAttributeMaxBlocksPerMultiprocessor",             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 106
  // CU_DEVICE_ATTRIBUTE_MAX_PERSISTING_L2_CACHE_SIZE
  {"cudaDevAttrMaxPersistingL2CacheSize",                              {"hipDeviceAttributeMaxPersistingL2CacheSize",               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 108
  // CU_DEVICE_ATTRIBUTE_MAX_ACCESS_POLICY_WINDOW_SIZE
  {"cudaDevAttrMaxAccessPolicyWindowSize",                             {"hipDeviceAttributeMaxAccessPolicyWindowSize",              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 109
  // CU_DEVICE_ATTRIBUTE_RESERVED_SHARED_MEMORY_PER_BLOCK
  {"cudaDevAttrReservedSharedMemoryPerBlock",                          {"hipDeviceAttributeReservedSharedMemoryPerBlock",           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 111
  // CU_DEVICE_ATTRIBUTE_SPARSE_CUDA_ARRAY_SUPPORTED
  {"cudaDevAttrSparseCudaArraySupported",                              {"hipDeviceAttributeSparseCudaArraySupported",               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 112
  // CU_DEVICE_ATTRIBUTE_READ_ONLY_HOST_REGISTER_SUPPORTED
  {"cudaDevAttrHostRegisterReadOnlySupported",                         {"hipDeviceAttributeReadOnlyHostRestigerSupported",          "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 113
  // CU_DEVICE_ATTRIBUTE_TIMELINE_SEMAPHORE_INTEROP_SUPPORTED
  {"cudaDevAttrMaxTimelineSemaphoreInteropSupported",                  {"hipDeviceAttributeMaxTimelineSemaphoreInteropSupported",   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 114
  // CU_DEVICE_ATTRIBUTE_MEMORY_POOLS_SUPPORTED
  {"cudaDevAttrMemoryPoolsSupported",                                  {"hipDeviceAttributeMemoryPoolsSupported",                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 115
  // CU_DEVICE_ATTRIBUTE_GPU_DIRECT_RDMA_SUPPORTED
  {"cudaDevAttrGPUDirectRDMASupported",                                {"hipDeviceAttributeGPUDirectRDMASupported",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 116
  // CU_DEVICE_ATTRIBUTE_GPU_DIRECT_RDMA_FLUSH_WRITES_OPTIONS
  {"cudaDevAttrGPUDirectRDMAFlushWritesOptions",                       {"hipDeviceAttributeGpuDirectRdmaFlushWritesOptions",        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 117
  // CU_DEVICE_ATTRIBUTE_GPU_DIRECT_RDMA_WRITES_ORDERING
  {"cudaDevAttrGPUDirectRDMAWritesOrdering",                           {"hipDeviceAttributeGpuDirectRdmaWritesOrdering",            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 118
  // CU_DEVICE_ATTRIBUTE_MEMPOOL_SUPPORTED_HANDLE_TYPES
  {"cudaDevAttrMemoryPoolSupportedHandleTypes",                        {"hipDeviceAttributeMempoolSupportedHandleTypes",            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 119

  // CUdevice_P2PAttribute
  {"cudaDeviceP2PAttr",                                                {"hipDeviceP2PAttr",                                         "", CONV_TYPE, API_RUNTIME, 36}},
  // cudaDeviceP2PAttr enum values
  // CU_DEVICE_P2P_ATTRIBUTE_PERFORMANCE_RANK = 0x01
  {"cudaDevP2PAttrPerformanceRank",                                    {"hipDevP2PAttrPerformanceRank",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 1
  // CU_DEVICE_P2P_ATTRIBUTE_ACCESS_SUPPORTED = 0x02
  {"cudaDevP2PAttrAccessSupported",                                    {"hipDevP2PAttrAccessSupported",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 2
  // CU_DEVICE_P2P_ATTRIBUTE_NATIVE_ATOMIC_SUPPORTED = 0x03
  {"cudaDevP2PAttrNativeAtomicSupported",                              {"hipDevP2PAttrNativeAtomicSupported",                       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 3
  // CU_DEVICE_P2P_ATTRIBUTE_CUDA_ARRAY_ACCESS_SUPPORTED = 0x04
  {"cudaDevP2PAttrCudaArrayAccessSupported",                           {"hipDevP2PAttrHipArrayAccessSupported",                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 4

  // cudaEGL.h - presented only on Linux in nvidia-cuda-dev package
  // CUeglColorFormat
  {"cudaEglColorFormat",                                               {"hipEglColorFormat",                                        "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaEglColorFormat enum values
  // CU_EGL_COLOR_FORMAT_YUV420_PLANAR = 0x00
  {"cudaEglColorFormatYUV420Planar",                                   {"hipEglColorFormatYUV420Planar",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0
  // CU_EGL_COLOR_FORMAT_YUV420_SEMIPLANAR= 0x01
  {"cudaEglColorFormatYUV420SemiPlanar",                               {"hipEglColorFormatYUV420SemiPlanar",                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  // CU_EGL_COLOR_FORMAT_YUV422_PLANAR = 0x02
  {"cudaEglColorFormatYUV422Planar",                                   {"hipEglColorFormatYUV422Planar",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2
  // CU_EGL_COLOR_FORMAT_YUV422_SEMIPLANAR = 0x03
  {"cudaEglColorFormatYUV422SemiPlanar",                               {"hipEglColorFormatYUV422SemiPlanar",                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 3
  // CU_EGL_COLOR_FORMAT_RGB = 0x04
  {"cudaEglColorFormatRGB",                                            {"hipEglColorFormatRGB",                                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 4
  // CU_EGL_COLOR_FORMAT_BGR = 0x05
  {"cudaEglColorFormatBGR",                                            {"hipEglColorFormatBGR",                                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 5
  // CU_EGL_COLOR_FORMAT_ARGB = 0x06
  {"cudaEglColorFormatARGB",                                           {"hipEglColorFormatARGB",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 6
  // CU_EGL_COLOR_FORMAT_RGBA = 0x07
  {"cudaEglColorFormatRGBA",                                           {"hipEglColorFormatRGBA",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 7
  // CU_EGL_COLOR_FORMAT_L = 0x08
  {"cudaEglColorFormatL",                                              {"hipEglColorFormatL",                                       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 8
  // CU_EGL_COLOR_FORMAT_R = 0x09
  {"cudaEglColorFormatR",                                              {"hipEglColorFormatR",                                       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 9
  // CU_EGL_COLOR_FORMAT_YUV444_PLANAR = 0x0A
  {"cudaEglColorFormatYUV444Planar",                                   {"hipEglColorFormatYUV444Planar",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 10
  // CU_EGL_COLOR_FORMAT_YUV444_SEMIPLANAR = 0x0B
  {"cudaEglColorFormatYUV444SemiPlanar",                               {"hipEglColorFormatYUV444SemiPlanar",                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 11
  // CU_EGL_COLOR_FORMAT_YUYV_422 = 0x0C
  {"cudaEglColorFormatYUYV422",                                        {"hipEglColorFormatYUYV422",                                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 12
  // CU_EGL_COLOR_FORMAT_UYVY_422 = 0x0D
  {"cudaEglColorFormatUYVY422",                                        {"hipEglColorFormatUYVY422",                                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 13
  // CU_EGL_COLOR_FORMAT_ABGR = 0x0E
  {"cudaEglColorFormatABGR",                                           {"hipEglColorFormatABGR",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 14
  // CU_EGL_COLOR_FORMAT_BGRA = 0x0F
  {"cudaEglColorFormatBGRA",                                           {"hipEglColorFormatBGRA",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 15
  // CU_EGL_COLOR_FORMAT_A = 0x10
  {"cudaEglColorFormatA",                                              {"hipEglColorFormatA",                                       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 16
  // CU_EGL_COLOR_FORMAT_RG = 0x11
  {"cudaEglColorFormatRG",                                             {"hipEglColorFormatRG",                                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 17
  // CU_EGL_COLOR_FORMAT_AYUV = 0x12
  {"cudaEglColorFormatAYUV",                                           {"hipEglColorFormatAYUV",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 18
  // CU_EGL_COLOR_FORMAT_YVU444_SEMIPLANAR = 0x13
  {"cudaEglColorFormatYVU444SemiPlanar",                               {"hipEglColorFormatYVU444SemiPlanar",                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 19
  // CU_EGL_COLOR_FORMAT_YVU422_SEMIPLANAR = 0x14
  {"cudaEglColorFormatYVU422SemiPlanar",                               {"hipEglColorFormatYVU422SemiPlanar",                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 20
  // CU_EGL_COLOR_FORMAT_YVU420_SEMIPLANAR = 0x15
  {"cudaEglColorFormatYVU420SemiPlanar",                               {"hipEglColorFormatYVU420SemiPlanar",                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 21
  // CU_EGL_COLOR_FORMAT_Y10V10U10_444_SEMIPLANAR = 0x16
  {"cudaEglColorFormatY10V10U10_444SemiPlanar",                        {"hipEglColorFormatY10V10U10_444SemiPlanar",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 22
  // CU_EGL_COLOR_FORMAT_Y10V10U10_420_SEMIPLANAR = 0x17
  {"cudaEglColorFormatY10V10U10_420SemiPlanar",                        {"hipEglColorFormatY10V10U10_420SemiPlanar",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 23
  // CU_EGL_COLOR_FORMAT_Y12V12U12_444_SEMIPLANAR = 0x18
  {"cudaEglColorFormatY12V12U12_444SemiPlanar",                        {"hipEglColorFormatY12V12U12_444SemiPlanar",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 24
  // CU_EGL_COLOR_FORMAT_Y12V12U12_420_SEMIPLANAR = 0x19
  {"cudaEglColorFormatY12V12U12_420SemiPlanar",                        {"hipEglColorFormatY12V12U12_420SemiPlanar",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 25
  // CU_EGL_COLOR_FORMAT_VYUY_ER = 0x1A
  {"cudaEglColorFormatVYUY_ER",                                        {"hipEglColorFormatVYUY_ER",                                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 26
  // CU_EGL_COLOR_FORMAT_UYVY_ER = 0x1B
  {"cudaEglColorFormatUYVY_ER",                                        {"hipEglColorFormatUYVY_ER",                                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 27
  // CU_EGL_COLOR_FORMAT_YUYV_ER = 0x1C
  {"cudaEglColorFormatYUYV_ER",                                        {"hipEglColorFormatYUYV_ER",                                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 28
  // CU_EGL_COLOR_FORMAT_YVYU_ER = 0x1D
  {"cudaEglColorFormatYVYU_ER",                                        {"hipEglColorFormatYVYU_ER",                                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 29
  // CU_EGL_COLOR_FORMAT_YUV_ER = 0x1E
  {"cudaEglColorFormatYUV_ER",                                         {"hipEglColorFormatYUV_ER",                                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 30
  // CU_EGL_COLOR_FORMAT_YUVA_ER = 0x1F
  {"cudaEglColorFormatYUVA_ER",                                        {"hipEglColorFormatYUVA_ER",                                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 31
  // CU_EGL_COLOR_FORMAT_AYUV_ER = 0x20
  {"cudaEglColorFormatAYUV_ER",                                        {"hipEglColorFormatAYUV_ER",                                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 32
  // CU_EGL_COLOR_FORMAT_YUV444_PLANAR_ER = 0x21
  {"cudaEglColorFormatYUV444Planar_ER",                                {"hipEglColorFormatYUV444Planar_ER",                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 33
  // CU_EGL_COLOR_FORMAT_YUV422_PLANAR_ER = 0x22
  {"cudaEglColorFormatYUV422Planar_ER",                                {"hipEglColorFormatYUV422Planar_ER",                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 34
  // CU_EGL_COLOR_FORMAT_YUV420_PLANAR_ER = 0x23
  {"cudaEglColorFormatYUV420Planar_ER",                                {"hipEglColorFormatYUV420Planar_ER",                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 35
  // CU_EGL_COLOR_FORMAT_YUV444_SEMIPLANAR_ER = 0x24
  {"cudaEglColorFormatYUV444SemiPlanar_ER",                            {"hipEglColorFormatYUV444SemiPlanar_ER",                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 36
  // CU_EGL_COLOR_FORMAT_YUV422_SEMIPLANAR_ER = 0x25
  {"cudaEglColorFormatYUV422SemiPlanar_ER",                            {"hipEglColorFormatYUV422SemiPlanar_ER",                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 37
  // CU_EGL_COLOR_FORMAT_YUV420_SEMIPLANAR_ER = 0x26
  {"cudaEglColorFormatYUV420SemiPlanar_ER",                            {"hipEglColorFormatYUV420SemiPlanar_ER",                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 38
  // CU_EGL_COLOR_FORMAT_YVU444_PLANAR_ER = 0x27
  {"cudaEglColorFormatYVU444Planar_ER",                                {"hipEglColorFormatYVU444Planar_ER",                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 39
  // CU_EGL_COLOR_FORMAT_YVU422_PLANAR_ER = 0x28
  {"cudaEglColorFormatYVU422Planar_ER",                                {"hipEglColorFormatYVU422Planar_ER",                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 40
  // CU_EGL_COLOR_FORMAT_YVU420_PLANAR_ER = 0x29
  {"cudaEglColorFormatYVU420Planar_ER",                                {"hipEglColorFormatYVU420Planar_ER",                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 41
  // CU_EGL_COLOR_FORMAT_YVU444_SEMIPLANAR_ER = 0x2A
  {"cudaEglColorFormatYVU444SemiPlanar_ER",                            {"hipEglColorFormatYVU444SemiPlanar_ER",                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 42
  // CU_EGL_COLOR_FORMAT_YVU422_SEMIPLANAR_ER = 0x2B
  {"cudaEglColorFormatYVU422SemiPlanar_ER",                            {"hipEglColorFormatYVU422SemiPlanar_ER",                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 43
  // CU_EGL_COLOR_FORMAT_YVU420_SEMIPLANAR_ER = 0x2C
  {"cudaEglColorFormatYVU420SemiPlanar_ER",                            {"hipEglColorFormatYVU420SemiPlanar_ER",                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 44
  // CU_EGL_COLOR_FORMAT_BAYER_RGGB = 0x2D
  {"cudaEglColorFormatBayerRGGB",                                      {"hipEglColorFormatBayerRGGB",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 45
  // CU_EGL_COLOR_FORMAT_BAYER_BGGR = 0x2E
  {"cudaEglColorFormatBayerBGGR",                                      {"hipEglColorFormatBayerBGGR",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 46
  // CU_EGL_COLOR_FORMAT_BAYER_GRBG = 0x2F
  {"cudaEglColorFormatBayerGRBG",                                      {"hipEglColorFormatBayerGRBG",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 47
  // CU_EGL_COLOR_FORMAT_BAYER_GBRG = 0x30
  {"cudaEglColorFormatBayerGBRG",                                      {"hipEglColorFormatBayerGBRG",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 48
  // CU_EGL_COLOR_FORMAT_BAYER10_RGGB = 0x31
  {"cudaEglColorFormatBayer10RGGB",                                    {"hipEglColorFormatBayer10RGGB",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 49
  // CU_EGL_COLOR_FORMAT_BAYER10_BGGR = 0x32
  {"cudaEglColorFormatBayer10BGGR",                                    {"hipEglColorFormatBayer10BGGR",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 50
  // CU_EGL_COLOR_FORMAT_BAYER10_GRBG = 0x33
  {"cudaEglColorFormatBayer10GRBG",                                    {"hipEglColorFormatBayer10GRBG",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 51
  // CU_EGL_COLOR_FORMAT_BAYER10_GBRG = 0x34
  {"cudaEglColorFormatBayer10GBRG",                                    {"hipEglColorFormatBayer10GBRG",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 52
  // CU_EGL_COLOR_FORMAT_BAYER12_RGGB = 0x35
  {"cudaEglColorFormatBayer12RGGB",                                    {"hipEglColorFormatBayer12RGGB",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 53
  // CU_EGL_COLOR_FORMAT_BAYER12_BGGR = 0x36
  {"cudaEglColorFormatBayer12BGGR",                                    {"hipEglColorFormatBayer12BGGR",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 54
  // CU_EGL_COLOR_FORMAT_BAYER12_GRBG = 0x37
  {"cudaEglColorFormatBayer12GRBG",                                    {"hipEglColorFormatBayer12GRBG",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 55
  // CU_EGL_COLOR_FORMAT_BAYER12_GBRG = 0x38
  {"cudaEglColorFormatBayer12GBRG",                                    {"hipEglColorFormatBayer12GBRG",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 56
  // CU_EGL_COLOR_FORMAT_BAYER14_RGGB = 0x39
  {"cudaEglColorFormatBayer14RGGB",                                    {"hipEglColorFormatBayer14RGGB",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 57
  // CU_EGL_COLOR_FORMAT_BAYER14_BGGR = 0x3A
  {"cudaEglColorFormatBayer14BGGR",                                    {"hipEglColorFormatBayer14BGGR",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 58
  // CU_EGL_COLOR_FORMAT_BAYER14_GRBG = 0x3B
  {"cudaEglColorFormatBayer14GRBG",                                    {"hipEglColorFormatBayer14GRBG",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 59
  // CU_EGL_COLOR_FORMAT_BAYER14_GBRG = 0x3C
  {"cudaEglColorFormatBayer14GBRG",                                    {"hipEglColorFormatBayer14GBRG",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 60
  // CU_EGL_COLOR_FORMAT_BAYER20_RGGB = 0x3D
  {"cudaEglColorFormatBayer20RGGB",                                    {"hipEglColorFormatBayer20RGGB",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 61
  // CU_EGL_COLOR_FORMAT_BAYER20_BGGR = 0x3E
  {"cudaEglColorFormatBayer20BGGR",                                    {"hipEglColorFormatBayer20BGGR",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 62
  // CU_EGL_COLOR_FORMAT_BAYER20_GRBG = 0x3F
  {"cudaEglColorFormatBayer20GRBG",                                    {"hipEglColorFormatBayer20GRBG",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 63
  // CU_EGL_COLOR_FORMAT_BAYER20_GBRG = 0x40
  {"cudaEglColorFormatBayer20GBRG",                                    {"hipEglColorFormatBayer20GBRG",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 64
  // CU_EGL_COLOR_FORMAT_YVU444_PLANAR = 0x41
  {"cudaEglColorFormatYVU444Planar",                                   {"hipEglColorFormatYVU444Planar",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 65
  // CU_EGL_COLOR_FORMAT_YVU422_PLANAR = 0x42
  {"cudaEglColorFormatYVU422Planar",                                   {"hipEglColorFormatYVU422Planar",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 66
  // CU_EGL_COLOR_FORMAT_YVU420_PLANAR = 0x43
  {"cudaEglColorFormatYVU420Planar",                                   {"hipEglColorFormatYVU420Planar",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 67
  // CU_EGL_COLOR_FORMAT_BAYER_ISP_RGGB = 0x44
  {"cudaEglColorFormatBayerIspRGGB",                                   {"hipEglColorFormatBayerIspRGGB",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 68
  // CU_EGL_COLOR_FORMAT_BAYER_ISP_BGGR = 0x45
  {"cudaEglColorFormatBayerIspBGGR",                                   {"hipEglColorFormatBayerIspBGGR",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 69
  // CU_EGL_COLOR_FORMAT_BAYER_ISP_GRBG = 0x46
  {"cudaEglColorFormatBayerIspGRBG",                                   {"hipEglColorFormatBayerIspGRBG",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 70
  // CU_EGL_COLOR_FORMAT_BAYER_ISP_GBRG = 0x47
  {"cudaEglColorFormatBayerIspGBRG",                                   {"hipEglColorFormatBayerIspGBRG",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 71

  // CUeglFrameType
  {"cudaEglFrameType",                                                 {"hipEglFrameType",                                          "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaEglFrameType enum values
  // CU_EGL_FRAME_TYPE_ARRAY
  {"cudaEglFrameTypeArray",                                            {"hipEglFrameTypeArray",                                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0
  // CU_EGL_FRAME_TYPE_PITCH
  {"cudaEglFrameTypePitch",                                            {"hipEglFrameTypePitch",                                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1

  // CUeglResourceLocationFlags
  {"cudaEglResourceLocationFlags",                                     {"hipEglResourceLocationFlags",                              "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaEglResourceLocationFlagss enum values
  // CU_EGL_RESOURCE_LOCATION_SYSMEM
  {"cudaEglResourceLocationSysmem",                                    {"hipEglResourceLocationSysmem",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x00
  // CU_EGL_RESOURCE_LOCATION_VIDMEM
  {"cudaEglResourceLocationVidmem",                                    {"hipEglResourceLocationVidmem",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x01

  // CUresult
  {"cudaError",                                                        {"hipError_t",                                               "", CONV_TYPE, API_RUNTIME, 36}},
  {"cudaError_t",                                                      {"hipError_t",                                               "", CONV_TYPE, API_RUNTIME, 36}},
  // cudaError enum values
  // CUDA_SUCCESS
  {"cudaSuccess",                                                      {"hipSuccess",                                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0
  // CUDA_ERROR_INVALID_VALUE
  {"cudaErrorInvalidValue",                                            {"hipErrorInvalidValue",                                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 1
  // CUDA_ERROR_OUT_OF_MEMORY
  {"cudaErrorMemoryAllocation",                                        {"hipErrorOutOfMemory",                                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 2
  // CUDA_ERROR_NOT_INITIALIZED
  {"cudaErrorInitializationError",                                     {"hipErrorNotInitialized",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 3
  // CUDA_ERROR_DEINITIALIZED
  {"cudaErrorCudartUnloading",                                         {"hipErrorDeinitialized",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 4
  // CUDA_ERROR_PROFILER_DISABLED
  {"cudaErrorProfilerDisabled",                                        {"hipErrorProfilerDisabled",                                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 5
  // Deprecated since CUDA 5.0
  // CUDA_ERROR_PROFILER_NOT_INITIALIZED
  {"cudaErrorProfilerNotInitialized",                                  {"hipErrorProfilerNotInitialized",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, CUDA_DEPRECATED}}, // 6
  // Deprecated since CUDA 5.0
  // CUDA_ERROR_PROFILER_ALREADY_STARTED
  {"cudaErrorProfilerAlreadyStarted",                                  {"hipErrorProfilerAlreadyStarted",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, CUDA_DEPRECATED}}, // 7
  // Deprecated since CUDA 5.0
  // CUDA_ERROR_PROFILER_ALREADY_STOPPED
  {"cudaErrorProfilerAlreadyStopped",                                  {"hipErrorProfilerAlreadyStopped",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, CUDA_DEPRECATED}}, // 8
  // no analogue
  {"cudaErrorInvalidConfiguration",                                    {"hipErrorInvalidConfiguration",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 9
  // no analogue
  {"cudaErrorInvalidPitchValue",                                       {"hipErrorInvalidPitchValue",                                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 12
  // no analogue
  {"cudaErrorInvalidSymbol",                                           {"hipErrorInvalidSymbol",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 13
  // Deprecated since CUDA 10.1
  // no analogue
  {"cudaErrorInvalidHostPointer",                                      {"hipErrorInvalidHostPointer",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED | CUDA_DEPRECATED}}, // 16
  // Deprecated since CUDA 10.1
  // no analogue
  {"cudaErrorInvalidDevicePointer",                                    {"hipErrorInvalidDevicePointer",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, CUDA_DEPRECATED}}, // 17
  // no analogue
  {"cudaErrorInvalidTexture",                                          {"hipErrorInvalidTexture",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 18
  // no analogue
  {"cudaErrorInvalidTextureBinding",                                   {"hipErrorInvalidTextureBinding",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 19
  // no analogue
  {"cudaErrorInvalidChannelDescriptor",                                {"hipErrorInvalidChannelDescriptor",                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 20
  // no analogue
  {"cudaErrorInvalidMemcpyDirection",                                  {"hipErrorInvalidMemcpyDirection",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 21
  // Deprecated since CUDA 3.1
  // no analogue
  {"cudaErrorAddressOfConstant",                                       {"hipErrorAddressOfConstant",                                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED | CUDA_DEPRECATED}}, // 22
  // Deprecated since CUDA 3.1
  // no analogue
  {"cudaErrorTextureFetchFailed",                                      {"hipErrorTextureFetchFailed",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED | CUDA_DEPRECATED}}, // 23
  // Deprecated since CUDA 3.1
  // no analogue
  {"cudaErrorTextureNotBound",                                         {"hipErrorTextureNotBound",                                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED | CUDA_DEPRECATED}}, // 24
  // Deprecated since CUDA 3.1
  // no analogue
  {"cudaErrorSynchronizationError",                                    {"hipErrorSynchronizationError",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED | CUDA_DEPRECATED}}, // 25
  // no analogue
  {"cudaErrorInvalidFilterSetting",                                    {"hipErrorInvalidFilterSetting",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 26
  // no analogue
  {"cudaErrorInvalidNormSetting",                                      {"hipErrorInvalidNormSetting",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 27
  // Deprecated since CUDA 3.1
  // no analogue
  {"cudaErrorMixedDeviceExecution",                                    {"hipErrorMixedDeviceExecution",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED | CUDA_DEPRECATED}}, // 28
  // Deprecated since CUDA 4.1
  // no analogue
  {"cudaErrorNotYetImplemented",                                       {"hipErrorNotYetImplemented",                                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED | CUDA_DEPRECATED}}, // 31
  // Deprecated since CUDA 3.1
  // no analogue
  {"cudaErrorMemoryValueTooLarge",                                     {"hipErrorMemoryValueTooLarge",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED | CUDA_DEPRECATED}}, // 32
  // CUDA_ERROR_STUB_LIBRARY
  {"cudaErrorStubLibrary",                                             {"hipErrorStubLibrary",                                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 34
  // no analogue
  {"cudaErrorInsufficientDriver",                                      {"hipErrorInsufficientDriver",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 35
  // no analogue
  {"cudaErrorCallRequiresNewerDriver",                                 {"hipErrorCallRequiresNewerDriver",                          "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 36
  // no analogue
  {"cudaErrorInvalidSurface",                                          {"hipErrorInvalidSurface",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 37
  // no analogue
  {"cudaErrorDuplicateVariableName",                                   {"hipErrorDuplicateVariableName",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 43
  // no analogue
  {"cudaErrorDuplicateTextureName",                                    {"hipErrorDuplicateTextureName",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 44
  // no analogue
  {"cudaErrorDuplicateSurfaceName",                                    {"hipErrorDuplicateSurfaceName",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 45
  // no analogue
  {"cudaErrorDevicesUnavailable",                                      {"hipErrorDevicesUnavailable",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 46
  // no analogue
  {"cudaErrorIncompatibleDriverContext",                               {"hipErrorIncompatibleDriverContext",                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 49
  // no analogue
  {"cudaErrorMissingConfiguration",                                    {"hipErrorMissingConfiguration",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 52
  // Deprecated since CUDA 3.1
  // no analogue
  {"cudaErrorPriorLaunchFailure",                                      {"hipErrorPriorLaunchFailure",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, CUDA_DEPRECATED}}, // 53
  // no analogue
  {"cudaErrorLaunchMaxDepthExceeded",                                  {"hipErrorLaunchMaxDepthExceeded",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 65
  // no analogue
  {"cudaErrorLaunchFileScopedTex",                                     {"hipErrorLaunchFileScopedTex",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 66
  // no analogue
  {"cudaErrorLaunchFileScopedSurf",                                    {"hipErrorLaunchFileScopedSurf",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 67
  // no analogue
  {"cudaErrorSyncDepthExceeded",                                       {"hipErrorSyncDepthExceeded",                                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 68
  // no analogue
  {"cudaErrorLaunchPendingCountExceeded",                              {"hipErrorLaunchPendingCountExceeded",                       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 69
  // no analogue
  {"cudaErrorInvalidDeviceFunction",                                   {"hipErrorInvalidDeviceFunction",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 98
  // CUDA_ERROR_NO_DEVICE
  {"cudaErrorNoDevice",                                                {"hipErrorNoDevice",                                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 100
  // CUDA_ERROR_INVALID_DEVICE
  {"cudaErrorInvalidDevice",                                           {"hipErrorInvalidDevice",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 101
  // CUDA_ERROR_DEVICE_NOT_LICENSED
  {"cudaErrorDeviceNotLicensed",                                       {"hipErrorDeviceNotLicensed",                                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 102
  // no analogue
  {"cudaErrorSoftwareValidityNotEstablished",                          {"hipErrorSoftwareValidityNotEstablished",                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 103
  // no analogue
  {"cudaErrorStartupFailure",                                          {"hipErrorStartupFailure",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 127
  // CUDA_ERROR_INVALID_IMAGE
  {"cudaErrorInvalidKernelImage",                                      {"hipErrorInvalidImage",                                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 200
  // CUDA_ERROR_INVALID_CONTEXT
  {"cudaErrorDeviceUninitialized",                                     {"hipErrorInvalidContext",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 201
  // Typo fixed in 10.2
  // CUDA_ERROR_INVALID_CONTEXT
  {"cudaErrorDeviceUninitilialized",                                   {"hipErrorInvalidContext",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 201
  // CUDA_ERROR_MAP_FAILED
  {"cudaErrorMapBufferObjectFailed",                                   {"hipErrorMapFailed",                                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 205
  // CUDA_ERROR_UNMAP_FAILED
  {"cudaErrorUnmapBufferObjectFailed",                                 {"hipErrorUnmapFailed",                                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 206
  // CUDA_ERROR_ARRAY_IS_MAPPED
  {"cudaErrorArrayIsMapped",                                           {"hipErrorArrayIsMapped",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 207
  // CUDA_ERROR_ALREADY_MAPPED
  {"cudaErrorAlreadyMapped",                                           {"hipErrorAlreadyMapped",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 208
  // CUDA_ERROR_NO_BINARY_FOR_GPU
  {"cudaErrorNoKernelImageForDevice",                                  {"hipErrorNoBinaryForGpu",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 209
  // CUDA_ERROR_ALREADY_ACQUIRED
  {"cudaErrorAlreadyAcquired",                                         {"hipErrorAlreadyAcquired",                                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 210
  // CUDA_ERROR_NOT_MAPPED
  {"cudaErrorNotMapped",                                               {"hipErrorNotMapped",                                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 211
  // CUDA_ERROR_NOT_MAPPED_AS_ARRAY
  {"cudaErrorNotMappedAsArray",                                        {"hipErrorNotMappedAsArray",                                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 212
  // CUDA_ERROR_NOT_MAPPED_AS_POINTER
  {"cudaErrorNotMappedAsPointer",                                      {"hipErrorNotMappedAsPointer",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 213
  // CUDA_ERROR_ECC_UNCORRECTABLE
  {"cudaErrorECCUncorrectable",                                        {"hipErrorECCNotCorrectable",                                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 214
  // CUDA_ERROR_UNSUPPORTED_LIMIT
  {"cudaErrorUnsupportedLimit",                                        {"hipErrorUnsupportedLimit",                                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 215
  // CUDA_ERROR_CONTEXT_ALREADY_IN_USE
  {"cudaErrorDeviceAlreadyInUse",                                      {"hipErrorContextAlreadyInUse",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 216
  // CUDA_ERROR_PEER_ACCESS_UNSUPPORTED
  {"cudaErrorPeerAccessUnsupported",                                   {"hipErrorPeerAccessUnsupported",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 217
  // CUDA_ERROR_INVALID_PTX
  {"cudaErrorInvalidPtx",                                              {"hipErrorInvalidKernelFile",                                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 218
  // CUDA_ERROR_INVALID_GRAPHICS_CONTEXT
  {"cudaErrorInvalidGraphicsContext",                                  {"hipErrorInvalidGraphicsContext",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 219
  // CUDA_ERROR_NVLINK_UNCORRECTABLE
  {"cudaErrorNvlinkUncorrectable",                                     {"hipErrorNvlinkUncorrectable",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 220
  // CUDA_ERROR_JIT_COMPILER_NOT_FOUND
  {"cudaErrorJitCompilerNotFound",                                     {"hipErrorJitCompilerNotFound",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 221
  // CUDA_ERROR_UNSUPPORTED_PTX_VERSION
  {"cudaErrorUnsupportedPtxVersion",                                   {"hipErrorUnsupportedPtxVersion",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 222
  // CUDA_ERROR_JIT_COMPILATION_DISABLED
  {"cudaErrorJitCompilationDisabled",                                  {"hipErrorJitCompilationDisabled",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 223
  // CUDA_ERROR_INVALID_SOURCE
  {"cudaErrorInvalidSource",                                           {"hipErrorInvalidSource",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 300
  // CUDA_ERROR_FILE_NOT_FOUND
  {"cudaErrorFileNotFound",                                            {"hipErrorFileNotFound",                                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 301
  // CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND
  {"cudaErrorSharedObjectSymbolNotFound",                              {"hipErrorSharedObjectSymbolNotFound",                       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 302
  // CUDA_ERROR_SHARED_OBJECT_INIT_FAILED
  {"cudaErrorSharedObjectInitFailed",                                  {"hipErrorSharedObjectInitFailed",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 303
  // CUDA_ERROR_OPERATING_SYSTEM
  {"cudaErrorOperatingSystem",                                         {"hipErrorOperatingSystem",                                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 304
  // CUDA_ERROR_INVALID_HANDLE
  {"cudaErrorInvalidResourceHandle",                                   {"hipErrorInvalidHandle",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 400
  // CUDA_ERROR_ILLEGAL_STATE
  {"cudaErrorIllegalState",                                            {"hipErrorIllegalState",                                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 401
  // CUDA_ERROR_NOT_FOUND
  {"cudaErrorSymbolNotFound",                                          {"hipErrorNotFound",                                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 500
  // CUDA_ERROR_NOT_READY
  {"cudaErrorNotReady",                                                {"hipErrorNotReady",                                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 600
 // CUDA_ERROR_ILLEGAL_ADDRESS
  {"cudaErrorIllegalAddress",                                          {"hipErrorIllegalAddress",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 700
  // CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES
  {"cudaErrorLaunchOutOfResources",                                    {"hipErrorLaunchOutOfResources",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 701
  // CUDA_ERROR_LAUNCH_TIMEOUT
  {"cudaErrorLaunchTimeout",                                           {"hipErrorLaunchTimeOut",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 702
  // CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING
  {"cudaErrorLaunchIncompatibleTexturing",                             {"hipErrorLaunchIncompatibleTexturing",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 703
  // CUDA_ERROR_PEER_ACCESS_ALREADY_ENABLED
  {"cudaErrorPeerAccessAlreadyEnabled",                                {"hipErrorPeerAccessAlreadyEnabled",                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 704
  // CUDA_ERROR_PEER_ACCESS_NOT_ENABLED
  {"cudaErrorPeerAccessNotEnabled",                                    {"hipErrorPeerAccessNotEnabled",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 705
  // CUDA_ERROR_PRIMARY_CONTEXT_ACTIVE
  {"cudaErrorSetOnActiveProcess",                                      {"hipErrorSetOnActiveProcess",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 708
  // CUDA_ERROR_CONTEXT_IS_DESTROYED
  {"cudaErrorContextIsDestroyed",                                      {"hipErrorContextIsDestroyed",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 709
  // CUDA_ERROR_ASSERT
  {"cudaErrorAssert",                                                  {"hipErrorAssert",                                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 710
  // CUDA_ERROR_TOO_MANY_PEERS
  {"cudaErrorTooManyPeers",                                            {"hipErrorTooManyPeers",                                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 711
  // CUDA_ERROR_HOST_MEMORY_ALREADY_REGISTERED
  {"cudaErrorHostMemoryAlreadyRegistered",                             {"hipErrorHostMemoryAlreadyRegistered",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 712
  // CUDA_ERROR_HOST_MEMORY_NOT_REGISTERED
  {"cudaErrorHostMemoryNotRegistered",                                 {"hipErrorHostMemoryNotRegistered",                          "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 713
  // CUDA_ERROR_HARDWARE_STACK_ERROR
  {"cudaErrorHardwareStackError",                                      {"hipErrorHardwareStackError",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 714
  // CUDA_ERROR_ILLEGAL_INSTRUCTION
  {"cudaErrorIllegalInstruction",                                      {"hipErrorIllegalInstruction",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 715
  // CUDA_ERROR_MISALIGNED_ADDRESS
  {"cudaErrorMisalignedAddress",                                       {"hipErrorMisalignedAddress",                                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 716
  // CUDA_ERROR_INVALID_ADDRESS_SPACE
  {"cudaErrorInvalidAddressSpace",                                     {"hipErrorInvalidAddressSpace",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 717
  // CUDA_ERROR_INVALID_PC
  {"cudaErrorInvalidPc",                                               {"hipErrorInvalidPc",                                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 718
  // CUDA_ERROR_LAUNCH_FAILED
  {"cudaErrorLaunchFailure",                                           {"hipErrorLaunchFailure",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 719
  // CUDA_ERROR_COOPERATIVE_LAUNCH_TOO_LARGE
  {"cudaErrorCooperativeLaunchTooLarge",                               {"hipErrorCooperativeLaunchTooLarge",                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 720
  // CUDA_ERROR_NOT_PERMITTED
  {"cudaErrorNotPermitted",                                            {"hipErrorNotPermitted",                                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 800
  // CUDA_ERROR_NOT_SUPPORTED
  {"cudaErrorNotSupported",                                            {"hipErrorNotSupported",                                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 801
  // CUDA_ERROR_SYSTEM_NOT_READY
  {"cudaErrorSystemNotReady",                                          {"hipErrorSystemNotReady",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 802
  // CUDA_ERROR_SYSTEM_DRIVER_MISMATCH
  {"cudaErrorSystemDriverMismatch",                                    {"hipErrorSystemDriverMismatch",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 803
  // CUDA_ERROR_COMPAT_NOT_SUPPORTED_ON_DEVICE
  {"cudaErrorCompatNotSupportedOnDevice",                              {"hipErrorCompatNotSupportedOnDevice",                       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 804
  // CUDA_ERROR_STREAM_CAPTURE_UNSUPPORTED
  {"cudaErrorStreamCaptureUnsupported",                                {"hipErrorStreamCaptureUnsupported",                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 900
  // CUDA_ERROR_STREAM_CAPTURE_INVALIDATED
  {"cudaErrorStreamCaptureInvalidated",                                {"hipErrorStreamCaptureInvalidated",                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 901
  // CUDA_ERROR_STREAM_CAPTURE_MERGE
  {"cudaErrorStreamCaptureMerge",                                      {"hipErrorStreamCaptureMerge",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 902
  // CUDA_ERROR_STREAM_CAPTURE_UNMATCHED
  {"cudaErrorStreamCaptureUnmatched",                                  {"hipErrorStreamCaptureUnmatched",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 903
  // CUDA_ERROR_STREAM_CAPTURE_UNJOINED
  {"cudaErrorStreamCaptureUnjoined",                                   {"hipErrorStreamCaptureUnjoined",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 904
  // CUDA_ERROR_STREAM_CAPTURE_ISOLATION
  {"cudaErrorStreamCaptureIsolation",                                  {"hipErrorStreamCaptureIsolation",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 905
  // CUDA_ERROR_STREAM_CAPTURE_IMPLICIT
  {"cudaErrorStreamCaptureImplicit",                                   {"hipErrorStreamCaptureImplicit",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 906
  // CUDA_ERROR_CAPTURED_EVENT
  {"cudaErrorCapturedEvent",                                           {"hipErrorCapturedEvent",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 907
  // CUDA_ERROR_STREAM_CAPTURE_WRONG_THREAD
  {"cudaErrorStreamCaptureWrongThread",                                {"hipErrorStreamCaptureWrongThread",                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 908
  // CUDA_ERROR_TIMEOUT
  {"cudaErrorTimeout",                                                 {"hipErrorTimeout",                                          "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 909
  // CUDA_ERROR_GRAPH_EXEC_UPDATE_FAILURE
  {"cudaErrorGraphExecUpdateFailure",                                  {"hipErrorGraphExecUpdateFailure",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 910
  // CUDA_ERROR_UNKNOWN
  {"cudaErrorUnknown",                                                 {"hipErrorUnknown",                                          "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 999
  // Deprecated since CUDA 4.1
  {"cudaErrorApiFailureBase",                                          {"hipErrorApiFailureBase",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED | CUDA_DEPRECATED}}, // 10000

  // CUexternalMemoryHandleType
  {"cudaExternalMemoryHandleType",                                     {"hipExternalMemoryHandleType",                              "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaExternalMemoryHandleType enum values
  // CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD
  {"cudaExternalMemoryHandleTypeOpaqueFd",                             {"hipExternalMemoryHandleTypeOpaqueFD",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  // CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32
  {"cudaExternalMemoryHandleTypeOpaqueWin32",                          {"hipExternalMemoryHandleTypeOpaqueWin32",                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2
  // CU_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT
  {"cudaExternalMemoryHandleTypeOpaqueWin32Kmt",                       {"hipExternalMemoryHandleTypeOpaqueWin32KMT",                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 3
  // CU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP
  {"cudaExternalMemoryHandleTypeD3D12Heap",                            {"hipExternalMemoryHandleTypeD3D12Heap",                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 4
  // CU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE
  {"cudaExternalMemoryHandleTypeD3D12Resource",                        {"hipExternalMemoryHandleTypeD3D12Resource",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 5
  // CU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_RESOURCE
  {"cudaExternalMemoryHandleTypeD3D11Resource",                        {"hipExternalMemoryHandleTypeD3D11Resource",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 6
  // CU_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_RESOURCE_KMT
  {"cudaExternalMemoryHandleTypeD3D11ResourceKmt",                     {"hipExternalMemoryHandleTypeD3D11ResourceKmt",              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 7
  // CU_EXTERNAL_MEMORY_HANDLE_TYPE_NVSCIBUF
  {"cudaExternalMemoryHandleTypeNvSciBuf",                             {"hipExternalMemoryHandleTypeNvSciBuf",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 8

  // CUexternalSemaphoreHandleType
  {"cudaExternalSemaphoreHandleType",                                  {"hipExternalSemaphoreHandleType",                           "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaExternalSemaphoreHandleType enum values
  // CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD
  {"cudaExternalSemaphoreHandleTypeOpaqueFd",                          {"hipExternalSemaphoreHandleTypeOpaqueFD",                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  // CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32
  {"cudaExternalSemaphoreHandleTypeOpaqueWin32",                       {"hipExternalSemaphoreHandleTypeOpaqueWin32",                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2
  // CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT
  {"cudaExternalSemaphoreHandleTypeOpaqueWin32Kmt",                    {"hipExternalSemaphoreHandleTypeOpaqueWin32KMT",             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 3
  // CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE
  {"cudaExternalSemaphoreHandleTypeD3D12Fence",                        {"hipExternalSemaphoreHandleTypeD3D12Fence",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 4
  // CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D11_FENCE
  {"cudaExternalSemaphoreHandleTypeD3D11Fence",                        {"hipExternalSemaphoreHandleTypeD3D11Fence",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 5
  // CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_NVSCISYNC
  {"cudaExternalSemaphoreHandleTypeNvSciSync",                         {"hipExternalSemaphoreHandleTypeNvSciSync",                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 6
  // CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D11_KEYED_MUTEX
  {"cudaExternalSemaphoreHandleTypeKeyedMutex",                        {"hipExternalSemaphoreHandleTypeKeyedMutex",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 7
  // CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D11_KEYED_MUTEX_KMT
  {"cudaExternalSemaphoreHandleTypeKeyedMutexKmt",                     {"hipExternalSemaphoreHandleTypeKeyedMutexKmt",              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 8
  // CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_TIMELINE_SEMAPHORE_FD
  {"cudaExternalSemaphoreHandleTypeTimelineSemaphoreFd",               {"hipExternalSemaphoreHandleTypeTimelineSemaphoreFd",        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 9
  // CU_EXTERNAL_SEMAPHORE_HANDLE_TYPE_TIMELINE_SEMAPHORE_WIN32
  {"cudaExternalSemaphoreHandleTypeTimelineSemaphoreWin32",            {"hipExternalSemaphoreHandleTypeTimelineSemaphoreWin32",     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 9

  // CUfunction_attribute
  // NOTE: only last, starting from 8, values are presented and are equal to Driver's ones
  {"cudaFuncAttribute",                                                {"hipFuncAttribute",                                         "", CONV_TYPE, API_RUNTIME, 36}},
  // cudaFuncAttribute enum values
  // CU_FUNC_ATTRIBUTE_MAX_DYNAMIC_SHARED_SIZE_BYTES
  {"cudaFuncAttributeMaxDynamicSharedMemorySize",                      {"hipFuncAttributeMaxDynamicSharedMemorySize",               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, //  8
  // CU_FUNC_ATTRIBUTE_PREFERRED_SHARED_MEMORY_CARVEOUT
  {"cudaFuncAttributePreferredSharedMemoryCarveout",                   {"hipFuncAttributePreferredSharedMemoryCarveout",            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, //  9
  // CU_FUNC_ATTRIBUTE_MAX
  {"cudaFuncAttributeMax",                                             {"hipFuncAttributeMax",                                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 10

  // CUfunc_cache
  {"cudaFuncCache",                                                    {"hipFuncCache_t",                                           "", CONV_TYPE, API_RUNTIME, 36}},
  // cudaFuncCache enum values
  // CU_FUNC_CACHE_PREFER_NONE = 0x00
  {"cudaFuncCachePreferNone",                                          {"hipFuncCachePreferNone",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0
  // CU_FUNC_CACHE_PREFER_SHARED = 0x01
  {"cudaFuncCachePreferShared",                                        {"hipFuncCachePreferShared",                                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 1
  // CU_FUNC_CACHE_PREFER_L1 = 0x02
  {"cudaFuncCachePreferL1",                                            {"hipFuncCachePreferL1",                                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 2
  // CU_FUNC_CACHE_PREFER_EQUAL = 0x03
  {"cudaFuncCachePreferEqual",                                         {"hipFuncCachePreferEqual",                                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 3

  // CUarray_cubemap_face
  {"cudaGraphicsCubeFace",                                             {"hipGraphicsCubeFace",                                      "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaGraphicsCubeFace enum values
  // CU_CUBEMAP_FACE_POSITIVE_X
  {"cudaGraphicsCubeFacePositiveX",                                    {"hipGraphicsCubeFacePositiveX",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x00
  // CU_CUBEMAP_FACE_NEGATIVE_X
  {"cudaGraphicsCubeFaceNegativeX",                                    {"hipGraphicsCubeFaceNegativeX",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x01
  // CU_CUBEMAP_FACE_POSITIVE_Y
  {"cudaGraphicsCubeFacePositiveY",                                    {"hipGraphicsCubeFacePositiveY",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x02
  // CU_CUBEMAP_FACE_NEGATIVE_Y
  {"cudaGraphicsCubeFaceNegativeY",                                    {"hipGraphicsCubeFaceNegativeY",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x03
  // CU_CUBEMAP_FACE_POSITIVE_Z
  {"cudaGraphicsCubeFacePositiveZ",                                    {"hipGraphicsCubeFacePositiveZ",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x04
  // CU_CUBEMAP_FACE_NEGATIVE_Z
  {"cudaGraphicsCubeFaceNegativeZ",                                    {"hipGraphicsCubeFaceNegativeZ",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x05

  // CUgraphicsMapResourceFlags
  {"cudaGraphicsMapFlags",                                             {"hipGraphicsMapFlags",                                      "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaGraphicsMapFlags enum values
  // CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE = 0x00
  {"cudaGraphicsMapFlagsNone",                                         {"hipGraphicsMapFlagsNone",                                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0
  // CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY = 0x01
  {"cudaGraphicsMapFlagsReadOnly",                                     {"hipGraphicsMapFlagsReadOnly",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  // CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD = 0x02
  {"cudaGraphicsMapFlagsWriteDiscard",                                 {"hipGraphicsMapFlagsWriteDiscard",                          "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2

  // CUgraphicsRegisterFlags
  {"cudaGraphicsRegisterFlags",                                        {"hipGraphicsRegisterFlags",                                 "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaGraphicsRegisterFlags enum values
  // CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE = 0x00
  {"cudaGraphicsRegisterFlagsNone",                                    {"hipGraphicsRegisterFlagsNone",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0
  // CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY = 0x01
  {"cudaGraphicsRegisterFlagsReadOnly",                                {"hipGraphicsRegisterFlagsReadOnly",                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  // CU_GRAPHICS_REGISTER_FLAGS_WRITE_DISCARD = 0x02
  {"cudaGraphicsRegisterFlagsWriteDiscard",                            {"hipGraphicsRegisterFlagsWriteDiscard",                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2
  // CU_GRAPHICS_REGISTER_FLAGS_SURFACE_LDST = 0x04
  {"cudaGraphicsRegisterFlagsSurfaceLoadStore",                        {"hipGraphicsRegisterFlagsSurfaceLoadStore",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 4
  // CU_GRAPHICS_REGISTER_FLAGS_TEXTURE_GATHER = 0x08
  {"cudaGraphicsRegisterFlagsTextureGather",                           {"hipGraphicsRegisterFlagsTextureGather",                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 8

  // CUgraphNodeType
  {"cudaGraphNodeType",                                                {"hipGraphNodeType",                                         "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaGraphNodeType enum values
  // CU_GRAPH_NODE_TYPE_KERNEL = 0
  {"cudaGraphNodeTypeKernel",                                          {"hipGraphNodeTypeKernel",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x00
  // CU_GRAPH_NODE_TYPE_MEMCPY = 1
  {"cudaGraphNodeTypeMemcpy",                                          {"hipGraphNodeTypeMemcpy",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x01
  // CU_GRAPH_NODE_TYPE_MEMSET = 2
  {"cudaGraphNodeTypeMemset",                                          {"hipGraphNodeTypeMemset",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x02
  // CU_GRAPH_NODE_TYPE_HOST = 3
  {"cudaGraphNodeTypeHost",                                            {"hipGraphNodeTypeHost",                                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x03
  // CU_GRAPH_NODE_TYPE_GRAPH = 4
  {"cudaGraphNodeTypeGraph",                                           {"hipGraphNodeTypeGraph",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x04
  // CU_GRAPH_NODE_TYPE_EMPTY = 5
  {"cudaGraphNodeTypeEmpty",                                           {"hipGraphNodeTypeEmpty",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x05
  // CU_GRAPH_NODE_TYPE_WAIT_EVENT = 6
  {"cudaGraphNodeTypeWaitEvent",                                       {"hipGraphNodeTypeWaitEvent",                                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x06
  // CU_GRAPH_NODE_TYPE_EVENT_RECORD = 7
  {"cudaGraphNodeTypeEventRecord",                                     {"hipGraphNodeTypeEventRecord",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x07
  // CU_GRAPH_NODE_TYPE_COUNT
  {"cudaGraphNodeTypeCount",                                           {"hipGraphNodeTypeCount",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUgraphExecUpdateResult
  {"cudaGraphExecUpdateResult",                                        {"hipGraphExecUpdateResult",                                 "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaGraphExecUpdateResult enum values
  // CU_GRAPH_EXEC_UPDATE_SUCCESS
  {"cudaGraphExecUpdateSuccess",                                       {"hipGraphExecUpdateSuccess",                                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x0
  // CU_GRAPH_EXEC_UPDATE_ERROR
  {"cudaGraphExecUpdateError",                                         {"hipGraphExecUpdateError",                                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x1
  // CU_GRAPH_EXEC_UPDATE_ERROR_TOPOLOGY_CHANGED
  {"cudaGraphExecUpdateErrorTopologyChanged",                          {"hipGraphExecUpdateErrorTopologyChanged",                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x2
  // CU_GRAPH_EXEC_UPDATE_ERROR_NODE_TYPE_CHANGED
  {"cudaGraphExecUpdateErrorNodeTypeChanged",                          {"hipGraphExecUpdateErrorNodeTypeChanged",                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x3
  // CU_GRAPH_EXEC_UPDATE_ERROR_FUNCTION_CHANGED
  {"cudaGraphExecUpdateErrorFunctionChanged",                          {"hipGraphExecUpdateErrorFunctionChanged",                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x4
  // CU_GRAPH_EXEC_UPDATE_ERROR_PARAMETERS_CHANGED
  {"cudaGraphExecUpdateErrorParametersChanged",                        {"hipGraphExecUpdateErrorParametersChanged",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x5
  // CU_GRAPH_EXEC_UPDATE_ERROR_NOT_SUPPORTED
  {"cudaGraphExecUpdateErrorNotSupported",                             {"hipGraphExecUpdateErrorNotSupported",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x6
  // CU_GRAPH_EXEC_UPDATE_ERROR_UNSUPPORTED_FUNCTION_CHANGE
  {"cudaGraphExecUpdateErrorUnsupportedFunctionChange",                {"hipGraphExecUpdateErrorUnsupportedFunctionChange",         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x7

  // CUlimit
  {"cudaLimit",                                                        {"hipLimit_t",                                               "", CONV_TYPE, API_RUNTIME, 36}},
  // cudaLimit enum values
  // CU_LIMIT_STACK_SIZE
  {"cudaLimitStackSize",                                               {"hipLimitStackSize",                                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x00
  // CU_LIMIT_PRINTF_FIFO_SIZE
  {"cudaLimitPrintfFifoSize",                                          {"hipLimitPrintfFifoSize",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x01
  // CU_LIMIT_MALLOC_HEAP_SIZE
  {"cudaLimitMallocHeapSize",                                          {"hipLimitMallocHeapSize",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x02
  // CU_LIMIT_DEV_RUNTIME_SYNC_DEPTH
  {"cudaLimitDevRuntimeSyncDepth",                                     {"hipLimitDevRuntimeSyncDepth",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x03
  // CU_LIMIT_DEV_RUNTIME_PENDING_LAUNCH_COUNT
  {"cudaLimitDevRuntimePendingLaunchCount",                            {"hipLimitDevRuntimePendingLaunchCount",                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x04
  // CU_LIMIT_MAX_L2_FETCH_GRANULARITY
  {"cudaLimitMaxL2FetchGranularity",                                   {"hipLimitMaxL2FetchGranularity",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x05
  // CU_LIMIT_PERSISTING_L2_CACHE_SIZE
  {"cudaLimitPersistingL2CacheSize",                                   {"hipLimitPersistingL2CacheSize",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x06

  // no analogue
  {"cudaMemcpyKind",                                                   {"hipMemcpyKind",                                            "", CONV_TYPE, API_RUNTIME, 36}},
  // cudaMemcpyKind enum values
  {"cudaMemcpyHostToHost",                                             {"hipMemcpyHostToHost",                                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0
  {"cudaMemcpyHostToDevice",                                           {"hipMemcpyHostToDevice",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 1
  {"cudaMemcpyDeviceToHost",                                           {"hipMemcpyDeviceToHost",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 2
  {"cudaMemcpyDeviceToDevice",                                         {"hipMemcpyDeviceToDevice",                                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 3
  {"cudaMemcpyDefault",                                                {"hipMemcpyDefault",                                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 4

  // CUmem_advise
  {"cudaMemoryAdvise",                                                 {"hipMemoryAdvise",                                          "", CONV_TYPE, API_RUNTIME, 36}},
  // cudaMemoryAdvise enum values
  // CU_MEM_ADVISE_SET_READ_MOSTLY
  {"cudaMemAdviseSetReadMostly",                                       {"hipMemAdviseSetReadMostly",                                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 1
  // CU_MEM_ADVISE_UNSET_READ_MOSTLY
  {"cudaMemAdviseUnsetReadMostly",                                     {"hipMemAdviseUnsetReadMostly",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 2
  // CU_MEM_ADVISE_SET_PREFERRED_LOCATION
  {"cudaMemAdviseSetPreferredLocation",                                {"hipMemAdviseSetPreferredLocation",                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 3
  // CU_MEM_ADVISE_UNSET_PREFERRED_LOCATION
  {"cudaMemAdviseUnsetPreferredLocation",                              {"hipMemAdviseUnsetPreferredLocation",                       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 4
  // CU_MEM_ADVISE_SET_ACCESSED_BY
  {"cudaMemAdviseSetAccessedBy",                                       {"hipMemAdviseSetAccessedBy",                                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 5
  // CU_MEM_ADVISE_UNSET_ACCESSED_BY
  {"cudaMemAdviseUnsetAccessedBy",                                     {"hipMemAdviseUnsetAccessedBy",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 6

  // no analogue
  // NOTE: CUmemorytype is partial analogue
  {"cudaMemoryType",                                                   {"hipMemType_t",                                             "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaMemoryType enum values
  {"cudaMemoryTypeUnregistered",                                       {"hipMemTypeUnregistered",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0
  {"cudaMemoryTypeHost",                                               {"hipMemTypeHost",                                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  {"cudaMemoryTypeDevice",                                             {"hipMemTypeDevice",                                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2
  {"cudaMemoryTypeManaged",                                            {"hipMemTypeManaged",                                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 3

  // CUmem_range_attribute
  {"cudaMemRangeAttribute",                                            {"hipMemRangeAttribute",                                     "", CONV_TYPE, API_RUNTIME, 36}},
  // cudaMemRangeAttribute enum values
  // CU_MEM_RANGE_ATTRIBUTE_READ_MOSTLY
  {"cudaMemRangeAttributeReadMostly",                                  {"hipMemRangeAttributeReadMostly",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 1
  // CU_MEM_RANGE_ATTRIBUTE_PREFERRED_LOCATION
  {"cudaMemRangeAttributePreferredLocation",                           {"hipMemRangeAttributePreferredLocation",                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 2
  // CU_MEM_RANGE_ATTRIBUTE_ACCESSED_BY
  {"cudaMemRangeAttributeAccessedBy",                                  {"hipMemRangeAttributeAccessedBy",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 3
  // CU_MEM_RANGE_ATTRIBUTE_LAST_PREFETCH_LOCATION
  {"cudaMemRangeAttributeLastPrefetchLocation",                        {"hipMemRangeAttributeLastPrefetchLocation",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 4

  // no analogue
  {"cudaOutputMode",                                                   {"hipOutputMode",                                            "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  {"cudaOutputMode_t",                                                 {"hipOutputMode",                                            "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaOutputMode enum values
  {"cudaKeyValuePair",                                                 {"hipKeyValuePair",                                          "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x00
  {"cudaCSV",                                                          {"hipCSV",                                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x01

  // CUresourcetype
  {"cudaResourceType",                                                 {"hipResourceType",                                          "", CONV_TYPE, API_RUNTIME, 36}},
  // cudaResourceType enum values
  // CU_RESOURCE_TYPE_ARRAY
  {"cudaResourceTypeArray",                                            {"hipResourceTypeArray",                                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x00
  // CU_RESOURCE_TYPE_MIPMAPPED_ARRAY
  {"cudaResourceTypeMipmappedArray",                                   {"hipResourceTypeMipmappedArray",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x01
  // CU_RESOURCE_TYPE_LINEAR
  {"cudaResourceTypeLinear",                                           {"hipResourceTypeLinear",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x02
  // CU_RESOURCE_TYPE_PITCH2D
  {"cudaResourceTypePitch2D",                                          {"hipResourceTypePitch2D",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x03

  // CUresourceViewFormat
  {"cudaResourceViewFormat",                                           {"hipResourceViewFormat",                                    "", CONV_TYPE, API_RUNTIME, 36}},
  // enum cudaResourceViewFormat
  // CU_RES_VIEW_FORMAT_NONE
  {"cudaResViewFormatNone",                                            {"hipResViewFormatNone",                                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x00
  // CU_RES_VIEW_FORMAT_UINT_1X8
  {"cudaResViewFormatUnsignedChar1",                                   {"hipResViewFormatUnsignedChar1",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x01
  // CU_RES_VIEW_FORMAT_UINT_2X8
  {"cudaResViewFormatUnsignedChar2",                                   {"hipResViewFormatUnsignedChar2",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x02
  // CU_RES_VIEW_FORMAT_UINT_4X8
  {"cudaResViewFormatUnsignedChar4",                                   {"hipResViewFormatUnsignedChar4",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x03
  // CU_RES_VIEW_FORMAT_SINT_1X8
  {"cudaResViewFormatSignedChar1",                                     {"hipResViewFormatSignedChar1",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x04
  // CU_RES_VIEW_FORMAT_SINT_2X8
  {"cudaResViewFormatSignedChar2",                                     {"hipResViewFormatSignedChar2",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x05
  // CU_RES_VIEW_FORMAT_SINT_4X8
  {"cudaResViewFormatSignedChar4",                                     {"hipResViewFormatSignedChar4",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x06
  // CU_RES_VIEW_FORMAT_UINT_1X16
  {"cudaResViewFormatUnsignedShort1",                                  {"hipResViewFormatUnsignedShort1",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x07
  // CU_RES_VIEW_FORMAT_UINT_2X16
  {"cudaResViewFormatUnsignedShort2",                                  {"hipResViewFormatUnsignedShort2",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x08
  // CU_RES_VIEW_FORMAT_UINT_4X16
  {"cudaResViewFormatUnsignedShort4",                                  {"hipResViewFormatUnsignedShort4",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x09
  // CU_RES_VIEW_FORMAT_SINT_1X16
  {"cudaResViewFormatSignedShort1",                                    {"hipResViewFormatSignedShort1",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x0a
  // CU_RES_VIEW_FORMAT_SINT_2X16
  {"cudaResViewFormatSignedShort2",                                    {"hipResViewFormatSignedShort2",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x0b
  // CU_RES_VIEW_FORMAT_SINT_4X16
  {"cudaResViewFormatSignedShort4",                                    {"hipResViewFormatSignedShort4",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x0c
  // CU_RES_VIEW_FORMAT_UINT_1X32
  {"cudaResViewFormatUnsignedInt1",                                    {"hipResViewFormatUnsignedInt1",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x0d
  // CU_RES_VIEW_FORMAT_UINT_2X32
  {"cudaResViewFormatUnsignedInt2",                                    {"hipResViewFormatUnsignedInt2",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x0e
  // CU_RES_VIEW_FORMAT_UINT_4X32
  {"cudaResViewFormatUnsignedInt4",                                    {"hipResViewFormatUnsignedInt4",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x0f
  // CU_RES_VIEW_FORMAT_SINT_1X32
  {"cudaResViewFormatSignedInt1",                                      {"hipResViewFormatSignedInt1",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x10
  // CU_RES_VIEW_FORMAT_SINT_2X32
  {"cudaResViewFormatSignedInt2",                                      {"hipResViewFormatSignedInt2",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x11
  // CU_RES_VIEW_FORMAT_SINT_4X32
  {"cudaResViewFormatSignedInt4",                                      {"hipResViewFormatSignedInt4",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x12
  // CU_RES_VIEW_FORMAT_FLOAT_1X16
  {"cudaResViewFormatHalf1",                                           {"hipResViewFormatHalf1",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x13
  // CU_RES_VIEW_FORMAT_FLOAT_2X16
  {"cudaResViewFormatHalf2",                                           {"hipResViewFormatHalf2",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x14
  // CU_RES_VIEW_FORMAT_FLOAT_4X16
  {"cudaResViewFormatHalf4",                                           {"hipResViewFormatHalf4",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x15
  // CU_RES_VIEW_FORMAT_FLOAT_1X32
  {"cudaResViewFormatFloat1",                                          {"hipResViewFormatFloat1",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x16
  // CU_RES_VIEW_FORMAT_FLOAT_2X32
  {"cudaResViewFormatFloat2",                                          {"hipResViewFormatFloat2",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x17
  // CU_RES_VIEW_FORMAT_FLOAT_4X32
  {"cudaResViewFormatFloat4",                                          {"hipResViewFormatFloat4",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x18
  // CU_RES_VIEW_FORMAT_UNSIGNED_BC1
  {"cudaResViewFormatUnsignedBlockCompressed1",                        {"hipResViewFormatUnsignedBlockCompressed1",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x19
  // CU_RES_VIEW_FORMAT_UNSIGNED_BC2
  {"cudaResViewFormatUnsignedBlockCompressed2",                        {"hipResViewFormatUnsignedBlockCompressed2",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x1a
  // CU_RES_VIEW_FORMAT_UNSIGNED_BC3
  {"cudaResViewFormatUnsignedBlockCompressed3",                        {"hipResViewFormatUnsignedBlockCompressed3",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x1b
  // CU_RES_VIEW_FORMAT_UNSIGNED_BC4
  {"cudaResViewFormatUnsignedBlockCompressed4",                        {"hipResViewFormatUnsignedBlockCompressed4",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x1c
  // CU_RES_VIEW_FORMAT_SIGNED_BC4
  {"cudaResViewFormatSignedBlockCompressed4",                          {"hipResViewFormatSignedBlockCompressed4",                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x1d
  // CU_RES_VIEW_FORMAT_UNSIGNED_BC5
  {"cudaResViewFormatUnsignedBlockCompressed5",                        {"hipResViewFormatUnsignedBlockCompressed5",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x1e
  // CU_RES_VIEW_FORMAT_SIGNED_BC5
  {"cudaResViewFormatSignedBlockCompressed5",                          {"hipResViewFormatSignedBlockCompressed5",                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x1f
  // CU_RES_VIEW_FORMAT_UNSIGNED_BC6H
  {"cudaResViewFormatUnsignedBlockCompressed6H",                       {"hipResViewFormatUnsignedBlockCompressed6H",                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x20
  // CU_RES_VIEW_FORMAT_SIGNED_BC6H
  {"cudaResViewFormatSignedBlockCompressed6H",                         {"hipResViewFormatSignedBlockCompressed6H",                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x21
  // CU_RES_VIEW_FORMAT_UNSIGNED_BC7
  {"cudaResViewFormatUnsignedBlockCompressed7",                        {"hipResViewFormatUnsignedBlockCompressed7",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0x22

  // CUshared_carveout
  {"cudaSharedCarveout",                                               {"hipSharedCarveout",                                        "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaSharedCarveout enum values
  // CU_SHAREDMEM_CARVEOUT_DEFAULT
  {"cudaSharedmemCarveoutDefault",                                     {"hipSharedmemCarveoutDefault",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // -1
  // CU_SHAREDMEM_CARVEOUT_MAX_SHARED
  {"cudaSharedmemCarveoutMaxShared",                                   {"hipSharedmemCarveoutMaxShared",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 100
  // CU_SHAREDMEM_CARVEOUT_MAX_L1
  {"cudaSharedmemCarveoutMaxL1",                                       {"hipSharedmemCarveoutMaxL1",                                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0

  // CUsharedconfig
  {"cudaSharedMemConfig",                                              {"hipSharedMemConfig",                                       "", CONV_TYPE, API_RUNTIME, 36}},
  // cudaSharedMemConfig enum values
  // CU_SHARED_MEM_CONFIG_DEFAULT_BANK_SIZE = 0x00
  {"cudaSharedMemBankSizeDefault",                                     {"hipSharedMemBankSizeDefault",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0
  // CU_SHARED_MEM_CONFIG_FOUR_BYTE_BANK_SIZE = 0x01
  {"cudaSharedMemBankSizeFourByte",                                    {"hipSharedMemBankSizeFourByte",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 1
  // CU_SHARED_MEM_CONFIG_EIGHT_BYTE_BANK_SIZE = 0x02
  {"cudaSharedMemBankSizeEightByte",                                   {"hipSharedMemBankSizeEightByte",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 2

  // CUstreamCaptureStatus
  {"cudaStreamCaptureStatus",                                          {"hipStreamCaptureStatus",                                   "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaStreamCaptureStatus enum values
  // CU_STREAM_CAPTURE_STATUS_NONE
  {"cudaStreamCaptureStatusNone",                                      {"hipStreamCaptureStatusNone",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0
  // CU_STREAM_CAPTURE_STATUS_ACTIVE
  {"cudaStreamCaptureStatusActive",                                    {"hipStreamCaptureStatusActive",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  // CU_STREAM_CAPTURE_STATUS_INVALIDATED
  {"cudaStreamCaptureStatusInvalidated",                               {"hipStreamCaptureStatusInvalidated",                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2

  // CUstreamCaptureMode
  {"cudaStreamCaptureMode",                                            {"hipStreamCaptureMode",                                     "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaStreamCaptureMode enum values
  // CU_STREAM_CAPTURE_MODE_GLOBAL
  {"cudaStreamCaptureModeGlobal",                                      {"hipStreamCaptureModeGlobal",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0
  // CU_STREAM_CAPTURE_MODE_THREAD_LOCAL
  {"cudaStreamCaptureModeThreadLocal",                                 {"hipStreamCaptureModeThreadLocal",                          "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  // CU_STREAM_CAPTURE_MODE_RELAXED
  {"cudaStreamCaptureModeRelaxed",                                     {"hipStreamCaptureModeRelaxed",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2

  // no analogue
  {"cudaSurfaceBoundaryMode",                                          {"hipSurfaceBoundaryMode",                                   "", CONV_TYPE, API_RUNTIME, 36}},
  // cudaSurfaceBoundaryMode enum values
  {"cudaBoundaryModeZero",                                             {"hipBoundaryModeZero",                                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0
  {"cudaBoundaryModeClamp",                                            {"hipBoundaryModeClamp",                                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 1
  {"cudaBoundaryModeTrap",                                             {"hipBoundaryModeTrap",                                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 2

  // no analogue
  {"cudaSurfaceFormatMode",                                            {"hipSurfaceFormatMode",                                     "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // enum cudaSurfaceFormatMode
  {"cudaFormatModeForced",                                             {"hipFormatModeForced",                                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0
  {"cudaFormatModeAuto",                                               {"hipFormatModeAuto",                                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1

  // CUaddress_mode_enum
  {"cudaTextureAddressMode",                                           {"hipTextureAddressMode",                                    "", CONV_TYPE, API_RUNTIME, 36}},
  // cudaTextureAddressMode enum values
  // CU_TR_ADDRESS_MODE_WRAP
  {"cudaAddressModeWrap",                                              {"hipAddressModeWrap",                                       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0
  // CU_TR_ADDRESS_MODE_CLAMP
  {"cudaAddressModeClamp",                                             {"hipAddressModeClamp",                                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 1
  // CU_TR_ADDRESS_MODE_MIRROR
  {"cudaAddressModeMirror",                                            {"hipAddressModeMirror",                                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 2
  // CU_TR_ADDRESS_MODE_BORDER
  {"cudaAddressModeBorder",                                            {"hipAddressModeBorder",                                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 3

  // CUfilter_mode
  {"cudaTextureFilterMode",                                            {"hipTextureFilterMode",                                     "", CONV_TYPE, API_RUNTIME, 36}},
  // cudaTextureFilterMode enum values
  // CU_TR_FILTER_MODE_POINT
  {"cudaFilterModePoint",                                              {"hipFilterModePoint",                                       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0
  // CU_TR_FILTER_MODE_LINEAR
  {"cudaFilterModeLinear",                                             {"hipFilterModeLinear",                                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 1

  // no analogue
  {"cudaTextureReadMode",                                              {"hipTextureReadMode",                                       "", CONV_TYPE, API_RUNTIME, 36}},
  // cudaTextureReadMode enum values
  {"cudaReadModeElementType",                                          {"hipReadModeElementType",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 0
  {"cudaReadModeNormalizedFloat",                                      {"hipReadModeNormalizedFloat",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36}}, // 1

  // CUGLDeviceList
  {"cudaGLDeviceList",                                                 {"hipGLDeviceList",                                          "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaGLDeviceList enum values
  // CU_GL_DEVICE_LIST_ALL = 0x01
  {"cudaGLDeviceListAll",                                              {"hipGLDeviceListAll",                                       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  // CU_GL_DEVICE_LIST_CURRENT_FRAME = 0x02
  {"cudaGLDeviceListCurrentFrame",                                     {"hipGLDeviceListCurrentFrame",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2
  // CU_GL_DEVICE_LIST_NEXT_FRAME = 0x03
  {"cudaGLDeviceListNextFrame",                                        {"hipGLDeviceListNextFrame",                                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 3

  // CUGLmap_flags
  {"cudaGLMapFlags",                                                   {"hipGLMapFlags",                                            "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaGLMapFlags enum values
  // CU_GL_MAP_RESOURCE_FLAGS_NONE = 0x00
  {"cudaGLMapFlagsNone",                                               {"hipGLMapFlagsNone",                                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0
  // CU_GL_MAP_RESOURCE_FLAGS_READ_ONLY = 0x01
  {"cudaGLMapFlagsReadOnly",                                           {"hipGLMapFlagsReadOnly",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  // CU_GL_MAP_RESOURCE_FLAGS_WRITE_DISCARD = 0x02
  {"cudaGLMapFlagsWriteDiscard",                                       {"hipGLMapFlagsWriteDiscard",                                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2

  // CUd3d9DeviceList
  {"cudaD3D9DeviceList",                                               {"hipD3D9DeviceList",                                        "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // CUd3d9DeviceList enum values
  // CU_D3D9_DEVICE_LIST_ALL = 0x01
  {"cudaD3D9DeviceListAll",                                            {"HIP_D3D9_DEVICE_LIST_ALL",                                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  // CU_D3D9_DEVICE_LIST_CURRENT_FRAME = 0x02
  {"cudaD3D9DeviceListCurrentFrame",                                   {"HIP_D3D9_DEVICE_LIST_CURRENT_FRAME",                       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2
  // CU_D3D9_DEVICE_LIST_NEXT_FRAME = 0x03
  {"cudaD3D9DeviceListNextFrame",                                      {"HIP_D3D9_DEVICE_LIST_NEXT_FRAME",                          "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 3

  // CUd3d9map_flags
  {"cudaD3D9MapFlags",                                                 {"hipD3D9MapFlags",                                          "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaD3D9MapFlags enum values
  // CU_D3D9_MAPRESOURCE_FLAGS_NONE = 0x00
  {"cudaD3D9MapFlagsNone",                                             {"HIP_D3D9_MAPRESOURCE_FLAGS_NONE",                          "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0
  // CU_D3D9_MAPRESOURCE_FLAGS_READONLY = 0x01
  {"cudaD3D9MapFlagsReadOnly",                                         {"HIP_D3D9_MAPRESOURCE_FLAGS_READONLY",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  // CU_D3D9_MAPRESOURCE_FLAGS_WRITEDISCARD = 0x02
  {"cudaD3D9MapFlagsWriteDiscard",                                     {"HIP_D3D9_MAPRESOURCE_FLAGS_WRITEDISCARD",                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2

  // CUd3d9Register_flags
  {"cudaD3D9RegisterFlags",                                            {"hipD3D9RegisterFlags",                                     "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaD3D9RegisterFlags enum values
  // CU_D3D9_REGISTER_FLAGS_NONE = 0x00
  {"cudaD3D9RegisterFlagsNone",                                        {"HIP_D3D9_REGISTER_FLAGS_NONE",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0
  // CU_D3D9_REGISTER_FLAGS_ARRAY = 0x01
  {"cudaD3D9RegisterFlagsArray",                                       {"HIP_D3D9_REGISTER_FLAGS_ARRAY",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1

  // CUd3d10DeviceList
  {"cudaD3D10DeviceList",                                              {"hipd3d10DeviceList",                                       "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaD3D10DeviceList enum values
  // CU_D3D10_DEVICE_LIST_ALL = 0x01
  {"cudaD3D10DeviceListAll",                                           {"HIP_D3D10_DEVICE_LIST_ALL",                                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  // CU_D3D10_DEVICE_LIST_CURRENT_FRAME = 0x02
  {"cudaD3D10DeviceListCurrentFrame",                                  {"HIP_D3D10_DEVICE_LIST_CURRENT_FRAME",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2
  // CU_D3D10_DEVICE_LIST_NEXT_FRAME = 0x03
  {"cudaD3D10DeviceListNextFrame",                                     {"HIP_D3D10_DEVICE_LIST_NEXT_FRAME",                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 3

  // CUd3d10map_flags
  {"cudaD3D10MapFlags",                                                {"hipD3D10MapFlags",                                         "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaD3D10MapFlags enum values
  // CU_D3D10_MAPRESOURCE_FLAGS_NONE = 0x00
  {"cudaD3D10MapFlagsNone",                                            {"HIP_D3D10_MAPRESOURCE_FLAGS_NONE",                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0
  // CU_D3D10_MAPRESOURCE_FLAGS_READONLY = 0x01
  {"cudaD3D10MapFlagsReadOnly",                                        {"HIP_D3D10_MAPRESOURCE_FLAGS_READONLY",                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  // CU_D3D10_MAPRESOURCE_FLAGS_WRITEDISCARD = 0x02
  {"cudaD3D10MapFlagsWriteDiscard",                                    {"HIP_D3D10_MAPRESOURCE_FLAGS_WRITEDISCARD",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2

  // CUd3d10Register_flags
  {"cudaD3D10RegisterFlags",                                           {"hipD3D10RegisterFlags",                                    "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaD3D10RegisterFlags enum values
  // CU_D3D10_REGISTER_FLAGS_NONE = 0x00
  {"cudaD3D10RegisterFlagsNone",                                       {"HIP_D3D10_REGISTER_FLAGS_NONE",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0
  // CU_D3D10_REGISTER_FLAGS_ARRAY = 0x01
  {"cudaD3D10RegisterFlagsArray",                                      {"HIP_D3D10_REGISTER_FLAGS_ARRAY",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1

  // CUd3d11DeviceList
  {"cudaD3D11DeviceList",                                              {"hipd3d11DeviceList",                                       "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaD3D11DeviceList enum values
  // CU_D3D11_DEVICE_LIST_ALL = 0x01
  {"cudaD3D11DeviceListAll",                                           {"HIP_D3D11_DEVICE_LIST_ALL",                                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  // CU_D3D11_DEVICE_LIST_CURRENT_FRAME = 0x02
  {"cudaD3D11DeviceListCurrentFrame",                                  {"HIP_D3D11_DEVICE_LIST_CURRENT_FRAME",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2
  // CU_D3D11_DEVICE_LIST_NEXT_FRAME = 0x03
  {"cudaD3D11DeviceListNextFrame",                                     {"HIP_D3D11_DEVICE_LIST_NEXT_FRAME",                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 3

  // no analogue
  {"libraryPropertyType",                                              {"hipLibraryPropertyType_t",                                 "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  {"libraryPropertyType_t",                                            {"hipLibraryPropertyType_t",                                 "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // no analogue
  {"MAJOR_VERSION",                                                    {"hipLibraryMajorVersion",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // no analogue
  {"MINOR_VERSION",                                                    {"hipLibraryMinorVersion",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // no analogue
  {"PATCH_LEVEL",                                                      {"hipLibraryPatchVersion",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  //
  {"cudaAccessProperty",                                               {"hipAccessProperty",                                        "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  //
  {"cudaAccessPropertyNormal",                                         {"hipAccessPropertyNormal",                                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0
  //
  {"cudaAccessPropertyStreaming",                                      {"hipAccessPropertyStreaming",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  //
  {"cudaAccessPropertyPersisting",                                     {"hipAccessPropertyPersisting",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2

  //
  {"cudaSynchronizationPolicy",                                        {"hipSynchronizationPolicy",                                 "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  //
  {"cudaSyncPolicyAuto",                                               {"hipSyncPolicyAuto",                                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  //
  {"cudaSyncPolicySpin",                                               {"hipSyncPolicySpin",                                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2
  //
  {"cudaSyncPolicyYield",                                              {"hipSyncPolicyYield",                                       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 3
  //
  {"cudaSyncPolicyBlockingSync",                                       {"hipSyncPolicyBlockingSync",                                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 4

  //
  {"cudaStreamAttrID",                                                 {"hipStreamAttrID",                                          "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  //
  {"cudaStreamAttributeAccessPolicyWindow",                            {"hipStreamAttributeAccessPolicyWindow",                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  //
  {"cudaStreamAttributeSynchronizationPolicy",                         {"hipStreamAttributeSynchronizationPolicy",                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 3

  //
  {"cudaKernelNodeAttrID",                                             {"hipKernelNodeAttrID",                                      "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  //
  {"cudaKernelNodeAttributeAccessPolicyWindow",                        {"hipKernelNodeAttributeAccessPolicyWindow",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  //
  {"cudaKernelNodeAttributeCooperative",                               {"hipKernelNodeAttributeCooperative",                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2

  // CUmemPool_attribute
  {"cudaMemPoolAttr",                                                  {"hipMemPoolAttr",                                           "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaMemPoolAttr enum values
  // CU_MEMPOOL_ATTR_REUSE_FOLLOW_EVENT_DEPENDENCIES
  {"cudaMemPoolReuseFollowEventDependencies",                          {"hipMemPoolReuseFollowEventDependencies",                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x1
  // CU_MEMPOOL_ATTR_REUSE_ALLOW_OPPORTUNISTIC
  {"cudaMemPoolReuseAllowOpportunistic",                               {"hipMemPoolReuseAllowOpportunistic",                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x2
  // CU_MEMPOOL_ATTR_REUSE_ALLOW_INTERNAL_DEPENDENCIES
  {"cudaMemPoolReuseAllowInternalDependencies",                        {"hipMemPoolReuseAllowInternalDependencies",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x3
  // CU_MEMPOOL_ATTR_RELEASE_THRESHOLD
  {"cudaMemPoolAttrReleaseThreshold",                                  {"hipMemPoolAttrReleaseThreshold",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x4
  // CU_MEMPOOL_ATTR_RESERVED_MEM_CURRENT
  {"cudaMemPoolAttrReservedMemCurrent",                                {"hipMemPoolAttrReservedMemCurrent",                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x5
  // CU_MEMPOOL_ATTR_RESERVED_MEM_HIGH
  {"cudaMemPoolAttrReservedMemHigh",                                   {"hipMemPoolAttrReservedMemHigh",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x6
  // CU_MEMPOOL_ATTR_USED_MEM_CURRENT
  {"cudaMemPoolAttrUsedMemCurrent",                                    {"hipMemPoolAttrUsedMemCurrent",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x7
  // CU_MEMPOOL_ATTR_USED_MEM_HIGH
  {"cudaMemPoolAttrUsedMemHigh",                                       {"hipMemPoolAttrUsedMemHigh",                                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x8

  // CUmemLocationType
  {"cudaMemLocationType",                                              {"hipMemoryLocationType",                                    "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaMemLocationType enum values
  // CU_MEM_LOCATION_TYPE_INVALID
  {"cudaMemLocationTypeInvalid",                                       {"hipMemoryLocationTypeInvalid",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0
  // CU_MEM_LOCATION_TYPE_DEVICE
  {"cudaMemLocationTypeDevice",                                        {"hipMemoryLocationTypeDevice",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1

  // CUmemAllocationType
  {"cudaMemAllocationType",                                            {"hipMemoryAllocationType",                                  "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // CUmemAllocationType enum values
  // CU_MEM_ALLOCATION_TYPE_INVALID
  {"cudaMemAllocationTypeInvalid",                                     {"hipMemoryAllocationTypeInvalid",                           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x0
  // CU_MEM_ALLOCATION_TYPE_PINNED
  {"cudaMemAllocationTypePinned",                                      {"hipMemoryAllocationTypePinned",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x1
  // CU_MEM_ALLOCATION_TYPE_MAX
  {"cudaMemAllocationTypeMax",                                         {"hipMemoryAllocationTypeMax",                               "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x7FFFFFFF

  // CUmemAccess_flags
  {"cudaMemAccessFlags",                                               {"hipMemoryAccessFlags",                                     "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaMemAccessFlags enum values
  // CU_MEM_ACCESS_FLAGS_PROT_NONE
  {"cudaMemAccessFlagsProtNone",                                       {"hipMemoryAccessFlagsProtNone",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0
  // CU_MEM_ACCESS_FLAGS_PROT_READ
  {"cudaMemAccessFlagsProtRead",                                       {"hipMemoryAccessFlagsProtRead",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  // CU_MEM_ACCESS_FLAGS_PROT_READWRITE
  {"cudaMemAccessFlagsProtReadWrite",                                  {"hipMemoryAccessFlagsProtReadWrite",                        "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 3

  // CUmemAllocationHandleType
  {"cudaMemAllocationHandleType",                                      {"hipMemoryAllocationHandleType",                            "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaMemAllocationHandleType enum values
  // CU_MEM_HANDLE_TYPE_NONE
  {"cudaMemHandleTypeNone",                                            {"hipMemoryHandleTypeNone",                                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0
  // CU_MEM_HANDLE_TYPE_POSIX_FILE_DESCRIPTOR
  {"cudaMemHandleTypePosixFileDescriptor",                             {"hipMemoryHandleTypePosixFileDescriptor",                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1
  // CU_MEM_HANDLE_TYPE_WIN32
  {"cudaMemHandleTypeWin32",                                           {"hipMemoryHandleTypeWin32",                                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 2
  // CU_MEM_HANDLE_TYPE_WIN32_KMT
  {"cudaMemHandleTypeWin32Kmt",                                        {"hipMemoryHandleTypeWin32Kmt",                              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 4

  // CUstreamUpdateCaptureDependencies_flags
  {"cudaStreamUpdateCaptureDependenciesFlags",                         {"hipStreamUpdateCaptureDependenciesFlags",                  "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaStreamUpdateCaptureDependenciesFlags enum values
  // CU_STREAM_ADD_CAPTURE_DEPENDENCIES
  {"cudaStreamAddCaptureDependencies",                                 {"hipStreamAddCaptureDependencies",                          "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x0
  // CU_STREAM_SET_CAPTURE_DEPENDENCIES
  {"cudaStreamSetCaptureDependencies",                                 {"hipStreamSetCaptureDependencies",                          "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x1

  // CUuserObject_flags
  {"cudaUserObjectFlags",                                              {"hipUserObjectFlags",                                       "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaUserObjectFlags enum values
  // CU_USER_OBJECT_NO_DESTRUCTOR_SYNC
  {"cudaUserObjectNoDestructorSync",                                   {"hipUserObjectNoDestructorSync",                            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x1

  // CUuserObjectRetain_flags
  {"cudaUserObjectRetainFlags",                                        {"hipUserObjectRetainFlags",                                 "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaUserObjectRetainFlags enum values
  // CU_GRAPH_USER_OBJECT_MOVE
  {"cudaGraphUserObjectMove",                                          {"hipGraphUserObjectMove",                                   "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x1

  // CUflushGPUDirectRDMAWritesOptions
  {"cudaFlushGPUDirectRDMAWritesOptions",                              {"hipFlushGPUDirectRDMAWritesOptions",                       "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaFlushGPUDirectRDMAWritesOptions enum values
  // CU_FLUSH_GPU_DIRECT_RDMA_WRITES_OPTION_HOST
  {"cudaFlushGPUDirectRDMAWritesOptionHost",                           {"hipFlushGPUDirectRDMAWritesOptionHost",                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1<<0
  // CU_FLUSH_GPU_DIRECT_RDMA_WRITES_OPTION_MEMOPS
  {"cudaFlushGPUDirectRDMAWritesOptionMemOps",                         {"hipFlushGPUDirectRDMAWritesOptionMemOps",                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1<<1

  // CUGPUDirectRDMAWritesOrdering
  {"cudaGPUDirectRDMAWritesOrdering",                                  {"hipGPUDirectRDMAWritesOrdering",                           "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaGPUDirectRDMAWritesOrdering enum values
  // CU_GPU_DIRECT_RDMA_WRITES_ORDERING_NONE
  {"cudaGPUDirectRDMAWritesOrderingNone",                              {"hipGPUDirectRDMAWritesOrderingNone",                       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0
  // CU_GPU_DIRECT_RDMA_WRITES_ORDERING_OWNER
  {"cudaGPUDirectRDMAWritesOrderingOwner",                             {"hipGPUDirectRDMAWritesOrderingOwner",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 100
  // CU_GPU_DIRECT_RDMA_WRITES_ORDERING_ALL_DEVICES
  {"cudaGPUDirectRDMAWritesOrderingAllDevices",                        {"hipGPUDirectRDMAWritesOrderingAllDevices",                 "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 200

  // CUflushGPUDirectRDMAWritesScope
  {"cudaFlushGPUDirectRDMAWritesScope",                                {"hipFlushGPUDirectRDMAWritesScope",                         "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaFlushGPUDirectRDMAWritesScope enum values
  // CU_FLUSH_GPU_DIRECT_RDMA_WRITES_TO_OWNER
  {"cudaFlushGPUDirectRDMAWritesToOwner",                              {"hipFlushGPUDirectRDMAWritesToOwner",                       "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 100
  // CU_FLUSH_GPU_DIRECT_RDMA_WRITES_TO_ALL_DEVICES
  {"cudaFlushGPUDirectRDMAWritesToAllDevices",                         {"hipFlushGPUDirectRDMAWritesToAllDevices",                  "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 200

  // CUflushGPUDirectRDMAWritesTarget
  {"cudaFlushGPUDirectRDMAWritesTarget",                               {"hipFlushGPUDirectRDMAWritesTarget",                        "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaFlushGPUDirectRDMAWritesTarget enum values
  // CU_FLUSH_GPU_DIRECT_RDMA_WRITES_TARGET_CURRENT_CTX
  {"cudaFlushGPUDirectRDMAWritesTargetCurrentDevice",                  {"hipFlushGPUDirectRDMAWritesTargetCurrentDevice",           "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // no analogue
  {"cudaGetDriverEntryPointFlags",                                     {"hipGetDriverEntryPointFlags",                              "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaGetDriverEntryPointFlags enum values
  {"cudaEnableDefault",                                                {"hipEnableDefault",                                         "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x0
  {"cudaEnableLegacyStream",                                           {"hipEnableLegacyStream",                                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x1
  {"cudaEnablePerThreadDefaultStream",                                 {"hipEnablePerThreadDefaultStream",                          "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x2

  // CUgraphDebugDot_flags
  {"cudaGraphDebugDotFlags",                                           {"hipGraphDebugDotFlags",                                    "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // cudaGraphDebugDotFlags enum values
  // CU_GRAPH_DEBUG_DOT_FLAGS_VERBOSE
  {"cudaGraphDebugDotFlagsVerbose",                                    {"hipGraphDebugDotFlagsVerbose",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1<<0
  // CU_GRAPH_DEBUG_DOT_FLAGS_KERNEL_NODE_PARAMS
  {"cudaGraphDebugDotFlagsKernelNodeParams",                           {"hipGraphDebugDotFlagsKernelNodeParams",                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1<<2
  // CU_GRAPH_DEBUG_DOT_FLAGS_MEMCPY_NODE_PARAMS
  {"cudaGraphDebugDotFlagsMemcpyNodeParams",                           {"hipGraphDebugDotFlagsMemcpyNodeParams",                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1<<3
  // CU_GRAPH_DEBUG_DOT_FLAGS_MEMSET_NODE_PARAMS
  {"cudaGraphDebugDotFlagsMemsetNodeParams",                           {"hipGraphDebugDotFlagsMemsetNodeParams",                    "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1<<4
  // CU_GRAPH_DEBUG_DOT_FLAGS_HOST_NODE_PARAMS
  {"cudaGraphDebugDotFlagsHostNodeParams",                             {"hipGraphDebugDotFlagsHostNodeParams",                      "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1<<5
  // CU_GRAPH_DEBUG_DOT_FLAGS_EVENT_NODE_PARAMS
  {"cudaGraphDebugDotFlagsEventNodeParams",                            {"hipGraphDebugDotFlagsEventNodeParams",                     "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1<<6
  // CU_GRAPH_DEBUG_DOT_FLAGS_EXT_SEMAS_SIGNAL_NODE_PARAMS
  {"cudaGraphDebugDotFlagsExtSemasSignalNodeParams",                   {"hipGraphDebugDotFlagsExtSemasSignalNodeParams",            "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1<<7
  // CU_GRAPH_DEBUG_DOT_FLAGS_EXT_SEMAS_WAIT_NODE_PARAMS
  {"cudaGraphDebugDotFlagsExtSemasWaitNodeParams",                     {"hipGraphDebugDotFlagsExtSemasWaitNodeParams",              "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1<<8
  // CU_GRAPH_DEBUG_DOT_FLAGS_KERNEL_NODE_ATTRIBUTES
  {"cudaGraphDebugDotFlagsKernelNodeAttributes",                       {"hipGraphDebugDotFlagsKernelNodeAttributes",                "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1<<9
  // CU_GRAPH_DEBUG_DOT_FLAGS_HANDLES
  {"cudaGraphDebugDotFlagsHandles",                                    {"hipGraphDebugDotFlagsHandles",                             "", CONV_NUMERIC_LITERAL, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 1<<10

  // 4. Typedefs

  // CUhostFn
  {"cudaHostFn_t",                                                     {"hipHostFn",                                                "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUstreamCallback
  {"cudaStreamCallback_t",                                             {"hipStreamCallback_t",                                      "", CONV_TYPE, API_RUNTIME, 36}},

  // CUsurfObject
  {"cudaSurfaceObject_t",                                              {"hipSurfaceObject_t",                                       "", CONV_TYPE, API_RUNTIME, 36}},

  // CUtexObject
  {"cudaTextureObject_t",                                              {"hipTextureObject_t",                                       "", CONV_TYPE, API_RUNTIME, 36}},

  // CUuuid
  {"cudaUUID_t",                                                       {"hipUUID_t",                                                "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUmemoryPool
  {"cudaMemPool_t",                                                    {"hipMemoryPool",                                            "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // CUuserObject
  {"cudaUserObject_t",                                                 {"hipUserObject_t",                                          "", CONV_TYPE, API_RUNTIME, 36, HIP_UNSUPPORTED}},

  // 5. Defines

  // no analogue
  {"CUDA_EGL_MAX_PLANES",                                              {"HIP_EGL_MAX_PLANES",                                       "", CONV_DEFINE, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 3
  // CU_IPC_HANDLE_SIZE
  {"CUDA_IPC_HANDLE_SIZE",                                             {"HIP_IPC_HANDLE_SIZE",                                      "", CONV_DEFINE, API_RUNTIME, 36}}, // 64
  // no analogue
  {"cudaArrayDefault",                                                 {"hipArrayDefault",                                          "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x00
  // CUDA_ARRAY3D_LAYERED
  {"cudaArrayLayered",                                                 {"hipArrayLayered",                                          "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x01
  // CUDA_ARRAY3D_SURFACE_LDST
  {"cudaArraySurfaceLoadStore",                                        {"hipArraySurfaceLoadStore",                                 "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x02
  // CUDA_ARRAY3D_CUBEMAP
  {"cudaArrayCubemap",                                                 {"hipArrayCubemap",                                          "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x04
  // CUDA_ARRAY3D_TEXTURE_GATHER
  {"cudaArrayTextureGather",                                           {"hipArrayTextureGather",                                    "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x08
  // CUDA_ARRAY3D_COLOR_ATTACHMENT
  {"cudaArrayColorAttachment",                                         {"hipArrayColorAttachment",                                  "", CONV_DEFINE, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x20
  // CUDA_ARRAY3D_SPARSE
  {"cudaArraySparse",                                                  {"hipArraySparse",                                           "", CONV_DEFINE, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x40
  // CUDA_COOPERATIVE_LAUNCH_MULTI_DEVICE_NO_PRE_LAUNCH_SYNC
  {"cudaCooperativeLaunchMultiDeviceNoPreSync",                        {"hipCooperativeLaunchMultiDeviceNoPreSync",                 "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x01
  // CUDA_COOPERATIVE_LAUNCH_MULTI_DEVICE_NO_POST_LAUNCH_SYNC
  {"cudaCooperativeLaunchMultiDeviceNoPostSync",                       {"hipCooperativeLaunchMultiDeviceNoPostSync",                "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x02
  // CU_DEVICE_CPU ((CUdevice)-1)
  {"cudaCpuDeviceId",                                                  {"hipCpuDeviceId",                                           "", CONV_DEFINE, API_RUNTIME, 36}}, // ((int)-1)
  // CU_DEVICE_INVALID ((CUdevice)-2)
  {"cudaInvalidDeviceId",                                              {"hipInvalidDeviceId",                                       "", CONV_DEFINE, API_RUNTIME, 36}}, // ((int)-2)
  // CU_CTX_BLOCKING_SYNC
  // NOTE: Deprecated since CUDA 4.0 and replaced with cudaDeviceScheduleBlockingSync
  {"cudaDeviceBlockingSync",                                           {"hipDeviceScheduleBlockingSync",                            "", CONV_DEFINE, API_RUNTIME, 36, CUDA_DEPRECATED}}, // 0x04
  // CU_CTX_LMEM_RESIZE_TO_MAX
  {"cudaDeviceLmemResizeToMax",                                        {"hipDeviceLmemResizeToMax",                                 "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x10
  // CU_CTX_MAP_HOST
  {"cudaDeviceMapHost",                                                {"hipDeviceMapHost",                                         "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x08
  // CU_CTX_FLAGS_MASK
  {"cudaDeviceMask",                                                   {"hipDeviceMask",                                            "", CONV_DEFINE, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x1f
  // no analogue
  {"cudaDevicePropDontCare",                                           {"hipDevicePropDontCare",                                    "", CONV_DEFINE, API_RUNTIME, 36, HIP_UNSUPPORTED}},
  // CU_CTX_SCHED_AUTO
  {"cudaDeviceScheduleAuto",                                           {"hipDeviceScheduleAuto",                                    "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x00
  // CU_CTX_SCHED_SPIN
  {"cudaDeviceScheduleSpin",                                           {"hipDeviceScheduleSpin",                                    "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x01
  // CU_CTX_SCHED_YIELD
  {"cudaDeviceScheduleYield",                                          {"hipDeviceScheduleYield",                                   "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x02
  // CU_CTX_SCHED_BLOCKING_SYNC
  {"cudaDeviceScheduleBlockingSync",                                   {"hipDeviceScheduleBlockingSync",                            "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x04
  // CU_CTX_SCHED_MASK
  {"cudaDeviceScheduleMask",                                           {"hipDeviceScheduleMask",                                    "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x07
  // CU_EVENT_DEFAULT
  {"cudaEventDefault",                                                 {"hipEventDefault",                                          "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x00
  // CU_EVENT_BLOCKING_SYNC
  {"cudaEventBlockingSync",                                            {"hipEventBlockingSync",                                     "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x01
  // CU_EVENT_DISABLE_TIMING
  {"cudaEventDisableTiming",                                           {"hipEventDisableTiming",                                    "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x02
  // CU_EVENT_INTERPROCESS
  {"cudaEventInterprocess",                                            {"hipEventInterprocess",                                     "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x04
  // CU_EVENT_RECORD_DEFAULT
  {"cudaEventRecordDefault",                                           {"hipEventRecordDefault",                                    "", CONV_DEFINE, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x00
  // CU_EVENT_RECORD_EXTERNAL
  {"cudaEventRecordExternal",                                          {"hipEventRecordExternal",                                   "", CONV_DEFINE, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x01
  // CU_EVENT_WAIT_DEFAULT
  {"cudaEventWaitDefault",                                             {"hipEventWaitDefault",                                      "", CONV_DEFINE, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x00
  // CU_EVENT_WAIT_EXTERNAL
  {"cudaEventWaitExternal",                                            {"hipEventWaitExternal",                                     "", CONV_DEFINE, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x01
  // CUDA_EXTERNAL_MEMORY_DEDICATED
  {"cudaExternalMemoryDedicated",                                      {"hipExternalMemoryDedicated",                               "", CONV_DEFINE, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x1
  // CUDA_EXTERNAL_SEMAPHORE_SIGNAL_SKIP_NVSCIBUF_MEMSYNC
  {"cudaExternalSemaphoreSignalSkipNvSciBufMemSync",                   {"hipExternalSemaphoreSignalSkipNvSciBufMemSync",            "", CONV_DEFINE, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x01
  // CUDA_EXTERNAL_SEMAPHORE_WAIT_SKIP_NVSCIBUF_MEMSYNC
  {"cudaExternalSemaphoreWaitSkipNvSciBufMemSync",                     {"hipExternalSemaphoreWaitSkipNvSciBufMemSync",              "", CONV_DEFINE, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x02
  // CUDA_NVSCISYNC_ATTR_SIGNAL
  {"cudaNvSciSyncAttrSignal",                                          {"hipNvSciSyncAttrSignal",                                   "", CONV_DEFINE, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x1
  // CUDA_NVSCISYNC_ATTR_WAIT
  {"cudaNvSciSyncAttrWait",                                            {"hipNvSciSyncAttrWait",                                     "", CONV_DEFINE, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x2
  // no analogue
  {"cudaHostAllocDefault",                                             {"hipHostMallocDefault",                                     "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x00
  // CU_MEMHOSTALLOC_PORTABLE
  {"cudaHostAllocPortable",                                            {"hipHostMallocPortable",                                    "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x01
  // CU_MEMHOSTALLOC_DEVICEMAP
  {"cudaHostAllocMapped",                                              {"hipHostMallocMapped",                                      "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x02
  // CU_MEMHOSTALLOC_WRITECOMBINED
  {"cudaHostAllocWriteCombined",                                       {"hipHostMallocWriteCombined",                               "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x04
  // no analogue
  {"cudaHostRegisterDefault",                                          {"hipHostRegisterDefault",                                   "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x00
  // CU_MEMHOSTREGISTER_PORTABLE
  {"cudaHostRegisterPortable",                                         {"hipHostRegisterPortable",                                  "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x01
  // CU_MEMHOSTREGISTER_DEVICEMAP
  {"cudaHostRegisterMapped",                                           {"hipHostRegisterMapped",                                    "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x02
  // CU_MEMHOSTREGISTER_IOMEMORY
  {"cudaHostRegisterIoMemory",                                         {"hipHostRegisterIoMemory",                                  "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x04
  // CU_MEMHOSTREGISTER_READ_ONLY
  {"cudaHostRegisterReadOnly",                                         {"hipHostRegisterReadOnly",                                  "", CONV_DEFINE, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x08
  // CU_IPC_MEM_LAZY_ENABLE_PEER_ACCESS
  {"cudaIpcMemLazyEnablePeerAccess",                                   {"hipIpcMemLazyEnablePeerAccess",                            "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x01
  // CU_MEM_ATTACH_GLOBAL
  {"cudaMemAttachGlobal",                                              {"hipMemAttachGlobal",                                       "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x01
  // CU_MEM_ATTACH_HOST
  {"cudaMemAttachHost",                                                {"hipMemAttachHost",                                         "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x02
  // CU_MEM_ATTACH_SINGLE
  {"cudaMemAttachSingle",                                              {"hipMemAttachSingle",                                       "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x04
  // no analogue
  {"cudaTextureType1D",                                                {"hipTextureType1D",                                         "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x01
  // no analogue
  {"cudaTextureType2D",                                                {"hipTextureType2D",                                         "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x02
  // no analogue
  {"cudaTextureType3D",                                                {"hipTextureType3D",                                         "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x03
  // no analogue
  {"cudaTextureTypeCubemap",                                           {"hipTextureTypeCubemap",                                    "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x0C
  // no analogue
  {"cudaTextureType1DLayered",                                         {"hipTextureType1DLayered",                                  "", CONV_DEFINE, API_RUNTIME, 36}}, // 0xF1
  // no analogue
  {"cudaTextureType2DLayered",                                         {"hipTextureType2DLayered",                                  "", CONV_DEFINE, API_RUNTIME, 36}}, // 0xF2
  // no analogue
  {"cudaTextureTypeCubemapLayered",                                    {"hipTextureTypeCubemapLayered",                             "", CONV_DEFINE, API_RUNTIME, 36}}, // 0xFC
  // CU_OCCUPANCY_DEFAULT
  {"cudaOccupancyDefault",                                             {"hipOccupancyDefault",                                      "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x00
  // CU_OCCUPANCY_DISABLE_CACHING_OVERRIDE
  {"cudaOccupancyDisableCachingOverride",                              {"hipOccupancyDisableCachingOverride",                       "", CONV_DEFINE, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x01
  // CU_STREAM_DEFAULT
  {"cudaStreamDefault",                                                {"hipStreamDefault",                                         "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x00
  // CU_STREAM_NON_BLOCKING
  {"cudaStreamNonBlocking",                                            {"hipStreamNonBlocking",                                     "", CONV_DEFINE, API_RUNTIME, 36}}, // 0x01
  // CU_STREAM_LEGACY ((CUstream)0x1)
  {"cudaStreamLegacy",                                                 {"hipStreamLegacy",                                          "", CONV_DEFINE, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // ((cudaStream_t)0x1)
  // CU_STREAM_PER_THREAD ((CUstream)0x2)
  {"cudaStreamPerThread",                                              {"hipStreamPerThread",                                       "", CONV_DEFINE, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // ((cudaStream_t)0x2)
  // CU_ARRAY_SPARSE_PROPERTIES_SINGLE_MIPTAIL
  {"cudaArraySparsePropertiesSingleMipTail",                           {"hipArraySparsePropertiesSingleMipTail",                    "", CONV_DEFINE, API_RUNTIME, 36, HIP_UNSUPPORTED}}, // 0x1
};

const std::map<llvm::StringRef, cudaAPIversions> CUDA_RUNTIME_TYPE_NAME_VER_MAP {
  {"cudaEglFrame",                                                     {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglFrame_st",                                                  {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglPlaneDesc",                                                 {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglPlaneDesc_st",                                              {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaExternalMemoryBufferDesc",                                     {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalMemoryHandleDesc",                                     {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalMemoryMipmappedArrayDesc",                             {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreHandleDesc",                                  {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreSignalParams",                                {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreWaitParams",                                  {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaHostNodeParams",                                               {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaKernelNodeParams",                                             {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaLaunchParams",                                                 {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaMemsetParams",                                                 {CUDA_100, CUDA_0,   CUDA_0  }},
  {"CUexternalMemory_st",                                              {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalMemory_t",                                             {CUDA_100, CUDA_0,   CUDA_0  }},
  {"CUexternalSemaphore_st",                                           {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphore_t",                                          {CUDA_100, CUDA_0,   CUDA_0  }},
  {"CUgraph_st",                                                       {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaGraph_t",                                                      {CUDA_100, CUDA_0,   CUDA_0  }},
  {"CUgraphExec_st",                                                   {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaGraphExec_t",                                                  {CUDA_100, CUDA_0,   CUDA_0  }},
  {"CUgraphNode_st",                                                   {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaGraphNode_t",                                                  {CUDA_100, CUDA_0,   CUDA_0  }},
  {"CUeglStreamConnection_st",                                         {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglStreamConnection",                                          {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaFunction_t",                                                   {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaAccessPolicyWindow",                                           {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaStreamAttrValue",                                              {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaKernelNodeAttrValue",                                          {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaCGScope",                                                      {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaCGScopeInvalid",                                               {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaCGScopeGrid",                                                  {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaCGScopeMultiGrid",                                             {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaDevAttrHostNativeAtomicSupported",                             {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaDevAttrSingleToDoublePrecisionPerfRatio",                      {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaDevAttrPageableMemoryAccess",                                  {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaDevAttrConcurrentManagedAccess",                               {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaDevAttrComputePreemptionSupported",                            {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaDevAttrCanUseHostPointerForRegisteredMem",                     {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaDevAttrReserved92",                                            {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaDevAttrReserved93",                                            {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaDevAttrReserved94",                                            {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaDevAttrCooperativeLaunch",                                     {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaDevAttrCooperativeMultiDeviceLaunch",                          {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaDevAttrMaxSharedMemoryPerBlockOptin",                          {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaDevAttrCanFlushRemoteWrites",                                  {CUDA_92,  CUDA_0,   CUDA_0  }},
  {"cudaDevAttrHostRegisterSupported",                                 {CUDA_92,  CUDA_0,   CUDA_0  }},
  {"cudaDevAttrPageableMemoryAccessUsesHostPageTables",                {CUDA_92,  CUDA_0,   CUDA_0  }},
  {"cudaDevAttrDirectManagedMemAccessFromHost",                        {CUDA_92,  CUDA_0,   CUDA_0  }},
  {"cudaDevAttrMaxBlocksPerMultiprocessor",                            {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaDevAttrReservedSharedMemoryPerBlock",                          {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaDeviceP2PAttr",                                                {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaDevP2PAttrPerformanceRank",                                    {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaDevP2PAttrAccessSupported",                                    {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaDevP2PAttrNativeAtomicSupported",                              {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaDevP2PAttrCudaArrayAccessSupported",                           {CUDA_92,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormat",                                               {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYUV420Planar",                                   {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYUV420SemiPlanar",                               {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYUV422Planar",                                   {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYUV422SemiPlanar",                               {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatRGB",                                            {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBGR",                                            {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatARGB",                                           {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatRGBA",                                           {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatL",                                              {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatR",                                              {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYUV444Planar",                                   {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYUV444SemiPlanar",                               {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYUYV422",                                        {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatUYVY422",                                        {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatABGR",                                           {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBGRA",                                           {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatA",                                              {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatRG",                                             {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatAYUV",                                           {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYVU444SemiPlanar",                               {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYVU422SemiPlanar",                               {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYVU420SemiPlanar",                               {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatY10V10U10_444SemiPlanar",                        {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatY10V10U10_420SemiPlanar",                        {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatY12V12U12_444SemiPlanar",                        {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatY12V12U12_420SemiPlanar",                        {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatVYUY_ER",                                        {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatUYVY_ER",                                        {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYUYV_ER",                                        {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYVYU_ER",                                        {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYUV_ER",                                         {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYUVA_ER",                                        {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatAYUV_ER",                                        {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYUV444Planar_ER",                                {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYUV422Planar_ER",                                {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYUV420Planar_ER",                                {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYUV444SemiPlanar_ER",                            {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYUV422SemiPlanar_ER",                            {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYUV420SemiPlanar_ER",                            {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYVU444Planar_ER",                                {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYVU422Planar_ER",                                {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYVU420Planar_ER",                                {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYVU444SsemiPlanar_ER",                           {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYVU422SemiPlanar_ER",                            {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYVU420SemiPlanar_ER",                            {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayerRGGB",                                      {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayerBGGR",                                      {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayerGRBG",                                      {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayerGBRG",                                      {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayer10RGGB",                                    {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayer10BGGR",                                    {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayer10GRBG",                                    {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayer10GBRG",                                    {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayer12RGGB",                                    {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayer12BGGR",                                    {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayer12GRBG",                                    {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayer12GBRG",                                    {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayer14RGGB",                                    {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayer14BGGR",                                    {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayer14GRBG",                                    {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayer14GBRG",                                    {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayer20RGGB",                                    {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayer20BGGR",                                    {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayer20GRBG",                                    {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayer20GBRG",                                    {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYVU444Planar",                                   {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYVU422Planar",                                   {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatYVU420Planar",                                   {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayerIspRGGB",                                   {CUDA_92,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayerIspBGGR",                                   {CUDA_92,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayerIspGRBG",                                   {CUDA_92,  CUDA_0,   CUDA_0  }},
  {"cudaEglColorFormatBayerIspGBRG",                                   {CUDA_92,  CUDA_0,   CUDA_0  }},
  {"cudaEglFrameType",                                                 {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglFrameTypeArray",                                            {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglFrameTypePitch",                                            {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglResourceLocationFlags",                                     {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglResourceLocationSysmem",                                    {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaEglResourceLocationVidmem",                                    {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaErrorProfilerNotInitialized",                                  {CUDA_0,   CUDA_50,  CUDA_0  }},
  {"cudaErrorProfilerAlreadyStarted",                                  {CUDA_0,   CUDA_50,  CUDA_0  }},
  {"cudaErrorProfilerAlreadyStopped",                                  {CUDA_0,   CUDA_50,  CUDA_0  }},
  {"cudaErrorInvalidHostPointer",                                      {CUDA_0,   CUDA_101, CUDA_0  }},
  {"cudaErrorInvalidDevicePointer",                                    {CUDA_0,   CUDA_101, CUDA_0  }},
  {"cudaErrorAddressOfConstant",                                       {CUDA_0,   CUDA_31,  CUDA_0  }},
  {"cudaErrorTextureFetchFailed",                                      {CUDA_0,   CUDA_31,  CUDA_0  }},
  {"cudaErrorTextureNotBound",                                         {CUDA_0,   CUDA_31,  CUDA_0  }},
  {"cudaErrorSynchronizationError",                                    {CUDA_0,   CUDA_31,  CUDA_0  }},
  {"cudaErrorMixedDeviceExecution",                                    {CUDA_0,   CUDA_31,  CUDA_0  }},
  {"cudaErrorNotYetImplemented",                                       {CUDA_0,   CUDA_41,  CUDA_0  }},
  {"cudaErrorMemoryValueTooLarge",                                     {CUDA_0,   CUDA_31,  CUDA_0  }},
  {"cudaErrorPriorLaunchFailure",                                      {CUDA_0,   CUDA_31,  CUDA_0  }},
  {"cudaErrorDeviceUninitilialized",                                   {CUDA_101, CUDA_0,   CUDA_102}},
  {"cudaErrorArrayIsMapped",                                           {CUDA_101, CUDA_0,   CUDA_0  }},
  {"cudaErrorAlreadyMapped",                                           {CUDA_101, CUDA_0,   CUDA_0  }},
  {"cudaErrorDeviceUninitialized",                                     {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaErrorAlreadyAcquired",                                         {CUDA_101, CUDA_0,   CUDA_0  }},
  {"cudaErrorNotMapped",                                               {CUDA_101, CUDA_0,   CUDA_0  }},
  {"cudaErrorNotMappedAsArray",                                        {CUDA_101, CUDA_0,   CUDA_0  }},
  {"cudaErrorNotMappedAsPointer",                                      {CUDA_101, CUDA_0,   CUDA_0  }},
  {"cudaErrorNvlinkUncorrectable",                                     {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaErrorJitCompilerNotFound",                                     {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaErrorInvalidSource",                                           {CUDA_101, CUDA_0,   CUDA_0  }},
  {"cudaErrorFileNotFound",                                            {CUDA_101, CUDA_0,   CUDA_0  }},
  {"cudaErrorIllegalState",                                            {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaErrorSymbolNotFound",                                          {CUDA_101, CUDA_0,   CUDA_0  }},
  {"cudaErrorLaunchIncompatibleTexturing",                             {CUDA_101, CUDA_0,   CUDA_0  }},
  {"cudaErrorContextIsDestroyed",                                      {CUDA_101, CUDA_0,   CUDA_0  }},
  {"cudaErrorCooperativeLaunchTooLarge",                               {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaErrorSystemNotReady",                                          {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaErrorSystemDriverMismatch",                                    {CUDA_101, CUDA_0,   CUDA_0  }},
  {"cudaErrorCompatNotSupportedOnDevice",                              {CUDA_101, CUDA_0,   CUDA_0  }},
  {"cudaErrorStreamCaptureUnsupported",                                {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaErrorStreamCaptureInvalidated",                                {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaErrorStreamCaptureMerge",                                      {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaErrorStreamCaptureUnmatched",                                  {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaErrorStreamCaptureUnjoined",                                   {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaErrorStreamCaptureIsolation",                                  {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaErrorStreamCaptureImplicit",                                   {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaErrorCapturedEvent",                                           {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaErrorStreamCaptureWrongThread",                                {CUDA_101, CUDA_0,   CUDA_0  }},
  {"cudaErrorTimeout",                                                 {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaErrorGraphExecUpdateFailure",                                  {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaErrorApiFailureBase",                                          {CUDA_0,   CUDA_41,  CUDA_0  }},
  {"cudaExternalMemoryHandleType",                                     {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalMemoryHandleTypeOpaqueFd",                             {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalMemoryHandleTypeOpaqueWin32",                          {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalMemoryHandleTypeOpaqueWin32Kmt",                       {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalMemoryHandleTypeD3D12Heap",                            {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalMemoryHandleTypeD3D12Resource",                        {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalMemoryHandleTypeD3D11Resource",                        {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalMemoryHandleTypeD3D11ResourceKmt",                     {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaExternalMemoryHandleTypeNvSciBuf",                             {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreHandleType",                                  {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreHandleTypeOpaqueFd",                          {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreHandleTypeOpaqueWin32",                       {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreHandleTypeOpaqueWin32Kmt",                    {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreHandleTypeD3D12Fence",                        {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreHandleTypeD3D11Fence",                        {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreHandleTypeNvSciSync",                         {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreHandleTypeKeyedMutex",                        {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreHandleTypeKeyedMutexKmt",                     {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaFuncAttribute",                                                {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaFuncAttributeMaxDynamicSharedMemorySize",                      {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaFuncAttributePreferredSharedMemoryCarveout",                   {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaFuncAttributeMax",                                             {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaGraphNodeType",                                                {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaGraphNodeTypeKernel",                                          {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaGraphNodeTypeMemcpy",                                          {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaGraphNodeTypeMemset",                                          {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaGraphNodeTypeHost",                                            {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaGraphNodeTypeGraph",                                           {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaGraphNodeTypeEmpty",                                           {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaGraphNodeTypeCount",                                           {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaGraphExecUpdateResult",                                        {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaGraphExecUpdateSuccess",                                       {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaGraphExecUpdateError",                                         {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaGraphExecUpdateErrorTopologyChanged",                          {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaGraphExecUpdateErrorNodeTypeChanged",                          {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaGraphExecUpdateErrorFunctionChanged",                          {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaGraphExecUpdateErrorParametersChanged",                        {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaGraphExecUpdateErrorNotSupported",                             {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaLimitMaxL2FetchGranularity",                                   {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaLimitPersistingL2CacheSize",                                   {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaMemoryAdvise",                                                 {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaMemAdviseSetReadMostly",                                       {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaMemAdviseUnsetReadMostly",                                     {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaMemAdviseSetPreferredLocation",                                {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaMemAdviseUnsetPreferredLocation",                              {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaMemAdviseSetAccessedBy",                                       {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaMemAdviseUnsetAccessedBy",                                     {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaMemoryTypeManaged",                                            {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaMemRangeAttribute",                                            {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaMemRangeAttributeReadMostly",                                  {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaMemRangeAttributePreferredLocation",                           {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaMemRangeAttributeAccessedBy",                                  {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaMemRangeAttributeLastPrefetchLocation",                        {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaSharedCarveout",                                               {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaSharedmemCarveoutDefault",                                     {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaSharedmemCarveoutMaxShared",                                   {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaSharedmemCarveoutMaxL1",                                       {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaStreamCaptureStatus",                                          {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaStreamCaptureStatusNone",                                      {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaStreamCaptureStatusActive",                                    {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaStreamCaptureStatusInvalidated",                               {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaStreamCaptureMode",                                            {CUDA_101, CUDA_0,   CUDA_0  }},
  {"cudaStreamCaptureModeGlobal",                                      {CUDA_101, CUDA_0,   CUDA_0  }},
  {"cudaStreamCaptureModeThreadLocal",                                 {CUDA_101, CUDA_0,   CUDA_0  }},
  {"cudaStreamCaptureModeRelaxed",                                     {CUDA_101, CUDA_0,   CUDA_0  }},
  {"libraryPropertyType",                                              {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"libraryPropertyType_t",                                            {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"MAJOR_VERSION",                                                    {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"MINOR_VERSION",                                                    {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"PATCH_LEVEL",                                                      {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaAccessProperty",                                               {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaAccessPropertyNormal",                                         {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaAccessPropertyStreaming",                                      {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaAccessPropertyPersisting",                                     {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaSynchronizationPolicy",                                        {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaSyncPolicyAuto",                                               {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaSyncPolicySpin",                                               {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaSyncPolicyYield",                                              {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaSyncPolicyBlockingSync",                                       {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaStreamAttrID",                                                 {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaStreamAttributeAccessPolicyWindow",                            {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaStreamAttributeSynchronizationPolicy",                         {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaKernelNodeAttrID",                                             {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaKernelNodeAttributeAccessPolicyWindow",                        {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaKernelNodeAttributeCooperative",                               {CUDA_110, CUDA_0,   CUDA_0  }},
  {"cudaHostFn_t",                                                     {CUDA_100, CUDA_0,   CUDA_0  }},
  {"CUDA_EGL_MAX_PLANES",                                              {CUDA_91,  CUDA_0,   CUDA_0  }},
  {"cudaArrayColorAttachment",                                         {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaCooperativeLaunchMultiDeviceNoPreSync",                        {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaCooperativeLaunchMultiDeviceNoPostSync",                       {CUDA_90,  CUDA_0,   CUDA_0  }},
  {"cudaCpuDeviceId",                                                  {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaInvalidDeviceId",                                              {CUDA_80,  CUDA_0,   CUDA_0  }},
  {"cudaExternalMemoryDedicated",                                      {CUDA_100, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreSignalSkipNvSciBufMemSync",                   {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreWaitSkipNvSciBufMemSync",                     {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaNvSciSyncAttrSignal",                                          {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaNvSciSyncAttrWait",                                            {CUDA_102, CUDA_0,   CUDA_0  }},
  {"cudaHostRegisterIoMemory",                                         {CUDA_75,  CUDA_0,   CUDA_0  }},
  {"cudaHostRegisterReadOnly",                                         {CUDA_111, CUDA_0,   CUDA_0  }},
  {"cudaEventRecordDefault",                                           {CUDA_111, CUDA_0,   CUDA_0  }},
  {"cudaEventRecordExternal",                                          {CUDA_111, CUDA_0,   CUDA_0  }},
  {"cudaEventWaitDefault",                                             {CUDA_111, CUDA_0,   CUDA_0  }},
  {"cudaEventRecordExternal",                                          {CUDA_111, CUDA_0,   CUDA_0  }},
  {"cudaArraySparse",                                                  {CUDA_111, CUDA_0,   CUDA_0  }},
  {"cudaErrorStubLibrary",                                             {CUDA_111, CUDA_0,   CUDA_0  }},
  {"cudaErrorCallRequiresNewerDriver",                                 {CUDA_111, CUDA_0,   CUDA_0  }},
  {"cudaErrorDeviceNotLicensed",                                       {CUDA_111, CUDA_0,   CUDA_0  }},
  {"cudaErrorUnsupportedPtxVersion",                                   {CUDA_111, CUDA_0,   CUDA_0  }},
  {"cudaArraySparsePropertiesSingleMipTail",                           {CUDA_111, CUDA_0,   CUDA_0  }},
  {"cudaArraySparseProperties",                                        {CUDA_111, CUDA_0,   CUDA_0  }},
  {"cudaDevAttrSparseCudaArraySupported",                              {CUDA_111, CUDA_0,   CUDA_0  }},
  {"cudaDevAttrHostRegisterReadOnlySupported",                         {CUDA_111, CUDA_0,   CUDA_0  }},
  {"cudaGraphNodeTypeWaitEvent",                                       {CUDA_111, CUDA_0,   CUDA_0  }},
  {"cudaGraphNodeTypeEventRecord",                                     {CUDA_111, CUDA_0,   CUDA_0  }},
  {"cudaErrorSoftwareValidityNotEstablished",                          {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaErrorJitCompilationDisabled",                                  {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaChannelFormatKindNV12",                                        {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaDevAttrMaxTimelineSemaphoreInteropSupported",                  {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaDevAttrMemoryPoolsSupported",                                  {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemPoolAttr",                                                  {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemPoolReuseFollowEventDependencies",                          {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemPoolReuseAllowOpportunistic",                               {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemPoolReuseAllowInternalDependencies",                        {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemPoolAttrReleaseThreshold",                                  {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemLocationType",                                              {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemLocationTypeInvalid",                                       {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemLocationTypeDevice",                                        {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemLocation",                                                  {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemAccessFlags",                                               {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemAccessFlagsProtNone",                                       {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemAccessFlagsProtRead",                                       {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemAccessFlagsProtReadWrite",                                  {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemAccessDesc",                                                {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemAllocationType",                                            {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemAllocationTypeInvalid",                                     {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemAllocationTypePinned",                                      {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemAllocationTypeMax",                                         {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemAllocationHandleType",                                      {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemHandleTypeNone",                                            {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemHandleTypePosixFileDescriptor",                             {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemHandleTypeWin32",                                           {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemHandleTypeWin32Kmt",                                        {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemPoolProps",                                                 {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemPoolPtrExportData",                                         {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreHandleTypeTimelineSemaphoreFd",               {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreHandleTypeTimelineSemaphoreWin32",            {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreSignalParams_v1",                             {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreWaitParams_v1",                               {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaMemPool_t",                                                    {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreSignalNodeParams",                            {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaExternalSemaphoreWaitNodeParams",                              {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaGraphExecUpdateErrorUnsupportedFunctionChange",                {CUDA_112, CUDA_0,   CUDA_0  }},
  {"cudaStreamUpdateCaptureDependenciesFlags",                         {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaStreamAddCaptureDependencies",                                 {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaStreamSetCaptureDependencies",                                 {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaUserObjectFlags",                                              {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaUserObjectNoDestructorSync",                                   {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaUserObjectRetainFlags",                                        {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaGraphUserObjectMove",                                          {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaFlushGPUDirectRDMAWritesOptions",                              {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaFlushGPUDirectRDMAWritesOptionHost",                           {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaFlushGPUDirectRDMAWritesOptionMemOps",                         {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaGPUDirectRDMAWritesOrdering",                                  {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaGPUDirectRDMAWritesOrderingNone",                              {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaGPUDirectRDMAWritesOrderingOwner",                             {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaGPUDirectRDMAWritesOrderingAllDevices",                        {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaFlushGPUDirectRDMAWritesScope",                                {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaFlushGPUDirectRDMAWritesToOwner",                              {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaFlushGPUDirectRDMAWritesToAllDevices",                         {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaFlushGPUDirectRDMAWritesTarget",                               {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaFlushGPUDirectRDMAWritesTargetCurrentDevice",                  {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaDevAttrMaxPersistingL2CacheSize",                              {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaDevAttrMaxAccessPolicyWindowSize",                             {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaDevAttrGPUDirectRDMASupported",                                {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaDevAttrGPUDirectRDMAFlushWritesOptions",                       {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaDevAttrGPUDirectRDMAWritesOrdering",                           {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaDevAttrMemoryPoolSupportedHandleTypes",                        {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaMemPoolAttrReservedMemCurrent",                                {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaMemPoolAttrReservedMemHigh",                                   {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaMemPoolAttrUsedMemCurrent",                                    {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaMemPoolAttrUsedMemHigh",                                       {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaUserObject_t",                                                 {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaGetDriverEntryPointFlags",                                     {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaEnableDefault",                                                {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaEnableLegacyStream",                                           {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaEnablePerThreadDefaultStream",                                 {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaGraphDebugDotFlags",                                           {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaGraphDebugDotFlagsVerbose",                                    {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaGraphDebugDotFlagsKernelNodeParams",                           {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaGraphDebugDotFlagsMemcpyNodeParams",                           {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaGraphDebugDotFlagsMemsetNodeParams",                           {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaGraphDebugDotFlagsHostNodeParams",                             {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaGraphDebugDotFlagsEventNodeParams",                            {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaGraphDebugDotFlagsExtSemasSignalNodeParams",                   {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaGraphDebugDotFlagsExtSemasWaitNodeParams",                     {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaGraphDebugDotFlagsKernelNodeAttributes",                       {CUDA_113, CUDA_0,   CUDA_0  }},
  {"cudaGraphDebugDotFlagsHandles",                                    {CUDA_113, CUDA_0,   CUDA_0  }},
};

const std::map<llvm::StringRef, hipAPIversions> HIP_RUNTIME_TYPE_NAME_VER_MAP {
  {"hipHostRegisterDefault",                                           {HIP_1060, HIP_0,    HIP_0   }},
  {"hipArrayDefault",                                                  {HIP_1070, HIP_0,    HIP_0   }},
  {"hipFuncAttribute",                                                 {HIP_3090, HIP_0,    HIP_0   }},
  {"hipFuncAttributeMaxDynamicSharedMemorySize",                       {HIP_3090, HIP_0,    HIP_0   }},
  {"hipFuncAttributePreferredSharedMemoryCarveout",                    {HIP_3090, HIP_0,    HIP_0   }},
  {"hipFuncAttributeMax",                                              {HIP_3090, HIP_0,    HIP_0   }},
  {"hipChannelFormatKind",                                             {HIP_1060, HIP_0,    HIP_0   }},
  {"hipChannelFormatKindSigned",                                       {HIP_1060, HIP_0,    HIP_0   }},
  {"hipChannelFormatKindUnsigned",                                     {HIP_1060, HIP_0,    HIP_0   }},
  {"hipChannelFormatKindFloat",                                        {HIP_1060, HIP_0,    HIP_0   }},
  {"hipChannelFormatKindNone",                                         {HIP_1060, HIP_0,    HIP_0   }},
  {"hipChannelFormatDesc",                                             {HIP_1060, HIP_0,    HIP_0   }},
  {"hipArray_const_t",                                                 {HIP_1060, HIP_0,    HIP_0   }},
  {"hipMipmappedArray_const_t",                                        {HIP_1060, HIP_0,    HIP_0   }},
  {"hipResourceType",                                                  {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResourceTypeArray",                                             {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResourceTypeMipmappedArray",                                    {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResourceTypeLinear",                                            {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResourceTypePitch2D",                                           {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResourceViewFormat",                                            {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatNone",                                             {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatUnsignedChar1",                                    {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatUnsignedChar2",                                    {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatUnsignedChar4",                                    {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatSignedChar1",                                      {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatSignedChar2",                                      {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatSignedChar4",                                      {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatUnsignedShort1",                                   {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatUnsignedShort2",                                   {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatUnsignedShort4",                                   {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatSignedShort1",                                     {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatSignedShort2",                                     {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatSignedShort4",                                     {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatUnsignedInt1",                                     {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatUnsignedInt2",                                     {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatUnsignedInt4",                                     {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatSignedInt1",                                       {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatSignedInt2",                                       {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatSignedInt4",                                       {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatHalf1",                                            {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatHalf2",                                            {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatHalf4",                                            {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatFloat1",                                           {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatFloat2",                                           {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatFloat4",                                           {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatUnsignedBlockCompressed1",                         {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatUnsignedBlockCompressed2",                         {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatUnsignedBlockCompressed3",                         {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatUnsignedBlockCompressed4",                         {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatSignedBlockCompressed4",                           {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatUnsignedBlockCompressed5",                         {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatSignedBlockCompressed5",                           {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatUnsignedBlockCompressed6H",                        {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatSignedBlockCompressed6H",                          {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResViewFormatUnsignedBlockCompressed7",                         {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResourceDesc",                                                  {HIP_1070, HIP_0,    HIP_0   }},
  {"hipResourceViewDesc",                                              {HIP_1070, HIP_0,    HIP_0   }},
  {"hipMemcpyKind",                                                    {HIP_1050, HIP_0,    HIP_0   }},
  {"hipMemcpyHostToHost",                                              {HIP_1050, HIP_0,    HIP_0   }},
  {"hipMemcpyHostToDevice",                                            {HIP_1050, HIP_0,    HIP_0   }},
  {"hipMemcpyDeviceToHost",                                            {HIP_1050, HIP_0,    HIP_0   }},
  {"hipMemcpyDeviceToDevice",                                          {HIP_1050, HIP_0,    HIP_0   }},
  {"hipMemcpyDefault",                                                 {HIP_1050, HIP_0,    HIP_0   }},
  {"hipPitchedPtr",                                                    {HIP_1070, HIP_0,    HIP_0   }},
  {"hipExtent",                                                        {HIP_1070, HIP_0,    HIP_0   }},
  {"hipPos",                                                           {HIP_1070, HIP_0,    HIP_0   }},
  {"hipMemcpy3DParms",                                                 {HIP_1070, HIP_0,    HIP_0   }},
  {"hipTextureAddressMode",                                            {HIP_1070, HIP_0,    HIP_0   }},
  {"hipAddressModeWrap",                                               {HIP_1070, HIP_0,    HIP_0   }},
  {"hipAddressModeClamp",                                              {HIP_1070, HIP_0,    HIP_0   }},
  {"hipAddressModeMirror",                                             {HIP_1070, HIP_0,    HIP_0   }},
  {"hipAddressModeBorder",                                             {HIP_1070, HIP_0,    HIP_0   }},
  {"hipSurfaceBoundaryMode",                                           {HIP_1090, HIP_0,    HIP_0   }},
  {"hipBoundaryModeZero",                                              {HIP_1090, HIP_0,    HIP_0   }},
  {"hipBoundaryModeTrap",                                              {HIP_1090, HIP_0,    HIP_0   }},
  {"hipBoundaryModeClamp",                                             {HIP_1090, HIP_0,    HIP_0   }},
  {"hipSurfaceObject_t",                                               {HIP_1090, HIP_0,    HIP_0   }},
  {"surfaceReference",                                                 {HIP_1090, HIP_0,    HIP_0   }},
  {"hipTextureType1D",                                                 {HIP_1060, HIP_0,    HIP_0   }},
  {"hipTextureType2D",                                                 {HIP_1070, HIP_0,    HIP_0   }},
  {"hipTextureType3D",                                                 {HIP_1070, HIP_0,    HIP_0   }},
  {"hipTextureTypeCubemap",                                            {HIP_1070, HIP_0,    HIP_0   }},
  {"hipTextureType1DLayered",                                          {HIP_1070, HIP_0,    HIP_0   }},
  {"hipTextureType2DLayered",                                          {HIP_1070, HIP_0,    HIP_0   }},
  {"hipTextureTypeCubemapLayered",                                     {HIP_1070, HIP_0,    HIP_0   }},
  {"hipTextureFilterMode",                                             {HIP_1060, HIP_0,    HIP_0   }},
  {"hipFilterModePoint",                                               {HIP_1060, HIP_0,    HIP_0   }},
  {"hipFilterModeLinear",                                              {HIP_1070, HIP_0,    HIP_0   }},
  {"hipTextureReadMode",                                               {HIP_1060, HIP_0,    HIP_0   }},
  {"hipReadModeElementType",                                           {HIP_1060, HIP_0,    HIP_0   }},
  {"hipReadModeNormalizedFloat",                                       {HIP_1070, HIP_0,    HIP_0   }},
  {"hipTextureDesc",                                                   {HIP_1070, HIP_0,    HIP_0   }},
  {"hipPointerAttribute_t",                                            {HIP_1060, HIP_0,    HIP_0   }},
  {"hipLaunchParams",                                                  {HIP_2060, HIP_0,    HIP_0   }},
  {"hipStreamCallback_t",                                              {HIP_1060, HIP_0,    HIP_0   }},
  {"hipErrorInvalidConfiguration",                                     {HIP_1060, HIP_0,    HIP_0   }},
  {"hipErrorInvalidSymbol",                                            {HIP_1060, HIP_0,    HIP_0   }},
  {"hipErrorInvalidDevicePointer",                                     {HIP_1060, HIP_0,    HIP_0   }},
  {"hipErrorInvalidMemcpyDirection",                                   {HIP_1060, HIP_0,    HIP_0   }},
  {"hipErrorInsufficientDriver",                                       {HIP_1070, HIP_0,    HIP_0   }},
  {"hipErrorMissingConfiguration",                                     {HIP_1060, HIP_0,    HIP_0   }},
  {"hipErrorPriorLaunchFailure",                                       {HIP_1060, HIP_0,    HIP_0   }},
  {"hipErrorInvalidDeviceFunction",                                    {HIP_1060, HIP_0,    HIP_0   }},
  {"hipErrorInvalidPitchValue",                                        {HIP_4020, HIP_0,    HIP_0   }},
};
