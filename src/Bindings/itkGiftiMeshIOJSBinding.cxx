/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include <emscripten.h>
#include <emscripten/bind.h>

#include "itkGiftiMeshIO.h"

#include "itkMeshIOBaseJSBinding.h"

typedef itk::MeshIOBaseJSBinding< itk::GiftiMeshIO > GiftiMeshIOJSBindingType;

EMSCRIPTEN_BINDINGS(itk_gifti_mesh_io_js_binding) {
  emscripten::enum_<GiftiMeshIOJSBindingType::IOPixelType>("IOPixelType")
    .value("UNKNOWNPIXELTYPE", itk::MeshIOBase::UNKNOWNPIXELTYPE)
    .value("SCALAR", itk::MeshIOBase::SCALAR)
    .value("RGB", itk::MeshIOBase::RGB)
    .value("RGBA", itk::MeshIOBase::RGBA)
    .value("OFFSET", itk::MeshIOBase::OFFSET)
    .value("VECTOR", itk::MeshIOBase::VECTOR)
    .value("POINT", itk::MeshIOBase::POINT)
    .value("COVARIANTVECTOR", itk::MeshIOBase::COVARIANTVECTOR)
    .value("SYMMETRICSECONDRANKTENSOR", itk::MeshIOBase::SYMMETRICSECONDRANKTENSOR)
    .value("DIFFUSIONTENSOR3D", itk::MeshIOBase::DIFFUSIONTENSOR3D)
    .value("COMPLEX", itk::MeshIOBase::COMPLEX)
    .value("FIXEDARRAY", itk::MeshIOBase::FIXEDARRAY)
    .value("ARRAY", itk::MeshIOBase::ARRAY)
    .value("MATRIX", itk::MeshIOBase::MATRIX)
    .value("VARIABLELENGTHVECTOR", itk::MeshIOBase::VARIABLELENGTHVECTOR)
    .value("VARIABLESIZEMATRIX", itk::MeshIOBase::VARIABLESIZEMATRIX)
    ;
  emscripten::enum_<GiftiMeshIOJSBindingType::IOComponentType>("IOComponentType")
    .value("UNKNOWNCOMPONENTTYPE", itk::MeshIOBase::UNKNOWNCOMPONENTTYPE)
    .value("UCHAR", itk::MeshIOBase::UCHAR)
    .value("CHAR", itk::MeshIOBase::CHAR)
    .value("USHORT", itk::MeshIOBase::USHORT)
    .value("SHORT", itk::MeshIOBase::SHORT)
    .value("UINT", itk::MeshIOBase::UINT)
    .value("INT", itk::MeshIOBase::INT)
    .value("ULONG", itk::MeshIOBase::ULONG)
    .value("LONG", itk::MeshIOBase::LONG)
    .value("ULONGLONG", itk::MeshIOBase::ULONGLONG)
    .value("LONGLONG", itk::MeshIOBase::LONGLONG)
    .value("FLOAT", itk::MeshIOBase::FLOAT)
    .value("DOUBLE", itk::MeshIOBase::DOUBLE)
    .value("LDOUBLE", itk::MeshIOBase::LDOUBLE)
    ;
  emscripten::enum_<GiftiMeshIOJSBindingType::FileType>("FileType")
    .value("ASCII", itk::MeshIOBase::ASCII)
    .value("BINARY", itk::MeshIOBase::BINARY)
    .value("TYPENOTAPPLICABLE", itk::MeshIOBase::TYPENOTAPPLICABLE)
    ;
  emscripten::enum_<GiftiMeshIOJSBindingType::ByteOrder>("ByteOrder")
    .value("BigEndian", itk::MeshIOBase::BigEndian)
    .value("LittleEndian", itk::MeshIOBase::LittleEndian)
    .value("OrderNotApplicable", itk::MeshIOBase::OrderNotApplicable)
    ;
  emscripten::class_<GiftiMeshIOJSBindingType>("ITKMeshIO")
  .constructor<>()
  .function("SetFileName", &GiftiMeshIOJSBindingType::SetFileName)
  .function("GetFileName", &GiftiMeshIOJSBindingType::GetFileName)
  .function("CanReadFile", &GiftiMeshIOJSBindingType::CanReadFile)
  .function("CanWriteFile", &GiftiMeshIOJSBindingType::CanWriteFile)
  .function("SetPointPixelType", &GiftiMeshIOJSBindingType::SetPointPixelType)
  .function("GetPointPixelType", &GiftiMeshIOJSBindingType::GetPointPixelType)
  .function("SetCellPixelType", &GiftiMeshIOJSBindingType::SetCellPixelType)
  .function("GetCellPixelType", &GiftiMeshIOJSBindingType::GetCellPixelType)
  .function("SetFileType", &GiftiMeshIOJSBindingType::SetFileType)
  .function("GetFileType", &GiftiMeshIOJSBindingType::GetFileType)
  .function("SetByteOrder", &GiftiMeshIOJSBindingType::SetByteOrder)
  .function("GetByteOrder", &GiftiMeshIOJSBindingType::GetByteOrder)
  .function("SetPointComponentType", &GiftiMeshIOJSBindingType::SetPointComponentType)
  .function("GetPointComponentType", &GiftiMeshIOJSBindingType::GetPointComponentType)
  .function("SetCellComponentType", &GiftiMeshIOJSBindingType::SetCellComponentType)
  .function("GetCellComponentType", &GiftiMeshIOJSBindingType::GetCellComponentType)
  .function("SetPointPixelComponentType", &GiftiMeshIOJSBindingType::SetPointPixelComponentType)
  .function("GetPointPixelComponentType", &GiftiMeshIOJSBindingType::GetPointPixelComponentType)
  .function("SetCellPixelComponentType", &GiftiMeshIOJSBindingType::SetCellPixelComponentType)
  .function("GetCellPixelComponentType", &GiftiMeshIOJSBindingType::GetCellPixelComponentType)
  .function("SetNumberOfPointPixelComponents", &GiftiMeshIOJSBindingType::SetNumberOfPointPixelComponents)
  .function("GetNumberOfPointPixelComponents", &GiftiMeshIOJSBindingType::GetNumberOfPointPixelComponents)
  .function("SetNumberOfCellPixelComponents", &GiftiMeshIOJSBindingType::SetNumberOfCellPixelComponents)
  .function("GetNumberOfCellPixelComponents", &GiftiMeshIOJSBindingType::GetNumberOfCellPixelComponents)
  .function("SetPointDimension", &GiftiMeshIOJSBindingType::SetPointDimension)
  .function("GetPointDimension", &GiftiMeshIOJSBindingType::GetPointDimension)
  .function("SetNumberOfPoints", &GiftiMeshIOJSBindingType::SetNumberOfPoints)
  .function("GetNumberOfPoints", &GiftiMeshIOJSBindingType::GetNumberOfPoints)
  .function("SetNumberOfCells", &GiftiMeshIOJSBindingType::SetNumberOfCells)
  .function("GetNumberOfCells", &GiftiMeshIOJSBindingType::GetNumberOfCells)
  .function("SetNumberOfPointPixels", &GiftiMeshIOJSBindingType::SetNumberOfPointPixels)
  .function("GetNumberOfPointPixels", &GiftiMeshIOJSBindingType::GetNumberOfPointPixels)
  .function("SetNumberOfCellPixels", &GiftiMeshIOJSBindingType::SetNumberOfCellPixels)
  .function("GetNumberOfCellPixels", &GiftiMeshIOJSBindingType::GetNumberOfCellPixels)
  .function("SetCellBufferSize", &GiftiMeshIOJSBindingType::SetCellBufferSize)
  .function("GetCellBufferSize", &GiftiMeshIOJSBindingType::GetCellBufferSize)
  .function("SetUpdatePoints", &GiftiMeshIOJSBindingType::SetUpdatePoints)
  .function("SetUpdatePointData", &GiftiMeshIOJSBindingType::SetUpdatePointData)
  .function("SetUpdateCells", &GiftiMeshIOJSBindingType::SetUpdateCells)
  .function("SetUpdateCellData", &GiftiMeshIOJSBindingType::SetUpdateCellData)
  .function("ReadMeshInformation", &GiftiMeshIOJSBindingType::ReadMeshInformation)
  .function("WriteMeshInformation", &GiftiMeshIOJSBindingType::WriteMeshInformation)
  .function("ReadPoints", &GiftiMeshIOJSBindingType::ReadPoints)
  .function("ReadCells", &GiftiMeshIOJSBindingType::ReadCells)
  .function("ReadPointData", &GiftiMeshIOJSBindingType::ReadPointData)
  .function("ReadCellData", &GiftiMeshIOJSBindingType::ReadCellData)
  .function("WritePoints", &GiftiMeshIOJSBindingType::WritePoints)
  .function("WriteCells", &GiftiMeshIOJSBindingType::WriteCells)
  .function("WritePointData", &GiftiMeshIOJSBindingType::WritePointData)
  .function("WriteCellData", &GiftiMeshIOJSBindingType::WriteCellData)
  .function("Write", &GiftiMeshIOJSBindingType::Write)
  .function("SetUseCompression", &GiftiMeshIOJSBindingType::SetUseCompression)
  ;
}
