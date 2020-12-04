#pragma once
#pragma warning(push)
#pragma warning(disable : 4638)

namespace NetScriptFramework
{
	namespace SkyrimSE
	{
		/// <summary>
		/// Game library header.
		/// </summary>
		/// <seealso cref="NetScriptFramework::Game" />
		ref class SkyrimSEGame sealed : Game
		{
		public:
			/// <summary>
			/// Initializes a new instance of the <see cref="SkyrimSEGame" /> class.
			/// </summary>
			SkyrimSEGame() : Game()
			{
				this->AppVersion = gcnew System::Collections::Generic::List<int>(4);
				this->AppVersion->AddRange(NetScriptFramework::Memory::GetMainModuleVersion());
			}

			/// <summary>
			/// Gets the name of the executable of current game including file extension. For example "TESV.exe".
			/// </summary>
			/// <value>
			/// The name of the executable.
			/// </value>
			property System::String^ ExecutableName
			{
				System::String^ __clrcall get() override
				{
					return "SkyrimSE.exe";
				}
			}

			/// <summary>
			/// Gets the name of the target module. This is usually equal to ExecutableName but sometimes we may want to target a DLL inside the process
			/// instead in which case they would be different.
			/// </summary>
			/// <value>
			/// The name of the module.
			/// </value>
			property System::String^ ModuleName
			{
				System::String^ __clrcall get() override
				{
					return "SkyrimSE.exe";
				}
			}

			/// <summary>
			/// Gets the full name of current game. For example "The Elder Scrolls V: Skyrim"
			/// </summary>
			/// <value>
			/// The full name.
			/// </value>
			property System::String^ FullName
			{
				System::String^ __clrcall get() override
				{
					return "The Elder Scrolls V: Skyrim Special Edition";
				}
			}

			/// <summary>
			/// Gets the version of current game. It is read from the executable. This is a list of four integers always.
			/// The first integer in the list is the most significant version number and last is the least significant.
			/// For example { 1, 9, 32, 0 }
			/// </summary>
			/// <value>
			/// The version of game.
			/// </value>
			property System::Collections::Generic::IReadOnlyList<System::Int32>^ GameVersion
			{
				System::Collections::Generic::IReadOnlyList<System::Int32>^ __clrcall get() override
				{
					return this->AppVersion;
				}
			}

			/// <summary>
			/// Gets a value indicating whether currently loaded game version is a valid version supported by this library.
			/// This is only used during game header initialization. If it returns false the game will abort and display an error.
			/// </summary>
			/// <value>
			/// <c>true</c> if this instance is valid version; otherwise, <c>false</c>.
			/// </value>
			property System::Boolean IsValidVersion
			{
				System::Boolean __clrcall get() override
				{
					return true;
				}
			}

			/// <summary>
			/// Gets the library version. This is separate from game's version. Multiple library versions may exist for the same
			/// version of the game.
			/// </summary>
			/// <value>
			/// The library version.
			/// </value>
			property System::Int32 LibraryVersion
			{
				System::Int32 __clrcall get() override
				{
					return 14;
				}
			}

			/// <summary>
			/// Gets the version library hash that is required to be loaded.
			/// </summary>
			/// <value>
			/// The version library hash.
			/// </value>
			property System::UInt64 VersionLibraryHash
			{
				System::UInt64 __clrcall get() override
				{
					return 0x14AEB93E09DDA87F;
				}
			}

			/// <summary>
			/// Gets the short name of current game. For example "Skyrim".
			/// </summary>
			/// <value>
			/// The short name.
			/// </value>
			property System::String^ ShortName
			{
				System::String^ __clrcall get() override
				{
					return "SkyrimSE";
				}
			}

		private:
			/// <summary>
			/// The application version.
			/// </summary>
			initonly System::Collections::Generic::List<System::Int32>^ AppVersion;

		protected:
			/// <summary>
			/// Initializes the game library.
			/// </summary>
			void Initialize() override;

		private:
			/// <summary>
			/// Registers types.
			/// </summary>
			void RegisterTypes();
		};

		struct stack_base
		{
		protected:
			stack_base()
			{
				m_size = 0;
				m_ptr = (__int64)m_data;
				if ((m_ptr & 0xF) != 0)
					m_ptr += 0x10 - (m_ptr & 0xF);
			}

			int m_size;
		private:
			__int64 m_ptr;
			char m_data[0x10];

		public:
			template <typename T>
			void set(int offset, T value)
			{
				if (offset < 0 || offset >= m_size)
					throw 1008023;

				T* addr = (T*)(m_ptr + offset);
				*addr = value;
			}

			template <typename T>
			T get(int offset)
			{
				if (offset < 0 || offset >= m_size)
					throw 1008024;

				T* addr = (T*)(m_ptr + offset);
				return *addr;
			}

			void set(int offset, System::IntPtr value)
			{
				set(offset, value.ToInt64());
			}

			void zero()
			{
				for (int i = 0; i < m_size; i += sizeof(__int64))
					*(__int64*)(m_ptr + i) = (__int64)0;
			}

			System::IntPtr ptr()
			{
				return System::IntPtr((void*)m_ptr);
			}
		};

		struct stack10 : stack_base
		{
			stack10() : stack_base()
			{
				m_size = 0x10;
				zero();
			}

		private:
			char m_data_ex[0x10];
		};

		struct stack20 : stack_base
		{
			stack20() : stack_base()
			{
				m_size = 0x20;
				zero();
			}

		private:
			char m_data_ex[0x20];
		};

		struct stack40 : stack_base
		{
			stack40() : stack_base()
			{
				m_size = 0x40;
				zero();
			}

		private:
			char m_data_ex[0x40];
		};

		struct stack80 : stack_base
		{
			stack80() : stack_base()
			{
				m_size = 0x80;
				zero();
			}

		private:
			char m_data_ex[0x80];
		};

		struct stack100 : stack_base
		{
			stack100() : stack_base()
			{
				m_size = 0x100;
				zero();
			}

		private:
			char m_data_ex[0x100];
		};

		struct stack200 : stack_base
		{
			stack200() : stack_base()
			{
				m_size = 0x200;
				zero();
			}

		private:
			char m_data_ex[0x200];
		};

		struct stack400 : stack_base
		{
			stack400() : stack_base()
			{
				m_size = 0x400;
				zero();
			}

		private:
			char m_data_ex[0x400];
		};

		struct stack800 : stack_base
		{
			stack800() : stack_base()
			{
				m_size = 0x800;
				zero();
			}

		private:
			char m_data_ex[0x800];
		};

		struct stack1000 : stack_base
		{
			stack1000() : stack_base()
			{
				m_size = 0x1000;
				zero();
			}

		private:
			char m_data_ex[0x1000];
		};

		struct stack2000 : stack_base
		{
			stack2000() : stack_base()
			{
				m_size = 0x2000;
				zero();
			}

		private:
			char m_data_ex[0x2000];
		};

		struct stack4000 : stack_base
		{
			stack4000() : stack_base()
			{
				m_size = 0x4000;
				zero();
			}

		private:
			char m_data_ex[0x4000];
		};

		struct stack8000 : stack_base
		{
			stack8000() : stack_base()
			{
				m_size = 0x8000;
				zero();
			}

		private:
			char m_data_ex[0x8000];
		};

		struct stack10000 : stack_base
		{
			stack10000() : stack_base()
			{
				m_size = 0x10000;
				zero();
			}

		private:
			char m_data_ex[0x10000];
		};
	}
}

#pragma warning(pop)
