#pragma once
#pragma warning(push)
#pragma warning(disable : 4638)

namespace NetScriptFramework
{
	namespace SkyrimSE
	{
		#pragma managed(push, off)
		struct customRayHitCollectorResult
		{
			float fraction;
			float normal[3];
			void * obj;

			customRayHitCollectorResult * next;
		};

		struct customRayHitCollector
		{
			customRayHitCollector()
			{
				first = 0;
				last = 0;
				_early_out_hit_fraction = 1.0f;
				_hit_fraction = 1.0f;
				_extra_info = -1;
				_shape_key = -1;
				_shape_keys_0 = -1;
				_shape_key_index = 0;
				_root_collidable = 0;
			}

			~customRayHitCollector()
			{
				Free();
			}

			// virtual void addRayHit( const hkpCdBody& cdBody, const hkpShapeRayCastCollectorOutput& hitInfo );
			virtual void ProcessHit(void * a2, void * a3)
			{
				__int64 a2_ptr = (__int64)a2;
				__int64 a3_ptr = (__int64)a3;

				auto n = new customRayHitCollectorResult();
				n->fraction = *((float*)(a3_ptr + 0x10));
				for (int i = 0; i < 3; i++)
					n->normal[i] = *((float*)(a3_ptr + 4 * i));

				auto obj = a2_ptr;
				while (obj != 0)
				{
					auto parent = *((__int64*)(obj + 24));
					if (parent == 0)
						break;
					obj = parent;
				}
				n->obj = (void*)obj;

				if (first == 0)
				{
					first = n;
					last = n;
				}
				else
				{
					last->next = n;
					last = n;
				}
			}

			virtual void Delete(bool a2) { }

			void Free()
			{
				auto n = first;
				while (n != 0)
				{
					auto p = n;
					n = n->next;
					delete p;
				}
				first = 0;
				last = 0;
			}

			private:
			float _early_out_hit_fraction;
			int _pad_C;
			__int64 _pad_10;
			__int64 _pad_18;
			float _hit_fraction;
			int _extra_info;
			int _shape_key;
			int _pad_2C;
			int _shape_keys_0;
			int _pad_34;
			__int64 _pad_38;
			__int64 _pad_40;
			__int64 _pad_48;
			int _shape_key_index;
			int _pad_54;
			__int64 _pad_58;
			__int64 _root_collidable;
			__int64 _pad_68;
			customRayHitCollectorResult * last;
			public:
			customRayHitCollectorResult * first;
		};
		#pragma managed(pop)

		/// <summary>
		/// This class is used to cache string to keyword search.
		/// </summary>
		public ref class KeywordCache sealed
		{
			static System::Collections::Generic::Dictionary<System::String^, System::Collections::Generic::List<BGSKeyword^>^>^ _map;
			static initonly System::Collections::Generic::List<BGSKeyword^>^ _empty = gcnew System::Collections::Generic::List<BGSKeyword^>();

			internal:
			static void Initialize();

			public:
			/// <summary>
			/// Gets the cached results for specified keyword text.
			/// </summary>
			/// <param name="text">The text of keyword.</param>
			static System::Collections::Generic::IReadOnlyList<BGSKeyword^>^ Get(System::String^ text)
			{
				if (text == nullptr)
					return _empty;

				text = text->ToLowerInvariant();
				System::Collections::Generic::List<BGSKeyword^>^ ls = nullptr;
				if (_map->TryGetValue(text, ls))
					return ls;
				return _empty;
			}
		};

		/// <summary>
		/// Parameters for loading a NiObject from file.
		/// </summary>
		public ref class NiObjectLoadParameters sealed
		{
			public:			
			/// <summary>
			/// Initializes a new instance of the <see cref="NiObjectLoadParameters"/> class.
			/// </summary>
			NiObjectLoadParameters() { }

			/// <summary>
			/// Gets or sets the name of the file. For example:
			/// <para>Meshes\\Weapons\\Iron\\LongSword.nif</para>
			/// </summary>
			/// <value>
			/// The name of the file.
			/// </value>
			property System::String^ FileName
			{
				System::String^ get() { return _fileName; }
				void set(System::String^ value) { _fileName = value; }
			}

			/// <summary>
			/// Gets or sets the count. This is how many copies are created and returned on successful load.
			/// </summary>
			/// <value>
			/// The count.
			/// </value>
			property System::Int32 Count
			{
				System::Int32 get() { return _count; }
				void set(System::Int32 value) { _count = value; }
			}

			/// <summary>
			/// Gets or sets the callback. This is invoked when the loading is finished whether or not it succeeded or failed.
			/// </summary>
			/// <value>
			/// The callback.
			/// </value>
			property System::Action<NiObjectLoadParameters^>^ Callback
			{
				System::Action<NiObjectLoadParameters^>^ get() { return _callback; }
				void set(System::Action<NiObjectLoadParameters^>^ value) { _callback = value; }
			}

			/// <summary>
			/// Gets the resulting objects. These will be deleted immediately after callback is invoked unless you use them somewhere or manually invoke IncRef on the objects.
			/// </summary>
			/// <value>
			/// The result.
			/// </value>
			property System::Collections::Generic::IReadOnlyList<NiObject^>^ Result
			{
				System::Collections::Generic::IReadOnlyList<NiObject^>^ get() { return _result; }
			}

			/// <summary>
			/// Gets a value indicating whether this <see cref="NiObjectLoadParameters"/> was successful. This is what you should check during Callback.
			/// </summary>
			/// <value>
			///   <c>true</c> if success; otherwise, <c>false</c>.
			/// </value>
			property bool Success
			{
				bool get() { return _success; }
			}

			private:
			System::String^ _fileName = nullptr;
			System::Int32 _count = 1;
			System::Action<NiObjectLoadParameters^>^ _callback = nullptr;
			System::Collections::Generic::List<NiObject^>^ _result = gcnew System::Collections::Generic::List<NiObject^>();
			MemoryAllocation^ _alloc = nullptr;
			bool _success = false;
			static System::Object^ _locker = gcnew System::Object();
			static System::Collections::Generic::List<NiObjectLoadParameters^>^ _queued = gcnew System::Collections::Generic::List<NiObjectLoadParameters^>();

			bool Process();
			void Cleanup();
			void Finish();

			internal:
			static void _RequestModelDirect(NiObjectLoadParameters^ p);
			static void _RequestModelAsync(NiObjectLoadParameters^ p);
			static void _UpdateRequestModel();
		};

		/// <summary>
		/// Implements game object reference handling.
		/// </summary>
		/// <seealso cref="TemporaryObject" />
		public ref class ObjectRefHolder sealed : NetScriptFramework::TemporaryObject
		{
			public:
			/// <summary>
			/// Initializes a new instance of the <see cref="ObjectRefHolder" /> class.
			/// </summary>
			/// <param name="obj">The object to create reference ID for.</param>
			ObjectRefHolder(TESObjectREFR^ obj)
			{
				if(obj == nullptr)
					return;

				auto objptr = obj->Cast<TESObjectREFR^>();
				if(objptr == System::IntPtr::Zero)
					return;

				_allocated = false;
				_obj = obj;
				auto alloc = NetScriptFramework::Memory::Allocate(0x10, 0, false);
				NetScriptFramework::Memory::WriteUInt32(alloc->Address, 0, false);
				try
				{
					NetScriptFramework::Memory::InvokeCdecl(__VIDS::VID12192.Value, alloc->Address, objptr);
					_value = NetScriptFramework::Memory::ReadUInt32(alloc->Address, false);
				}
				finally
				{
					if (alloc != nullptr)
						delete alloc;
				}
			}

			/// <summary>
			/// Initializes a new instance of the <see cref="ObjectRefHolder"/> class.
			/// </summary>
			/// <param name="refId">The reference identifier to look up.</param>
			ObjectRefHolder(System::UInt32 refId)
			{
				_value = refId;
				_allocated = true;
				if (refId != 0)
				{
					auto alloc = NetScriptFramework::Memory::Allocate(0x20, 0, false);
					NetScriptFramework::Memory::WriteUInt32(alloc->Address, refId, false);
					NetScriptFramework::Memory::WritePointer(alloc->Address + 0x10, System::IntPtr::Zero, false);
					try
					{
						NetScriptFramework::Memory::InvokeCdecl(__VIDS::VID16828.Value, alloc->Address, alloc->Address + 0x10);
						System::IntPtr result = NetScriptFramework::Memory::ReadPointer(alloc->Address + 0x10, false);
						if (result != System::IntPtr::Zero)
							_obj = NetScriptFramework::MemoryObject::FromAddress<TESObjectREFR^>(result);
					}
					finally
					{
						if (alloc != nullptr)
							delete alloc;
					}
				}
			}

			/// <summary>
			/// Gets the handle ID. This is zero if not valid!
			/// </summary>
			/// <value>
			/// The handle.
			/// </value>
			property System::UInt32 Handle
			{
				System::UInt32 get()
				{
					return _value;
				}
			}

			/// <summary>
			/// Gets the object instance. This is null if not valid!
			/// </summary>
			/// <value>
			/// The object.
			/// </value>
			property TESObjectREFR^ Object
			{
				TESObjectREFR^ get()
				{
					return _obj;
				}
			}

			/// <summary>
			/// Returns true if this handle is valid.
			/// </summary>
			/// <value>
			///   <c>true</c> if this instance is valid; otherwise, <c>false</c>.
			/// </value>
			property bool IsValid
			{
				bool get()
				{
					return _obj != nullptr && _value != 0;
				}
			}

			private:
			TESObjectREFR^ _obj = nullptr;
			System::UInt32 _value = 0;
			bool _allocated;

			protected:
			void Free() override
			{
				if (_obj != nullptr && _value != 0 && _allocated)
				{
					_obj->DecRef();
					_obj = nullptr;
					_value = 0;
				}
			}
		};

		/// <summary>
		/// Contains parameters for performing a raycast.
		/// </summary>
		public ref class RayCastParameters sealed
		{
			public:			
			/// <summary>
			/// Initializes a new instance of the <see cref="RayCastParameters"/> class.
			/// </summary>
			RayCastParameters()
			{

			}

			/// <summary>
			/// Gets or sets the begin coordinate.
			/// </summary>
			/// <value>
			/// The begin.
			/// </value>
			property array<float>^ Begin
			{
				array<float>^ get()
				{
					return _begin;
				}

				void set(array<float>^ value)
				{
					if (value != nullptr && value->Length < 3)
					{
						auto p = value;
						value = gcnew array<float>(3);
						for (int i = 0; i < p->Length; i++)
							value[i] = p[i];
					}
					_begin = value;
				}
			}

			/// <summary>
			/// Gets or sets the end coordinate.
			/// </summary>
			/// <value>
			/// The end.
			/// </value>
			property array<float>^ End
			{
				array<float>^ get()
				{
					return _end;
				}

				void set(array<float>^ value)
				{
					if (value != nullptr && value->Length < 3)
					{
						auto p = value;
						value = gcnew array<float>(3);
						for (int i = 0; i < p->Length; i++)
							value[i] = p[i];
					}
					_end = value;
				}
			}

			/// <summary>
			/// Gets or sets the cell. This must be set.
			/// </summary>
			/// <value>
			/// The cell.
			/// </value>
			property TESObjectCELL^ Cell
			{
				TESObjectCELL^ get()
				{
					return _cell;
				}

				void set(TESObjectCELL^ value)
				{
					_cell = value;
				}
			}

			private:
			array<float>^ _begin = nullptr;
			array<float>^ _end = nullptr;
			TESObjectCELL^ _cell = nullptr;
		};

		/// <summary>
		/// Contains results from raycasting.
		/// </summary>
		public ref class RayCastResult sealed
		{
			internal:
			RayCastResult()
			{

			}

			public:			
			/// <summary>
			/// Gets the fraction.
			/// </summary>
			/// <value>
			/// The fraction.
			/// </value>
			property float Fraction
			{
				float get() { return _fraction; }
				internal: void set(float value) { _fraction = value; }
			}

			public:			
			/// <summary>
			/// Gets the normal of the collision.
			/// </summary>
			/// <value>
			/// The normal.
			/// </value>
			property array<float>^ Normal
			{
				array<float>^ get() { return _normal; }
				internal: void set(array<float>^ value) { _normal = value; }
			}

			public:
			/// <summary>
			/// Gets the position of the collision.
			/// </summary>
			/// <value>
			/// The position.
			/// </value>
			property array<float>^ Position
			{
				array<float>^ get() { return _pos; }
				internal: void set(array<float>^ value) { _pos = value; }
			}

			public:
			/// <summary>
			/// Gets the object of the collision.
			/// </summary>
			/// <value>
			/// The object.
			/// </value>
			property NiAVObject^ Object
			{
				NiAVObject^ get() { return NetScriptFramework::MemoryObject::FromAddress<NiAVObject^>(_obj); }
			}

			/// <summary>
			/// Gets the havok object.
			/// </summary>
			/// <value>
			/// The havok object.
			/// </value>
			property System::IntPtr HavokObject
			{
				System::IntPtr get()
				{
					return _hkObj;
				}
			}

			private:
			float _fraction;
			array<float>^ _normal;
			array<float>^ _pos;
			internal:
			System::IntPtr _obj;
			System::IntPtr _hkObj;

			public:			
			/// <summary>
			/// Gets the closest result from a list of results.
			/// </summary>
			/// <param name="source">The source position.</param>
			/// <param name="results">The results returned from raycast.</param>
			/// <param name="ignore">If set then ignore collisions with these objects.</param>
			/// <returns></returns>
			static RayCastResult^ GetClosestResult(array<float>^ source, System::Collections::Generic::List<RayCastResult^>^ results, ... array<NiAVObject^>^ ignore);
		};

		/// <summary>
		/// Implements game string handling.
		/// </summary>
		/// <seealso cref="TemporaryObject" />
		public ref class StringRefHolder sealed : NetScriptFramework::TemporaryObject
		{
			public:
			/// <summary>
			/// Initializes a new instance of the <see cref="StringRefHolder"/> class.
			/// </summary>
			/// <param name="text">The text.</param>
			StringRefHolder(System::String^ text)
			{
				if (text == nullptr)
					return;

				auto bytes = System::Text::Encoding::UTF8->GetBytes(text);
				_alloc = NetScriptFramework::Memory::Allocate(0x10 + bytes->Length + 8, 0, false);
				{
					NetScriptFramework::Memory::WriteBytes(_alloc->Address + 0x10, bytes, false);
					NetScriptFramework::Memory::WriteUInt32(_alloc->Address + 0x10 + bytes->Length, 0, false);
					NetScriptFramework::Memory::InvokeCdecl(__VIDS::VID67819.Value, _alloc->Address, _alloc->Address + 0x10);
				}
			}

			/// <summary>
			/// Gets the address of the allocation. This is usually what is passed as function argument.
			/// </summary>
			property System::IntPtr AddressOf
			{
				System::IntPtr __clrcall get()
				{
					if (_alloc == nullptr)
						return System::IntPtr::Zero;

					return _alloc->Address;
				}
			}

			/// <summary>
			/// Gets the value of the string.
			/// </summary>
			property System::IntPtr Value
			{
				System::IntPtr __clrcall get()
				{
					if (_alloc == nullptr)
						return System::IntPtr::Zero;

					return NetScriptFramework::Memory::ReadPointer(_alloc->Address, false);
				}
			}

			/// <summary>
			/// Gets the text value of the string. This may or may not be equal to what was passed as argument in constructor!
			/// </summary>
			property System::String^ Text
			{
				System::String^ __clrcall get()
				{
					auto ptr = Value;
					if (ptr == System::IntPtr::Zero)
						return nullptr;

					return NetScriptFramework::Memory::ReadString(ptr, false, false);
				}
			}

			private:
			NetScriptFramework::MemoryAllocation^ _alloc = nullptr;

			protected:
			void Free() override
			{
				if (_alloc != nullptr)
				{
					NetScriptFramework::Memory::InvokeCdecl(__VIDS::VID67822.Value, _alloc->Address);

					delete _alloc;
					_alloc = nullptr;
				}
			}
		};

		/// <summary>
		/// Havok helper functions.
		/// </summary>
		private ref class _Havok sealed
		{
			public:
			static System::Collections::Generic::List<RayCastResult^>^ RayCast(RayCastParameters^ p);
		};
	}
}

#pragma warning(pop)
