/*
* Copyright (c) 2007 SlimDX Group
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/
#pragma once

using namespace System;

#include "../DirectXObject.h"

namespace SlimDX
{
	namespace Direct3D10
	{
		public ref class VertexShader : public DirectXObject<ID3D10VertexShader>
		{
		internal:
			VertexShader(ID3D10VertexShader *shader) : DirectXObject( shader ) { }
			
		public:
			VertexShader( IntPtr shader )
			{
				if( shader == IntPtr::Zero )
					throw gcnew ArgumentNullException( "shader" );

				void* pointer;
				IUnknown* unknown = (IUnknown*) shader.ToPointer();
				HRESULT hr = unknown->QueryInterface( IID_ID3D10VertexShader, &pointer );
				if( FAILED( hr ) )
					throw gcnew InvalidCastException( "Failed to QueryInterface on user-supplied pointer." );

				m_Pointer = (ID3D10VertexShader*) pointer;
			}

			virtual ~VertexShader() { Destruct(); }
			DXOBJECT_FUNCTIONS;
		};
	}
};